/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: @jnunezca11.alumnes
 *
 * Created on 12 de marzo de 2017, 1:24
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "ArrayStack.h"

using namespace std;

/*
 * Metodes del main
 */
int menu(void);
void afegirpila(ArrayStack &ArrayStackAux);
void eliminarpila(ArrayStack &ArrayStackAux);
void showpila(ArrayStack &ArrayStackAux);
void buidarpila(ArrayStack &ArrayStackAux);

/*
 * Casos del menu
 */
int main(int argc, char** argv) {
    string nombre;
    int opcion;
    ArrayStack ArrayStackAux;
    try {


    cout << "Hola, com et dius?" << endl;
    cin >> nombre;

    do {
        cout << "Hola " << nombre << " que vols fer?" << endl;
        opcion = menu();
        switch (opcion) {
            case 1: cout << "Adios" << endl;
                break;
            case 2: cout << "Insertar en la pila" << endl;
                afegirpila(ArrayStackAux);
                break;
            case 3:
                cout << "Eliminar elements de la pila" << endl;
                ArrayStackAux.pop();
                break;

            case 4:
                cout << "buidar la pila" << endl;
                buidarpila(ArrayStackAux);
                break;
            case 5:
                showpila(ArrayStackAux);
                break;
            default:
                cout << "Opcion Incorrecta" << endl;
        }
    } while ((opcion != 1));
    }
    
    
    catch (out_of_range ex) {
        cout << ex.what() << endl;
    }
    return 0;
    
}
/*
 * Menu del programa
 */
int menu(void) {
    int numero;
    vector<string> v;
    v.push_back("Sortir");
    v.push_back("Insertar Enters en la pila");
    v.push_back("Eliminar elements de la pila");
    v.push_back("buidar la pila");
    v.push_back("Mostar pila");



    for (int i = 1; i <= v.size(); i++) {
        cout << i << ": " << v[i - 1] << ": " << endl;

    }
    cout << ("Opcion") << endl;
    cin>>numero;

    return numero;
}
/*
 * Metode afegirpila 
 */
void afegirpila(ArrayStack &ArrayStackAux) {
    int dada;
    cout << "Introduce un valor" << endl;
    cin>>dada;
    ArrayStackAux.push(dada);
}
/*
 * Metode per mostrar la pila per pantalla
 */
void showpila(ArrayStack &ArrayStackAux){
    ArrayStackAux.print();
}

/*
 *Metode per eliminar la pila
 */
void eliminarpila(ArrayStack &ArrayStackAux){
    ArrayStackAux.pop();
}
/*
 * Metode per buidar la pila
 */
void buidarpila(ArrayStack &ArrayStackAux){
    ArrayStackAux.clean();
}



