/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBST.h
 * Author: Johnny
 *
 * Created on 8 de mayo de 2017, 23:54
 */

#ifndef BALANCEDBST_H
#define BALANCEDBST_H
#include <iostream>
#include <stdexcept>
#include "NodeTree.h"
#include "Contacte.h"

using namespace std;

template <class E> class BalancedBST {
public:
    BalancedBST();
    ~BalancedBST();
    void DesBalancedSearchTree(NodeTree<E>* Element);
    const int size() const {
        if (rootB == nullptr) return 0;
        else return size(rootB);
    };

    const int height() const {
        return this->height(this->rootB);
    };
    bool empty() const;
    const NodeTree<E>* root() const;
    void insert(string, Contacte);
    bool search(const E& element) const;
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
    const int size(NodeTree<E>* subArbre) const;
    void printPreorder(const NodeTree<E>* elem) const;
    void printPostorder(const NodeTree<E>* elem) const;
    void printInorder(const NodeTree<E>* elem) const;
    const int height(NodeTree<E>* node) const;
    NodeTree<E>* nodoDesbalanceado(NodeTree<E>* nodeInserted) const;
    void rebalancear(NodeTree<E>* ArbolaRebalancear);
    void leftRotation(NodeTree<E>* NodeaRebalancear);
    void rightRotation(NodeTree<E>* NodeaRebalancear);
    NodeTree<E>* rootB;
};

template <class E> BalancedBST<E>::BalancedBST() {
    this->rootB = nullptr;
}

template <class E> BalancedBST<E>::~BalancedBST() {
    DesBalancedSearchTree(rootB);
}

template <class E> const int BalancedBST<E>::size(NodeTree<E>* subArbre) const {
    if (subArbre->isExternal()) return 1;
    else if (subArbre->left() != 0 && subArbre->right() != 0) return size(subArbre->left()) + size(subArbre->right()) + 1;
    else if (subArbre->right() != 0) return size(subArbre->right()) + 1;
    else return size(subArbre->left()) + 1;
}

template <class E> const NodeTree<E>* BalancedBST<E>::root() const {
    if (this->empty()) throw new out_of_range("Arbol vacio");
    else return this->rootB;
}

template <class E> bool BalancedBST<E>::empty() const {
    return (this->size() == 0);
}
template <class E> void BalancedBST<E> ::DesBalancedSearchTree(NodeTree<E>* subArbre) {
    if (subArbre != nullptr) {
        DesBalancedSearchTree(subArbre->left());
        DesBalancedSearchTree(subArbre->right());
        delete subArbre;
    }
}

template <class E> void BalancedBST<E>::insert(string key,Contacte c) {
    if (this->empty()) {
        this->rootB = new NodeTree<E>(key,c, 0);
    } else {
        NodeTree <E>* node;
        NodeTree <E>* guide = this->rootB;
        while (guide->getKey() != c.getCognom()) {
            if (guide->getKey() > c.getCognom()) {
                if (!guide->left() == 0) guide = guide->left();
                else {
                    node = new NodeTree<E>(key,c,guide);
                    guide->setLeft(node);
                    guide = node;
                }
            } else {
                if (!guide->right() == 0) guide = guide->right();
                else {
                    node = new NodeTree<E>(key,c, guide);
                    guide->setRight(node);
                    guide = node;
                }
            }
        }
        guide = nodoDesbalanceado(guide);
        if (guide != 0) rebalancear(guide);
    }
}

