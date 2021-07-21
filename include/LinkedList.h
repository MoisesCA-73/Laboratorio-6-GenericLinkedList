/*
    Generic Linked List for any type

*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Iterator.h"

template <typename T>
class LinkedList;   //Defining it previously to the declaration of the overloading with outstream <<

template <typename T>
std::ostream &operator << (std::ostream &out,const LinkedList<T> &l);   //operator <<  overloading for LinkedList

template <typename T>
class LinkedList
{
private:
    int size;   //Size of the linked list
    Node<T>* head;  //Head node of the linked list
public:
    //Constructors
    LinkedList(Node<T>* head, int sz); //Constructor with parameters node* as the head and sz as the size 
    LinkedList();    //Default constructor

    //Big five
    ~LinkedList();  //Destructor
    LinkedList(const LinkedList<T> &list); //Copy constructor
    LinkedList(LinkedList<T> && list);  //Move constructor
    LinkedList<T> &operator= (const LinkedList<T> &list);  //Copy assignment
    LinkedList<T> &operator= (LinkedList<T> && list); //Move assignment

    //Getters
    int get_size() const;
    Node<T>* get_head() const;
    
    //Iterator types
    Iterator<T> begin() const;  
    Iterator<T> end() const;

    //Methods
    void insert(T x, int pos);
    void push_front(T x);   //Inserts an element at the beginning of the list
    void push_back(T x);    //Inserts an element at the end of the list

    void pop_front();   //Deletes first element
    void pop_back();    //Deletes last element
    void remove(int pos);   //Remove a node given its position (starting by 0)

    void print() const; //prints Linked List in console
    void clear();   //Resets the linkedlist with 0 nodes

    //Friendship with outstream overloading <<
    friend std::ostream &operator << <>(std::ostream &out,const LinkedList<T> &l);
};

//Constructor
template <typename T>
LinkedList<T>::LinkedList(Node<T>* head, int sz)
{
    this->head = head;
    this->size = sz;
}
//Default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

//Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* aux = this->head;
    while(aux)
    {
        this->head = aux->next;
        delete aux;
        aux = aux->next;
    }
    delete aux;
}

//Copy Constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = list.head;
    while(actual_o)
    {
        this->push_back(actual_o->elem);
        actual_o = actual_o->next;
    }
}

//Move Constructor
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> && list)
{
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = list.head;
    while(actual_o)
    {
        this->push_back(actual_o->elem);
        actual_o = actual_o->next;
    }
}

//Copy assignment
template <typename T>
LinkedList<T> &LinkedList<T>::operator = (const LinkedList<T> &list)
{
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = list.head;
    while(actual_o)
    {
        this->push_back(actual_o->elem);
        actual_o = actual_o->next;
    }

    return *this;
}

//Move assignment
template <typename T>
LinkedList<T> &LinkedList<T>::operator= (LinkedList<T> && list)
{
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = list.head;
    while(actual_o)
    {
        this->push_back(actual_o->elem);
        actual_o = actual_o->next;
    }

    return *this;
}

//Getters
template <typename T>
int LinkedList<T>::get_size() const
{
    return this->size;
}

template <typename T>
Node<T>* LinkedList<T>::get_head() const
{
    return this->head;
}


template <typename T>
Iterator<T> LinkedList<T>::begin() const
{
    return Iterator<T>(this->head);
}

template <typename T>
Iterator<T> LinkedList<T>::end() const
{
    return Iterator<T>(nullptr);
}

//Metodos
template <typename T>
void LinkedList<T>::insert(T x, int pos)
{
    Node<T>* new_node = new Node<T>;
    new_node->elem = x;

    Node<T> *aux = this->head;
    Node<T> *aux2;
    for(size_t i = 0; i < pos; i++)
    {
        aux2 = aux;
        aux = aux->next;
    }
    if(pos == 0)
    {
        this->head = new_node;
    }
    else
    {
        aux2->next = new_node;
    }

    new_node->next = aux;
    this->size++;

}


template <typename T>
void LinkedList<T>::push_front(T x)
{
    Node<T>* new_node = new Node<T>;
    new_node->elem = x;

    if (this->size == 0)
    {
        this->head = new_node;
    }
    else
    {
        Node<T>* aux = this->head;
        this->head = new_node;
        new_node->next = aux;
    }
    this->size++;

}

template <typename T>
void LinkedList<T>::push_back(T x)
{
    Node<T>* new_node = new Node<T>;
    new_node->elem = x;

    Node<T> *aux = this->head;
    Node<T> *aux2;
    while(aux)
    {
        aux2 = aux;
        aux = aux->next;
    }
    if(this->size == 0)
    {
        this->head = new_node;
    }
    else
    {
        aux2->next = new_node;
    }

    new_node->next = aux;
    this->size++;
}

template <typename T>
void LinkedList<T>::remove(int pos)
{
    if(pos == 0)
    {
        this->head = this->head->next;
    }
    else
    {
        Node<T>* aux = new Node<T>;
        aux = this->head;
        for(int i = 0; i < pos-1; i++)
        {
            aux = aux->next;
        }
        aux->next = aux->next->next;
    }
    this->size--;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    if(this->size == 1)
    {
        this->head = nullptr;
    }
    else
    {
        this->head = this->head->next;
    }
    this->size--;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if(this->size == 1)
    {
        this->head = nullptr;
    }
    else
    {
        Node<T>* aux = new Node<T>;
        aux = this->head;
        while(aux->next->next)
        {
            aux = aux->next;
        }
        aux->next = nullptr;
    }
    this->size--;
}

template <typename T>
void LinkedList<T>::print() const
{
    Node<T>* aux = new Node<T>;
    aux->elem = this->head->get_elem();
    aux->next = this->head->get_next();
    while(aux)
    {
        std::cout << aux->get_elem() << " -> ";
        aux = aux->get_next();
    }
}

template <typename T>
void LinkedList<T>::clear()
{
    this->head = nullptr;
    this->size = 0;
}

//Sobrecarga de salida <<
template <typename T>
std::ostream &operator << (std::ostream &out,const LinkedList<T> &l)
{
   out << *l.head;
   return out;
}

#endif  //LINKEDLIST_H