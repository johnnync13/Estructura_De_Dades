/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: Johnny
 *
 * Created on 26 de abril de 2017, 19:41
 */

#ifndef NODETREE_H
#define NODETREE_H

template <class E> class NodeTree {
public:
    NodeTree(const E& element, NodeTree<E> * const parentAux);
    virtual ~NodeTree(){};
    const E getElement() const;
    NodeTree<E> * const parent() const;
    NodeTree<E> * const right() const;
    NodeTree<E> * const left() const;
    bool isRoot() const;
    bool isExternal() const;
    void setElement(NodeTree<E> * const Element);
    void setRight(NodeTree<E> * const rightAux);
    void setLeft(NodeTree<E> * const leftAux);
    void setParent(NodeTree<E> * const parentAux);
    int height(NodeTree<E>*const Element);

private:
    NodeTree<E>* leftN;
    NodeTree<E>* rightN;
    NodeTree<E>* parentN;
    E elementN;
};

template <class E> NodeTree <E>::NodeTree(const E& element, NodeTree<E> * const parentAux) {
    this->elementN = element;
    this->leftN = 0;
    this->rightN = 0;
    setParent(parentAux);
}

template <class E> const E NodeTree <E>::getElement() const {
    return this->elementN;
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
    return (this->parent() == 1);
}

template <class E> bool NodeTree<E>::isExternal() const {
    return (this->left() == 0 && this->right() == 0);
}

template <class E> void NodeTree<E>::setElement(NodeTree<E> * const Element) {
    this->elementN = Element;
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

