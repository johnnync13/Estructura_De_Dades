/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Johnny
 *
 * Created on 8 de mayo de 2017, 23:54
 */

#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "BalancedBST.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BalancedBST<int>* arbre = new BalancedBST<int>();
    arbre->insert(3);
    arbre->insert(4);
    arbre->insert(5);
    arbre->insert(6);
    arbre->insert(7);
    arbre->insert(2);
    arbre->insert(1);
    arbre->insert(0);
    
    cout << "Print Preorder" << endl;
    arbre->printPreorder();
    cout <<endl;
    cout << "Print Postorder" << endl;
    arbre->printPostorder();
    cout <<endl;
    cout << "Print Inorder" << endl;
    arbre->printInorder();
    cout << "\n"<< "El size del arbre es: "<<arbre->size();
    cout << "\n"<< "El height del arbre es: "<< arbre->height();
    cout << "\n"<< "L'adreça del root es : "<< arbre->root() << " amb el node "<< arbre->root()->getElement();
    cout <<endl;
    arbre->search(99);
    arbre->search(5);
    cout<<endl;
    arbre->~BalancedBST();
    return 0;
}

