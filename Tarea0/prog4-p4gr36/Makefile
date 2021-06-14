FLAG = -Wall -Wextra -O1 -g 


main: main.o  dtFechaHora.o dtJugador.o dtPartida.o dtPartidaIndividual.o dtPartidaMultijugador.o dtVideojuego.o jugador.o partida.o partidaIndividual.o partidaMultijugador.o videojuego.o Sistema.o
	g++  $(FLAG) -o main main.o  dtFechaHora.o dtJugador.o dtPartida.o dtPartidaIndividual.o dtPartidaMultijugador.o dtVideojuego.o jugador.o partida.o partidaIndividual.o partidaMultijugador.o videojuego.o Sistema.o

main.o: main.cpp 
	g++ $(FLAG) -c main.cpp

dtFechaHora.o: cpp/dataType/dtFechaHora.cpp
	g++ $(FLAG) -c cpp/dataType/dtFechaHora.cpp

dtJugador.o: cpp/dataType/dtJugador.cpp
	g++ $(FLAG) -c cpp/dataType/dtJugador.cpp 

dtPartida.o: cpp/dataType/dtPartida.cpp
	g++ $(FLAG) -c cpp/dataType/dtPartida.cpp

dtPartidaIndividual.o: cpp/dataType/dtPartidaIndividual.cpp
	g++ $(FLAG) -c cpp/dataType/dtPartidaIndividual.cpp 

dtPartidaMultijugador.o: cpp/dataType/dtPartidaMultijugador.cpp
	g++ $(FLAG) -c cpp/dataType/dtPartidaMultijugador.cpp 

dtVideojuego.o: cpp/dataType/dtVideojuego.cpp
	g++ $(FLAG) -c cpp/dataType/dtVideojuego.cpp 

partida.o: cpp/partida.cpp
	g++ $(FLAG) -c cpp/partida.cpp

jugador.o: cpp/jugador.cpp
	g++ $(FLAG) -c cpp/jugador.cpp 

partidaIndividual.o: cpp/partidaIndividual.cpp
	g++ $(FLAG) -c cpp/partidaIndividual.cpp

partidaMultijugador.o: cpp/partidaMultijugador.cpp
	g++  $(FLAG) -c cpp/partidaMultijugador.cpp 

videojuego.o: cpp/videojuego.cpp
	g++ $(FLAG) -c cpp/videojuego.cpp
	
Sistema.o: cpp/Sistema.cpp
	g++ $(FLAG) -c cpp/Sistema.cpp

clean:
	rm -f *.o
	rm -f  main
	
full: clean main
	./main
