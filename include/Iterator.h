/*
    Generic Iterator Pattern design to iterate trough a Linked List
*/
#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator
{
private:
    Node<T>* current_node;  //current node being iterated
public:
    Iterator(Node<T>* nodo);    //Constructor with a pointer to a generic node as parameter
    Iterator();     //Default constructor
    ~Iterator();    //Destructor
    Iterator &operator++(); //Increment by one operator overloading
    Iterator operator = (const Node<T>* nodo);  //Assignment operator overloading when assigning to a pointer to a generic node
    bool operator!=(const Iterator& iterator);  //Inequality operator overloading when compared to another iterator
    T operator*();  //Dereference operator overloading
};
template <typename T>
Iterator<T>::Iterator(Node<T>* nodo)
{
    this->current_node = nodo;
}

template <typename T>
Iterator<T>::Iterator()
{
    this->current_node = nullptr;
}

template <typename T>
Iterator<T>::~Iterator()
{
    delete current_node;
}

template <typename T>
Iterator<T>& Iterator<T>::operator ++ ()
{
    if(this->current_node)
    {
        this->current_node = current_node->next;
    }
    return *this;
};
template <typename T>
Iterator<T> Iterator<T>::operator = (const Node<T>* nodo)
{
    this->current_node = nodo;
    return *this;
}
template <typename T>
bool Iterator<T>::operator != (const Iterator& iterator)
{
    return current_node != iterator.current_node;
}

template <typename T>
T Iterator<T>::operator*()
{
    return current_node->elem;
}
#endif  //ITERATOR_H