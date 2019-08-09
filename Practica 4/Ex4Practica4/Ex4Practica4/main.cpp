/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Johnny
 *
 * Created on 27 de mayo de 2017, 18:12
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <exception>
#include "HashMapContactFinder.h"
#include "HashMap.h"
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        /* C++11-Style */
        std::chrono::time_point<std::chrono::system_clock> start, end;

        HashMapContactFinder hashContact;
        string fitxer, cognom, resposta;
        Contacte contact;
        ifstream isf("directori.txt");
        cout << "Quin fitxer vols (P/G)?" << endl;
        cin >> fitxer;
        /**
         * PUNTO 1 DEL MAIN
         * @param argc
         * @param argv
         * @return 
         */
        start = std::chrono::system_clock::now();
        hashContact.appendContactList(fitxer);
        end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> bstContactFinder = end - start;
        /**
         * PUNTO 2 DEL MAIN
         * @param argc
         * @param argv
         * @return 
         */
        cout << "Mostrar la llista de Contactes" << endl;
      
            hashContact.viewIndex();
            cout<<endl;
        
        /**
         * PUNTO 3 DEL MAIN
         * @param argc
         * @param argv
         * @return 
         */
        start = std::chrono::system_clock::now();
        int contactesTrobats=0;
        int contactesNoTrobats=0;
        while (!isf.eof()) {
            isf >> cognom;
            std::transform(cognom.begin(), cognom.end(), cognom.begin(), ::tolower);
            if (hashContact.findContactBool(cognom)==true){
                ++contactesTrobats;
            }
            else {
                ++contactesNoTrobats;
            }
            

        }
        end = std::chrono::system_clock::now();
        cout << "Contactes Trobats: " << contactesTrobats << endl;
        cout << "Contactes No Trobats: " << contactesNoTrobats << endl;

        std::chrono::duration<double, std::milli> mill = end - start;
        std::cout << "finished computation Create HashContact at " << bstContactFinder.count() << "ms\n";
        std::cout << "finished computation FIND ALL CONTACTS at " << mill.count() << "ms\n";


        /**
         * PUNTO 4 DEL MAIN
         * @param 
         * @param 
         * @return 
         */
        int numCeldas = hashContact.getNumCeldas();
        cout << "el numero de celdas de la tabla hash: " << numCeldas << endl;
        cout << "el numero de colisiones que han producido: " << hashContact.getNumColisions() << endl;
        cout << "el numero de elementos que tiene la celda mas grande: " << hashContact.getNumElementsMaxCelda() << endl;
        cout << "celdas llenas: " << hashContact.getCeldasOcupades() << endl;
        float celdasvacias = numCeldas - hashContact.getCeldasOcupades();
        float porcentaje = (celdasvacias / numCeldas) * 100.;
        cout << "el porcentaje de celdas vacias de la tabla Hash: " << porcentaje << endl;


    } catch (runtime_error& e) {
        cout << e.what() << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}



