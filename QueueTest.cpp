#include <iostream>
#include <exception>

#include "Queue.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Queue<int> *integerArray = new Queue<int>(2);
    try
    {
        integerArray->enqueue(10);
        integerArray->enqueue(100);
        integerArray->displayElement();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
