/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.h
 * Author: johnny
 *
 * Created on 15 de abril de 2017, 16:42
 */

#ifndef POSITION_H
#define POSITION_H
#include "NodeList.h"


template <class Element>
class Position {
public:
    Position(NodeList<Element>* node); // Constructor amb paràmetres
    Position<Element> next() const; // retorna la següent posició
    Position<Element> previous() const; // retorna l’anterior posició
    const Element& element() const; // retorna el contingut de l’actual posició
    Position<Element> operator++() const; // sobrecarrega operador ++
    Position<Element> operator--() const; // sobrecarrega operador --
    bool operator==(const Position& other) const; // sobrecarrega operador ==
    bool operator!=(const Position& other) const; // sobrecarrega operador !=
    const Element& operator*() const; // sobrecarrega operador contingut
private:
    NodeList<Element>* _node;
};

template<class Element> Position<Element>::Position(NodeList<Element>* node){
    this->_node=node;
}
template<class Element> Position<Element>::next() const{
    return this->_node->getNext();
    
}
template<class Element> Position<Element>::previous() const{
    return this->_node->getPrev();
    
}
template<class Element> Position<Element>::element() const{
    return this->_node->getElement();
    
}
template<class Element> Position<Element> Position<Element>::operator ++() const{
    return this->_node->getNext()->getNext();
    
}
template<class Element> Position<Element> Position<Element>::operator --() const{
    return this->_node->getPrev()->getPrev();
    
}
template<class Element> bool Position<Element>::operator ==(const Position& other) const{
    return *other.element() == _node->getElement();
    
}
template<class Element> bool Position<Element>::operator !=(const Position& other) const{
    return *other.element()!= _node->getElement();    
}
template<class Element> Element& Position<Element>::operator *() const{
    return _node->getNext();
    
}

#endif /* POSITION_H */

