/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapContactFinder.h
 * Author: Johnny
 * Author: Ling
 * Created on 27 de mayo de 2017, 11:43
 */

#ifndef HEAPCONTACTFINDER_H
#define HEAPCONTACTFINDER_H
#include <string>
#include "Contacte.h"
#include <vector>
#include "MinHeap.h"

class HeapContactFinder {
public:
    HeapContactFinder();

    ~HeapContactFinder() {
    };
    void appendContactList(const string filename);
    //Aquest metode rep el nom d'un fitxer i emmagatzema el seu contingut dins de l'arbre.

    void insertContact(const string nom, const string cognom, const string adreca, const string ciutat, string telefon, const string email);

    string showContact(string cognom);

    Contacte findContact(string cognom);
    bool findContactBool(string cognom);

    void viewIndex();

    int height();

private:
    MinHeap<Contacte> heap;
};

#endif /* HEAPCONTACTFINDER_H */

