#include "../hpp/videojuego.hpp" 



//Contructores
videojuego::videojuego(string nombre, tipoJuego genero, partida** arr_partidas, int tope_P){
    this->nombre = nombre;
    this->genero = genero;
    this->arr_partidas = arr_partidas;
    this->tope_P = tope_P;
};

videojuego::videojuego(){

};

//Getters
string videojuego::getNombre(){
    return this->nombre;
};

tipoJuego videojuego::getGenero(){
    return this->genero;
};

partida** videojuego::getpartidas(){
    return this->arr_partidas;
};

int videojuego::getTopePartidas(){
    return this->tope_P;
};

//Setters
void videojuego::setNombre(string nombre){
    this->nombre = nombre;
};

void videojuego::setGenero(tipoJuego genero){
    this->genero = genero;
};
void videojuego::setpartidas(partida* partidaagregar){
    int topeaux = this->tope_P;
    this->arr_partidas[topeaux] = partidaagregar;
    this->tope_P++;
};
void videojuego::setTopePartidas(int i){
    this->tope_P = i;
};
//Destructor
videojuego::~videojuego(){

};