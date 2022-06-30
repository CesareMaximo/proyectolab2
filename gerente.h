#pragma once
#include "persona.h"
class Gerente : public Persona {
private:
    char usuario[30];
	char clave[30];
	float sueldo;
	Fecha ingreso;
public:
    void cargar();
	void mostrar();
	bool leer(int);
	bool escribir();
	bool sobre_escribir(int);
	//gets
	Fecha getingreso() { return ingreso; }
	float getsueldo() { return sueldo; }
	char *getUsuario(){return usuario;}
	char *getClave(){return clave;}
	//sets
	void setingreso(Fecha i) { ingreso = i; }
	void setsueldo(float s) { sueldo = s; }
	void setClave(char*c){strcpy(clave,c);}
	bool setUsuario(char*);
	//backup
	bool backup_escribir();
};
