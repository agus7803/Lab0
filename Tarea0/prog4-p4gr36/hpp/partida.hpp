#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <string.h>
#include "dataType/dtFechaHora.hpp"
#include "jugador.hpp"
#include "enumerado/tipoJuego.hpp"

class partida{
    protected:
        dtFechaHora* fecha;
        float  duracion;
        jugador* iniciadorPartida;
    public:
        //Constructores
        partida();
        partida(dtFechaHora* fecha, float duracion, jugador* iniciadorPartida);
        //getters
        virtual dtFechaHora* getfecha();
        virtual float getduracion();
        jugador* getIniciador();
        //metodosaparte
        virtual float darTotalHorasParticipantes() = 0;
};
#endif
