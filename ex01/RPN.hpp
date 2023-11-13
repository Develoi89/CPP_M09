#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <stack>
#include <exception>

class RPN
{
private:
    std::stack<char> _pol;
public:
    RPN(std::string pl);
    RPN(RPN const &c);
    RPN & operator = (RPN const & c);
    ~RPN();
    void solveIt();
    // void printIt();
};

#endif