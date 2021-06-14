#ifndef B_HPP
#define B_HPP


#include "A.hpp"
#include "C.hpp"

#include<iostream>
using namespace std;

class A;
class C;

class B {
	private:
		int b;
		A* asociacionA;
		C* asociacionC;
	public:
	    B();
	    B(int);
		int getB();
		A* getAdeB();
		C* getCdeB();
		void setA(A*);
		void setC(C*);
		~B();
		
		void Imprimir();
		
		//friend ostream& operator<<(ostream&, B*);
};


#endif