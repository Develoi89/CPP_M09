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
                    DBase.insert(std::make_pair(line.substr(0,coma), line.substr(coma + 1, line.size() - (coma + 1))));
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
void BitcoinExchange::searchExe(std::string l)
{
    std::string date = l.substr(0, l.find("|") - 1);
    double amount = std::stod(l.substr(13, l.size()-13));
    if (DBase[date] == "")
    {
        std::map<std::string, std::string>::iterator it = DBase.upper_bound(date);
        --it;
        --it;
        double value = std::stod(DBase[it->first]);
        std::cout << date << " => " << amount << " = " << (amount * value) << std::endl; 
    }
    else
    {
        double value = std::stod(DBase[date]);
        std::cout << date << " => " << amount << " = " << (amount * value) << std::endl;
    }
}