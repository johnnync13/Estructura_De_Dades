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
#include <string>

using namespace std;

/*
 * Metodes del main
 */
int menu(void);

void problema(int &);
int inicial(int &, ArrayStack&, ArrayStack&, ArrayStack&);
void hanoi(int, ArrayStack&, ArrayStack&, ArrayStack&);
void printin(int &, ArrayStack&, ArrayStack&, ArrayStack&);
void printfin(int &, ArrayStack&, ArrayStack&, ArrayStack&);
void solverProblema(int &, ArrayStack&, ArrayStack&, ArrayStack&);

/*
 * Casos del menu
 */
int main(int argc, char** argv) {
    string nombre;
    int n, opcion;
    string A,B,C;
    A='A';B='B';C='C';
    ArrayStack origen, aux, desti;

    try {
        cout << "Resolució del joc de les Torres de Hanoi" << endl;
        n = inicial(n, origen, aux, desti);
        origen.setlabel(A);aux.setlabel(B);desti.setlabel(C);
        do {


            opcion = menu();
            switch (opcion) {
                case 1: cout << "Adios" << endl;
                    break;
                case 2: cout << "Jugar Hanoi:" << endl;
                    solverProblema(n, origen, aux, desti);
                    break;

                default:
                    cout << "Opcion Incorrecta" << endl;
            }
        } while ((opcion != 1));
    } catch (out_of_range ex) {
        cout << ex.what() << endl;
    } catch (int error) {
        cout << "Hay un error" << endl;
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
    v.push_back("Jugar Hanoi");




    for (int i = 1; i <= v.size(); i++) {
        cout << i << ": " << v[i - 1] << ": " << endl;

    }
    cout << ("Opcion") << endl;
    cin>>numero;

    return numero;
}

/**
 * Mostrar moviments hanoi
 * @param n
 */
void problema(int &n,ArrayStack &A, ArrayStack &B, ArrayStack &C) {
    cout << "Els moviments que s'han de fer:\n";
    hanoi(n, A, C, B); // transfereix n discos de A a C utilitzant B // transfereix n discos de A a C utilitzant B
}
/**
 * Mostrar moviments del hanoi
 * @param n
 * @param origen
 * @param desti
 * @param aux
 */

/**
 * Metode per resoldre Hanoi, fa crida a diferents metodes
 * @param n
 * @param A
 * @param B
 * @param C
 */
void solverProblema(int &n, ArrayStack &A, ArrayStack &B, ArrayStack &C) {
    if (A.empty()) {
        n = 0;
        C.clean();
        inicial(n, A, B, C);
    } else {
        printin(n, A, B, C);
        hanoi(n, A, C, B);
        printfin(n, A, B, C);
    }
}
/**
 * Metode per inicialitzar el joc, es a dir, la pila A
 * @param n
 * @param A
 * @param B
 * @param C
 * @return 
 */
int inicial(int &n, ArrayStack &A, ArrayStack &B, ArrayStack &C) {
    if (A.empty()) {
        cout << "\n Introdueix el nombre de discs: ";
        if (n == 0) {
            cin >>n;
        }
        for (int i = 1; i <= n; i++) {
            A.push(i);
        }

    }
    return n;
}
/**
 * Algoritme iteratiu adaptat a piles
 * @param n
 * @param A
 * @param C
 * @param B
 */
void hanoi(int n, ArrayStack &origen,ArrayStack &desti,ArrayStack &aux) {
    if(n != 0) {       
        hanoi(n-1,origen,aux,desti);
        desti.push(origen.top());
        origen.pop();
        cout << "Mou disc " << n << " de " << origen.getlabel() << " a " << desti.getlabel() << endl;
        hanoi(n-1,aux, desti, origen); 
    }
}
/**
 * Print estat inicial
 * @param n
 * @param A
 * @param B
 * @param C
 */
void printin(int &n, ArrayStack &A, ArrayStack &B, ArrayStack &C) {
    cout << "Estado Inicial de les varetes: ";
    cout << "\n A: ";
    A.print();
    cout << "\n B: ";
    B.print();
    cout << "\n C: ";
    C.print();
    cout << endl;

    cout << "------------------------";
    cout << endl;
};
/**
 * Print estat final
 * @param n
 * @param A
 * @param B
 * @param C
 */
void printfin(int &n, ArrayStack &A, ArrayStack &B, ArrayStack &C) {

    cout << "------------------------";
    cout << endl;
    cout << "Estado Final de les varetes: ";
    cout << "\n A: ";
    A.print();
    cout << "\n B: ";
    B.print();
    cout << "\n C: ";
    C.print();
    cout << endl;
    
}

