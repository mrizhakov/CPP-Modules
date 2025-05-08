/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/08 16:32:52 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

#define DB_FILENAME "data.csv"
#define DB_HEADER "date,exchange_rate"

class BitcoinExchange
{
private:
    std::map<std::string, double> database;
    
    BitcoinExchange &operator=(const BitcoinExchange &other);
    BitcoinExchange(const BitcoinExchange &other);

    void validateArgs(int argc, char *argv[]) const;
    
    void readDatabaseLine(std::string &line, std::ifstream &file);
    void readInputLine(std::string &line) const;
    void loadDatabase(std::string db_name);
    
    bool isValidDate(const std::string &date) const;
    void isValidValue(const double &value) const;
    bool isValidPrice(const double &value) const;
    double findValueByDate(const std::string& date) const;

    void printDB(void) const;
    void processInput(char *filename) const;
    
public:
    BitcoinExchange(void);
    ~BitcoinExchange(void);

    void run(int argc, char *argv[]);    
};
