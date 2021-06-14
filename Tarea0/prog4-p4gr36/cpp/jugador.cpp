#include "../hpp/jugador.hpp" 
        
            
jugador::jugador(){

}
jugador::jugador(string nickName, int edad, string contrasenia){
    this->nickName = nickName;
    this->edad = edad;
    this->contrasenia = contrasenia;
}        
//getters
string jugador:: getNickName(){
    return this->nickName;

}
int jugador:: getEdad(){
    return this->edad;
}
string jugador:: getContrasenia(){
    return this->contrasenia;

}
//setters
void jugador:: setNickName(string nickName){
    this->nickName = nickName;


}
void jugador:: setEdad(int edad){
    this->edad = edad;

} 
void jugador:: setContrasenia(string contrasenia){
    this->contrasenia = contrasenia;
}
//Destructor
jugador::~jugador(){

}