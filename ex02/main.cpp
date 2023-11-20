#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "PmergeMe need numbers to sort" << std::endl;
        return 0;
    }
    for (size_t i = 1; i < argc; i++)
    {
        if(verify(argv[i]))
        {
            std::cout << "error" << std::endl;
            return 0;
        }
    }
    std::cout << "Before:";
    for (size_t i = 0; i < (argc - 1); i++)
        std::cout << " " << argv[i + 1];
    std::cout << std::endl;
    std::vector<int> vNum;
    std::list<int> lNum;
    for (size_t i = 0; i < (argc - 1); i++)
    {
        vNum.push_back(std::stoi(argv[i + 1]));
        lNum.push_back(std::stoi(argv[i + 1]));
    }
    clock_t start = clock();
    PmergeMe::init(vNum);
    clock_t end = clock();
    clock_t start2 = clock();
    PmergeMe::start(lNum);
    clock_t end2 = clock();
    long double elapsed_time_list = static_cast<long double>(end - start) / CLOCKS_PER_SEC;
    long double elapsed_time_list2 = static_cast<long double>(end2 - start2) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << elapsed_time_list << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << elapsed_time_list2 << " us" << std::endl;
    return 0;
}