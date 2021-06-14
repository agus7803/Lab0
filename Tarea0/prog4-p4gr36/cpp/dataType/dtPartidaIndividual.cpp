#include "../../hpp/dataType/dtPartidaIndividual.hpp"

dtPartidaIndividual::dtPartidaIndividual():dtPartida(){

};

dtPartidaIndividual::dtPartidaIndividual(bool continuaPartidaAnterior, dtFechaHora* fecha, float duracion):dtPartida(fecha,duracion){
    this->continuaPartidaAnterior = continuaPartidaAnterior;
};

dtPartidaIndividual::~dtPartidaIndividual(){
    
};

dtFechaHora* dtPartidaIndividual::getFecha(){
    return dtPartida::getFechaHora();
};

float dtPartidaIndividual::getDuracion(){
    return dtPartida::getDuracion();
};

bool dtPartidaIndividual::getContinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;
};
