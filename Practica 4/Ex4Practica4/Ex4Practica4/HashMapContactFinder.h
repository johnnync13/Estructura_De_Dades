/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashMapWordFinder.h
 * Created on 27 de mayo de 2016, 16:59
 */

#ifndef HASHMAPWORDFINDER_H
#define HASHMAPWORDFINDER_H

#include "HashMap.h"


using namespace std;

class HashMapContactFinder {
public:
    HashMapContactFinder();

    ~HashMapContactFinder() {
    };
    void appendContactList(const string filename);
    //Aquest metode rep el nom d'un fitxer i emmagatzema el seu contingut dins de l'arbre.

    void insertContact(const string nom, const string cognom, const string adreca, const string ciutat, string telefon, const string email);

    string showContact();

    Contacte findContact(string cognom);
    bool findContactBool(string cognom);

    void viewIndex();

    int height();

    int getNumColisions(); //el nombre de col·lisions totals que s’han produït
    int getNumCeldas(); //mida de la tabla
    int getNumElementsMaxCelda(); // el nombre d'elements que té la cel·la més gran 
    int getCeldasOcupades(); //numero de celdas no nulls que hay 
private:
    HashMap<Contacte> tablaHash;
};

#endif /* HASHMAPWORDFINDER_H */

