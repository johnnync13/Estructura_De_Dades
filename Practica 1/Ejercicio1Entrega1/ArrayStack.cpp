/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.cpp
 * Author: @johnny
 * 
 * Created on 12 de marzo de 2017, 1:24
 */

#include "ArrayStack.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;
/*
 * Constructor
 */
ArrayStack::ArrayStack() {
    t = 0; //top stack 0
    data = vector<int> (MAX_STACK);
}

/*
 * Destructor
 */
ArrayStack::~ArrayStack() {
}
/*
 * 
 * indica si la pila es buida
 * 
 */

bool ArrayStack::empty() {
    return (t==0);
}
/* 
 * indica si la pila es plena
 */

bool ArrayStack::full() {
    return (t == MAX_STACK);
} 
/*
 * Afegir elements a la pila
 */
void ArrayStack::push(const int item) {
    if (!full()) {
        data[t] = item;
        t++;
    }
    else{
        throw out_of_range("La pila esta llena");
    }
}
/**
 * treu l'ultim element de la pila,
 * i retorna una excepció si no ha estat possible
 */
void ArrayStack::pop() {
    if (!empty())
    {
        t--;
        data[top()-1];
    }
    else
    {
        throw out_of_range("La pila esta vacia");
        
    }
} 

/**
 * retorna l’element del top de la pila
 * retorna una excepció si no ha estat possible
 * @return 
 */
int ArrayStack::top() {
    if (!empty()){
        return data[t-1];
    }
    else{
        throw out_of_range("La pila esta vacia");
    }

}
/*
 * Imprimir el vector per pantalla
 */

void ArrayStack::print() {
    std::vector<int>::iterator it= data.begin();
    cout<<"Enteros de la pila son \n";
    for(int i = 0; i < t; i++){
        cout<< *it<< " / "<< " ";
        it++;
    }
}

void ArrayStack::clean(){
    if(!empty()){
    t=0;
    data.clear();
    }
    else {
        throw out_of_range("La pila esta vacia");
    }
}