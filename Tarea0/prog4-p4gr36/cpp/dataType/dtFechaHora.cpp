#include "../../hpp/dataType/dtFechaHora.hpp"

//Constructores
dtFechaHora::dtFechaHora (){

}

dtFechaHora::dtFechaHora (int dia,int mes,int anio,int hora, int minuto){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}
//Geters
int dtFechaHora::getdia (){
    return this->dia;

}

int dtFechaHora::getmes (){
    return this->mes;

}
int dtFechaHora::getanio (){
    return this->anio;

}
int dtFechaHora::gethora (){
    return this->hora;

}
int dtFechaHora::getminuto (){
    return this->minuto;

}
dtFechaHora:: ~dtFechaHora(){
}


