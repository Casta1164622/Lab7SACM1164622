#include <string>
#include <sstream>
using namespace std;

#pragma once
class Poligonos
{
public:
	int id;
	string type; // 0 triangulo, 1 rectangulo, 2 cuadrado
	double area;
	double perimetro;
	string color;

	Poligonos() {}

	void calc_area() {}
	void calc_perimetro() {}

};

