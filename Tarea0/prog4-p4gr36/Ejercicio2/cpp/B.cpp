#include "../hpp/B.hpp"

B::B(){
    this->asociacionA = NULL;
    this->asociacionC = NULL;
}

B::B(int b){
    this->b = b;
}

int B::getB(){
    return this->b;
}

A* B::getAdeB(){
    return this->asociacionA;
}

C* B::getCdeB(){
    return this->asociacionC;
}

void B::setA(A* a){
    this->asociacionA = a;
}

void B::setC(C* c){
    this->asociacionC = c;
}

B::~B(){}

void B::Imprimir(){
    cout<<"Clase B- "<<this->b<< endl;
}
/*
ostream& operator<<(ostream& out, B* imp){
    out<<"B-"<< imp->b << endl;
    return out;
}*/
