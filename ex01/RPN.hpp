#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <stack>
#include <exception>

class RPN
{
private:
    std::stack<int> _tmp;
    std::string _pol;
public:
    RPN(std::string pl);
    RPN(RPN const &c);
    RPN & operator = (RPN const & c);
    ~RPN();
    int solveIt();
    int operate(char c);
    // void printIt();
};

#endif