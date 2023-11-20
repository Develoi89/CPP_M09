#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>
#include <limits>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const & c);
        PmergeMe & operator = (PmergeMe const & c);
        ~PmergeMe();
        int static init(std::vector<int> nmb);
        int static start(std::list<int> nmb);
};

int verify(std::string s);

#endif