/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Johnny
 *
 * Created on 26 de abril de 2017, 19:41
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "BinarySearchTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BinarySearchTree<int>* arbre = new BinarySearchTree<int>();
    arbre->insert(10);
    arbre->insert(5);
    arbre->insert(17);
    arbre->insert(8);
    arbre->insert(3);
    arbre->insert(7);
    
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
    arbre->~BinarySearchTree();
    return 0;
}

