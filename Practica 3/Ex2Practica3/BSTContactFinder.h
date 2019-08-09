/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTContactFinder.h
 * Author: Johnny
 *
 * Created on 27 de abril de 2017, 9:31
 */


#ifndef BSTCONTACTFINDER_H
#define BSTCONTACTFINDER_H
#include <string>
#include "BinarySearchTree.h"
#include "Contacte.h"
#include <vector>
using namespace std;

class BSTContactFinder {
public:
    BSTContactFinder();
    ~BSTContactFinder(){};
    void appendContactList(const string filename);
    //Aquest metode rep el nom d'un fitxer i emmagatzema el seu contingut dins de l'arbre.

    void insertContact(const string nom, const string cognom, const string adreca,const string ciutat,string telefon,const string email);

    const string showContact(string cognom) const;

    Contacte findContact(string cognom);
    
    void viewIndex() const; 
    
    const int height() const;

private:
    BinarySearchTree<Contacte> bst;
};


#endif /* BSTCONTACTFINDER_H */

