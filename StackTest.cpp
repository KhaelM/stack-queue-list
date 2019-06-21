#include <iostream>
#include <exception>

#include "Stack.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Stack<int> *integerArray = new Stack<int>(2);
    try
    {
        /* List is empty here so it should throw an Exception */
        // integerArray->pop();

        integerArray->push(10);
        integerArray->push(100);
        integerArray->displayElement();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
