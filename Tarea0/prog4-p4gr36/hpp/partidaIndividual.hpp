#ifndef PARTIDAINDIVIDUAL_HPP
#define PARTIDAINDIVIDUAL_HPP
#include "partida.hpp"
#include "dataType/dtFechaHora.hpp"
#include "dataType/dtPartidaIndividual.hpp"
#include "dataType/dtPartida.hpp"


class partidaIndividual : public partida{
    protected:
        bool continuaPartidaAnterior;
    public:
        //Constructores
        partidaIndividual();
        partidaIndividual(bool continuaPartidaAnterior, dtFechaHora* fecha, float  duracion, jugador* iniciadorPartida);
        //Destructores
        ~partidaIndividual();
        //Setters
        void setPartidaAnterior(bool);
        void setFecha(dtFechaHora* fecha);
        void setDuracion(float duracion);
        //Getters
        bool  getPartidaAnterior();
        dtFechaHora* getfecha();
        float getduracion();
        float darTotalHorasParticipantes();
};
#endif