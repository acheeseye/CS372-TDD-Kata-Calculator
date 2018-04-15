#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Catch::Session session;
    int result = session.applyCommandLine(argc, argv);
    if(!result)
    {
        cout << "BEGIN TESTS" << endl;
        result = session.run();
        cout << "END OF TESTS" << endl;
    }
    return result;
}