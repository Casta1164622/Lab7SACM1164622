#pragma once
#include "Poligonos.h"
class Rectangulo : public Poligonos
{
public:
	int base;
	int altura;

	Rectangulo() {}
	Rectangulo(int base, int altura ,string type, string color, int id)
	{
		this->id = id;
		this->type = type;
		this->color = color;
		this->base = base;
		this->altura = altura;
	}
	void calc_area()
	{
		area = round(base * altura);
	}
	void calc_perimetro()
	{
		perimetro = round((2 *base)+(2*altura));
	}
};
