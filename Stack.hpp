#pragma once

template<class T>
class Stack
{
private:
    T* array;
    int size = -1;
    int maxSize;
    const int DEFAULT_SIZE = 100;
public:
    Stack();
    Stack(int initialSize);
    ~Stack();
    void push(T); // Empiler
    T pop(); // Depiler
    bool isEmpty();
};

template<class T>
Stack<T>::Stack()
{
    this->array = new T[this->DEFAULT_SIZE];
}

template<class T>
Stack<T>::Stack(int initialSize)
{
    this->array = new T[initialSize];
    this->maxSize = initialSize;
}

template<class T>
Stack<T>::~Stack()
{
    delete this->array;
}

template<class T>
void Stack<T>::push(T element)
{
    if(this->size >= this->maxSize - 1) {
        throw new std::runtime_error("Le tableau est déjà plein.");
    }

    this->array[++this->size] = element;
}

template<class T>
T Stack<T>::pop()
{
    if(this->isEmpty()) {
        throw std::runtime_error("Impossible de depiler, le tableau est vide.");
    }

    return this->array[this->size--];
}

template<class T>
bool Stack<T>::isEmpty()
{
    return this->size < 0;
}