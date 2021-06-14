#include "../hpp/partidaMultijugador.hpp" 
#include <string>
using namespace std;

//Constructor
PartidaMultijugador:: PartidaMultijugador() : partida(){}

PartidaMultijugador:: PartidaMultijugador(bool transmitidaEnVivo, dtFechaHora* fecha, float duracion, jugador* iniciadorPartida, jugador** arrayJUnidos, int topeJUnidos) : partida(fecha, duracion, iniciadorPartida) {
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->arrayJUnidos = arrayJUnidos;
    this->topeJUnidos = topeJUnidos;
};

//Destructor
PartidaMultijugador:: ~ PartidaMultijugador(){};

//Getters
bool PartidaMultijugador::getTransmitidaEnVivo(){
    return this->transmitidaEnVivo;
    }
dtFechaHora* PartidaMultijugador:: getFechaHora(){
    return partida::getfecha();
};

jugador** PartidaMultijugador::getArrayJUnidos(){
    return this->arrayJUnidos;
};

float PartidaMultijugador::getDuracion(){
    return partida::getduracion();
};    
//setters
void PartidaMultijugador:: setTransmitidaEnVivo(bool transmitidaEnVivo){
        this->transmitidaEnVivo = transmitidaEnVivo;
};
void PartidaMultijugador:: setfecha(dtFechaHora* fecha){
    this->fecha = fecha;
};
void PartidaMultijugador:: setduracion(float duracion){
    this->duracion = duracion;
};
//polimorfirmo
float PartidaMultijugador:: darTotalHorasParticipantes(){
    return partida::getduracion();
};

dtPartidaMultijugador* PartidaMultijugador::getDTJUnidos(){
    string *resJugadores = new string[topeJUnidos];
    for (int i = 0; i < topeJUnidos; i++){
        resJugadores[i] = arrayJUnidos[i]->getNickName();
    }
    return new dtPartidaMultijugador(transmitidaEnVivo, resJugadores, topeJUnidos, partida::getfecha(), partida::getduracion());
};
