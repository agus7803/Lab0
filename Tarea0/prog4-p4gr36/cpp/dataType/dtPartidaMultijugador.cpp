#include "../../hpp/dataType/dtPartidaMultijugador.hpp"
//constructores
dtPartidaMultijugador::dtPartidaMultijugador():dtPartida(){
    
}
dtPartidaMultijugador::dtPartidaMultijugador(bool transmitidaEnVivo, string* nickNameJugadoresUnidos, int cantidadDeJugadoresUnidos, dtFechaHora* fecha, float duracion):dtPartida(fecha,duracion){
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->nickNameJugadoresUnidos = nickNameJugadoresUnidos;
    this->cantidadDeJugadoresUnidos = cantidadDeJugadoresUnidos;
}

//getters
bool dtPartidaMultijugador::getTransmitidaEnVivo(){
    return this->transmitidaEnVivo;

}
string *dtPartidaMultijugador:: getNickNameJugadoresUnidos(){
    return this->nickNameJugadoresUnidos;

}
int dtPartidaMultijugador::getCantidadDeJugadoresUnidos(){
    return this->cantidadDeJugadoresUnidos;

}
dtFechaHora* dtPartidaMultijugador::getFechaHora(){
    return dtPartida::getFechaHora();
}
float dtPartidaMultijugador:: getDuracion(){
    return dtPartida::getDuracion();
}    
//Destructor
dtPartidaMultijugador:: ~dtPartidaMultijugador(){
    
}