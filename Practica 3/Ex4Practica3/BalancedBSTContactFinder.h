/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBSTContactFinder.h
 * Author: Johnny
 *
 * Created on 16 de mayo de 2017, 15:55
 */

#ifndef BALANCEDBSTCONTACTFINDER_H
#define BALANCEDBSTCONTACTFINDER_H
#include <string>
#include "BalancedBST.h"
#include "Contacte.h"
#include <vector>
class BalancedBSTContactFinder {
public:
    BalancedBSTContactFinder(){};
    ~BalancedBSTContactFinder(){};
    void appendContactList(const string filename);
    //Aquest metode rep el nom d'un fitxer i emmagatzema el seu contingut dins de l'arbre.

    void insertContact(const string nom, const string cognom, const string adreca,const string ciutat,string telefon,const string email);

    const string showContact(string cognom) const;

    Contacte findContact(string cognom);
    
    void viewIndex() const; 
    
    const int height() const;
private:
    BalancedBST<Contacte> bst;
};

#endif /* BALANCEDBSTCONTACTFINDER_H */

