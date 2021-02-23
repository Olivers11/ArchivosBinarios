#include "Registro.h"



void Registro::GuardarRegistro(Persona persona_guardar)
{
	this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
	if (this->archivo.fail()) { cout << "ERROR VERGA DEL ARCHIVO \n"; }
	else
	{
		this->archivo.write((char*)&persona_guardar, sizeof(Persona));
		this->archivo.close();
		cout << "Guardado Exitosamente \n";
	}
}



void Registro::MostrarRegistros()
{
	Persona persona_mostrar = Persona();
	this->archivo.open("Personas.bin", ios::in | ios::binary);
	if (this->archivo.fail())
	{
		cout << "ERROR AL ABRIR EL ARCHIVO " << endl;
	}
	else
	{
		while (!this->archivo.eof())
		{
			this->archivo.read((char*)&persona_mostrar, sizeof(Persona));
			if (!this->archivo.eof())
			{
				persona_mostrar.Imprimir();
			}
		}
		this->archivo.close();
	}
}



void Registro::ModificarRegistro(int id)
{
	bool encontrado = false;
	Persona aux;
	ifstream lectura; ofstream escritura;
	lectura.open("Personas.bin", ios::in | ios::binary);
	escritura.open("auxiliar.bin", ios::app | ios::binary);
	if (lectura.fail() or escritura.fail()) { cout << "ERROR AL ABRIR LOS ARCHIVOS \n"; }
	else
	{
		while (lectura.read((char*)&aux, sizeof(aux)))
		{
			if(aux.ObtenerCedula() == id)
			{
				encontrado = true;
				int cedula; char n[20]; int edad;
				cout << "Cedula: "; cin >> cedula;
				cout << "Nombre: ";
				fflush(stdin);
				cin.getline(n, 20, '\n');
				cout << "Edad: "; cin >> edad;
				aux.ActualizarDatos(cedula, n, edad);
				escritura.write((char*)&aux, sizeof(aux));
			}
			else
			{
				escritura.write((char*)&aux, sizeof(aux));
			}
		}
		lectura.close();
		escritura.close();
		remove("Personas.bin");
		if (rename("auxiliar.bin", "Personas.bin"))
			printf("File rename error\n");
		if (encontrado)
		{
			cout << id << " modificado coorectamente!" << endl;
		}
		else
		{
			cout << id << " no existe en el registro \n";
		}
	}

}




void Registro::EliminarRegistro(int id)
{
	bool encontrado = false;
	Persona aux;
	ifstream lectura; ofstream escritura;
	lectura.open("Personas.bin", ios::in | ios::binary);
	escritura.open("auxiliar.bin", ios::app | ios::binary);
	if (lectura.fail() or escritura.fail()) { cout << "ERROR AL ABRIR LOS ARCHIVOS \n"; }
	else
	{
		while (lectura.read((char*)&aux, sizeof(aux)))
		{
			if (aux.ObtenerCedula() != id)
			{
				escritura.write((char*)&aux, sizeof(aux));
			}
			else
			{
				encontrado = true;
			}
		}
		lectura.close();
		escritura.close();
		remove("Personas.bin");
		if (rename("auxiliar.bin", "Personas.bin"))
			printf("File rename error\n");
	}
	
	if (encontrado) { cout << id << " eliminado correctamente! \n"; }
	else { cout << "Inexistente en el registro \n"; }
}

