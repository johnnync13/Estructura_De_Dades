/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.h
 * Author: johnny
 *
 * Created on 12 de marzo de 2017, 1:24
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <vector>
#include <stdexcept>
#include <string>

class ArrayStack {
    /*
     *atributs privats.
     */
    private:
    int MAX_STACK = 100;
    std::vector<int> data = std::vector<int>(MAX_STACK);
    int t; //top de la pila
    std::string nombre;
    
    /*
     *metodes publics
     */
public:    
    ArrayStack(); //inicialitza una pila,buida
    ArrayStack(const ArrayStack& orig);
    virtual ~ArrayStack();
    bool empty(); // indica si la pila es buida
    bool full(); //indica si la pila es plena
    void push(const int item); // introdueix un element a la pila,
    // i retorna una excepció si no ha estat possible
    void pop(); // treu un element de la pila,
    // i retorna una excepció si no ha estat possible
    int top(); // retorna l’element del top de la pila
    // retorna una excepció si no ha estat possible
    void print(); // imprimeix tot el contingut de la pila
    void clean();
    void printstack();
    void setlabel(std::string nombre);
    std::string getlabel();

};

#endif /* ARRAYSTACK_H */