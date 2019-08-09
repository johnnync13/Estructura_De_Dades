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
#include <vector>
#include <iostream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "ArrayQueue.h"
#include "Vol.h"
using namespace std;
void CarregarFitxers(ArrayQueue &, ArrayQueue &);
void volArribada(Vol&, string, string, string, string, string);
void volSortida(Vol&, string, string, string, string, string);
void pistalliure(ArrayQueue &, ArrayQueue &, ArrayQueue &, string &);
void MostrarCua(ArrayQueue &, ArrayQueue &, ArrayQueue &);
/* Metodes del main*/

int menu(void);

/*
 * Casos del menu
 */
int main(int argc, char** argv) {
    int opcion;
    int conts, conta;
    conts = 0;
    conta = 0;
    ArrayQueue sortida, arribada, pista;
    string seleccionar;
    try {
        cout << "Benvingut al programa de gestió d'enlairaments i aterratges "
                "diari de l'aeroport de BCN." << endl;
        do {
            cout << "Escull una opció: " << endl;
            opcion = menu();
            switch (opcion) {
                case 1: cout << "Carregar fitxers" << endl;
                    CarregarFitxers(sortida, arribada);
                    break;
                case 2: cout << "Pista lliure" << endl;
                    pistalliure(sortida, arribada, pista, seleccionar);
                    if (seleccionar == "S") {
                        sortida.dequeue();
                    } else {
                        arribada.dequeue();
                    }

                    break;
                case 3:
                    cout << "Mostrar la cua" << endl;
                    MostrarCua(sortida,arribada,pista);
                    break;
                case 4:
                    cout << "Sortir" << endl;
                    break;
                default:
                    cout << "Opcion Incorrecta" << endl;
            }
        } while ((opcion != 4));
    } catch (out_of_range ex) {
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
    v.push_back("Carregar fitxers");
    v.push_back("Pista lliure");
    v.push_back("Mostrar la cua");
    v.push_back("Sortir");



    for (int i = 1; i <= v.size(); i++) {
        cout << i << ": " << v[i - 1] << ": " << endl;

    }
    cout << ("Opcion") << endl;
    cin>>numero;

    return numero;
}
/**
 * Metode per carregar fitxers
 * @param sortida
 * @param arribada
 */
void CarregarFitxers(ArrayQueue &sortida, ArrayQueue &arribada) {
    string op, codicomp, numVol, codiSortida, codiArribada, hSortida, hArribada;
    int cont;
    string linea;
    cont = 0;
    cout << "Vols carregar un fitxer de sortides o arribades? (S/A)" << endl;
    cin>>op;
    if (op == "S" || op == "s") {
        ifstream fs("Sortides.txt", ifstream::in);
        if (fs.is_open()) {
            while (!fs.eof()) {
                fs >> codicomp;
                fs >> numVol;
                fs >> codiArribada;
                fs >> hSortida;
                fs >> hArribada;
                Vol v;
                volSortida(v, codicomp, numVol, codiArribada, hSortida, hArribada);
                sortida.enqueue(v);
                sortida.print();
                cont++;
            }
            cout << "S'han carregat " << cont << " vols correctament." << endl;
            fs.close();
        }
    } else {
        ifstream fa("Arribades.txt", ifstream::in);
        if (fa.is_open()) {
            cout << "dentro" << endl;
            while (!fa.eof()) {
                fa >> codicomp;
                fa >> numVol;
                fa >> codiSortida;
                fa >> hSortida;
                fa >> hArribada;
                Vol v;
                volSortida(v, codicomp, numVol, codiSortida, hSortida, hArribada);
                arribada.enqueue(v);
                arribada.print();
                cont++;
            }
            cout << "S'han carregat " << cont << " vols correctament." << endl;
            fa.close();

        }
    }
}
/**
 * Metode per afegir volArribada
 * @param v
 * @param codicomp
 * @param numVol
 * @param codiSortida
 * @param hSortida
 * @param hArribada
 */
void volArribada(Vol &v, string codicomp, string numVol, string codiSortida, string hSortida, string hArribada) {
    v.set_codicomp(codicomp);
    v.set_numVol(numVol);
    v.set_codiSor(codiSortida);
    v.set_horaSor(hSortida);
    v.set_horaArr(hArribada);

}
/**
 * Metode afegir vol de sortida
 * @param v
 * @param codicomp
 * @param numVol
 * @param codiArribada
 * @param hSortida
 * @param hArribada
 */
void volSortida(Vol &v, string codicomp, string numVol, string codiArribada, string hSortida, string hArribada) {
    v.set_codicomp(codicomp);
    v.set_numVol(numVol);
    v.set_codiSor(codiArribada);
    v.set_horaSor(hSortida);
    v.set_horaArr(hArribada);

}
/**
 * Metodo pista lliure on agafarem els minuts, ja que el fitxer està ordenat,i comparem
 * @param sortida
 * @param arribada
 * @param pista
 * @param seleccionar
 */
void pistalliure(ArrayQueue &sortida, ArrayQueue &arribada, ArrayQueue &pista, string &seleccionar) {


    if (sortida.empty() && arribada.empty()) {
        cout << "Has de carregar els fitxers" << endl;

    } else {
        //string a = "25";
        //int b = atoi(a.c_str());
        Vol vSortida, vArribada;
        vSortida = sortida._front();
        string horaS = vSortida.get_horaSor();
        int posS = horaS.find(":");
        string subs = horaS.substr(posS + 1);
        int S = atoi(subs.c_str());

        vArribada = arribada._front();
        string horaA = vArribada.get_horaArr();
        int posA = horaA.find(":");
        string suba = horaA.substr(posA + 1);
        int A = atoi(suba.c_str());
        if (S < A) {
            pista.enqueue(vSortida);
            seleccionar = "S";
        } else {
            pista.enqueue(vArribada);
            seleccionar = "A";

        }
    }
}

/**
 * Metode per mostrar les diferents cues del exercici
 * @param sortida
 * @param arribada
 * @param pista
 */
void MostrarCua(ArrayQueue &sortida, ArrayQueue &arribada, ArrayQueue &pista) {
    string opcio;
    cout << "Quina cua vols veure: arribades, sortides o pista? (A/S/P)" << endl;
    cin>>opcio;
    if (sortida.empty() && arribada.empty()) {
        cout << "Has de carregar els fitxers" << endl;

    } else {
        if (opcio == "A") {
            arribada.print();
        } else if (opcio == "S") {
            sortida.print();
        } else {
            pista.print();
        }
    }
}




