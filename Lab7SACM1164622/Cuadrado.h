#pragma once
#include "Poligonos.h"
#include "Rectangulo.h"
class Cuadrado : public Poligonos
{
public:
	double lado;
	Cuadrado() {}
	Cuadrado(double lado, string type, string color, int id)
	{
		this->id = id;
		this->type = type;
		this->color = color;
		this->lado = lado;
	}
	void calc_area()
	{
		area = round(lado * lado);
	}
	void calc_perimetro()
	{
		perimetro = round(4 * lado);
	}
};