#include "../hpp/Sistema.hpp"
#include "../hpp/constantes.hpp"
#include <string>
#include "../hpp/partida.hpp"
#include "../hpp/videojuego.hpp"
#include "../hpp/jugador.hpp"
#include "../hpp/partidaIndividual.hpp"
#include "../hpp/partidaMultijugador.hpp"
#include "../hpp/dataType/dtJugador.hpp"
#include "../hpp/dataType/dtPartida.hpp"
#include "../hpp/dataType/dtVideojuego.hpp"
#include "../hpp/dataType/dtPartidaIndividual.hpp"
#include "../hpp/dataType/dtPartidaMultijugador.hpp"
#include "../hpp/enumerado/tipoJuego.hpp"
using namespace std;


//Contructores
Sistema::Sistema(){
};

Sistema:: Sistema(jugador** array_jugadores, int tope_Jugadores, videojuego** array_videojuegos, int tope_Videojuegos, partida** array_partidas, int tope_Partidas){
    this->array_jugadores = array_jugadores;
    this->array_videojuegos = array_videojuegos;
    this->array_partidas = array_partidas;

    this->tope_Jugadores = tope_Jugadores;
    this->tope_Videojuegos = tope_Videojuegos;
    this->tope_Partidas = tope_Partidas;   
};
/*
Registra un nuevo jugador en el sistema. Si ya existe un jugador registrado con el mismo nickname, se
lanza una excepción de tipo std::invalid_argument.
*/
void Sistema::agregarJugador(string nickname, int edad, string contrasenia){
    int i = 0;
    if (this->tope_Jugadores < MAX_JUGADORES){
        while (i < this->tope_Jugadores && nickname != this->array_jugadores[i]->getNickName())
            i++;
        if(i < this->tope_Jugadores) //PN: Encontramos el nick repetido
            throw invalid_argument("Nombre existente " + nickname); //devolver la instancia con el texto adentro 
        else{
            //Creamos jugador con new y asignamos a la posicion de tope +1 y sumamos al tope
            jugador* nuevoj = new jugador(nickname , edad, contrasenia);
            this->array_jugadores[this->tope_Jugadores]= nuevoj;
            this->tope_Jugadores ++;
            cout << "Se creo correctamente el Jugador en el Sistema." << '\n' << endl;
        }
    }
    else //Entra aca si ya excedio la cantidad maxima de jugadores
        throw invalid_argument("Cantidad de Jugadores excedida");
}

/*
Registra un nuevo videojuego en el sistema. Si ya existe un videojuego registrado con el mismo
nombre, se lanza una excepción de tipo std::invalid_argument.
*/
void Sistema:: agregarVideojuego(string nombre, tipoJuego genero){
    int i = 0;
    if (this->tope_Videojuegos < MAX_VIDEOJUEGOS){
        while (i < this->tope_Videojuegos && nombre != this->array_videojuegos[i]->getNombre())
            i++;
        if(i < tope_Videojuegos ) //FA:  Encontramos el Juego Repetido
            throw invalid_argument("Nombre existente " + nombre);// lo mismo que la funcion anterior
        else{//Creamos jugador con new y asignamos a la posicion de tope +1 y sumamos al tope
            partida **array_partidas = new partida*[MAX_PARTIDAS];
            for (int i = 0; i <= MAX_PARTIDAS; i++){
                array_partidas[i] = NULL;
            }
            videojuego *nuevoVj = new videojuego(nombre, genero, array_partidas, 0);// creamos el video juego y le mandamos 0 en el tope 
            this->array_videojuegos[this->tope_Videojuegos] = nuevoVj;  
            this->tope_Videojuegos++;  
        }
    }
    else
        throw invalid_argument("Cantidad excedida, Comuniquese con el administrador");
};

/*
Devuelve un arreglo con información sobre los jugadores registrados en el sistema. El parámetro
cantJugadores es un parámetro de salida donde se devuelve la cantidad de jugadores devueltos
por la operación (corresponde a la cantidad de instancias de DtJugador retornadas).
*/

