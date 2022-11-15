#pragma once
#include "Poligonos.h"
class Triangulo :  public Poligonos
{
public:
	int base, altura, lado;

	Triangulo() {}
	Triangulo(int base, int altura, int lado, string type, string color, int id)
	{
		this->id = id;
		this->type = type;
		this->color = color;
		this->base = base;
		this->altura = altura;
		this->lado = lado;
	}

	void calc_area()
	{
		area = round(base * altura / 2);
	}
	void calc_perimetro() 
	{
		perimetro = round(lado * 3);
	}
};

