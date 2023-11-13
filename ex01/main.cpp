#include "RPN.hpp"

int main(int argc, char* argv[])
{
    RPN r(argv[1]);
    r.solveIt();
    return 0;
}