#pragma once
class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
    Fecha();
	void cargar();
	void cargar(int);
	void mostrar();
	void leer(int);
	void escribir();
	//gets
	int getDia() { return dia; }
	int getMes() { return mes; }
	int getAnio() { return anio; }
	//sets
	void setDia(int d) { dia = d; }
	void setMes(int m) { mes= m; }
	void setAnio(int a) { anio = a; }
};
