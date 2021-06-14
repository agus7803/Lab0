#include "hpp/dataType/dtFechaHora.hpp"
#include "hpp/dataType/dtJugador.hpp"
#include "hpp/dataType/dtPartida.hpp"
#include "hpp/dataType/dtPartidaIndividual.hpp"
#include "hpp/dataType/dtPartidaMultijugador.hpp"
#include "hpp/dataType/dtVideojuego.hpp"
#include "hpp/enumerado/tipoJuego.hpp"
#include "hpp/jugador.hpp"
#include "hpp/partidaIndividual.hpp"
#include "hpp/partida.hpp"
#include "hpp/partidaMultijugador.hpp"
#include "hpp/Sistema.hpp"
#include "hpp/videojuego.hpp"
#include "hpp/constantes.hpp"

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <exception>
#include <iomanip>
#include <stddef.h>
#include <regex>
#include <bits/stdc++.h>
using namespace std;

jugador** array_jugadores = new jugador*[MAX_JUGADORES];
int tope_Jugadores = 0;
videojuego** array_videojuegos = new videojuego*[MAX_VIDEOJUEGOS];
int tope_Videojuegos = 0;
partida** array_partidas = new partida*[MAX_PARTIDAS];
int tope_Partidas= 0;


Sistema *principal = new Sistema( array_jugadores, tope_Jugadores, array_videojuegos, tope_Videojuegos, array_partidas, tope_Partidas);

ostream& operator<<(ostream& out, dtPartida* &arryPres){
	if(arryPres != NULL){
		dtPartidaMultijugador* DtpartidaMulti = dynamic_cast<dtPartidaMultijugador *> (arryPres);
		dtPartidaIndividual* DtpartidaIndi = dynamic_cast<dtPartidaIndividual *> (arryPres);
		if(DtpartidaMulti != NULL){
			string enVivoStr;
			if(DtpartidaMulti->getTransmitidaEnVivo())
				enVivoStr = "Si";
			else
				enVivoStr = "No";
			dtFechaHora *aux = DtpartidaMulti->getFechaHora();
			out<< "- Tipo Partida:  Partida Multijugador" << endl;
			out<< "- Fecha partida: " << aux->getdia() <<"/" << aux->getmes() << "/" << aux->getanio() << endl; // DD/MM/AAAA
			out<< "- Duración partida : " << DtpartidaMulti->getDuracion() << " hs" << endl;  
			/* Solo para partidas multijugador*/
			out<<"- Transmitida en vivo:"<< enVivoStr <<endl;
			out<<"- Cantidad jugadores unidos a la partida: "<<DtpartidaMulti->getCantidadDeJugadoresUnidos() <<endl;
			out<<"- Jugadores unidos a la partida: "<<ends; //nickname1, nickname2, ..
			string * arr_player = DtpartidaMulti->getNickNameJugadoresUnidos();
			for (int i = 0; i < DtpartidaMulti->getCantidadDeJugadoresUnidos(); i++)
				out<< arr_player[i] << ", "<<ends;
		}
		else{
			string conti;
			if(DtpartidaIndi->getContinuaPartidaAnterior()){
				conti = "Si";
			}
			else{
				conti = "No";
			}
			dtFechaHora *aux = DtpartidaIndi->getFechaHora();
			out<< "- Tipo Partida: Individual" << endl;	
			out<< "- Fecha partida: " << aux->getdia() <<"/" << aux->getmes() << "/" << aux->getanio() << endl;
			out<< "- Duración partida : " << DtpartidaIndi->getDuracion() << " hs" << endl;  
			/* Solo para partidas individuales */
			out<< "Continuación de una partida anterior: "<< conti <<endl;
			}
		}
	return out;
}

