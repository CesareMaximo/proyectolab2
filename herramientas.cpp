#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>

#include "funciones.h"
#include "herramientas.h"
#include <string.h>
#include <sstream>
using namespace std;



Herramientas::Herramientas(int _ID_herramienta){
    if(_ID_herramienta==0){
        FILE *p;
        p=fopen("herramientas.dat","rb");
        if(p==NULL){
            ID_herramienta=1;
        }
        else{
            fseek(p,0,SEEK_END);
            _ID_herramienta=ftell(p)/sizeof(Herramientas);
            ID_herramienta=_ID_herramienta+1;
        }
    }
}

bool Herramientas::escribir(){
	bool escribio;
	FILE* p;
	p=fopen("herramientas.dat","ab");
	if(p==NULL){
		cout << "ERROR- al abrir el archivo" << endl;
		return false;
	}
	escribio=fwrite(this,sizeof(Herramientas),1,p);
	fclose(p);
	return escribio;
}
bool Herramientas::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("herramientas.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Herramientas)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Herramientas),1,p);
    fclose(p);
    return escribio;
}
bool Herramientas::leer(int pos){
	bool leyo;
	FILE* p;
	p=fopen("herramientas.dat","rb");
	if(p==NULL) {
		cout << "No encontró ningún herramienta" << endl;
		return false;
	}
    fseek(p,sizeof(Herramientas)*pos,SEEK_SET);
	leyo=fread(this, sizeof(Herramientas), 1, p);
	fclose(p);
	return leyo;
}


// CARGAR HERRAMIENTA VALIDADO
void Herramientas::cargar(){
    bool aux=true;

	while(aux){
        cout << "Ingrese el codigo de marca: ";
        cin >> ID_marca;
        if(ID_marca >0){
            aux = false;
        }
        else{

                 cout << "Numero invalido, vuelve a ingresar "<<endl;
                system("pause");

            aux=true;
        }
	}
    cout<<"////////////////////////////////////////////////////////////////////////"<<endl;

    cout << "Ingrese el nombre de la herramienta: ";
    cin.ignore();
    cin.getline(nomherramienta,50);

      cout<<"////////////////////////////////////////////////////////////////////////"<<endl;
    aux=true;

    while(aux){
        cout << "Ingrese el precio: ";
        cin >> precio;

        if(precio>0){
            aux = false;
        }
        else{

                cout << "El precio no puede ser menor a 0 "<<endl;
                aux=true;
                system("pause");
        }

    }

      cout<<"////////////////////////////////////////////////////////////////////////"<<endl;
    aux=true;



	 while(aux){
            cout << "Ingrese stock: ";
            cin >> stock;

        if(stock>0){
            aux = false;
        }
        else{

                cout << "El stockno puede ser menor a 0, por favor vuelve a intentar "<<endl;
                aux=true;
                system("pause");
        }

    }

  cout<<"////////////////////////////////////////////////////////////////////////"<<endl;
   cout << "Ingrese la fecha en la que se creo el producto "<<endl;
	fabricado.cargar();
	estado=true;
}

void Herramientas::mostrar(){
	if(estado==true){
        cout << "Codigo de herramienta: " << ID_herramienta << endl;
        cout << "Codigo de marca: " << ID_marca << endl;
        cout << "Herramienta: " << nomherramienta << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Stock: " << stock <<endl;
        fabricado.mostrar();
	}
}

bool Herramientas::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/herramientas.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Herramientas),1,p);
    fclose(p);
    return escribio;
}
