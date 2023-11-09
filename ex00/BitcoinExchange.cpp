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

bool isNumeric(std::string n)
{
	int l = 0;
	int p = 0;
	for (size_t i = 0; i < n.size(); i++)
	{
		// if (n[i] == '-' || n[i] == '+')
		// 	l ++;
		if (n[i] == '.')
			p ++;
		if ((n[i] < 48 || n[i] > 57) && n[i] != '-' && n[i] != '+' && n[i] != '.' )
		{
			std::cout << "Error bad input => " << n << std::endl;
			return false;
		}
		if (i > 0 && (n[i] == '-' || n[i] == '+'))
		{
			std::cout << "Error: bad input => " << n << std::endl;
			return false;
		}
		if ((i == 0 || i == n.size() - 1) && n[i] == '.')
		{
			std::cout << "Error: bad input => " << n << std::endl;
			return false;
		}
	}
	long long int m = std::stoll(n);
	if (m > 1000)
	{
		std::cout << "Error: to large a number." << std::endl;
		return false;
	}
	if (m < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}	
	return true;
}

bool ValidNum(std::string l)
{
	std::string sn = l.substr(13, l.size() - 13);
	if (!(isNumeric(sn)))
		return false;
	else
		return true;
}

bool RealDate(std::string date)
{
	int y = std::stoi(date.substr(0, 4));
	int m = std::stoi(date.substr(5, 2));
	int d = std::stoi(date.substr(8, 2));
	bool bis = false;
	if(y < 2009)
		return false;
	if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		bis = true;
	if (d > 0 && d <= 31)
	{
		if ((m == 4 || m == 6 || m == 9 || m == 11 || m == 2) && d < 31)
		{
			if (m == 2 && bis == true && d <= 29)
				return true;
			else if (m == 2 && bis == false && d <= 28)
				return true;
			else
				return false;
		}
		return true;
	}
	else
		return false;
}

bool ComproveIt(std::string l)
{
	std::string date = l.substr(0, l.find("|") - 1);
	if(date.size() > 10)
		return false;
	std::string format = "%Y-%m-%d";
	struct std::tm timeinfo;
	std::memset(&timeinfo, 0, sizeof(timeinfo));
	if (strptime(date.c_str(), format.c_str(), &timeinfo) == nullptr) 
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (!(RealDate(date)))
	{
		std::cout << "no valid date" << std::endl;
		return false;
	}
	if (l.substr(10, 3).compare(" | ") == std::string::npos)
	{
		std::cout << "wrong format line." << std::endl;
		return false;
	}
	if (!(ValidNum(l)))
		return false;
		if (l.size() < 14)
	{
		std::cout << "wrong format line." << std::endl;
		return false;
	}
	return true;
}