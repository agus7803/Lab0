#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP

#include <string>
#include "partida.hpp"
#include "enumerado/tipoJuego.hpp"
using namespace std;


class videojuego{
    private:
        string nombre;
        tipoJuego genero;
        partida **arr_partidas;
        int tope_P;
    public:
        //Contructores
        videojuego();
        videojuego(string nombre, tipoJuego genero,partida** arr_partidas, int tope_P);
        //Getters
        string getNombre();
        tipoJuego getGenero();
        partida** getpartidas();
        int getTopePartidas();
        //Setters
        void setNombre(string nombre); 
        void setGenero(tipoJuego genero);
        void setpartidas(partida* arr_partidas);
        void setTopePartidas(int tope_P);
        //Destructor
        ~videojuego();
};
#endif