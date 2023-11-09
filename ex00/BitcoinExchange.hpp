#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, std::string> DBase;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & c);
        BitcoinExchange & operator =(BitcoinExchange const &c);
        ~BitcoinExchange();
        void searchExe(std::string l);
};

bool isNumeric(std::string n);
bool ValidNum(std::string l);
bool RealDate(std::string date);
bool ComproveIt(std::string l);

#endif