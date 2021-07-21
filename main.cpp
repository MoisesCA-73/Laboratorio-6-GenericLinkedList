#include <iostream>
#include "include/LinkedList.h"

int main()
{
    LinkedList<int> lista;

    lista.push_front(5);
    lista.push_front(9);
    lista.push_front(4);
    lista.push_front(6);
    lista.push_front(1);
    lista.push_front(2);
    
    lista.push_back(11);
    lista.push_back(20);
    lista.push_back(13);
    lista.push_back(15);

    std::cout << "Imprimiendo los contenidos de lista 1\n";
    lista.print();
    std::cout << '\n';

    LinkedList<char> lista2;
    lista2.push_front('z');
    lista2.push_front('x');
    lista2.push_front('w');

    lista2.push_back('r');
    lista2.push_back('t');
    lista2.push_back('s');

    std::cout << "Imprimiendo los contenidos de lista 2\n";
    lista2.print();
    std::cout << '\n';

    lista2.remove(4);
    std::cout << "Imprimiendo los contenidos de lista 2 quitando un elemento\n";
    lista2.print();
    std::cout << '\n';

    std::cout << "Imprimiendo los contenidos de lista 2 con la sobrecaga de <<\n";
    std::cout << lista2 << '\n';

    lista2.pop_back();
    lista2.pop_front();

    std::cout << "Imprimiendo los contenidos de lista 2 quitando el primer y ultimo elemento\n";
    std::cout << lista2 << '\n';
    

    std::cout << "Imprimiendo los contenidos de lista 1 con el patron Iterator\n";
    for (Iterator<int> it = lista.begin(); it != lista.end(); ++it)
    {
        std::cout << *it << " -> ";
    }
    std::cout << '\n';

    LinkedList<float> lista3;

    lista3.push_back(3.f);
    lista3.push_back(7.f);
    lista3.push_back(5.f);
    lista3.push_back(4.f);

    std::cout << "Imprimiendo los contenidos de lista 3\n";
    std::cout << lista3 << '\n';

    LinkedList<float> lista4 = std::move(lista3);

    std::cout << "Imprimiendo los contenidos de lista 4, copiados de lista 3 con std::move\n";
    std::cout << lista4 << '\n';

    LinkedList<float> lista5;

    lista5.push_back(9.f);
    lista5.push_back(13.f);
    lista5.push_back(-9.f);

    std::cout << "Imprimiendo los contenidos de lista 5\n";
    std::cout << lista5 << '\n';

    lista4 = std::move(lista5);

    std::cout << "Imprimiendo los contenidos de lista 4, copiados de lista 5 con std::move\n";
    std::cout << lista4 << '\n';

    lista4 = lista3;
    std::cout << "Imprimiendo los contenidos de lista 4, copiados con el operador de asignacion de lista 3\n";
    std::cout << lista4 << '\n';



    return 0;
}