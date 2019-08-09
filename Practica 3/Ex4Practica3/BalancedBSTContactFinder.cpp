/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBSTContactFinder.cpp
 * Author: Johnny
 * 
 * Created on 16 de mayo de 2017, 15:55
 */

#include "BalancedBSTContactFinder.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>

void BalancedBSTContactFinder::appendContactList(const string filename) {
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

void BalancedBSTContactFinder::insertContact(const string nom, const string cognom, const string adreca, const string ciutat, const string telefon, const string email) {

    Contacte aux(nom, cognom, adreca, ciutat, telefon, email);
    bst.insert(aux.getCognom(), aux);

}

const std::string BalancedBSTContactFinder::showContact(string cognom) const {

    Contacte c = bst.searchContact(cognom);
    return c.toString();
}

Contacte BalancedBSTContactFinder::findContact(string cognom) {
    Contacte c = bst.searchContact(cognom);
    return c;
}

void BalancedBSTContactFinder::viewIndex() const {
    bst.printInorder();
}

const int BalancedBSTContactFinder::height() const {
    return bst.height();
}