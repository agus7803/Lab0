#include "../../hpp/dataType/dtJugador.hpp"


//Constructores
dtJugador:: dtJugador(){

};
dtJugador:: dtJugador(string nickName, int edad){
    this->nickName = nickName;
    this->edad = edad;
};
//Destructor
dtJugador::~dtJugador(){

};
//Getters
string dtJugador:: getNickName(){
    return this->nickName;
};
int dtJugador::  getEdad(){
    return this->edad;
};

