/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vol.cpp
 * Author: johnny
 * 
 * Created on 20 de marzo de 2017, 20:00
 */

#include "Vol.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>



Vol::Vol() {

}


Vol::~Vol() {
}

void Vol::set_codicomp(){ 
    std::cin>>this->codicomp;
    //std::cout << this->codicomp;
}
std::string Vol::get_codicomp(){
    return this->codicomp;
}

void Vol::set_horaSor(){
    std::cin>>this->horaSor;
}
std::string Vol::get_horaSor(){
    return this->horaSor;
}
void Vol::set_horaArr(){
    std::cin>>this->horaArr;
}
std::string Vol::get_horaArr(){
    return this->horaArr;
}

void Vol::set_codiSor(){
    std::cin>>this->codiSor;
}
std::string Vol::get_codiSor(){
    return this->codiSor;
}


void Vol::set_codiArr(){
    std::cin>>this->codiArr;
}

std::string Vol::get_codiArr(){
    return this->codiArr;
}


void Vol::set_numVol(){
    std::cin>>this->numvol;
}
int Vol::get_numVol(){
    return this->numvol;
}