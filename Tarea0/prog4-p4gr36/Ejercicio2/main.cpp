#include "hpp/A.hpp"
#include "hpp/B.hpp"
#include "hpp/C.hpp"
#include<iostream>
using namespace std;

int main(){
    A* a;
    B* b; 
    C* c; 
    

    a = new A(9);
    b = new B(1);
    c = new C(3);
    
    a->setB(b);
    a->setC(c);  
    
    b->setA(a);
    b->setC(c);
        
    c->setB(b);
    c->setA(a);
    
    B* ba = a->getBdeA();
    C* ca = a->getCdeA();
    
    ba->Imprimir();
    ca->Imprimir();
    
    A* ab = b->getAdeB();
    C* cb = b->getCdeB();
    
    ab->Imprimir();
    cb->Imprimir();
    
    A* ac = c->getAdeC();
    B* bc = c->getBdeC();
    
    ac->Imprimir();
    bc->Imprimir();
    

    return 0;
};