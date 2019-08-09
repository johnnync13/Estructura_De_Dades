/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ling
 *
 * Created on 30 / de març / 2017, 08:10
 */
#include <cstdlib>
#include "LinkedStack.h"
#include <iostream>
using namespace std;
/*En esta pregunta hemos implementado el problema con LinkedStacks. Hemos hecho las operaciones top() y pop() para
 * conseguir el numero maximo y guardar en un LinkedStack temporal, después volvemos a inserir los elementos del LinkedStack
 * temporal a la lista nativa. Pero tambien se puede crear dos listas y cuando preguntamos al usuario los datos añadimos a las dos
 * listas.
 * 
 */

int main(int argc, char** argv) {
    int numero,intemp,j;
    string opcio;//Para saber si el usuario quiere introduci mas numeros.
    LinkedStack<int> l,tmp;//Una de las dos listas sirve para añadir elementos y otra para hacer las operacioons para conseguir el numero mayor.
    cout<<"Que numero vols afegir a la lista:"<<endl;//pide al usuario el numero.
    cin>>numero;
    l.push(numero); 
    cout<<"Lista actual:";
    l.print();
    cout<<"Vols seguir afegir numeros?(Y per seguir)"<<endl;
    cin>>opcio;
    while (opcio=="Y"){//El bucle para introducir mas de un numero.
        cout<<"Que numero vols afegir a la lista:"<<endl;
        cin>>numero;
        l.push(numero); 
        cout<<"Lista actual:";
        l.print();
        cout<<"Vols seguir afegir numeros?(Y per seguir)"<<endl;
        cin>>opcio;
    }
    while(!l.empty()){//La operacion para conseguir el numero maximo.
        intemp = l.top();
        l.pop();
        tmp.push(intemp);
        if(j<intemp){
            j=intemp;
        }
    }
    cout<<"El numero mes gran de la llista es: "<<j<<"."<<endl;
    while(!tmp.empty()){//Bucle para conseguir el estado de la lista antes de hacer las operaciones.
        intemp = tmp.top();
        tmp.pop();
        l.push(intemp);
    }
    return 0;
}

