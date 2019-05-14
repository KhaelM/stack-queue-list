#include <iostream>
#include <exception>

#include "Stack.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Stack<int> *integerArray = new Stack<int>(2);
    try
    {
        integerArray->pop();
        // cout << integerArray->isEmpty() << '\n';
        // integerArray->push(10);
        // integerArray->push(100);
        // cout << integerArray->isEmpty() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
