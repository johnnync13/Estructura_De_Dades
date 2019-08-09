/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: Johnny
 * Author: Ling
 * Created on 3 de mayo de 2017, 21:17
 */

#ifndef NODETREE_H
#define NODETREE_H
#include <string>
#include <vector>
using namespace std;
template <class E> class NodeTree {
public:
    NodeTree(string key,const E values);
    virtual ~NodeTree(){};
    const std::string getKey() const;
    const E& getValues() const;
    void setValues(const E& newValues);
    void setKey(std::string newKey);
   
    string key;
    E values;
};

template <class E> NodeTree <E>::NodeTree(string key,const E values) {
    this->key=key;
    this->values = values;
    
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




#endif /* NODETREE_H */

