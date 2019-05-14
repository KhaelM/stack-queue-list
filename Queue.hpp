#pragma once

template<class T>
class Queue
{
private:
    T* array;
    int firstElementIndex = -1;
    int lastElementIndex = -1;
    int maxSize;
    const int DEFAULT_SIZE = 100;

public:
    Queue();
    Queue(int initialSize);
    ~Queue();
    bool isEmpty();
    void enqueue(T); // Enfiler
    T dequeue(); // Defiler
    void displayElement();
    int getSize();
};

template<class T>
Queue<T>::Queue()
{
    this->array = new T[this->DEFAULT_SIZE];
}

template<class T>
Queue<T>::Queue(int initialSize)
{
    this->array = new T[initialSize];
    this->maxSize = initialSize;
}

template<class T>
Queue<T>::~Queue()
{
    delete this->array;
}

template<class T>
bool Queue<T>::isEmpty()
{
    return this->lastElementIndex <= this->firstElementIndex;
}

template<class T>
void Queue<T>::enqueue(T element)
{
    if(this->size >= this->maxSize - 1) {
        throw new std::runtime_error("Impossible de d'enfiler: Le tableau est déjà plein.");
    }

    this->array[++this->lastElementIndex] = element;
}

template<class T>
T Queue<T>::dequeue()
{
    if(this->isEmpty()) {
        throw std::runtime_error("Impossible de defiler, le tableau est vide.");
    }

    return this->array[this->firstElementIndex++];
}

template<class T>
void Queue<T>::displayElement()
{
    std::cout << '[';
    for (int i = this->firstElementIndex; i <= this->lastElementIndex; i++)
    {
        std::cout << this->array[i];
        if (i != this->lastElementIndex)
            std::cout << ',';
    }
    std::cout << ']' << '\n';
}

template<class T>
int Queue<T>::getSize()
{
    return this->lastElementIndex - this->firstElementIndex;
}