dtJugador** Sistema::obtenerJugadores(int& cantJugadores){
    cantJugadores = this->tope_Jugadores; 
    dtJugador **res = new dtJugador*[cantJugadores];
    int i = 0;
    while (i < cantJugadores)
    {
        res[i] = new dtJugador(this->array_jugadores[i]->getNickName(), this->array_jugadores[i]->getEdad()); //mappeo a dtJugador
        i++;
    }
    return res;
};

/*
Devuelve un arreglo con información sobre los videojuegos registrados en el sistema. El parámetro
cantVideojuegos es un parámetro de salida donde se devuelve la cantidad de jugadores
devueltos por la operación (corresponde a la cantidad de instancias de DtVideojuego retornadas).
El atributo totalHorasDeJuego corresponde a la suma de horas jugadas por todos los jugadores
del videojuego. Esto debe calcularse sumando las horas devueltas por las invocaciones a
darTotalHorasParticipantes() sobre cada partida del juego. Si la partida es individual, la
cantidad de horas devuelta por dicha operación es igual a su duración, mientras que si es multijugador
devuelve su duración multiplicada por la cantidad de participantes de la partida.
*/

dtVideojuego** Sistema::obtenerVideojuegos(int& cantVideojuegos){
    cantVideojuegos = this->tope_Videojuegos;
    dtVideojuego **res = new dtVideojuego*[cantVideojuegos];
    int i = 0;
    float horaTotalPartidas = 0;
    partida **aux = NULL;
    while (i < cantVideojuegos){
        aux = this->array_videojuegos[i]->getpartidas();
        if (aux[i] != NULL){
            for (int  j = 0; j < this->array_videojuegos[i]->getTopePartidas(); j++){
                horaTotalPartidas = aux[j]->getduracion() + horaTotalPartidas;
            }
        }else
            horaTotalPartidas = 0;
        res[i] = new dtVideojuego(this->array_videojuegos[i]->getNombre(), this->array_videojuegos[i]->getGenero(), horaTotalPartidas); //mappeo a dtJugador
        i++;
    }
    return res;
};

/*
Devuelve un arreglo con información de las partidas del videojuego identificado por videojuego.
El parámetro cantPartidas es un parámetro de salida donde se devuelve la cantidad de partidas 
devueltas por la operación (corresponde a la cantidad de instancias de DtPartida retornadas).
Entre los datos devueltos para ambos tipos de partida se encuentra la duración. Además, entre los
específicos de cada partida individual se encuentra si la misma es o no continuación de una partida
anterior, mientras que para cada partida multijugador se indica si la misma es transmitida en vivo y la
cantidad total de jugadores que se unen a la misma junto con sus nicknames. Si no existe un
videojuego registrado con el nombre enviado, se lanza una excepción de tipo
std::invalid_argument.

*/

dtPartida** Sistema::obtenerPartidas(string videojuego, int& cantPartidas){
    cantPartidas = this->tope_Partidas; //this->array_videojuegos[i]->getTopePartidas()
    int i = 0;
    partida** arrresP = NULL;
    dtPartida** res = NULL; //new dtPartida*[cantPartidas];//arrays de dtpartidas para hacer una copia "limpia" 
    while (i < this->tope_Videojuegos && videojuego != this->array_videojuegos[i]->getNombre())
        i++;
    if (i == this->tope_Videojuegos){ //NO LO ENCONTRO
        throw invalid_argument("Videojuego no encontrado" + videojuego);
    }
    else{
        arrresP = this->array_videojuegos[i]->getpartidas();
        cantPartidas = this->array_videojuegos[i]->getTopePartidas();
        res = new dtPartida* [cantPartidas];
        for (int j = 0; j < cantPartidas; j++){
            partidaIndividual* dynauxI = dynamic_cast<partidaIndividual*> (arrresP[j]);
            PartidaMultijugador* dynauxM = dynamic_cast<PartidaMultijugador*> (arrresP[j]);
            if (dynauxI != NULL){
                res[j] = new dtPartidaIndividual(dynauxI->getPartidaAnterior(),dynauxI->getfecha(), dynauxI->getduracion());
            }else{
                res[j] = dynauxM->getDTJUnidos();
            }
        }
    }
    return res;
};

