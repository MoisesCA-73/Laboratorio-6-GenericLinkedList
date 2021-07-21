/*
    Class template that acts as the pieces of a Linked List
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>   
class LinkedList;

template <typename T>
class Node;

template <typename T>
class Iterator;

template <typename T>
std::ostream &operator << (std::ostream &out,const LinkedList<T> &l);   //Overloading of the outstream operator for Linked List <<
template <typename T>
std::ostream &operator << (std::ostream &out,const Node<T> &l); //Overloading of the outstream operator for Node <<

template <typename T>
class Node
{
private:    
    T elem;
    Node* next;
    //Friend classes
    friend class LinkedList<T>;
    friend class Iterator<T>;

public:
    //Constructor
    Node(T x);
    Node();
    Node(const Node<T> &node);

    //Getters
    T get_elem() const;
    Node* get_next() const;

    //Setters
    void set_elem(T elem);
    void set_next(Node<T>* next);

    //Sobrecarga a <<
    friend std::ostream &operator << <>(std::ostream &out, const Node<T> &n);
};

template <typename T>
Node<T>::Node(T x)
{
    this->elem = x;
    this->next = nullptr;
}

template <typename T>
Node<T>::Node()
{
    this->elem = T();
    this->next = nullptr;
}

template <typename T>
Node<T>::Node(const Node &node)
{
    this->elem = node.elem;
    this->next = node.next;
}

template <typename T>
T Node<T>::get_elem() const
{
    return this->elem;
}

template <typename T>
Node<T>* Node<T>::get_next() const
{
    return this->next;
}

//Setters
template <typename T>
void Node<T>::set_elem(T elem)
{
    this->elem = elem;
}

template <typename T>
void Node<T>::set_next(Node* next)
{
    this->next = next;
}

//Sobrecarga de salida <<
template <typename T>
std::ostream &operator << (std::ostream &out, const Node<T> &n)
{
    Node<T>* aux= new Node<T>();
    aux->elem = n.elem;
    aux->next = n.next;
    
    while(aux)
    {
        out << aux->elem << " -> ";
        aux = aux->next;
    }
    return out;
}

#endif  //NODE_H