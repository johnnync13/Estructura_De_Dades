/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Johnny
 * Author: Ling
 * Created on 26 de abril de 2017, 19:41
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <exception>
#include "HeapContactFinder.h"
#include "MinHeap.h"
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

        HeapContactFinder heapContact;
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
        heapContact.appendContactList(fitxer);
        end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> bstContactFinder = end - start;
        /**
         * PUNTO 2 DEL MAIN
         * @param argc
         * @param argv
         * @return 
         */
        cout << "Mostrar la llista de Contactes" << endl;
      
            heapContact.viewIndex();
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
            if (heapContact.findContactBool(cognom)==true){
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
        std::cout << "finished computation Create BSTCONTACT at " << bstContactFinder.count() << "ms\n";
        std::cout << "finished computation FIND ALL CONTACTS at " << mill.count() << "ms\n";
        
        
        /**
         * PUNTO 4 DEL MAIN
         * @param 
         * @param 
         * @return 
         */
        
        cout <<"La profunditat de l'arbre és: " <<  heapContact.height() << endl;


    } catch (runtime_error& e) {
        cout << e.what() << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

