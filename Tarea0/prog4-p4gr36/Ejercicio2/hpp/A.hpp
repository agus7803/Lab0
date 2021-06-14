#ifndef A_HPP
#define A_HPP

#include "B.hpp"
#include "C.hpp"
#include<iostream>
using namespace std;


class C;
class B;

class A {
	private:
		int a;
		B* asociacionB;
		C* asociacionC;
	public:
	    A();
	    A(int);
		int getA();
		C* getCdeA();
		B* getBdeA();
		void setC(C*);
		void setB(B*);		
		~A();
		void Imprimir();
};
#endif