void validarFecha(dtFechaHora* fecha){
	int dia = fecha->getdia();
	int mes = fecha->getmes();
	int anio = fecha->getanio();
	if(dia < 1 || dia > 31)
		throw std::invalid_argument("Atencion! El dia ingresado es incorrecto");
	else if((mes < 1) || (mes > 12))
		throw invalid_argument("Atencion! El mes ingresado es incorrecto");	
	else if(anio < 1900)
		throw invalid_argument("Atencion! El año ingresado es incorrecto");
	else{
		if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
			if((dia < 1) || (dia > 31))
				throw invalid_argument("Atencion! La fecha ingresada es incorrecta");	
		}else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
			if((dia < 1) || (dia > 30))
				throw invalid_argument("Atencion! La fecha ingresada es incorrecta");
		}else if((mes == 2) || (anio%4 == 0)){
			if((dia < 1) || (dia > 29))
				throw invalid_argument("Atencion! Febrero en años biciesto tiene 29 dias");
		}else{
			if((dia < 1) || (dia > 28)){
				throw invalid_argument("Atencion! Si el año no es biciesto Febrero tiene 28 dias");
			}
		}
	}
}
void validarDia(int dia){
    if(dia < 0 || dia > 31)
		throw std::invalid_argument("Atencion! El dia ingresado es incorrecto");
}

void validarmes(int dia, int mes){
    if(mes < 1 || mes > 12)
		throw std::invalid_argument("Atencion! El mes ingresado es incorrecto");
    else{
		if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
			if((dia < 1) || (dia > 31))
				throw invalid_argument("Atencion! La fecha ingresada es incorrecta");	
			}
			else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
					if((dia < 1) || (dia > 30))
					throw invalid_argument("Atencion! La fecha ingresada es incorrecta");
			}
    }
}

void casoDeUsoAgregarJugador(){
	string nickName;
	int edad;
	string contrasenia;
	cout << "---------------Agregar Jugador---------------" << endl<<endl;
	cout << "Ingrese el NickName (apodo) del jugador: " << endl;
	cin >> nickName;
	cin.ignore();
	cout << "Ingrese la Edad del jugador: " << endl;
	cin >> edad;
	cin.ignore();
	cout << "Ingrese la Contraseña del jugador: " << endl;
	cin >> contrasenia;
	cin.ignore();
	try{
		dtJugador *DTJ = new dtJugador(nickName, edad);
		principal->agregarJugador(DTJ->getNickName(),DTJ->getEdad(), contrasenia);
	}
	catch(invalid_argument& e){
		std::cout <<"An exception occurred " << e.what() << '\n';
	}
};

void casoDeUsoAgregarVideojuego(){
	string titulo;
	tipoJuego genero;
	int res;
	cout << "---------------Agregar Videojuego---------------" << endl<<endl;
	cout << "Ingrese el titulo del videojuego:" << endl;
	cin >> titulo;
	cin.ignore();
	cout << "Ingrese el genero del juego:" << endl;
	cout << "1- Acción" << endl;
	cout << "2- Aventura" << endl;
	cout << "3- Deporte" << endl;
	cout << "4- Otro" << endl;
	cin >> res;
	//cin.ignore();ignora espacios en blanco
	try{
		if (res == 1)
			genero = Accion;
		else if (res == 2){
			genero = Aventura;
		}else if(res == 3){
			genero = Deporte;
		}else if(res == 4){
			genero = Otro;
		}else{
			throw invalid_argument ("Genero del juego incorrecto");
		}
		dtVideojuego *DTVJ = new dtVideojuego(titulo, genero, 0); 
		principal->agregarVideojuego(DTVJ->getTitulo(), DTVJ->getGenero());
		cout << "Se Ingreso su Videojuego Correctamente" << endl;
	}
	catch(invalid_argument& e){
			std::cout <<"An exception occurred " << e.what() << '\n';
	}
};

