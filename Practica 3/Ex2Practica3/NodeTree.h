/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: Johnny
 *
 * Created on 3 de mayo de 2017, 21:17
 */

#ifndef NODETREE_H
#define NODETREE_H
#include <string>
#include <vector>
using namespace std;
template <class E> class NodeTree {
public:
    NodeTree(string key,const E values, NodeTree<E> * const parentAux);
    virtual ~NodeTree(){};
    const std::string getKey() const;
    const E& getValues() const;
    void setValues(const E& newValues);
    void setKey(std::string newKey);
    NodeTree<E> * const parent() const;
    NodeTree<E> * const right() const;
    NodeTree<E> * const left() const;
    bool isRoot() const;
    bool isExternal() const;
    void setRight(NodeTree<E> * const rightAux);
    void setLeft(NodeTree<E> * const leftAux);
    void setParent(NodeTree<E> * const parentAux);
    int height(NodeTree<E>*const Element);

private:
    NodeTree <E>* leftN;
    NodeTree <E>* rightN;
    NodeTree <E>* parentN;
    string key;
    E values;
};

template <class E> NodeTree <E>::NodeTree(string key,const E values, NodeTree<E> * const parentAux) {
    this->key=key;
    this->values = values;
    this->leftN = nullptr;
    this->rightN = nullptr;
    setParent(parentAux);
}
template <class E> const E& NodeTree <E>::getValues() const {
    return this->values;
}

template <class E> const string NodeTree <E>::getKey() const {
    return this->key;
}

template <class E> void NodeTree <E>::setValues(const E& newValues) {
    this->values = newValues;
}

template <class E> void NodeTree<E>::setKey(std::string newKey) {
    this->key = newKey;
}


template <class E> NodeTree<E> * const NodeTree <E>::parent() const {
    return this->parentN;
}

template <class E> NodeTree<E> * const NodeTree <E>::right() const {
    return this->rightN;
}

template <class E> NodeTree<E> * const NodeTree <E>::left() const {
    return this->leftN;
}

template <class E> bool NodeTree<E>::isRoot() const {
    return (this->parent() == nullptr);
}

template <class E> bool NodeTree<E>::isExternal() const {
    return (this->left() == nullptr && this->right() == nullptr);
}

template <class E> void NodeTree<E>::setRight(NodeTree<E> * const rightAux) {
    this->rightN = rightAux;
}

template <class E> void NodeTree<E>::setLeft(NodeTree<E> * const leftAux) {
    this->leftN = leftAux;
}

template <class E> void NodeTree<E>::setParent(NodeTree<E> * const parentAux) {
    this->parentN = parentAux;
}

template <class E> int NodeTree<E>::height(NodeTree<E>* const N) {
    if (N->isRoot()) return 0;
    else {
        return 1 + height(N->parent());
    }
}


#endif /* NODETREE_H */

