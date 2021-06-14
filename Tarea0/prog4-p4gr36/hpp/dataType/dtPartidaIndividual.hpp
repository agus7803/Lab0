#ifndef DTPARTIDAINDIVIDUAL_HPP
#define DTPARTIDAINDIVIDUAL_HPP

#include "dtPartida.hpp"
#include "dtFechaHora.hpp"
#include <string>
#include <iostream>

class dtPartidaIndividual : public dtPartida {
    protected:
        bool continuaPartidaAnterior;
    public:
        //Constructores
        dtPartidaIndividual();
        dtPartidaIndividual(bool continuaPartidaAnterior, dtFechaHora* fecha, float duracion);
        //Destructores
        ~dtPartidaIndividual();
        //Getters
        dtFechaHora* getFecha();
        float getDuracion();
        bool getContinuaPartidaAnterior();
};

#endif