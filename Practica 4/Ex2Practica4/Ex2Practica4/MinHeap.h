/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinHeap.h
 * Author: Johnny
 * Author: Ling
 * Created on 24 de mayo de 2017, 18:05
 */

#ifndef MINHEAP_H
#define MINHEAP_H

#include "NodeTree.h"
#include "Contacte.h"
#include <vector>
#include <istream>
#include <iostream>
using namespace std;

template <class E>
class MinHeap {
public:
    MinHeap();
    virtual ~MinHeap();
    int size(); //retorna el nombre de nodes que hi ha en el Heap
    bool empty(); //retorna cert si el Heap està buit, fals en cas contrari
    void insert(string key, Contacte c); //afegeix un nou element al Heap. Aquesta funció rep la clau i el valor/s d’aquesta clau
    const string min(); //min: retorna la clau mínima del Heap
    int profunditat(); //retorna la profundidad del heap 
    const E& minValues(); //retorna els valors de la clau mínima del Heap
    void removeMin(); //elimina el node mínim del heap
    void printHeap(); // imprimeix per consola tot el Heap
    Contacte getContacte(const string cognom);
    bool getContacteT(const string cognom);
private:
    vector <NodeTree<E>*> heap;
    ; // vector
    void swap(int pos1, int pos2);
    void upHeap();
    void downHeap();
    int getLeftChild(int parent); //Obtenim el fill esquerre
    int getRightChild(int parent); //Obtenim el fill dret
    int getParent(int child); //Obtenim el pare

};

/**
 * Constructor
 */
template <class E> MinHeap<E> ::MinHeap() {
}

template <class E> MinHeap<E>::~MinHeap() {

    for (int i = heap.size() - 1; i >= 0; i--) {
        if (heap[i] != 0) delete heap[i];
    }
}

/*Retorna el numero de elementos*/
template <class E> int MinHeap<E> ::size() {
    return heap.size();
}

/*Retorna si el heap esta vacio*/
template <class E> bool MinHeap<E> ::empty() {
    return heap.size() == 0;
}

/*Retorna la profundidad del heap*/
template <class E> int MinHeap<E> ::profunditat() {
    int index = 0;
    int altura = 0;
    /*Recorre el heap consultando si tiene hijo izquierdo 
     ya que es un arbol completo siempre tiene hijo izquierdo
     */
    while (index <= size()) {
        altura++;
        index = 2 * index + 1;
    }
    return altura;
}

/**
 * Private Method
 * 
 * @param nodo1
 * @param nodo2
 */
template<class E> void MinHeap<E>::swap(int child, int parent) {

    NodeTree<E>* positionAux = heap[child];
    heap[child] = heap[parent];
    heap[parent] = positionAux;
}

/*Retorna el elemento minimo*/
template <class E> const string MinHeap<E> ::min() {
    if (empty()) {
        throw std::out_of_range("Heap vacio.");
    }
    return heap[0]->getKey();
}

/*Retorna los valores del minimo elemento*/
template <class E> const E& MinHeap<E> ::minValues() {
    if (empty()) throw new out_of_range("Heap buit");
    return heap[0]->getValues();
}

template <class E>
int MinHeap<E> ::getParent(int child) {
    if (child % 2 == 0)
        return (child / 2) - 1;
    else
        return child / 2;

}

template <class E>
int MinHeap<E> ::getLeftChild(int parent) {
    return 2 * parent + 1;
}

template <class E>
int MinHeap<E> ::getRightChild(int parent) {
    return 2 * parent + 2;
}

template<class E> void MinHeap<E>::upHeap() {
    int child = heap.size() - 1;
    int parent = getParent(child);

    //while((heap[pos]->getKey() < heap[(pos - 1)/2]->getKey() ) )
    while (child >= 0 && parent >= 0 && heap[child]->getKey() < heap[parent]->getKey()) {

        swap(child, parent);
        child = parent;
        parent = getParent(child);

    }
}

template <class E>
void MinHeap<E> ::insert(string key, Contacte c) {
    if (empty()) {
        heap.push_back(new NodeTree<E>(key, c));
    } else {
        heap.push_back(new NodeTree<E>(key, c));
        upHeap();
    }
}

template<class E> Contacte MinHeap<E>::getContacte(string cognom) {
    bool found = false;
    int i = 0;
    Contacte c;
    while (!found && i < heap.size()) {
        found = heap.at(i)->getKey() == cognom;
        i++;
    }
    if (!found) return c;
    else {
        c = heap.at(i)->getValues();
        return c;
    }
}

template<class E> bool MinHeap<E>::getContacteT(string cognom) {
    bool found = false;
    int i = 0;
    while (!found && i < heap.size()) {
        found = heap.at(i)->getKey() == cognom;
        i++;
    }
    if (!found) return false;
    else {
        heap.at(i)->getValues();
        return true;
    }
}

/*Elimina el minimo elemento*/
template <class E>
void MinHeap<E>::removeMin() {
    if (empty()) {
        throw new out_of_range("Heap buit");
    } else {
        int child = heap.size() - 1;
        swap(child, 0);
        heap.pop_back();
        int parent = 0;

        while (1) {
            int left = getLeftChild(parent);
            int right = getRightChild(parent);
            int length = heap.size();
            int parentAux = parent;

            if (left < length && heap[left] < heap[parentAux])
                parentAux = left;

            if (right < length && heap[right]->getKey() < heap[parentAux]->getKey())
                parentAux = right;

            if (parentAux != parent) {
                swap(parentAux, parent);
                parent = parentAux;
            } else {
                break;
            }
        }
    }
}

/*Imprime el heap*/
template <class E>
void MinHeap<E> ::printHeap() {
    Contacte contact;
    int cont = 0;
    string resposta;
    //recorrer el heap(que es un vector)
    for (typename vector<NodeTree <E>* >::iterator it = heap.begin(); it != heap.end(); ++it) {
        contact = (*it)->getValues();
        cont++;
        cout << "Key: " << (*it)->getKey() << "\t" << "Contacte: " << contact.toString() << endl; //imprimir la palabra
        if (cont % 40 == 0) {
            cout << "Vols seguir llegint" << endl;
            cin >> resposta;

            if (resposta == "N") {
                break;
            }
            else {
                cont = 0;
            }
        }
    }
}

#endif /* MINHEAP_H */

