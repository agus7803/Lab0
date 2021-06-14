#ifndef DTPARTIDAMULTIJUGADOR_H
#define DTPARTIDAMULTIJUGADOR_H

#include "dtPartida.hpp"
#include "dtJugador.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "../constantes.hpp"

using namespace std;


class dtPartidaMultijugador : public dtPartida{
protected:
    bool transmitidaEnVivo;
    //Esto devuelve un puntero a un char ya te toma todo el arreglo como un conjunto de strings.
    string* nickNameJugadoresUnidos;
    int cantidadDeJugadoresUnidos;
public:
    //constructores
    dtPartidaMultijugador();
    dtPartidaMultijugador(bool transmitidaEnVivo, string* nickNameJugadoresUnidos, int cantidadDeJugadoresUnidos, dtFechaHora* fecha, float duracion);
    //getters
    bool getTransmitidaEnVivo();
    string* getNickNameJugadoresUnidos();
    int getCantidadDeJugadoresUnidos();
    dtFechaHora* getFechaHora();
    float getDuracion();    
    //Destructor
    ~dtPartidaMultijugador();
};
#endif 