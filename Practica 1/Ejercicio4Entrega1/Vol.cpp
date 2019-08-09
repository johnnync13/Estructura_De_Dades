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


using namespace std;
Vol::Vol() {

}


Vol::~Vol() {
}

void Vol::set_codicomp(string codicomp){ 
    this->codicomp=codicomp;
    //std::cout << this->codicomp;
}
std::string Vol::get_codicomp(){
    return this->codicomp;
}

void Vol::set_horaSor(string horaSor){
    this->horaSor=horaSor;
}
std::string Vol::get_horaSor(){
    return this->horaSor;
}
void Vol::set_horaArr(string horaArr){
    this->horaArr=horaArr;
}
std::string Vol::get_horaArr(){
    return this->horaArr;
}

void Vol::set_codiSor(string codiSor){
    this->codiSor=codiSor;
}
std::string Vol::get_codiSor(){
    return this->codiSor;
}


void Vol::set_codiArr(string codiArr){
    this->codiArr=codiArr;
}

std::string Vol::get_codiArr(){
    return this->codiArr;
}


void Vol::set_numVol(string numVol){
    this->numvol=numVol;
}
string Vol::get_numVol(){
    return this->numvol;
}