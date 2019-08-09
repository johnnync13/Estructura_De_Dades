/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedHashEntry.h
 * Created on 23 / maig / 2016, 16:57
 */

#ifndef LINKEDHASHENTRY_H
#define LINKEDHASHENTRY_H
#include <string>
#include "Contacte.h"

// K és el tipus de la Key
template <class E>
class LinkedHashEntry{
    
    private:
        // Define Key and Values
        string key;
        Contacte values; 
        LinkedHashEntry* next;
        
    public:
        LinkedHashEntry(string key,E values);        
        const string getKey()const;
        const E getValues() const;
        
        void setValues(const E& newValues);
        
        LinkedHashEntry* getNext(){ return next;};
        void setNext(LinkedHashEntry* next);
};

template <class E> LinkedHashEntry<E>::LinkedHashEntry(string key,E values){
    this->key=key;
    this->values=values;
    next=nullptr;
}

template <class E> const string LinkedHashEntry<E>::getKey() const{
    return this->key;
}

template <class E>const E LinkedHashEntry<E>::getValues() const{
    return values;
}

template <class E> void LinkedHashEntry<E>::setValues(const E& newValues){
    this->values=newValues;
}


template <class E> void LinkedHashEntry<E>::setNext(LinkedHashEntry* next){
    this->next=next;
}
#endif /* LINKEDHASHENTRY_H */

