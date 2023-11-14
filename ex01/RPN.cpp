#include "RPN.hpp"

RPN::RPN(std::string pl)
{
    int d = 0;
    _pol.resize(pl.size());
    for (size_t i = 0; i < pl.size(); i++)
    {
        if(pl[i] == ' ' )
            i++;
        _pol[d] = pl[i];
        d++;
        i++;
    }
    _pol.resize(d);
}

int RPN::operate(char c)
{
    int b = _tmp.top();
    _tmp.pop();
    int a = _tmp.top();
    _tmp.pop();

    if (c == '+')
        return (a + b);
    else if (c == '-')
        return (a - b);
    else if (c == '*')
        return (a * b);
    else if (c == '/')
        return (a / b);
    else
        return (0);
}

int RPN::solveIt()
{
    for (size_t i = 0; i < _pol.size(); i++)
    {
        if(_pol[i] >= 48 && _pol[i] <= 57)
        {
            _tmp.push(_pol[i] - '0');
        }
        else if (_pol[i] == '-' || _pol[i] == '+' || _pol[i] == '*' || _pol[i] == '/')
        {
            _tmp.push(operate(_pol[i]));
        }
        else
        {
            std::cout << "Error" << std::endl;
            return (0);
        }
    }
    return (_tmp.top());
}

RPN::~RPN()
{}