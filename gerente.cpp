#include "herramientas.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>

#include"herramientas.h"
#include "funciones.h"
#include "gerente.h"
#include "persona.h"

using namespace std;
bool Gerente::setUsuario(char*_usuario){
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

//CARGAR GERENTE VALIDADO
void Gerente::cargar(){
    char _usuario[30];
    bool validado=false;
    bool  aux=true;
    while(validado==false){
        system("cls");
        cout<<"Usuario: ";
        cin>>_usuario;
        if(setUsuario(_usuario)){
           validado=true;
        }
    }
    cout<<"Clave: ";
    cin>>clave;
    Persona::cargar();

    while(aux){
      cout<<endl<<"Sueldo: $";
        cin>>sueldo;

        if(sueldo>0){
            aux = false;
        }
        else
            system("cls");


            cout<<" Sueldo menor a 0, por favor vuelva a ingresar el monto"<<endl;
            aux =true;
            system("pause");
        }




    cout<<endl<<endl<<endl<<"--Fecha de ingreso-- "<<endl;
    ingreso.cargar(0);

}
void Gerente::mostrar(){
    cout<<endl<<"Usuario: "<<usuario;
    cout<<endl<<"Sueldo: "<<sueldo<<endl;
    Persona::mostrar();
    ingreso.mostrar();
}
bool Gerente::leer(int pos){
    bool leyo;
    FILE *p;
    p=fopen("gerentes.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Gerente)*pos,SEEK_SET);
    leyo=fread(this,sizeof(Gerente),1,p);
    fclose(p);
    return leyo;
}
bool Gerente::escribir(){
    bool escribio;
    FILE *p;
    p=fopen("gerentes.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Gerente),1,p);
    fclose(p);
    return escribio;
}
bool Gerente::sobre_escribir(int posicion){
    bool escribio;
    FILE *p;
    p=fopen("gerentes.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Gerente)*posicion,SEEK_SET);
    escribio=fwrite(this,sizeof(Gerente),1,p);
    fclose(p);
    return escribio;
}
bool Gerente::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/gerentes.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Gerente),1,p);
    fclose(p);
    return escribio;
}
