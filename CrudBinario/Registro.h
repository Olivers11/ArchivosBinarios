#pragma once
#include "Persona.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdio.h> 





class Registro
{
	private:
		fstream archivo;
	public:
		void GuardarRegistro(Persona);
		void MostrarRegistros();
		void ModificarRegistro(int);
		void EliminarRegistro(int);

};

