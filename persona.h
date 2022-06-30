#pragma once
#include "fecha.h"
#include <cstring>
class Persona {
protected:
	char apellido[50];
	char nombre[50];
	Fecha nacimiento;
	int dni;
	char telefono[20];
public:
	void cargar();
	void mostrar();
	bool leer_persona(int);
	bool escribir();
	bool sobreescribir(int);
	//gets
	char* getapellido() { return apellido; }
	char* getnombre() { return nombre; }
	Fecha getfecha() { return nacimiento; }
	int getdni() {return dni;}
	char* gettelefono() { return telefono; }
	//sets
	void setapellido(char* a) { strcpy(apellido, a); }
	void setnombre(char* n) { strcpy(nombre, n); }
	bool setdni(int);
	void setnacimiento(Fecha e) { nacimiento = e; }
	void settelefono(char* t) { strcpy(telefono, t); }
};
