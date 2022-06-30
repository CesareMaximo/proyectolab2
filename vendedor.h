#pragma once
#include "persona.h"
#include "fecha.h"
class Vendedor : public Persona {
private:
	float sueldo;
	float comision;
	char usuario[50];
	char clave[50];
	Fecha ingreso;
public:
	void cargar();
	void mostrar();
	bool leer(int);
	bool escribir();
	bool sobre_escribir(int);

	//gets
	float getsueldo() { return sueldo; }
	char *getUsuario(){return usuario;}
	char *getClave(){return clave;}
	Fecha getingreso() { return ingreso; }
	float getComision(){return comision;}
	//sets
	void setsueldo(float s) { sueldo = s; }
	void setClave(char*c){strcpy(clave,c);}
	void setingreso(Fecha i) { ingreso = i; }
	bool setUsuario(char*u);
	void setComision(float c){comision = c;}
	//backup
	bool backup_escribir();
	//consturctor
	/*Vendedor(float c=0){
	comision=c;
	}*/
};
