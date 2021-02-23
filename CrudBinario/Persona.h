#pragma once
#include <iostream>
using namespace std;
class Persona
{
	private:
		char nombre[20];
		int cedula;
		int edad;
	public:
		Persona();
		void ActualizarDatos(int, char[20], int);
		void Imprimir();
		int ObtenerCedula();
												

};