template <class E> Contacte BalancedBST<E>::searchContact(const string cognom) const {
    Contacte c;
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

template <class E> void BalancedBST<E>::printPreorder(const NodeTree<E>* elem) const {
    cout << elem->getKey() << " ";
    if (!elem->isExternal()) {
        if (elem->left() != 0) printPreorder(elem->left());
        if (elem->right() != 0) printPreorder(elem->right());
    }
}

template <class E> void BalancedBST<E>::printPostorder(const NodeTree<E>* elem) const {
    if (!elem->isExternal()) {
        if (elem->left() != 0) printPostorder(elem->left());
        if (elem->right() != 0)printPostorder(elem->right());
    }
    cout << elem->getKey() << " ";
}

template <class E> void BalancedBST<E>::printInorder(const NodeTree<E>* elem) const {
    Contacte contact;
    if (!elem->isExternal() && elem->left() != 0) {
        printInorder(elem->left());
    }
    contact = elem->getValues();
    cout << contact.toString() << endl;
    if (!elem->isExternal() && elem->right() != 0) {
        printInorder(elem->right());
    }
}

template <class E> const int BalancedBST<E>::height(NodeTree<E>* node) const {
    return node->getHeight();
}

template<class E> NodeTree<E>* BalancedBST<E>::nodoDesbalanceado(NodeTree<E>* nodeInserted) const {
    int balanceFactor = 0;
    int heightLeft = 0;
    int heightRight = 0;
    NodeTree<E>* nodeSon = nodeInserted;
    while (nodeSon != this->rootB && balanceFactor < 2) {
        heightLeft = (nodeSon->parent()->left() != 0) ? nodeSon->parent()->left()->getHeight() : 0;
        heightRight = (nodeSon->parent()->right() != 0) ? nodeSon->parent()->right()->getHeight() : 0;
        balanceFactor = abs(heightLeft - heightRight);
        nodeSon->parent()->setHeight(max(nodeSon->parent()->getHeight(), nodeSon->getHeight() + 1));
        nodeSon = nodeSon->parent();
    }
    if (balanceFactor >= 2) return nodeSon;
    else return 0;
}

template<class E> void BalancedBST<E>::rebalancear(NodeTree<E>* ArbolaRebalancear) {
    int heightLeft = 0;
    int heightRight = 0;
    heightLeft = (ArbolaRebalancear->left() != 0) ? ArbolaRebalancear->left()->getHeight() : 0;
    heightRight = (ArbolaRebalancear->right() != 0) ? ArbolaRebalancear->right()->getHeight() : 0;
    if (heightLeft > heightRight) {
        heightLeft = (ArbolaRebalancear->left()->left() != 0) ? ArbolaRebalancear->left()->left()->getHeight() : 0;
        heightRight = (ArbolaRebalancear->left()->right() != 0) ? ArbolaRebalancear->left()->right()->getHeight() : 0;
        if (heightLeft > heightRight) {
            rightRotation(ArbolaRebalancear->left());
        } else {
            leftRotation(ArbolaRebalancear->left()->right());
            rightRotation(ArbolaRebalancear->left());
        }
    } else {
        heightLeft = (ArbolaRebalancear->right()->left() != 0) ? ArbolaRebalancear->right()->left()->getHeight() : 0;
        heightRight = (ArbolaRebalancear->right()->right() != 0) ? ArbolaRebalancear->right()->right()->getHeight() : 0;
        if (heightLeft > heightRight) {
            rightRotation(ArbolaRebalancear->right()->left());
            leftRotation(ArbolaRebalancear->right());
        } else {
            leftRotation(ArbolaRebalancear->right());
        }
    }
}

template <class E> void BalancedBST<E>::rightRotation(NodeTree<E>* NodeaRebalancear) {
    NodeTree<E>* nodeParent = NodeaRebalancear->parent();
    NodeTree<E>* nodeParentParent = nodeParent->parent();
    NodeTree<E>* nodeSon = NodeaRebalancear;
    if (nodeParentParent != 0) {
        if (nodeParentParent->left() == nodeParent) nodeParentParent->setLeft(nodeSon); //Era el hijo izquierdo
        else nodeParentParent->setRight(nodeSon); // Era el hijo derecho
        nodeSon->setParent(nodeParentParent);
    } else {
        nodeSon->setParent(0);
        this->rootB = nodeSon;
    }
    if (nodeSon->right() != 0) {
        nodeSon->right()->setParent(nodeParent);
        nodeParent->setLeft(nodeSon->right());
    } else nodeParent->setLeft(0);
    nodeParent->setParent(nodeSon);
    nodeSon->setRight(nodeParent);
    nodeParent->setHeight(max(((nodeParent->left() != 0) ? nodeParent->left()->getHeight() : 0), ((nodeParent->right() != 0) ? nodeParent->right()->getHeight() : 0)) + 1);
    nodeSon->setHeight(max(((nodeSon->left() != 0) ? nodeSon->left()->getHeight() : 0), ((nodeSon->right() != 0) ? nodeSon->right()->getHeight() : 0)) + 1);
}

template<class E> void BalancedBST<E>::leftRotation(NodeTree<E>* NodeaRebalancear) {
    NodeTree<E>* nodeParent = NodeaRebalancear->parent();
    NodeTree<E>* nodeParentParent = nodeParent->parent();
    NodeTree<E>* nodeSon = NodeaRebalancear;
    if (nodeParentParent != 0) {
        if (nodeParentParent->left() == nodeParent) nodeParentParent->setLeft(nodeSon); //Era el hijo izquierdo
        else nodeParentParent->setRight(nodeSon);
        nodeSon->setParent(nodeParentParent);
    } else {
        nodeSon->setParent(0);
        this->rootB = nodeSon;
    }
    if (nodeSon->left() != 0) {
        nodeSon->left()->setParent(nodeParent);
        nodeParent->setRight(nodeSon->left());
    } else nodeParent->setRight(0);
    nodeParent->setParent(nodeSon);
    nodeSon->setLeft(nodeParent);
    nodeParent->setHeight(max(((nodeParent->left() != 0) ? nodeParent->left()->getHeight() : 0), ((nodeParent->right() != 0) ? nodeParent->right()->getHeight() : 0)) + 1);
    nodeSon->setHeight(max(((nodeSon->left() != 0) ? nodeSon->left()->getHeight() : 0), ((nodeSon->right() != 0) ? nodeSon->right()->getHeight() : 0)) + 1);
}

#endif /* BALANCEDBST_H */

