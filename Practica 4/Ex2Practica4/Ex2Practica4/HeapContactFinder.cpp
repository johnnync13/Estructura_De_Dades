/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapContactFinder.cpp
 * Author: Johnny
 * Author: Ling
 * Created on 27 de mayo de 2017, 11:43
 */

#include "HeapContactFinder.h"
#include "MinHeap.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>

HeapContactFinder::HeapContactFinder() {
}

void HeapContactFinder::appendContactList(const string filename) {
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
            /*contact = findContact(cognom);
            
            if (contact.getCognom().compare(cognom)==0){
                cout<<"Trobat" << contact.getCognom()<< endl;
                contact.addTelefon(telefon);
            }
            else {*/
            insertContact(nom, cognom, adreca, ciutat, telefon, email);                
            //}
                       

        }

        cout << "Archivo leido" << endl;
    }
    file.close();

}

void HeapContactFinder::insertContact(const string nom, const string cognom, const string adreca, const string ciutat, const string telefon, const string email) {

    Contacte aux(nom, cognom, adreca, ciutat, telefon, email);
    heap.insert(aux.getCognom(),aux);
    
}

string HeapContactFinder::showContact(string cognom)  {

   Contacte c = heap.getContacte(cognom);
   return c.toString();
}

Contacte HeapContactFinder::findContact(string cognom) {
    Contacte c = heap.getContacte(cognom);
    return c;
}
bool HeapContactFinder::findContactBool(string cognom) {
    return heap.getContacteT(cognom);
}

void HeapContactFinder::viewIndex() {
    heap.printHeap();
}
int HeapContactFinder::height()  {
    return heap.profunditat();
}