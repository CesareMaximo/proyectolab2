#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include <locale.h>

#include"funciones.h"

#include "fecha.h"
using namespace std;

Fecha::Fecha(){
    time_t fecha_actual = time(0);
    tm*time = localtime(&fecha_actual);

    dia=time->tm_mday;
    mes=time->tm_mon+1;
    anio=time->tm_year+1900;
}

void Fecha::cargar(){
	bool validar=false,validar2=false;
	int _dia,_mes,_anio;
	while(validar==false ||  validar2==false){
        validar=false,validar2=false;
        cout<<"Dia: ";
        cin>>_dia;
        cout<<"Mes: ";
        cin>>_mes;
        cout<<"Año: ";
        cin>>_anio;
        validar=validar_fecha(_dia,_mes,_anio);
        validar2=validar_con_fecha_actual(_dia,_mes,_anio);
        if(validar==true && validar2==true){
            dia=_dia;
            mes=_mes;
            anio=_anio;
        }
        else{
            system("cls");
            cout<<endl<<endl<<"<<ERROR- Fecha no existente o es menor a la fecha actual>>"<<endl<<endl;
            cout<<"              <<INGRESE UNA FECHA VALIDA>>                "<<endl<<endl;
            system("pause");
            system("cls");
        }
	}
}
void Fecha::cargar(int dif){
	bool validar=false;
	int _dia,_mes,_anio;
	while(validar==false){
        cout<<"Dia: ";
        cin>>_dia;
        cout<<"Mes: ";
        cin>>_mes;
        cout<<"Año: ";
        cin>>_anio;
        validar=validar_fecha(_dia,_mes,_anio);
        if(validar){
            dia=_dia;
            mes=_mes;
            anio=_anio;
        }
        else{
            system("cls");
            cout<<endl<<endl<<"<<ERROR- Fecha no existente>>"<<endl<<endl;
            cout<<"              <<INGRESE UNA FECHA VALIDA>>                "<<endl<<endl;
            system("pause");
            system("cls");
        }
	}
}

void Fecha::mostrar(){
    cout<<"Dia: "<<dia<<endl;
	cout<<"Mes: "<<mes<<endl;
	cout<<"Año: "<<anio<<endl;
}