void casoDeUsoObtenerJugadores(){
	dtJugador** arryJres = NULL;
	int topeJres = 0;
	cout << "Lista de Jugadores" << endl;
	try{
		arryJres = principal->obtenerJugadores(topeJres);
	}
	catch(invalid_argument& e){
		std::cout <<"An exception occurred " << e.what() << '\n';
	}
	for (int i = 0; i < topeJres; i++){
		cout<< endl <<"-----Jugador " << (i + 1) << "-----"<< endl;
		cout << arryJres[i]->getNickName() << endl;
		cout << arryJres[i]->getEdad() << endl;
	}
}

void casoDeUsoObtenerVideojuegos(){
	dtVideojuego** arrayVJres = NULL;
	int topeVJres = 0;
	string genStr;
	cout << "Obtener lista de Videojuegos" << endl;
	try{
		arrayVJres = principal->obtenerVideojuegos(topeVJres);
	}
	catch(invalid_argument& e){
		std::cout << "An exception occurred " << e.what() << '\n';
	}
	for (int i = 0; i < topeVJres; i++){
		cout<< endl <<"-----Videojuego " << (i + 1) << "-----"<< endl;
		cout << "Titulo: " << arrayVJres[i]->getTitulo() <<endl;
		if (arrayVJres[i]->getGenero() == Accion){
			genStr = "Accion";
		}else if(arrayVJres[i]->getGenero() == Aventura){
			genStr = "Aventura";
		}else if (arrayVJres[i]->getGenero() == Deporte){
			genStr = "Deporte";
		}else if (arrayVJres[i]->getGenero() == Otro){
			genStr = "Otro";
		}
		cout <<"Genero: " << genStr <<endl;
		cout <<"Total de horas de juego: " << arrayVJres[i]->getTotalHorasDeJuego() <<endl;
	}
}

void casoDeUsoObtenerPartidas(){
	dtPartida** arryPres = NULL;
	int topePres = 0;
	string nickvideojuego;
	cout << "Ingrese el nombre del Videojuego que desea listar sus partidas:" << endl;
	cin >> nickvideojuego;
	try{
		arryPres = principal->obtenerPartidas(nickvideojuego,topePres);
	}
	catch(invalid_argument& e){
		std::cout <<"An exception occurred " << e.what() << '\n';
	}
	cout << "Lista de Partidas:" << endl;
	for (int i = 0; i < topePres; i++){
		cout<< endl <<"-----Partidas " << (i + 1) << "-----"<< endl;
		cout << arryPres[i];
	}
	cout<< endl;
};

