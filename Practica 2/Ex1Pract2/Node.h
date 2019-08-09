/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Ling
 *
 * Created on 30 / de març / 2017, 08:47
 */

#ifndef NODE_H
#define NODE_H

template <class E>
    class Node{
        public:
            Node(E e);//constructor de node.
            ~Node();//destructor de node.
            const E& getElement()const;//Devuelve el node.
            Node<E> *getNext()const;//Metodo para conseguir el siguiente node y lo devuelve.
            void setNext(Node<E> *e);//Metodo para adjustar el siguiente node del node actual.
    // ...
        private:
            Node<E> *next;//El node siguiente.
            E element;//El node actual.
};               

/*El constructor de la classe Node. 
 * Inicializar el node con "e"
 * El punter next apunta al nullptr
 */
template <class E> Node<E>::Node(E e){
    this->element=e;
    this->next = 0;
}

/*
 * setNext()
 * Modifica la direccion de next
 */
template <class E> Node<E>::~Node(){
    this->setNext(0);
    delete next;
}

/*
 * Desturctor de Node()
 */
template <class E> const E& Node<E>::getElement() const{
    return this->element;
}


/**
 * getNext() 
 * Retorna la direccion del siguiente nodo
 * @return Node<E>*
 */
template <class E> Node <E>* Node<E>::getNext() const{
    return this->next;
}

/*
 * setNext()
 * Modifica la direccion de next por la direccion recibida como parametro
 * @param e
 */
template <class E> void Node<E>::setNext(Node<E>* e){
    this->next=e;
}
#endif /* NODE_H */

