#pragma once
#include "fecha.h"
#include <cstring>
class Herramientas{
private:
	int ID_herramienta;
	int ID_marca;
	char nomherramienta[50];
	int stock;
	float precio;
	bool estado;
	Fecha fabricado;
public:
    Herramientas(int _ID_herramienta=0);
	void cargar();
	void mostrar();
	bool leer(int);
	bool escribir();
	bool sobre_escribir(int);
	//get
	int getID_Herramienta() { return ID_herramienta; }
	int getID_marca() { return ID_marca; }
	char* getNomherramienta() {return nomherramienta; }
	int getStock() { return stock; }
	float getPrecio() { return precio; }
	bool getEstado(){return estado;}
	Fecha getFabricado() { return fabricado; }
	//sets
	void setID_marca(int i) { ID_marca = i; }
	void setNomherramienta(char* n) { strcpy(nomherramienta, n); }
	void setStock(int s) { stock = s; }
	void setPrecio(float p) { precio = p; }
	void setFabricado(Fecha f) { fabricado = f; }
	void setEstado(bool e){estado=e;}
	//backup
	bool backup_escribir();
};
