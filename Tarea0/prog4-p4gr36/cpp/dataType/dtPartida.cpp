#include "../../hpp/dataType/dtPartida.hpp"
//#include "../../hpp/dataType/dtPartidaMultijugador.hpp"
//#include "../../hpp/dataType/dtPartidaIndividual.hpp"


dtPartida::dtPartida(){
   }
dtPartida::dtPartida(dtFechaHora* fecha, float duracion){
      this->fecha = fecha;
      this->duracion = duracion;
   }
dtFechaHora* dtPartida:: getFechaHora(){
      return this->fecha;
   }
float dtPartida:: getDuracion(){
      return this->duracion;  
   }

