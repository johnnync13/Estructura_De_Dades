/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacte.h
 * Author: Johnny
 *
 * Created on 27 de abril de 2017, 9:17
 */

#ifndef CONTACTE_H
#define CONTACTE_H
#include <string>
#include <iostream>

using namespace std;

class Contacte {
public:
   
    //constructor con parametro
    Contacte(){};
    Contacte( string cognom, string telefon);
    Contacte(string nom, string cognom, string adreca, string ciutat, string telefon, string correu);
    //metodos getters de los atributos privados
    string getNom();
    string getCognom();
    string getAdreca();
    string getCiutat();
    string getTelefon();
    string getCorreu();
    //metodos setters de los atributos privados
    void setNom(string nom);
    void setCognom(string cognom);
    void setAdreca(string adreca);
    void setCiutat(string ciutat);
    void setTelefon(string telefon);
    void setCorreu(string correu);
    //metodo toString que devuelve el contenido de un contacto
    string toString();
private:
    string nom;
    string cognom;
    string adreca;
    string ciutat;
    string telefon;
    string correu;
         
    
};


#endif /* CONTACTE_H */

