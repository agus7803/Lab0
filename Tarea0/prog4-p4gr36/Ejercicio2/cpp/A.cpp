#include "../hpp/A.hpp"


A::A(){
    this->asociacionB = NULL;
    this->asociacionC = NULL;
}

A::A(int a){
    this->a = a;
}

int A::getA(){
    return this->a;
}

B* A::getBdeA(){
    return this->asociacionB;
}

C* A::getCdeA(){
    return this->asociacionC;
}

void A::setB(B* b){
    this->asociacionB = b;
}

void A::setC(C* c){
    this->asociacionC = c;
}

A::~A(){}

void A::Imprimir(){
    cout<<"Clase A- "<<this->a<< endl;
}

/*
ostream& operator<<(ostream& out, A* imp){
    out<<"A-"<< imp->a << endl;
    return out;
}
*/