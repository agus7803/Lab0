#ifndef PARTIDAMULTIJUGADOR_HPP
#define PARTIDAMULTIJUGADOR_HPP

#include "partida.hpp"
#include "jugador.hpp"
#include "dataType/dtFechaHora.hpp"
#include "dataType/dtPartidaMultijugador.hpp"
#include <string>
#include <iostream>


class PartidaMultijugador : public partida {
    protected:
        bool transmitidaEnVivo;
        jugador** arrayJUnidos;
        int topeJUnidos;
    public:
        //constructores
        PartidaMultijugador();
        PartidaMultijugador(bool transmitidaEnVivo, dtFechaHora* fecha, float duracion, jugador* iniciadorPartida, jugador** arrayJUnidos, int topeJUnidos);
        //getters
        bool getTransmitidaEnVivo();
        dtFechaHora* getFechaHora();
        float getDuracion();
        jugador** getArrayJUnidos();
        dtPartidaMultijugador* getDTJUnidos();    
        //setters
        void setTransmitidaEnVivo(bool transmitidaEnVivo);
        void setfecha(dtFechaHora* fecha);
        void setduracion(float duracion);
        //Polimorfismo
        float darTotalHorasParticipantes();
        //Destructor
        ~PartidaMultijugador();
};
#endif