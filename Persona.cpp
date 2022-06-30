#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>
#include "cliente.h"
#include "persona.h"
#include"funciones.h"
using namespace std;


bool Persona::setdni(int _dni){
    if(filtrar_dni_gerente(_dni)){
        if(filtrar_dni_vendedor(_dni)){
            dni=_dni;
            return true;
        }
        else{
            system("cls");
            cout<<endl<<endl<<"<<ERROR- ese DNI ya se encuentra registrado>>"<<endl<<endl;
            system("pause");
            return false;
        }
    }
    else{
        system("cls");
        cout<<endl<<endl<<"<<ERROR- ese DNI ya se encuentra registrado>>"<<endl<<endl;
        system("pause");
        return false;
    }
}

void Persona::cargar() {
    int _dni;
    bool validado=false;

    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese el nombre: ";
    cin >> nombre ;
    cout<<endl<<endl<<endl<<"--Fecha de Nacimiento-- "<<endl;
    nacimiento.cargar(0);
    while(validado==false){
        cout<<"Ingrese el DNI: ";
        cin >> _dni;
        if(setdni(_dni)){
            validado=true;
        }
        else{
            system("cls");
        }
    }
    cout << "Ingrese el telefono: ";
            cin >> telefono;


}

void Persona::mostrar() {
    cout << "Apellido: " << apellido << endl;
    cout << "Nombre: " << nombre << endl;
    nacimiento.mostrar();
    cout << "DNI: " << dni << endl;
    cout << "Telefono: " << telefono << endl;

}
//Leer de disco
bool Persona::leer_persona(int pos) {
    FILE* p;
    bool aux;
    p = fopen("persona.dat", "rb");
    if (p == NULL) {

        return false;
    }

    fseek(p, sizeof(Persona) * pos, 0);

    aux = fread(this, sizeof(Persona), 1, p);
    fclose(p);
    return aux;

}
//Guardar en disco
bool Persona::escribir() {
    FILE* p;
    bool aux;
    p = fopen("persona.dat", "ab");
    if (p == NULL) {

        return false;
    }

    aux = fwrite(this, sizeof(Persona), 1, p);
    fclose(p);
    return aux;

}
//Sobre escribir
bool Persona::sobreescribir(int pos) {
    FILE* p;
    p = fopen("persona.dat", "rb+");
    if (p == NULL) {

        return false;
    }
    fseek(p, sizeof(Persona) * pos, 0);
    bool aux;
    aux = fwrite(this, sizeof(Persona), 1, p);
    fclose(p);
    return aux;


}
