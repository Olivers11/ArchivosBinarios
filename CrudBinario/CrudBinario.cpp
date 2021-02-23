// CrudBinario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Persona.h"
#include "Registro.h"
using namespace std;
#define CL system("cls")
#define PA system("pause")

int main()
{
	Registro registro;
	int opcion;
	do
	{
		CL;
		cout << "[1] Nuevo Registro \n";
		cout << "[2] Mostrar Registros \n";
		cout << "[3] Modificar Registro \n";
		cout << "[4] Eliminar Registro \n";
		cout << "[5] Salir \n";
		cout << "opcion: ";
		cin >> opcion;
		
		if (opcion == 1)
		{
			CL;
			string nombre;
			int cedula;
			int edad;
			cout << "Cedula: "; cin >> cedula;
			cout << "Edad: "; cin >> edad;
			cout << "Nombre: "; 
			cin >> nombre;


			
			
			Persona nueva = Persona();
			nueva.ActualizarDatos(cedula, _strdup(nombre.c_str()), edad);
			registro.GuardarRegistro(nueva);
			PA;
		}
		else if (opcion == 2)
		{
			CL;
			cout << "REGISTROS \n";
			registro.MostrarRegistros();
			PA;
		}
		else if (opcion == 3)
		{
			CL;
			int id;
			cout << "Cedula de la persona a modificar: "; cin >> id;
			registro.ModificarRegistro(id);
			PA;
		}
		else if(opcion == 4)
		{
			CL;
			int id;
			cout << "Cedula de la persona a eliminar: "; cin >> id;
			registro.EliminarRegistro(id);
			PA;			
		}

	} while (opcion != 5);

}


