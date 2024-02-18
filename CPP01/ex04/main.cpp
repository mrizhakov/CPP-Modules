/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2024/02/15 16:12:03 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
    std::string line;
    size_t found;
    if (argc != 4)
    {
        std::cout <<  "Correct usage: ./replace <filename> <string to be replaced> <replacement string>" << std::endl;
        return (0);
    }
    std::ifstream inFile(argv[1]);
    if (!inFile)
    {
        std::cerr << "Error: unable to open infile" << std::endl;
        return (1);
    }
    std::string filename(argv[1]);
    std::string outFilename = filename + ".replace";
    const char *outFilenameCstring = outFilename.c_str();

    std::string needle(argv[2]);
    std::string newNeedle(argv[3]);

    std::ofstream outFile;
    outFile.open(outFilenameCstring, std::ofstream::out);
    if (!outFile) {
        std::cerr << "Cant open outfile for writing" << std::endl;
        return(1);
    }

    if (needle.size() == 0 ) {
        std::cerr << "No string to search for" << std::endl;
        return(1);
    }

    while(std::getline(inFile, line))
    {
        found = line.find(needle);
        while (found != std::string::npos)
        {
            line.erase(found, needle.size());
            if (newNeedle.size() != 0)
                line.insert(found, newNeedle);
            found = line.find(needle);
        }
        if (found == std::string::npos)
        {
            outFile << line << std::endl;
            found = line.find(argv[2]);
        }
    }
    inFile.close();
    outFile.close();
    return (0);
}