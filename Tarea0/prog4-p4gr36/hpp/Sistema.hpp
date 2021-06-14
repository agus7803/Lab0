#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <string>
#include <iostream>
#include "partida.hpp"
#include "videojuego.hpp"
#include "jugador.hpp"
#include "dataType/dtJugador.hpp"
#include "dataType/dtPartida.hpp"
#include "dataType/dtVideojuego.hpp"
using namespace std;

class Sistema {
    private:
        jugador** array_jugadores;
        int tope_Jugadores;
        videojuego** array_videojuegos;
        int tope_Videojuegos;
        partida** array_partidas; 
        int tope_Partidas;
    public:
    //Contructores
    Sistema();
    Sistema(jugador** array_jugadores, int tope_Jugadores, videojuego** array_videojuegos, int tope_Videojuegos, partida** array_partidas, int tope_Partidas);
    //Get
    int getTopeJugadores();
    int getTopeJuegos();
    int getTopePartidas();
    //Seters
    void setTopeJugadores(int tope_Jugadores);
    void setTopeJuegos(int tope_Videojuegos);
    void setTopePartidas(int tope_Partidas);
    
    //operaciones
    void agregarJugador(string nickname, int edad, string contrasenia);
    void agregarVideojuego(string nombre, tipoJuego genero);
    dtJugador** obtenerJugadores(int& cantJugadores);
    dtVideojuego** obtenerVideojuegos(int& cantVideojuegos);
    dtPartida** obtenerPartidas(string videojuego, int& cantPartidas);
    void iniciarPartida(string nickname, string videojuego, dtPartida* datos);
    //Destructor
    ~Sistema();
};

#endif