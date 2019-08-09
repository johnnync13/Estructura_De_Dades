/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johnny
 *
 * Created on 20 de marzo de 2017, 20:00
 */

#include <cstdlib>
#include "Vol.h"
#include "ArrayQueue.h"
void introducirVuelo(Vol &);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Vol vol_1;
    introducirVuelo(vol_1);
    return 0;
}
/**
 * Introducir vuelo en la cola
 * @param vol_1
 */
void introducirVuelo(Vol &vol_1) {
    cout << "Codi de la companyia de vol (per exemple, EW): " << endl;
    vol_1.set_codicomp();
    cout << "Número de vol (per exemple, 1234) " << endl;
    vol_1.set_numVol();
    cout << "Hora de sortida (per exemple, 10:20) " << endl;
    vol_1.set_horaSor();
    cout << "Hora d'arribada (per exemple, 11:45) " << endl;
    vol_1.set_horaArr();
    cout << "Codi de l'aeroport de sortida (per exemple, BCN): " << endl;
    vol_1.set_codiSor();
    cout << "Codi de l'aeroport d'arribada (per exemple, NYC): " << endl;
    vol_1.set_codiArr();
    ArrayQueue cola;
    cola.enqueue(vol_1);
    cola.print();
    cola.dequeue();

}

