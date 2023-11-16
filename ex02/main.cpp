#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
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
    long double elapsed_time_list = static_cast<long double>(end - start);
    long double elapsed_time_list2 = static_cast<long double>(end2 - start2);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << elapsed_time_list << " clicks" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << elapsed_time_list2 << " clicks" << std::endl;
    return 0;
}