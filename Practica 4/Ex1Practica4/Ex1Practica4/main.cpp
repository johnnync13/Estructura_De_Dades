/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Johnny
 * Author: Ling
 * Created on 24 de mayo de 2017, 16:18
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MinHeap.h"
#include "Contacte.h"

using namespace std;


int main(int argc, char** argv) {
    MinHeap<Contacte> arbre;
    Contacte a("James","james","6649 N Blue Gum St","New Orleans","504-621-8927","jbutt@gmail.com");
    Contacte b("Hola","reset","6649 N Blue Gum St","New Orleans","504-621-8927","jbutt@gmail.com");
    Contacte c("ASDFG","mola","6649 N Blue Gum St","New Orleans","504-555-8927","jbutt@gmail.com");
    Contacte e("hola","hola","6649 N Blue Gum St","New Orleans","000-000-0000","jbutt@gmail.com");
    string keya = "1";
    string keyb = "2";
    string keyc = "3";
    string keye = "4";
   
    arbre.insert(keya,a);
    arbre.insert(keyb,b);
    arbre.insert(keyc,c);
    arbre.insert(keye,e);
    
    cout << "Print heap" << endl;
    arbre.printHeap();
    cout <<endl;
    
    arbre.removeMin();
    arbre.removeMin();
    arbre.printHeap();
    cout <<endl;
    cout<<endl;;
    return 0;
}

