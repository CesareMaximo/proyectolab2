#pragma once
#include "fecha.h"
/*
FORMA DE PAGO:
1- Efectivo
2- Credito
3- Debito
4- Cheque
*/


class Venta {
private:
    int ID;
	Fecha fechav;
	int formapago;
	int id_cliente;
	char id_vendedor[50];
	bool envio;
public:
    Venta(int _ID=0);
	void cargar(int,char*);
	void mostrar();
	bool leer(int);
	bool escribir();
	bool escribir(int);
	bool sobre_escribir(int);
	//gets
	int getID(){return ID;}
	bool getEnvio() { return envio; }
	Fecha getFechav() { return fechav; }
	int getFormapago() { return formapago; }
	int getIDcliente() { return id_cliente; }
	char *getIDvendedor() { return id_vendedor; }
	//sets
	void setEnvio(bool e){envio=e;}
    void setFechav(Fecha f){fechav=f;}
	void setFormapago(int p){formapago=p;}
	void setIDcliente(int c){id_cliente=c;}
	void setIDvendedor(char*v){strcpy(id_vendedor,v);}
	//backup
	bool backup_escribir();
};
