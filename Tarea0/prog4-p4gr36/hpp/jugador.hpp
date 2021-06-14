#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>
#include "./enumerado/tipoJuego.hpp"
using namespace std;

class  jugador{
    private:
        //Atributos
        string nickName;
        int edad;
        string contrasenia;
    public:
        //Contructores
        jugador();
        jugador(string nickName, int edad, string contrasenia);        
        //getters
        string getNickName();
        int getEdad();
        string getContrasenia();
        //setters
        void setNickName(string nickName);
        void setEdad(int edad); 
        void setContrasenia(string contrasenia);
        //Destructor
        ~jugador();
};
#endif