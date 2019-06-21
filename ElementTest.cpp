#include <iostream>
#include <exception>

#include "Element.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Element<int> *element = new Element<int>(5);
    cout << element->get() << '\n';
}