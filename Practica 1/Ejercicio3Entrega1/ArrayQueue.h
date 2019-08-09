/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.h
 * Author: johnny
 *
 * Created on 20 de marzo de 2017, 20:02
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "Vol.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

class ArrayQueue {
private:
    int MAX_QUEUE = 100;
    std::vector<Vol> data = std::vector<Vol>(MAX_QUEUE);
    int front; // apunta al primer element de la cua
    int rear; // apunta al darrer element de la cua
public:
    ArrayQueue(const ArrayQueue& orig);
    virtual ~ArrayQueue();
    ArrayQueue(); // inicialitza una cua, buida
    bool empty(); // indica si la cua és buida
    bool full(); // indica si la cua és plena
    int size(); // indica la mida de la cua
    // encuem un membre a la cua
    // i retorna una excepció si no ha estat possible
    void enqueue(Vol v);
    // treu un element de la cua,
    // i retorna una excepció si no ha estat possible
    Vol dequeue();
    // consulta l’element de l’inici de la cua sense eliminar-lo,
    // i retorna una excepció si no ha estat possible
    const Vol& _front() const;
    void print(); // imprimeix tot el contingut de la cua
};

#endif /* ARRAYQUEUE_H */

