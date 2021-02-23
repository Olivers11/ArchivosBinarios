#include "Persona.h"



Persona::Persona()
{
	strcpy_s(this->nombre, " \0");
	this->cedula = 0;
	this->edad = 0;
}



void Persona::ActualizarDatos(int c, char n[20], int e)
{
	strcpy_s(this->nombre, n);
	this->cedula = c;
	this->edad = e;
}



void Persona::Imprimir()
{
	cout << "Cedula: " << this->cedula << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Edad: " << this->edad << endl;
	cout << endl;
}


int Persona::ObtenerCedula()
{
	return this->cedula;
}