/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/05/05 19:20:19 by mrizakov         ###   ########.fr       */
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

public:
    BitcoinExchange(void);
    ~BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void validateArgs(int argc, char *argv[]) const;
    void readDatabaseLine(std::string &line);
    void readInputLine(std::string &line);

    void loadDatabase(std::string db_name);
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const double &value) const;
    void printDB(void) const;
    void processInput(char *filename);

    void run(int argc, char *argv[]);
};
