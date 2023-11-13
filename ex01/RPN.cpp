#include "RPN.hpp"

RPN::RPN(std::string pl)
{
    for (int i = pl.size(); i > -1 ; i--)
        if (pl[i] != 32)
            _pol.push(pl[i]);
}

// void RPN::printIt()
// {
//     while(_pol.size() > 0)
//     {
//         std::cout << _pol.top();
//         _pol.pop();
//     }
//     std::cout << std::endl;
// }

int operate(int a, int b, char c)
{
    if (c == '+')
        return (a + b);
    else if (c == '-')
        return (a - b);
    else if (c == '*')
        return (a * b);
    else if (c == '/')
        return (a / b);
    else
    {
        std::cout << "wrong polynomial" << std::endl;
        return 0;
    }
}

void RPN::solveIt()
{
    try
    {
        int a = _pol.top() - '0';
        std::cout << a << std::endl;
        _pol.pop();
        while (_pol.size() > 1)
        {
            int b = _pol.top() - '0';
            _pol.pop();
            char c = _pol.top();
            _pol.pop();
            a = operate(a, b, c);
        }
        std::cout << "Result: " << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: wrong polynomial." << std::endl;
    }

}

RPN::~RPN()
{}