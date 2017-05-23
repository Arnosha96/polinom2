#include "polinom.h"
#include "CircleList.h"
#include "monom.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Polynom A, B,C;
	A.get_MyList("1x^2y^3z+xyz");
	cout <<endl<< "A=";
	A.getPolynom();
	B.get_MyList("x^4-xyz+80x^2y^3z");
	cout <<endl<< "B=";
	B.getPolynom();
	cout <<endl<< "A + B = ";
	C = A + B;
	C.getPolynom();
	cout <<  endl<< "A * B = ";
	C = A*B;
	C.getPolynom();
	_getch();
	return 0;

	
}
