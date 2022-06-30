#pragma once
#include "persona.h"
#include "fecha.h"

class Cliente : public Persona {
private:
	char domicilio[50];
	char mail[100];
public:
	void cargar();
	void mostrar();
	bool escribir();
	bool leer(int);
	bool sobre_escribir(int);
	//gets
	char* getdomicilio() { return domicilio; }
	char* getmail() { return mail; }
	//sets
	void setdomicilio(char* d) { strcpy(domicilio, d); }
	void setmail(char* m) { strcpy(mail, m); }
	//backup
	bool backup_escribir();
};
