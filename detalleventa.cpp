#include<iostream>
#include"stdio.h"
#include"detalleventa.h"

using namespace std;
Detalleventa::Detalleventa(int _id_venta,int _cantidad,float _precio,int _id_herramienta,bool _estado){
    id_venta=_id_venta;
    cantidad=_cantidad;
    precio=_precio;
    id_herramienta=_id_herramienta;
    estado=true;
}
void Detalleventa::mostrar(){
    cout<<endl<<"Codigo de Venta: "<<id_venta;
    cout<<endl<<"Codigo de Herramienta: "<<id_herramienta;
    cout<<endl<<"Precio: $"<<precio;
    cout<<endl<<"cantaidad: "<<cantidad;

}
bool Detalleventa::leer(int pos){
    bool leyo;
    FILE *p;
    p=fopen("detallesVenta.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Detalleventa)*pos,SEEK_SET);
    leyo=fread(this,sizeof(Detalleventa),1,p);
    fclose(p);
    return leyo;
}
bool Detalleventa::escribir(){
    bool escribio;
    FILE *p;
    p=fopen("detallesVenta.dat","ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this,sizeof(Detalleventa),1,p);
    fclose(p);
    return escribio;
}
bool Detalleventa::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("detallesVenta.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Detalleventa)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Detalleventa),1,p);
    fclose(p);
    return escribio;
}
bool Detalleventa::sobre_escribir(int pos,int b){
    bool escribio;
    FILE *p;
    p=fopen("detallesVenta.dat","rb+");
    if(p==NULL){
        return false;
    }
    pos=pos-1;
    fseek(p,sizeof(Detalleventa)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Detalleventa),1,p);
    fclose(p);
    return escribio;
}
bool Detalleventa::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/detalle.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Detalleventa),1,p);
    fclose(p);
    return escribio;
}
