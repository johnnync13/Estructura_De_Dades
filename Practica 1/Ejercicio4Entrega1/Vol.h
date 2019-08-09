/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vol.h
 * Author: johnny
 *
 * Created on 20 de marzo de 2017, 20:00
 */

#ifndef VOL_H
#define VOL_H
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>


using namespace std;
class Vol {
private:
    string codicomp, horaSor, horaArr, codiSor, codiArr,numvol;
public:
    Vol();
    virtual ~Vol();
    void set_codicomp(string);
    void set_horaSor(string);
    void set_horaArr(string);
    void set_codiSor(string);
    void set_codiArr(string);
    void set_numVol(string);
    string get_codicomp();
    string get_horaSor();
    string get_horaArr();
    string get_codiSor();
    string get_codiArr();
    string get_numVol();
};
#endif /* VOL_H */

