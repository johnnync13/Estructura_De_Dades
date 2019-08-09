/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ling
 *
 * Created on 23 / de març / 2017, 08:21
 */

#include <cstdlib>
#include "LinkedStack.h"
#include <iostream>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    LinkedStack<int> l;
    cout<<"Añadir 4 elementos a la pila"<<endl;
    for(int i = 0;i<4;i++){
        l.push(i);
    }
    l.print();
    
    cout<<"Ahora mostrar la pantalla el elemento top"<<endl;
    cout<<l.top()<<endl;
    
    cout<<"Eliminamos 3 veces"<<endl;
    for(int j =0; j <3;j++){
        l.pop();
    }
    l.print();
    cout<<"La longitud de la pila"<<endl;
    cout<<l.size()<<endl;
    return 0;
}
