#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream data("data.csv");
        if (data.is_open())
            {
                std::string line;
                while (std::getline(data, line))
                {
                    int coma;
                    coma = line.find(",");
                    DBase.insert(std::make_pair(line.substr(0,coma), line.substr(coma + 1, line.size())));
                }
            }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & c)
{
    DBase = c.DBase;
}
BitcoinExchange & BitcoinExchange::operator =(BitcoinExchange const &c)
{
    DBase = c.DBase;
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}