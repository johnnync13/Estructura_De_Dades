/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.cpp
 * Author: johnny
 * 
 * Created on 20 de marzo de 2017, 20:02
 */

#include "ArrayQueue.h"
#include "Vol.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

ArrayQueue::ArrayQueue() {

    front = -1;
    rear = -1;
}

ArrayQueue::ArrayQueue(const ArrayQueue& orig) {
}

ArrayQueue::~ArrayQueue() {
}

// indica si la cua és buida

bool ArrayQueue::empty() {
    return (front == -1 && rear == -1);

}
// indica si la cua és plena

bool ArrayQueue::full() {
    if ((rear + 1) % MAX_QUEUE == front) {
        return true;
    } else {
        return false;
    }

}
// indica la mida de la cua
// encuem un membre a la cua
// i retorna una excepció si no ha estat possible

int ArrayQueue::size() {
    int size;
    if (empty()) {
        std::cout << "ERROR";
    } else {
        return size = (rear + MAX_QUEUE - front) % MAX_QUEUE + 1;
    }
}


// treu un element de la cua,
// i retorna una excepció si no ha estat possible

void ArrayQueue::enqueue(Vol v) {

    cout << "Cola " << endl;
    if (full()) {
        cout << "Error: Queue is Full\n";
    }
    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_QUEUE;
    }
    data[rear] = v;
}

Vol ArrayQueue::dequeue() {
    if (empty()) {
        cout << "Error";

    } else if (front == rear) {
        rear = front = -1;
    } else {
        front++;
    }

}
// consulta l’element de l’inici de la cua sense eliminar-lo,
// i retorna una excepció si no ha estat possible

const Vol& ArrayQueue::_front() const {
    if (front == -1) {
        cout << "Error";
    }
    return data[front];
}
// imprimeix tot el contingut de la cua

void ArrayQueue::print() {
    cout <<"----------"<< endl;
    if (empty()) {
        std::cout << "ERROR";
    } else {
        int maxI = (rear + MAX_QUEUE - front) % MAX_QUEUE + 1;
        for (int i = 0; i < maxI; i++) {
            int index = (front + i) % MAX_QUEUE;
            cout << data[index].get_codicomp()<<endl;
            cout << data[index].get_numVol()<<endl;
            cout << data[index].get_horaSor()<<endl;
            cout << data[index].get_horaArr()<<endl;
            cout << data[index].get_codiSor()<<endl;
            cout << data[index].get_codiArr()<<endl;
        }
        cout<<"----------";
    }
}



