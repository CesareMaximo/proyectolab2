#pragma once
class Detalleventa {
private:
	int id_venta;
	int id_herramienta;
	float precio;
	int cantidad;
	bool estado;
public:
    Detalleventa(int _id_venta=0,int _cantidad=0,float _precio=0,int _id_herramienta=0,bool _estado=true);
    void cargar();
    void mostrar();
    bool leer(int);
    bool escribir();
    bool sobre_escribir(int);
    bool sobre_escribir(int,int);
    // gets
    int getIDherramienta() { return id_herramienta; }
    int getIDventa() { return id_venta; }
    int getCantidad() { return cantidad; }
    float getPrecio() { return precio; }
    bool getEstado(){return estado;}
    //sets
    void setIDherramienta(int i) { id_herramienta = i; }
    void setIDventa(int i) { id_venta = i; }
    void setCantidad(int c) { cantidad = c; }
    void setPrecio(float p) { precio = p; }
    bool setEstado(bool _estado){estado=_estado;}
    //backup
	bool backup_escribir();
};
