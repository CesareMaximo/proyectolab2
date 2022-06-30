#include "Descuento.h"

#include<iostream>
#include"stdio.h"


using namespace std;

void Descuento::mostrar(){

cout<<endl<<"¡Descuento disponible! ";
cout<<endl<<"dni: "<<dni_cliente;
cout<<endl<<"Porcentaje a descontar: %"<<porcentaje;
cout<<endl<<"Monto a descontar: $"<<monto_descuento;
}

bool Descuento::leer(int pos){
    bool leyo;
    FILE *p;
    p=fopen("descuento.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Descuento)*pos,SEEK_SET);
    leyo=fread(this,sizeof(Descuento),1,p);
    fclose(p);
    return leyo;
}
bool Descuento::escribir(){
    bool escribio;
    FILE *p;
    p=fopen("descuento.dat","ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this,sizeof(Descuento),1,p);
    fclose(p);
    return escribio;
}
bool Descuento::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("descuento.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Descuento)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Descuento),1,p);
    fclose(p);
    return escribio;
}
bool Descuento::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/descuento.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Descuento),1,p);
    fclose(p);
    return escribio;
}
