
#include "../hpp/partida.hpp" 

partida::partida(){
};

partida::partida(dtFechaHora* fecha, float duracion, jugador* iniciadorPartida){
    this->fecha = fecha;
    this->duracion = duracion;
    this->iniciadorPartida = iniciadorPartida ; 
};

dtFechaHora* partida::getfecha(){
    return this->fecha;
};
float partida::getduracion(){
    return this->duracion;
};
jugador* partida::getIniciador(){
    return this->iniciadorPartida;
};