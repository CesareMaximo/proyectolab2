#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>
#include "vendedor.h"
#include "fecha.h"
#include"funciones.h"
using namespace std;

bool Vendedor::setUsuario(char*_usuario){
    if(filtrar_gerente(_usuario)){
        if(filtrar_vendedor(_usuario)){
            strcpy(usuario,_usuario);
            return true;
        }
        else{
            system("cls");
            cout<<endl<<endl<<"<<ERROR- ese usuario ya se encuentra en uso por un vendedor>>"<<endl;
            cout<<"[CREAR NUEVO con diferente usuario]"<<endl<<endl;
            system("pause");
            return false;
        }
    }
    else{
        system("cls");
        cout<<endl<<endl<<"<<ERROR- ese usuario ya se encuentra en uso por un gerente>>"<<endl;
        cout<<"[CREAR NUEVO con diferente usuario]"<<endl<<endl;
        system("pause");
        return false;
    }
}
void Vendedor::cargar() {
    char _usuario[30];
    bool aux = true;
    bool validado=false;
    while(validado==false){
        system("cls");
        cout<<"Usuario: ";
        cin>>_usuario;
        if(setUsuario(_usuario)){
            validado=true;
        }
    }
    cout<<"Ingrese clave:";
    cin>>clave;
    Persona::cargar();
        while(aux){
          cout<<endl<<"Ingrese el sueldo: $";
            cin >>sueldo;
            if(sueldo>0){
                aux = false;
            }
            else{
                 cout<<endl<<" Sueldo invalido, vuelva a ingresarlo";
            }
        }


    cout<<endl<<endl<<endl<<"--Fecha de ingreso-- "<<endl;
    ingreso.cargar(0);
    comision=0;
}
void Vendedor::mostrar() {
    cout<< "Usuario: "<< usuario<<endl;
    Persona::mostrar();
    cout << "Sueldo: " << sueldo << endl;
    cout << "Fecha de ingreso" << endl;
   ingreso.mostrar();
  cout<<endl<<"Comision por venta: "<<comision<<"%";
  cout<<endl;

}
// LEER DE DISCO
bool Vendedor::leer(int pos) {
    FILE* p;
    p = fopen("vendedores.dat", "rb");
    if (p == NULL) {
        return false;
    }
    bool ok;
    fseek(p, sizeof(Vendedor) * pos, 0);
    ok = fread(this, sizeof(Vendedor), 1, p);
    fclose(p);
    return ok;

}
bool Vendedor::escribir() {
    FILE* p;
    p = fopen("vendedores.dat", "ab");
    if (p == NULL) {
        return true;

    }
    bool ok;
    ok = fwrite(this, sizeof(Vendedor), 1, p);
    fclose(p);
    return ok;
}
bool Vendedor::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("vendedores.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Vendedor)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Vendedor),1,p);
    fclose(p);
    return escribio;
}
bool Vendedor::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/vendedores.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Vendedor),1,p);
    fclose(p);
    return escribio;
}

