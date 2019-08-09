/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTContactFinder.cpp
 * Author: Johnny
 * 
 * Created on 27 de abril de 2017, 9:31
 */

#include "BSTContactFinder.h"
#include "Contacte.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>


BSTContactFinder::BSTContactFinder() {
}

void BSTContactFinder::appendContactList(const string filename) {
    ifstream file(filename);
    string line, nom, cognom, adreca, ciutat, telefon, email;

    if (file.fail()) throw runtime_error("El fitxer no existeix");
    else {

        while (getline(file, line, ',')) {
            nom = (line);
            getline(file, line, ',');
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            cognom = line;
            getline(file, line, ',');
            adreca = line;
            getline(file, line, ',');
            ciutat = line;
            getline(file, line, ',');
            telefon = line;
            getline(file, line, '\n');
            email = line;
            Contacte contact;
            contact = findContact(cognom);
            
            if (contact.getCognom().compare(cognom)==0){
                cout<<"Trobat" << contact.getCognom()<< endl;
                contact.addTelefon(telefon);
            }
            else {
            insertContact(nom, cognom, adreca, ciutat, telefon, email);                
            }
                       

        }

        cout << "Archivo leido" << endl;
    }
    file.close();

}

void BSTContactFinder::insertContact(const string nom, const string cognom, const string adreca, const string ciutat, const string telefon, const string email) {

    Contacte aux(nom, cognom, adreca, ciutat, telefon, email);
    bst.insert(aux.getCognom(),aux);
    
}

const std::string BSTContactFinder::showContact(string cognom) const {

   Contacte c = bst.searchContact(cognom);
   return c.toString();
}

Contacte BSTContactFinder::findContact(string cognom) {
    Contacte c = bst.searchContact(cognom);
    return c;
}

void BSTContactFinder::viewIndex() const {
    bst.printInorder();
}

const int BSTContactFinder::height() const {
    return bst.height();
}