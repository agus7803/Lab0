#ifndef DTJUDADOR_H
#define DTJUDADOR_H

#include <string>
#include <iostream>
using namespace std;

class dtJugador {
    private:
        string nickName;
        int edad;
    public:
        //Constructores
        dtJugador();
        dtJugador(string nickName, int edad);
        //Destructor
        ~dtJugador();
        //Getters
        string getNickName();
        int getEdad();
};
#endif