/*
Registra una partida individual o multijugador del videojuego identificado por videojuego,
iniciada por el jugador identificado por nickname. El parámetro de entrada datos contiene la
información completa de la partida. Entre los datos comunes a ambos tipos de partida se encuentra la
duración. Además, si datos es una instancia de DtPartidaIndividual contiene si la partida
es o no una continuación de una partida anterior, mientras que si es un instancia de
DtPartidaMultijugador, indica si la partida es transmitida en vivo y la cantidad total de
jugadores que se unen a la misma junto con sus nicknames. La partida se da de alta con la fecha del
sistema al momento del registro. Si no existe un jugador o videojuego registrado con el nickname y
nombre enviados, se lanza una excepción de tipo std::invalid_argument.

*/

void Sistema::iniciarPartida(string nickname, string videojuego, dtPartida* datos){
    dtPartidaIndividual* partidaIn = dynamic_cast<dtPartidaIndividual*> (datos);
    dtPartidaMultijugador* partidaMulti = dynamic_cast<dtPartidaMultijugador*> (datos);
    if (this->tope_Partidas != MAX_PARTIDAS){
        int ii = 0;
        while (ii < this->tope_Jugadores && this->array_jugadores[ii]->getNickName() != nickname)
            ii++;
        if (ii >= this->tope_Jugadores){
            throw invalid_argument("No existe el anfitrion " +  nickname);
        }
        int jj = 0;
        
        while (jj < this->tope_Videojuegos && this->array_videojuegos[jj]->getNombre() != videojuego){
            jj++;
        }
            
        if(jj >= this->tope_Videojuegos)
            throw invalid_argument("No existe juego " + videojuego);
        if (partidaIn != NULL){ // si es una instancia de dt partida individual        
            partidaIndividual* NewParIn = new partidaIndividual(partidaIn->getContinuaPartidaAnterior(), partidaIn->getFecha(), partidaIn->getDuracion(), this->array_jugadores[ii]);
            this->array_videojuegos[jj]->setpartidas(NewParIn);
            this->tope_Partidas++;
        }else{// si es una instacia de partida multijugador
            string* arr_nickname = new string[MAX_JUGADORES];
            arr_nickname = partidaMulti->getNickNameJugadoresUnidos(); 
            jugador **JUnidos = new jugador*[partidaMulti->getCantidadDeJugadoresUnidos()];
            int indice = 0;
            for(int ii = 0; ii <= partidaMulti->getCantidadDeJugadoresUnidos(); ii++){ //reviso si los jugadores que ingreso el usuario son los que estan en el sistema
                indice = 0;
                while (indice < this->tope_Jugadores && arr_nickname[ii].compare(this->array_jugadores[indice]->getNickName()) != 0){
                    JUnidos[indice] = this->array_jugadores[indice];
                    indice++;     
                }
                if (indice > this->tope_Jugadores)    
                    throw invalid_argument("No existe el jugador " + arr_nickname[ii]);
            }
            PartidaMultijugador* NewParMul = new  PartidaMultijugador(partidaMulti->getTransmitidaEnVivo(),partidaMulti->getFechaHora(),partidaMulti->getDuracion() * partidaMulti->getCantidadDeJugadoresUnidos(),this->array_jugadores[ii], JUnidos, partidaMulti->getCantidadDeJugadoresUnidos());
            this->array_videojuegos[jj]->setpartidas(NewParMul);
            this->tope_Partidas++;
        }
    }
}; 

//Get
int Sistema::getTopeJugadores(){
    return this->tope_Jugadores;
};
int Sistema::getTopeJuegos(){
    return this->tope_Videojuegos;
};
int Sistema::getTopePartidas(){
    return this->tope_Partidas;
};
//Seters
void Sistema::setTopeJugadores(int tope_Jugadores){
    this->tope_Jugadores = tope_Jugadores;
};
void Sistema::setTopeJuegos(int tope_Videojuegos){
    this->tope_Videojuegos = tope_Videojuegos;
};
void Sistema::setTopePartidas(int tope_Partidas){
    this->tope_Partidas = tope_Partidas;
};
//Destructor
Sistema::~Sistema(){
};

