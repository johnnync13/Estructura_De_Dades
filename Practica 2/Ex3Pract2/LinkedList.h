/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: johnny
 *
 * Created on 15 de abril de 2017, 16:42
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Position.h"


template <class Element>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList<Element>& list);
    virtual ~LinkedList();
    int size() const;
    bool empty() const;
    Position<Element> begin() const; // return first position
    Position<Element> end() const; // return last position
    // Reverse iteration
    Position<Element> rbegin() const; // return first position
    Position<Element> rend() const; // return last position
    void insertFront(const Element& element);
    void insertBack(const Element& element);
    void print();
private:
    NodeList<Element>* _head;
    NodeList<Element>* _rear;
    int _size;
};

template <class Element> LinkedList::LinkedList(){
    this->_head=nullptr;
    this->_rear=nullptr;
    this->_size=0;    
}

template <class Element> int LinkedList::size() const{
    return this->_size;
}

template <class Element> bool LinkedList::empty() const{
    return (this->_size=0);
}
template <class Element> Position<Element> LinkedList::begin() const{
    return this->_head->getNext()->getElement();
}
template <class Element> Position<Element> LinkedList::end() const{
    return this->_rear->getPrev()->getElement();
}
template <class Element> Position<Element> LinkedList::rbegin() const{
    return this->_head;
}
template <class Element> Position<Element> LinkedList::rend() const{
    return this->_rear;
}
template <class Element> void LinkedList::insertFront(const Element& element){
    NodeList<Element>* node= new NodeList(element);
    Position<Element>* position= new Position(node);
    position.
    
}
template <class Element> void LinkedList::insertBack(const Element& element){
    
}

#endif /* LINKEDLIST_H */

