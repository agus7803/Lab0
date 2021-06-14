#include "../hpp/partidaIndividual.hpp" 


partidaIndividual:: partidaIndividual() : partida(){

}

partidaIndividual:: partidaIndividual(bool continuaPartidaAnterior, dtFechaHora* fecha, float duracion, jugador* iniciadorPartida) : partida(fecha, duracion, iniciadorPartida){
    this->continuaPartidaAnterior = continuaPartidaAnterior;
}

partidaIndividual:: ~partidaIndividual(){

}

void partidaIndividual:: setPartidaAnterior(bool continuaPartidaAnterior){
    this->continuaPartidaAnterior = continuaPartidaAnterior;
}

void partidaIndividual:: setFecha(dtFechaHora* fecha){
    this->fecha = fecha;
}

void partidaIndividual:: setDuracion(float duracion){
    this->duracion = duracion;
}

bool partidaIndividual:: getPartidaAnterior(){
    return this->continuaPartidaAnterior;
}

dtFechaHora* partidaIndividual:: getfecha(){
    return partida::getfecha();
}

float partidaIndividual:: getduracion(){
    return partida::getduracion();
}

float partidaIndividual:: darTotalHorasParticipantes(){
    return partida::getduracion();
}

