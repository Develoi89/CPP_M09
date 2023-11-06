#include "BitcoinExchange.hpp"
#include <ctime>

bool ComproveIt(std::string l)
{
    std::string date = l.substr(0, 10);
    std::string format = "%Y-%m-%d";
    struct std::tm timeinfo;
    std::memset(&timeinfo, 0, sizeof(timeinfo));

    if (strptime(date.c_str(), format.c_str(), &timeinfo) == nullptr) 
        return false;
    return true;
}

int main(int argc, char* argv[])
{
    BitcoinExchange Data;
    std::ifstream input(argv[1]);
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