/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeList.h
 * Author: johnny
 *
 * Created on 15 de abril de 2017, 16:41
 */

#ifndef NODELIST_H
#define NODELIST_H

template <class E> class NodeList {
public:
    //Gestores
    NodeList(E elem); //Constructor amb referencia de l'element
    virtual ~NodeList(); //Destructor
    //Consultores
    NodeList<E>* getNext() const;
    NodeList<E>* getPrev() const;
    E getElement() const;
    //Modificadores
    void setNext(NodeList<E>* nextNode);
    void setPrev(NodeList<E>* prevNode);
private:
    E element;
    NodeList<E>* previous;
    NodeList<E>* next;

};

template<class E> NodeList<E>::NodeList(E elem) {
    this->element = elem;

}

template<class E> NodeList<E>::~NodeList() {
    delete previous;
    delete next;
}

template<class E> NodeList<E>::getElement() const {
    return this->element;
}

template<class E> NodeList<E>::getNext() const {
    return this->next;
}

template<class E> NodeList<E>::getPrev() const {
    return this->previous;
}

template<class E> void NodeList<E>::setNext(NodeList<E>* nextNode) {
    next = nextNode;
}

template<class E> void NodeList<E>::setPrev(NodeList<E>* prevNode) {
    previous = prevNode;
}

#endif /* NODELIST_H */