void casoDeUsoIniciarPartida(){
	string nickvideojuego;
	string  nickName;
	int tipoP;
	int dia;
	int mes;
	int anio;
	int hora;
	int minutos;
	int res;
	float duracion;
	bool esContinuacion;
	bool esTransmitidaEnVivo;
	cout << "---------------Iniciar partida---------------" << endl<<endl;
	cout << "Ingrese el NickName (apodo) del jugador: " << endl;
	cin >> nickName;
	cin.ignore();
	cout << "---------------Datos deL Juego---------------" << endl;
	cout << "Ingrese el Videojuego: " << endl;
	cin >> nickvideojuego;
	cin.ignore();
	cout << "---------------Ingrese los datos de la partida---------------" << endl;
	cout << "Ingrese el dia:" << endl;
	cin >> dia;
	validarDia(dia);
	cin.ignore();
	cout << "Ingrese el mes:" << endl;
	cin >> mes;
	validarmes(dia,mes);
	cin.ignore();
	cout << "Ingrese el añio:" << endl;
	cin >> anio;
	cin.ignore();
	cout << "Ingrese la hora:" << endl;
	cin >> hora;
	cin.ignore();
	cout << "Ingrese los minutos:" << endl;
	cin >> minutos;
	cin.ignore();
	cout << "Ingrese la duracion:" << endl;
	cin >> duracion;
	try{
		dtFechaHora* fecha = new dtFechaHora(dia,mes,anio,hora,minutos);
		validarFecha(fecha);
		cin.ignore();
		cout << "Ingrese el tipo de Partida:" << endl;
		cout << "1- Partida Individual" << endl;
		cout << "2- Partida Multijugador" << endl;
		cin >> tipoP;
		//cin.ignore();
		if (tipoP == 1){
			cout << "¿Es continuación de una partida ya creada?" << endl;
			cout << "1- Si" << endl;
			cout << "2- No" << endl;
			cin >> res;
			cin.ignore();
			if (res == 1){
				esContinuacion = true;
			}
			else if (res == 2){
				esContinuacion = false; 
			}
			else
				throw invalid_argument("No es una opción valida para la continuación de la partida");
		dtPartidaIndividual* datosPi = new dtPartidaIndividual (esContinuacion, fecha, duracion);
		cout << datosPi->getDuracion() << endl;
		principal->iniciarPartida(nickName, nickvideojuego, datosPi);
		}else if (tipoP == 2){
			cout << "Ingrese los Nombres de los Jugadores a unirse:" << endl;
			string *nicksJugadoresU = new string[MAX_JUGADORES];
			bool exit = false;
			int i = 0;
			nicksJugadoresU[i]=nickName;//agarra al primero
			while (!exit){
				cout << "¿Desea agregar otro jugador?" << endl;
				cout << "1- Si" << endl;
				cout << "2- No" << endl;
				cin >> res;  
				if (res == 2)
					exit = true;
				else if(res == 1){ 
					cin.ignore();
					cout << "Ingrese el Nombre del siguiente Jugador a unirse" << endl;
					cin >> nickName;
					i++;
					nicksJugadoresU[i] = nickName;//agarra a los otros
				}
				else{
					throw invalid_argument("No es una opción valida para agregar un jugador");
				}	
				
			}
			cout << "¿Es transmitida en vivo?" << endl;
			cout << "1- Si" << endl;
			cout << "2- No" << endl;
			cin >> res;
			if (res == 1){
				esTransmitidaEnVivo = true;
			}
			else if (res == 2){
				esTransmitidaEnVivo = false;
			}
			else
				throw invalid_argument("No es una opción valida para la transmición en vivo");
			dtPartidaMultijugador* datosPm = new dtPartidaMultijugador(esTransmitidaEnVivo, nicksJugadoresU, i+1, fecha, duracion);
			principal->iniciarPartida(nickName, nickvideojuego, datosPm);
		}else 
			throw invalid_argument("No es una opcion valida para el tipo de Partida");
	}
	catch(invalid_argument& e){
		std::cout <<"An exception occurred " << e.what() << '\n';
	}
}

int main(){
	int openMenu = 14; 
	while (openMenu!= 0){
		cout<<flush;
		cout<<endl<<endl<<endl<<"------------------Bienvenido------------------"<<endl<<endl;
		cout<<"------------------Elija la opcion:------------------"<<endl<<endl;
		cout<<"0  - Salir"<<endl;
		cout<<"1  - Agregar Jugador"<<endl;
		cout<<"2  - Agregar Videojuego"<<endl;
		cout<<"3  - Obtener lista de Jugadores"<<endl;
		cout<<"4  - Obtener lista de Videojuegos"<<endl;
		cout<<"5  - Obtener lista de Partidas"<<endl;
		cout<<"6  - Iniciar Partida"<<endl;	
		cout << "Opcion: " << endl;
		cin >> openMenu;
		cout << endl;
		cin.ignore();
		switch (openMenu){
			case 0: cout<< "Hasta Luego" <<endl;
			break;
			case 1: casoDeUsoAgregarJugador();
				main();
			break;
			case 2: casoDeUsoAgregarVideojuego();
			main();
			break;
			case 3: casoDeUsoObtenerJugadores();
				main();
			break;
			case 4: casoDeUsoObtenerVideojuegos();
				main();
			break;
			
			case 5: casoDeUsoObtenerPartidas();
				main();
			break;
			case 6: casoDeUsoIniciarPartida();
				main();
			break;
			default:cout << "La opcion ingresada es incorrecta" << endl;
			main();
			break;
		}
	return 1;
	}
}