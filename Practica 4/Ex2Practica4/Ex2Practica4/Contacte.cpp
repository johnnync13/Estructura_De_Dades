/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacte.cpp
 * Author: Johnny
 * Author: Ling
 * Created on 27 de abril de 2017, 9:17
 */

#include "Contacte.h"
#include "Contacte.h"
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

//constuctor con parametros
Contacte::Contacte(string cognom, string telefon) {
    this->nom = " ";
    this->cognom = cognom;
    this->adreca = " "; 
    this->ciutat= " ";
    this->addTelefon(telefon);
    this->correu = " ";
}

Contacte::Contacte(string nom,string cognom, string adreca, string ciutat, string telefon, string correu){
    this->nom=nom;
    this->cognom = cognom;
    this->adreca=adreca;
    this->ciutat=ciutat;
    this->addTelefon(telefon);
    this->correu=correu;
}

//metode getter del atributo cognom
string Contacte::getCognom(){
    return cognom;
}

//metodo getter del atributo telefon
string Contacte::getTelefon(){
    for (vector<string>::iterator itr = telefons.begin(); itr != telefons.end(); itr = ++itr){
        return *itr;
    }
}

string Contacte::getNom(){
    return nom;
}

string Contacte::getAdreca(){
    return adreca;
}

string Contacte::getCiutat(){
    return ciutat;
}

string Contacte::getCorreu(){
    return correu;
}
//metodos setters de los atributos declarados como privados
void Contacte::setNom(string nom){
    this->nom=nom;
}
void Contacte::setCognom(string cognom){
    this->cognom=cognom;
}
void Contacte::setAdreca(string adreca){
    this->adreca=adreca;
}
void Contacte::setCiutat(string ciutat){
    this->ciutat=ciutat;
}
void Contacte::addTelefon(string telefon){
    this->telefons.push_back(telefon);
}
void Contacte::setCorreu(string correu){
    this->correu=correu;
}

//metodo toString
string Contacte::toString(){
    string s =" ";
    s += getNom()+","+ getCognom()+","+getAdreca()+","+getCiutat()+","+getTelefon()+","+getCorreu();
    return s;
}
