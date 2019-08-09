/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedStack.h
 * Author: Ling
 *
 * Created on 23 / de març / 2017, 08:21
 */

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "Node.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
template <class E>
    class LinkedStack{
        public:
            LinkedStack<E>();
            LinkedStack(std::initializer_list<E> elements);
            ~LinkedStack();//Destructor de la clase LinKedStack.
            bool empty() const;//Indica si el LinkedStack esta vacia,i devuelve un boolean.
            int size() const;//Devuelve un integer indicando la capacidad actual del LinkedStack.
            const E& top() const;;//Devuelve el top del LinkedStack.
            void push(const E& e);//Inserir un elemento en la primera posicio del LinkedStack.
            void pop();//Eliminar el primer elemento del LinkedStack.
            void print() const;//Imprime todo el contenido del LinkedStack.
        // ...
        private:
            Node<E> *front;//El primer elemento del LinkedStack.
            int num_elements;//Indica cuantos elementos hay en el LinkedStack.
};


template<class E> LinkedStack<E>::LinkedStack() {
    num_elements = 0;
    front = nullptr;
}

template<class E> LinkedStack<E>::LinkedStack(std::initializer_list<E> elements) {
    std::initializer_list<int>::iterator it;
    for (it = elements.begin(); it != elements.end(); it=++it) {
        push(*it);
    }
}

/*
 * Destructor de pila
 */
template <class E> LinkedStack<E>::~LinkedStack(){
    while (!this->empty()){
        Node <E>* tmp = new Node<E>(0);
        tmp->setNext(this->front->getNext());
        delete this->front;
        this->front = tmp->getNext();
        delete tmp;
    }
    
}

/*
 * empty()
 * Para comprovar si la pila està vacia o no
 */
template <class E> bool LinkedStack<E>::empty() const{
    return (this-> size() == 0);
}

/*
 * pop()
 * Este metodo elimina el elemento que està en la posición 
 * front de la pila
 */
template <class E> void LinkedStack<E>::pop(){
    Node <E>* tmp = new Node<E>(0);
    tmp->setNext(this->front->getNext());
    delete this->front;
    this->front = tmp->getNext();
    delete tmp;
    --num_elements;
}

/*
 * push()
 * Este metodo añade un elemento en la pila
 * Aqui tenemos que cambiar el puntero de front al elemento nuevo que
 * hemos añadido
 */
template <class E> void LinkedStack<E>::push(const E& e){
    Node<E>* tmp = new Node<E>(e);
    tmp->setNext(front);
    front = tmp;
    ++num_elements;
}

/*
 * size()
 * Este metodo devuelve el tamaño de la pila
 */
template <class E> int LinkedStack<E>::size() const{
    return num_elements;
}

/*
 * top()
 * Este metodo devuelve el elemento que esta en el puntero front
 */
template <class E> const E& LinkedStack<E>::top() const{
    return front->getElement();
}

/*
 * print()
 * Este metodo imprime el contenido de la pila por la pantalla
 */
template <class E> void LinkedStack<E>::print() const {
    if (!empty()) {
        Node<E>* tmp = front; 
        for(int i=0;i<num_elements;++i) {
            std::cout<<"["<<tmp->getElement()<<"]";
            tmp = tmp->getNext();
        }
        std::cout<<std::endl;
    }
}
#endif /* LINKEDSTACK_H */