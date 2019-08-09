/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: Johnny
 *
 * Created on 26 de abril de 2017, 19:41
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <stdexcept>
#include "NodeTree.h"

using namespace std;

template <class E> class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void DesBinarySearchTree(NodeTree<E>* Element);

    const int size() const {
        if (rootB == 0) return 0;
        else return size(rootB);
    };

    const int height() const {
        if (heightB == 0) return 0;
        return this->height(this->rootB);
    };
    bool empty() const;
    const NodeTree<E>* root() const;
    void insert(const E& element);
    bool search(const E& element) const;

    void printPreorder() const {
        if (this->empty()) cout << "Arbol vacio" << endl;
        else this->printPreorder(this->rootB);
    };

    void printPostorder() const {
        if (this->empty()) cout << "Arbol vacio" << endl;
        else this->printPostorder(this->rootB);
    };

    void printInorder() const {
        if (this->empty()) cout << "Arbol vacio" << endl;
        else this->printInorder(this->rootB);
    };

private:
    const int size(NodeTree<E>* subArbre) const;
    void printPreorder(const NodeTree<E>* elem) const;
    void printPostorder(const NodeTree<E>* elem) const;
    void printInorder(const NodeTree<E>* elem) const;
    const int height(NodeTree<E>* node) const;
    NodeTree<E>* rootB;
    int heightB;
};

template <class E> BinarySearchTree <E>::BinarySearchTree() {
    this->rootB = 0;
    this->heightB = 1;
}

template <class E> BinarySearchTree <E>::~BinarySearchTree() {
    DesBinarySearchTree(rootB);
}

template <class E> void BinarySearchTree<E> ::DesBinarySearchTree(NodeTree<E>* subArbre) {
    if (subArbre != 0) {
        DesBinarySearchTree(subArbre->left());
        DesBinarySearchTree(subArbre->right());
        delete subArbre;
    }
}

template <class E> const int BinarySearchTree <E>::size(NodeTree<E>* subArbre) const {
    if (subArbre->isExternal()) return 1;
    else if (subArbre->left() != 0 && subArbre->right() != 0) return size(subArbre->left()) + size(subArbre->right()) + 1;
    else if (subArbre->right() != 0) return size(subArbre->right()) + 1;
    else return size(subArbre->left()) + 1;
}

template <class E> const NodeTree<E>* BinarySearchTree<E>::root() const {
    if (this->empty()) throw new out_of_range("Arbol vacio");
    else return this->rootB;
}

template <class E> bool BinarySearchTree <E>::empty() const {
    return (this->size() == 0);
}

template <class E> const int BinarySearchTree <E>::height(NodeTree<E>* node) const {
    if (node->isExternal()) return 0;
    else if (node->left() != 0 && node->right() != 0) return (max(height(node->left()), height(node->right())) + 1);
    else if (node->left() == 0) return height(node->right()) + 1;
    else return height(node->left()) + 1;
}

template <class E> void BinarySearchTree <E>::insert(const E& element) {
    if (this->empty()) {
        this->rootB = new NodeTree<E>(element, 0);
    } else {
        NodeTree <E>* node;
        NodeTree <E>* guide = this->rootB;
        while (guide->getElement() != element) {
            if (guide->getElement() > element) {
                if (!guide->left() == 0) guide = guide->left();
                else {
                    node = new NodeTree<E>(element, guide);
                    guide->setLeft(node);
                    guide = node;
                }
            } else {
                if (!guide->right() == 0) guide = guide->right();
                else {
                    node = new NodeTree<E>(element, guide);
                    guide->setRight(node);
                    guide = node;
                }
            }
        }
    }
}

template <class E> bool BinarySearchTree <E>::search(const E& element) const {
    NodeTree <E>* guide = this->rootB;
    bool trobat = guide->getElement() == element;
    bool final = false;
    while (!trobat && !final) {
        if (guide->getElement() == element){
            trobat = true;
            cout<< "Elemento encontrado " << element <<endl;
        }
        else if (guide->getElement() > element) {
            if (!guide->left() == 0) {
                guide = guide->left();
            }
            else final = true;            
        } else {
            if (!guide->right() == 0) {
                guide = guide->right();
                cout<< "Elemento no encontrado " << element <<endl;
            }
            else final = true;
        }
    }
    return trobat;
}


template <class E> void BinarySearchTree <E>::printPreorder(const NodeTree<E>* elem) const {
    cout << elem->getElement() <<" ";
    if (!elem->isExternal()) {
        if (elem->left() != 0) printPreorder(elem->left());
        if (elem->right() != 0) printPreorder(elem->right());
    }
}

template <class E> void BinarySearchTree <E>::printPostorder(const NodeTree<E>* elem) const {
    if (!elem->isExternal()) {
        if (elem->left() != 0) printPostorder(elem->left());
        if (elem->right() != 0)printPostorder(elem->right());
    }
    cout << elem->getElement() << " ";
}

template <class E> void BinarySearchTree <E>::printInorder(const NodeTree<E>* elem) const {
    if (!elem->isExternal() && elem->left() != 0) {
        printInorder(elem->left());
    }
    cout << elem->getElement() << " ";
    if (!elem->isExternal() && elem->right() != 0) {
        printInorder(elem->right());
    }
}

#endif /* BINARYSEARCHTREE_H */

