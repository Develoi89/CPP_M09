#include "BitcoinExchange.hpp"
#include <ctime>

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
		return false;
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
	if (RealDate(date))
		return true;
	else
	{
		std::cout << "no valid date" << std::endl;
		return false;
	}
	return true;
	if (l.substr(10, 3).compare(" | "))
		return false;
	
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
		while (std::getline(input, line))
		{
			if (ComproveIt(line))
				std::cout << "okk" << std::endl;
			else    
				std::cout << "no okk" << std::endl;

		}
	}
	return 0;
}