#include "RPN.hpp"

int main(int argc, char* argv[])
{
    std::string tmp;
    int d = 0;
    int l = 0;
    if(argc < 2)
        return 0;
    while(argv[1][d] == ' ')
        d++;
    tmp.resize(strlen(argv[1]) - d);
    while(l < tmp.size())
        tmp[l++] = argv[1][d++];
    for (size_t i = 0; i < tmp.size(); i++)
    {
        if((i % 2 != 0) && tmp[i] != 32 && (tmp[0] >= '0' && tmp[0] <= '9'))
        {
            std::cout << "Error" << std::endl;
            return 0;
        }
    }

    RPN r(tmp);
    std::cout << r.solveIt() << std::endl;
    return 0;
}