/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:36 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/05 20:17:54 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
   (void)other;
   *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
   (void)other;
   return *this;
}

void BitcoinExchange::run(int argc, char *argv[])
{
   validateArgs(argc, argv);
   loadDatabase(DB_FILENAME);
   // printDB();
   processInput(argv[1]);
}

void BitcoinExchange::readDatabaseLine(std::string &line)
{
   std::string date;
   std::string value;
   char **endptr = NULL;
   int value_double;

   size_t delimiter = line.find(',');
   if (delimiter != std::string::npos)
   {
      date = line.substr(0, delimiter);
      value = line.substr(delimiter + 1);
   }

   value_double = strtod(value.c_str(), endptr);
   if (endptr != NULL)
      throw std::runtime_error("Values in the database not in the correct format");

   if (isValidDate(date) && isValidValue(value_double))
      database[date] = value_double;
   else
   {
      if (!isValidDate(date))
         std::cerr << "Date is wrong: " << date << std::endl;

      if (!isValidValue(value_double))
         std::cerr << "Value is wrong: " << value << std::endl;

      std::cerr << "Error in this line in database: " << line << std::endl;
      throw std::runtime_error("Date or value in the database are not valid");
   }
}

void BitcoinExchange::readInputLine(std::string &line)
{
   std::string date;
   std::string value;
   char **endptr = NULL;
   int value_double;

   size_t delimiter = line.find('|');
   if (delimiter != std::string::npos)
   {
      date = line.substr(0, delimiter);
      value = line.substr(delimiter + 1);
   }
   else {
      std::cerr << "Error: bad input => " << line << std::endl;
   }

   value_double = strtod(value.c_str(), endptr);
   if (endptr != NULL)
      throw std::runtime_error("Values in the database not in the correct format");

   if (isValidDate(date) && isValidValue(value_double))
   {
      std::cout << date << " => " << value_double << " = " << "ADD CONVERSION HERE" << std::endl;
      
   }
   //
   else
   {
      // if (!isValidDate(date))
      //    std::cerr << "Error: bad input => " << date << std::endl;

      // if (!isValidValue(value_double))
      //    std::cerr << "Value is wrong: " << value << std::endl;

      // std::cerr << "Error in this line in database: " << line << std::endl;
      // throw std::runtime_error("Date or value in the database are not valid");
   }
}

void BitcoinExchange::validateArgs(int argc, char *argv[]) const
{
   if (argc != 2)
      throw std::runtime_error("No input file provided");
   std::ifstream file(argv[1]);
   if (!file.good())
   {
      file.close();
      throw std::runtime_error("Error opening file");
   }
   file.close();
}

void BitcoinExchange::loadDatabase(std::string db_name)
{
   std::ifstream file(db_name.c_str());
   if (!file.good())
      throw std::runtime_error("Error opening database file");
   std::string line;
   while (std::getline(file, line, '\n'))
   {
      if (file.fail() && !file.eof())
      {
         file.close();
         throw std::runtime_error("Error reading file");
      }
      if (line != DB_HEADER)
         readDatabaseLine(line);
   }
}

void BitcoinExchange::processInput(char *filename)
{
   std::ifstream file(filename);
   if (!file.good())
      throw std::runtime_error("Error opening input file");
   std::string line;
   std::getline(file, line, '\n');
   while (std::getline(file, line, '\n'))
   {
      if (file.fail() && !file.eof())
      {
         file.close();
         throw std::runtime_error("Error reading file");
      }
      readInputLine(line);
   }
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
   std::string year;
   std::string month_and_date;
   size_t delimiter = date.find('-');
   if (delimiter != std::string::npos)
   {
      year = date.substr(0, delimiter);
      month_and_date = date.substr(delimiter + 1);
      // std::cerr << "Year : " << year << " Month and date: " << month_and_date << std::endl;
   }
   unsigned int year_int = atoi(year.c_str());
   // std::cerr << "Year_int : " << year_int << std::endl;

   if (year_int < 0 || year_int > 9999)
      return false;

   std::string month;
   std::string day;

   delimiter = month_and_date.find('-');
   if (delimiter != std::string::npos)
   {
      month = month_and_date.substr(0, delimiter);
      day = month_and_date.substr(delimiter + 1);
      // std::cerr << "Month : " << month << " Day: " << day << std::endl;
   }
   unsigned int month_int = atoi(month.c_str());
   if (month_int < 1 || month_int > 12)
      return false;
   unsigned int day_int = atoi(day.c_str());
   if (day_int < 1 || day_int > 31)
      return false;
   return true;
}

bool BitcoinExchange::isValidValue(const double &value_double) const
{
   if (value_double < 0)
   {
      std::cerr << "Error: not a positive number" << std::endl;
      return false;
   }
   else if (value_double > 1000)
   {
      std::cerr << "Error: too large a number" << std::endl;
      return false;
   }
   else
      return true;
}

void BitcoinExchange::printDB(void) const
{
   std::map<std::string, double>::const_iterator it;
   for (it = database.begin(); it != database.end(); ++it)
   {
      std::cout << it->first << " => " << it->second << std::endl;
   }
}
