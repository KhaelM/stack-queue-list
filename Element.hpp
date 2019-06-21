#pragma once

template<class T>
class Element
{
private:
    T data;
    Element<T> *next;
    Element<T> *previous;
public:
    Element(T data);
    T getData();
    Element<T>* getNext();
    void setNext(Element<T> *next);
    Element<T>* getPrevious();
    void setPrevious(Element<T> *previous);
    bool hasNext();
};

template<class T>
Element<T>::Element(T data)
{
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

template<class T>
Element<T>* Element<T>::getNext() {
    return this->next;
}

template<class T>
void Element<T>::setNext(Element<T> *next) {
    this->next = next;
}

template<class T>
Element<T>* Element<T>::getPrevious() {
    return this->previous;
}

template<class T>
void Element<T>::setPrevious(Element<T> *previous) {
    this->previous = previous;
}

template<class T>
T Element<T>::getData()
{
    return this->data;
}

template<class T>
bool Element<T>::hasNext()
{
    return this->next != nullptr;
}