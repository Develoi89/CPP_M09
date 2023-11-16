#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const & c){}
PmergeMe & PmergeMe::operator = (PmergeMe const & c)
{
    return *this;
}
PmergeMe::~PmergeMe(){}

int verify(std::string s)
{
    try
    {
        long int tmp = stoll(s);
        if(tmp < 0 || tmp > __INT_MAX__)
            return 1;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

std::vector<int> sort(std::vector<int> a, std::vector<int> b)
{
    int sa = a.size();
    int sb = b.size();
    std::vector<int> r;
    while (a.size() > 0 && b.size()  > 0)
    {
        if (a.front() <= b.front())
        {
            r.push_back(a.front());
            a.erase(a.begin());
        }
        else
        {
            r.push_back(b.front());
            b.erase(b.begin());
        }
    }
    while (a.size() > 0 )
    {
            r.push_back(a.front());
            a.erase(a.begin());
    }
    while (b.size() > 0 )
    {
            r.push_back(b.front());
            b.erase(b.begin());
    }
    return r;
}

std::vector<int> splitV(std::vector<int> nmb)
{
    if (nmb.size() <= 1)
        return nmb;
    int mid = nmb.size() / 2;
    int end = nmb.size();
    std::vector<int> left;
    std::vector<int> right;
    
    for (size_t i = 0; i < mid; i++)
    {
        left.push_back(nmb.front());
        nmb.erase(nmb.begin());
    }
    for (size_t i = mid; i < end; i++)
    {
        right.push_back(nmb.front());
        nmb.erase(nmb.begin());
    }
    left = splitV(left);
    right = splitV(right);
    return (sort(left, right));
}

int PmergeMe::init(std::vector<int> nmb)
{
    nmb = splitV(nmb);
    std::cout << "After:";
    for (size_t i = 0; i < nmb.size(); i++)
        std::cout << " " << nmb[i];
    std::cout << std::endl;
    return 0;
}

std::list<int> sortL(std::list<int> a, std::list<int> b)
{
    int sa = a.size();
    int sb = b.size();
    std::list<int> r;
    while (a.size() > 0 && b.size()  > 0)
    {
        if (a.front() <= b.front())
        {
            r.push_back(a.front());
            a.erase(a.begin());
        }
        else
        {
            r.push_back(b.front());
            b.erase(b.begin());
        }
    }
    while (a.size() > 0 )
    {
            r.push_back(a.front());
            a.erase(a.begin());
    }
    while (b.size() > 0 )
    {
            r.push_back(b.front());
            b.erase(b.begin());
    }
    return r;
}

std::list<int> splitL(std::list<int> nmb)
{
    if (nmb.size() <= 1)
        return nmb;
    int mid = nmb.size() / 2;
    int end = nmb.size();
    std::list<int> left;
    std::list<int> right;
    
    for (size_t i = 0; i < mid; i++)
    {
        left.push_back(nmb.front());
        nmb.erase(nmb.begin());
    }
    for (size_t i = mid; i < end; i++)
    {
        right.push_back(nmb.front());
        nmb.erase(nmb.begin());
    }
    left = splitL(left);
    right = splitL(right);
    return (sortL(left, right));
}

int PmergeMe::start(std::list<int> nmb)
{
    nmb = splitL(nmb);
    return 0;
}