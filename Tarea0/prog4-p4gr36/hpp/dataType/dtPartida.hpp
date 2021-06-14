#ifndef DTPARTIDA_HPP
#define DTPARTIDA_HPP

#include "dtFechaHora.hpp"
#include <string>
#include <iostream>
using namespace std;

class dtPartida{
    protected:
        dtFechaHora* fecha;
        float  duracion;
    public:
        //Constructores
        dtPartida();
        dtPartida(dtFechaHora* fecha, float duracion);
        //getters
        virtual dtFechaHora* getFechaHora();
        virtual float getDuracion();
        //friend ostream& operator<<(ostream& out, dtPartida* partidaaux);
};
#endif



