#ifndef DTVIDEOJUEGO_H
#define DTVIDEOJUEGO_H

#include <iostream>
#include "../enumerado/tipoJuego.hpp"
#include <string>
#include <iostream>
using namespace std;

class dtVideojuego{
private:
    string titulo;
    tipoJuego genero;
    float totalHorasDeJuego;
public:
    //constructor
    dtVideojuego(string titulo, tipoJuego genero, float totlaHorasDeJuego);
    dtVideojuego();
    //getters
    string getTitulo();
    tipoJuego getGenero();
    float getTotalHorasDeJuego();
    //destructor
    ~dtVideojuego();
};



#endif

