#include "../../hpp/dataType/dtVideojuego.hpp"

//constructor
dtVideojuego::dtVideojuego(string titulo, tipoJuego genero, float totalHorasDeJuego){
    this->titulo = titulo;
    this->genero = genero;
    this->totalHorasDeJuego = totalHorasDeJuego;
};
dtVideojuego::dtVideojuego(){

};
//getters
string dtVideojuego::getTitulo(){
    return this->titulo;
};
tipoJuego dtVideojuego::getGenero(){
    return this->genero;
};
float dtVideojuego::getTotalHorasDeJuego(){
    return this->totalHorasDeJuego;
};
//destructor
dtVideojuego::~dtVideojuego(){
    
};