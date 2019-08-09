/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashMapWordFinder.cpp
 * Created on 27 de mayo de 2016, 16:59
 */

#include "HashMapContactFinder.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>

HashMapContactFinder::HashMapContactFinder() {
}

void HashMapContactFinder::appendContactList(const string filename) {
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

void HashMapContactFinder::insertContact(const string nom, const string cognom, const string adreca, const string ciutat, const string telefon, const string email) {

    Contacte aux(nom, cognom, adreca, ciutat, telefon, email);
    tablaHash.put(aux.getCognom(),aux);
    
}


Contacte HashMapContactFinder::findContact(string cognom) {
    Contacte c = tablaHash.getContacte(cognom);
    return c;
}

bool HashMapContactFinder::findContactBool(string cognom) {
    return tablaHash.get(cognom);
}

void HashMapContactFinder::viewIndex() {
    tablaHash.printHashMap();
}


int HashMapContactFinder:: getNumCeldas(){
    return tablaHash.getNumCeldas();
}

/**
 * Retornar el numero de colisiones(tener el mismo index despues de aplicar getHashCode) que se ha producido a la hora de insertar palabras a 
 la tabla hash.
 */
int HashMapContactFinder:: getNumColisions(){
    return tablaHash.getNumColisions();
}

/**
 * El nombre d'elements que té la cel·la més gran
 * @return int 
 */

int HashMapContactFinder:: getNumElementsMaxCelda(){
    return tablaHash.getNumElementsMaxCelda();
}
/**
 * El numero de celdas ocupadas
 * @return int 
 */
int HashMapContactFinder:: getCeldasOcupades(){
    return tablaHash.getCeldasOcupades();
}