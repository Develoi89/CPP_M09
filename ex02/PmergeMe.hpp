#ifndef PMERGEME_HPP
# define PMERGE_HPP
#include <iostream>


class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const & c);
        PmergeMe & operator = (PmergeMe const & c);
        ~PmergeMe();
        void init(std::string nmb);
};

#endif