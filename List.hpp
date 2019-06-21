#pragma once

#include "Element.hpp"

template<class T>
class List
{
private:
    Element<T> *start = nullptr;
    Element<T> *end = nullptr;
    int size = 0;
public:
    T get(int index);
    T removeAt(int index);
    void add(T data);
    void addBefore(int index, T data);
    void addAfter(int index, T data);
    T getFirst();
    T getLast();
    int getSize();
    void display();
};

template<class T>
T List<T>::getLast() {
    return this->end->getData();
}

template<class T>
T List<T>::getFirst() {
    return this->start->getData();
}

template<class T>
void List<T>::addAfter(int index, T data) {
    Element<T> *element = new Element<T>(data);

    if(index < 0 ) {
        throw std::runtime_error("L'indice ne peut être négatif.");
    }

    if(index >= size) {
        throw std::runtime_error("L'indice est trop grand.");
    }

    int currentIndex = 0;
    Element<T> *currentElement = start;
    while (currentIndex != index)
    {
        currentElement = currentElement->getNext();
        currentIndex++;
    }

    Element<T> *next = currentElement->getNext();
    element->setNext(next);
    element->setPrevious(currentElement);

    if(next != nullptr) {
        next->setPrevious(element);
    }

    currentElement->setNext(element);

    if(index == size-1) {
        end = element;
    }

    ++this->size;
}

template<class T>
void List<T>::addBefore(int index, T data) {
    Element<T> *element = new Element<T>(data);

    if(index < 0 ) {
        throw std::runtime_error("L'indice ne peut être négatif.");
    }

    if(index >= size) {
        throw std::runtime_error("L'indice est trop grand.");
    }

    int currentIndex = 0;
    Element<T> *currentElement = start;
    while (currentIndex != index)
    {
        currentElement = currentElement->getNext();
        currentIndex++;
    }

    Element<T> *previous = currentElement->getPrevious();
    element->setNext(currentElement);
    element->setPrevious(previous);

    if(previous != nullptr) {
        previous->setNext(element);
    }

    currentElement->setPrevious(element);

    if(index == 0) {
        start = element;
    }

    ++this->size;
}

template<class T>
T List<T>::removeAt(int index) {
    if(index < 0 ) {
        throw std::runtime_error("L'indice ne peut être négatif.");
    }

    if(index >= size) {
        throw std::runtime_error("L'indice est trop grand.");
    }

    Element<T> *currentElement = start;
    int currentIndex = 0;

    while(currentIndex != index) {
        currentElement = currentElement->getNext();
        currentIndex++;
    }

    Element<T> *next = currentElement->getNext();
    Element<T> *previous = currentElement->getPrevious();  
    previous->setNext(next);
    
    if(next != nullptr)
        next->setPrevious(previous);

    return currentElement->getData();
}

template<class T>
void List<T>::display() {
    Element<T> *currentElement = start;
    std::cout << '[';
    while(currentElement != nullptr) {
        std::cout << currentElement->getData() << ',';
        currentElement = currentElement->getNext();
    }
    std::cout << ']';
}

template<class T>
void List<T>::add(T data) {
    Element<T> *newElement = new Element<T>(data);
    
    
    if(end == nullptr) {
        start = newElement;
    } else {
        newElement->setPrevious(end);
        newElement->setNext(nullptr);
        end->setNext(newElement);
    }
    end = newElement;

    ++this->size;
}

template<class T>
T List<T>::get(int index)
{
    if(index < 0 ) {
        throw std::runtime_error("L'indice ne peut être négatif.");
    }

    if(index >= size) {
        throw std::runtime_error("L'indice est trop grand.");
    }

    Element<T> *currentElement = start;
    int currentIndex = 0;

    while(currentIndex != index) {
        currentElement = currentElement->getNext();
        currentIndex++;
    }

    return currentElement->getData();
}

template<class T>
int List<T>::getSize() {
    return this->size;
}