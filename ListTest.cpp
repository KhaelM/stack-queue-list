#include <iostream>
#include <exception>

#include "List.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    List<int> *list = new List<int>();
    try {
        list->add(1);
        list->add(10);
        list->add(30);
        list->add(40);
        list->addAfter(3, 20);
        list->display();
        cout << list->getLast();
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}