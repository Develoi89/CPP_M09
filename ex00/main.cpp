#include "BitcoinExchange.hpp"
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
	if (l.size() < 14)
	{
		std::cout << "wrong format line." << std::endl;
		return false;
	}
	std::string date = l.substr(0, l.find("|") - 1);
	if(date.size() > 10)
		return false;
	std::string format = "%Y-%m-%d";
	struct std::tm timeinfo;
	std::memset(&timeinfo, 0, sizeof(timeinfo));
	if (strptime(date.c_str(), format.c_str(), &timeinfo) == nullptr) 
	{
		std::cout << "no valid format date" << std::endl;
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
	return true;
}

int main(int argc, char* argv[])
{
	BitcoinExchange Data;
	std::ifstream input(argv[1]);
	if (argc < 2)
	{
		std::cout << "need input file." << std::endl;
		return 0;
	}
	if (input.is_open())
	{
		std::string line;
		std::getline(input, line);
		while (std::getline(input, line))
		{
			if (ComproveIt(line))
				std::cout << "okk" << std::endl;
		}
	}
	return 0;
}