/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashMap.h
 * Author: Johnny
 *
 * Created on 25 de mayo de 2017, 23:25
 */

#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include "Contacte.h"
#include "LinkedHashEntry.h"
using namespace std;

template<class E>
class HashMap {
public:
    HashMap();

    ~HashMap();

    int getHashCode(string key); //donat una clau retorni l'índex corresponent.

    void put(string key, Contacte c);
    /*que insereixi o actualitzi la paraula (clau o key) i els seus
     valors associats (valors o value) dins la taula Hash.*/
    bool get(string key);
    Contacte getContacte(string Contacte);
    /*que mostri per pantalla una llista amb les ocurrències (línia,
     * posició) corresponent a les aparicions de la paraula donada en el text.
     * Retornarà cert si la paraula existeix en el text, i fals altrament.*/
    int getNumColisions(); //el nombre de col·lisions totals que s’han produït
    int getNumCeldas(); //mida de la tabla
    int getNumElementsMaxCelda(); // el nombre d'elements que té la cel·la més gran 
    int getCeldasOcupades(); //numero de celdas no nulls que hay 
    void printHashMap();


private:
    static constexpr int MIDA_MAX = 233;
    //A cada cel·la del HashMap es guardarà un objecte LinkedHashEntry.
    LinkedHashEntry<E>* hash[MIDA_MAX]; //tabla hash
    int numColisions;
    int numElementsMaxCelda; // el nombre d'elements que té la cel·la més gran 
    int celdasOcupades;
};

template<class E> HashMap<E>::HashMap() {

    numColisions = 0;
    numElementsMaxCelda = 0; // el nombre d'elements que té la cel·la més gran 
    celdasOcupades = 0;
    for (int i = 0; i < MIDA_MAX; i++) {
        hash[i] = NULL; //reservar espacio de memoria?

    }
}

/**Destructor*/
template<class E> HashMap<E>::~HashMap() {
    for (int i = 0; i < MIDA_MAX; ++i) {
        delete hash[i];
    }
}

/**Donat una clau retorni l'índex corresponent.*/

template<class E> int HashMap<E>::getHashCode(string key) {

    char c;
    int suma = 0;

    //PRIMER CASO
    c = key.at(0); //tenemos el caracter
    int valorAscii = int (c);
    suma = suma + valorAscii;

    int z = 7; //Guardamos el valor para la regla de Horner

    for (int i = 1; i < key.length(); i++) {
        c = key.at(i); //tenemos el caracter
        valorAscii = int (c);
        suma = suma + valorAscii * z;
        z = 7 * z;
    }

    //posicion
    return abs(suma % MIDA_MAX);


}

/**
 * insereixi o actualitzi la paraula (clau o key) i els seus
 * valors associats (valors o value) dins la taula Hash.
 */

template<class E> void HashMap<E>::put(string key, Contacte c) {
    //cada vez que inserta un elemento renovamos el numElementsMaxCelda
    int indice = getHashCode(key);
    int numElementsCelda = 1; //anadir un elemento--> numElementsCelda = 1
    if (hash[indice] == 0) { //si la celda esta vacia, no hay colision, y ocupa una celda
        LinkedHashEntry<E>* newnodo = new LinkedHashEntry<E>(key, c);
        hash[indice] = newnodo;
        celdasOcupades++;
    } else { //si hay colision
        LinkedHashEntry<E>* aux = hash[indice];
        bool trobat = false;
        if (aux->getKey() == key) { //para primer caso,(si solo tiene un nodo, el siguiente es nulo, no entra a while)
            trobat = true;
        }
        while (!trobat && aux->getNext()) {//si el siguiente es null, final de la lista
            aux = aux->getNext();
            numElementsCelda++;
            if (aux->getKey() == key) {
                trobat = true;
            }
        }
        if (trobat) {
            aux->setValues(c);
        } else { //si no ha encontrado la misma clave entonces hay otra colision
            LinkedHashEntry<E>* newnodo = new LinkedHashEntry<E>(key, c);
            aux->setNext(newnodo);
            numColisions++;
            numElementsCelda++; //si hay colision y no encuentra, crea otro nodo

        }
    }
    if (numElementsCelda > numElementsMaxCelda) {
        numElementsMaxCelda = numElementsCelda;
    }
}

/* Mostri per pantalla una llista amb les ocurrències (línia,posició) corresponent
 *  a les aparicions de la paraula donada en el text.
 * Retornarà cert si la paraula existeix en el text, i fals altrament.
 */

template<class E> bool HashMap<E>::get(string key) {
    bool trobat = false;
    int indice = getHashCode(key);
    if (hash[indice]) { //si no es null 
        LinkedHashEntry<E>* aux = hash[indice];
        while (!trobat && aux) { //mientra no ha encontrado y el siguiente no es null(existe el siguiente) 
            if (aux->getKey() == key) {
                //imprimir los valores
                aux->getValues();
                trobat = true;
            } else {
                aux = aux->getNext(); // el siguiente no es null(existe el siguiente) 
            }
        }

    }
    return trobat;
}

template<class E> Contacte HashMap<E>::getContacte(string key) {
    bool trobat = false;
    Contacte c;
    int indice = getHashCode(key);
    if (hash[indice]) { //si no es null 
        LinkedHashEntry<E>* aux = hash[indice];
        while (!trobat && aux) { //mientra no ha encontrado y el siguiente no es null(existe el siguiente) 
            if (aux->getKey() == key) {
                //imprimir los valores
                c = aux->getValues();
                cout << endl;
                trobat = true;
            } else {
                aux = aux->getNext(); // el siguiente no es null(existe el siguiente) 
            }
        }

    }
    return c;

}

/**
 * Retornar el numero de colisiones(tener el mismo index despues de aplicar getHashCode) que se ha producido a la hora de insertar palabras a 
 la tabla hash.
 */
template<class E> int HashMap<E>::getNumColisions() {
    return numColisions;
}

/**
 * retorna el tamanyo de la tabla hash 
 * @return int
 */
template<class E> int HashMap<E>::getNumCeldas() {
    return MIDA_MAX;
}

/**
 * El nombre d'elements que té la cel·la més gran
 * @return int 
 */
template<class E> int HashMap<E>::getNumElementsMaxCelda() {
    return numElementsMaxCelda;
}

/**
 * El numero de celdas ocupadas
 * @return int 
 */
template<class E> int HashMap<E>::getCeldasOcupades() {
    return celdasOcupades;
}

template<class E> void HashMap<E>::printHashMap() {
    Contacte c;
    int cont = 0;
    string resposta;
    for (int i = 0; i < MIDA_MAX; i++) {
        if (!hash[i] == 0) {
            cont++;
            c = hash[i]->getValues();
            cout << "Key: " << hash[i]->getKey() << "\t" << "Contacte: " << c.toString() << endl;
            if (cont % 40 == 0) {
                cout << "Vols seguir llegint" << endl;
                cin >> resposta;

                if (resposta == "N") {
                    break;
                } else {
                    cont = 0;
                }
            }
        }
    }
}


#endif /* HASHMAP_H */

