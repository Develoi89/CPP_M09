#include "BitcoinExchange.hpp"

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
				Data.searchExe(line);
		}
	}
	return 0;
}