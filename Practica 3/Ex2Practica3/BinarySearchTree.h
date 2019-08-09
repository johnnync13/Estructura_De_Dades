/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: Johnny
 *
 * Created on 3 de mayo de 2017, 21:18
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdexcept>
#include "NodeTree.h"
#include "Contacte.h"


using namespace std;

template <class E> class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void DesBinarySearchTree(NodeTree<E>* Element);

    const int size() const {
        if (rootB == nullptr) return 0;
        else return size(rootB);
    };

    const int height() const {
        if (heightB == 1) return 0;
        return this->height(this->rootB);
    };
    bool empty() const;
    const NodeTree<E>* root() const;
    void insert(string, Contacte);
    Contacte searchContact(const string cognom) const;

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
    const NodeTree <E>* getNode(const string cognom);
    const int size(NodeTree<E>* subArbre) const;
    void printPreorder(const NodeTree<E>* elem) const;
    void printPostorder(const NodeTree<E>* elem) const;
    void printInorder(const NodeTree<E>* elem) const;
    const int height(NodeTree<E>* node) const;
    NodeTree<E>* rootB;
    int heightB;
    int index;
};

template <class E> BinarySearchTree <E>::BinarySearchTree() {
    this->rootB = nullptr;
    this->heightB = 1;
    this->index=0;
}

template <class E> BinarySearchTree <E>::~BinarySearchTree() {
    DesBinarySearchTree(rootB);
}

template <class E> void BinarySearchTree<E> ::DesBinarySearchTree(NodeTree<E>* subArbre) {
    if (subArbre != nullptr) {
        DesBinarySearchTree(subArbre->left());
        DesBinarySearchTree(subArbre->right());
        delete subArbre;
    }
}

template <class E> const int BinarySearchTree <E>::size(NodeTree<E>* subArbre) const {
    if (subArbre->isExternal()) return 1;
    else if (subArbre->left() != nullptr && subArbre->right() != nullptr) return size(subArbre->left()) + size(subArbre->right()) + 1;
    else if (subArbre->right() != nullptr) return size(subArbre->right()) + 1;
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

template <class E> void BinarySearchTree <E>::insert(string key, Contacte c) {
    if (this->empty()) {
        this->rootB = new NodeTree<E>(key, c, nullptr);
    } else {
        NodeTree <E>* node;
        NodeTree <E>* guide = this->rootB;
        int i = 0;
        while (guide->getKey() != c.getCognom()) {
            if (guide->getKey() > c.getCognom()) {
                if (!guide->left() == 0) guide = guide->left();
                else {
                    node = new NodeTree<E>(key, c, guide);
                    guide->setLeft(node);
                    guide = node;
                }
            } else {
                if (!guide->right() == 0) guide = guide->right();
                else {
                    node = new NodeTree<E>(key, c, guide);
                    guide->setRight(node);
                    guide = node;
                }
            }
            i++;
        }
        if (i > this->heightB) this->heightB = i;
    }
}

template <class E> Contacte BinarySearchTree <E>::searchContact(const string cognom) const {
    Contacte c;
    c.setCognom("No trobat");
    if (this->empty()) {
        return c;
    } else {
        NodeTree <E>* guia = this->rootB;
        bool trobat = guia->getKey() == cognom;
        bool finalC = false;
        while (!trobat && !finalC) {
            if (guia->getKey() == cognom) {
                c = guia->getValues();
                trobat = true;
                cout << "Contacto Encontrado: " << cognom << endl;
            } else if (guia->getKey() > cognom) {
                if (!guia->left() == 0) guia = guia->left();
                else finalC = true;
            } else {
                if (!guia->right() == 0) guia = guia->right();
                else finalC = true;
            }
        }
    }
    return c;
}

template<class E> const NodeTree <E>* BinarySearchTree<E>::getNode(const string cognom) {
    NodeTree <E>* guia = this->rootB;
    bool trobat = guia->getKey() == cognom;
    bool finalC = false;
    while (!trobat && !finalC) {
        if (guia->getKey() == cognom) trobat = true;
        else if (guia->getKey() > cognom) {
            if (!guia->left() == 0) guia = guia->left();
            else finalC = true;
        } else {
            if (!guia->right() == 0) guia = guia->right();
            else finalC = true;
        }
    }
    if (!trobat) return nullptr;
    else return guia;
}

template <class E> void BinarySearchTree <E>::printPreorder(const NodeTree<E>* elem) const {
    cout << elem->getKey() << " ";
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
    cout << elem->getKey() << " ";
}

template <class E> void BinarySearchTree <E>::printInorder(const NodeTree<E>* elem) const {
    Contacte contact;
    string resposta;
    if (index == 40) {
        cout << "Vols continuar llegint?: S/N" << endl;
        cin>>resposta;
        if (resposta == "S") {
        } else {
        }
    } else {
        if (!elem->isExternal() && elem->left() != 0) {
            printInorder(elem->left());
        }
        contact = elem->getValues();

        cout << contact.toString() << endl;
        if (!elem->isExternal() && elem->right() != 0) {
            printInorder(elem->right());
        }
    }


}


#endif /* BINARYSEARCHTREE_H */

