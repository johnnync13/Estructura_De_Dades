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



class Vol {
private:
    std::string codicomp, horaSor, horaArr, codiSor, codiArr;
    int numvol;
public:
    Vol();
    virtual ~Vol();
    void set_codicomp();
    void set_horaSor();
    void set_horaArr();
    void set_codiSor();
    void set_codiArr();
    void set_numVol();
    std::string get_codicomp();
    std::string get_horaSor();
    std::string get_horaArr();
    std::string get_codiSor();
    std::string get_codiArr();
    int get_numVol();
};
#endif /* VOL_H */

