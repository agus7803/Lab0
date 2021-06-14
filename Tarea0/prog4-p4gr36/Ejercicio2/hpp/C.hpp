#ifndef C_HPP
#define C_HPP


#include "A.hpp"
#include "B.hpp"

#include<iostream>
using namespace std;


class A;
class B;

class C {
	private:
		int c;
		A* asociacionA;
		B* asociacionB;
	public:
	    C();
	    C(int);
		int getC();
		A* getAdeC();
		B* getBdeC();
		
		void setB(B*);
		void setA(A*);
		~C();
		
		void Imprimir();
		
		//friend ostream& operator<<(ostream&, C*);
};
#endif