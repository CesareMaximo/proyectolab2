#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>
#include"cliente.h"
using namespace std;



void Cliente::cargar() {
	Persona::cargar();
	cout << "Ingrese el domicilio: ";
	cin>>domicilio;
	cout<<"Ingrese el mail: ";
	cin>>mail;
}

void Cliente::mostrar() {
	Persona::mostrar();
	cout<<endl<<"Domicilio: "<<domicilio;
	cout<<endl<<"Mail: "<<mail;
}

bool Cliente::leer(int pos){
    bool leyo;
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Cliente)*pos,SEEK_SET);
    leyo=fread(this,sizeof(Cliente),1,p);
    fclose(p);
    return leyo;
}
bool Cliente::escribir(){
    bool escribio;
    FILE *p;
    p=fopen("clientes.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}
bool Cliente::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Cliente)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}

bool Cliente::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/cliente.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}
