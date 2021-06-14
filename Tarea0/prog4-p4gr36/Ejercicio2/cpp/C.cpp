#include "../hpp/C.hpp"

C::C(){
    this->asociacionB = NULL;
    this->asociacionA = NULL;
}

C::C(int c){
    this->c = c;

}

int C::getC(){
    return this->c;
}

B* C::getBdeC(){
    return this->asociacionB;
}

A* C::getAdeC(){
    return this->asociacionA;
}

void C::setB(B* b){
    this->asociacionB = b;
}

void C::setA(A* a){
    this->asociacionA = a;
}

C::~C(){}

void C::Imprimir(){
    cout<<"Clase C- "<<this->c<< endl;
}
