#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>

#include "funciones.h"
#include "gerente.h"
#include "herramientas.h"
#include "venta.h"
#include"fecha.h"

using namespace std;


Venta::Venta(int _ID){
    int cantidad;
    if(_ID==0){
        FILE *p;
        p=fopen("ventas.dat","rb");
        if(p==NULL){
            ID=1;
        }
        else{
            fseek(p,0,SEEK_END);
            _ID=ftell(p)/sizeof(Venta);
            ID=_ID+1;
        }
    }
}
void Venta::cargar(int dniCliente,char*usuarioVendedor){
    int desicion=9,desicion2;
    setIDcliente(dniCliente);
    setIDvendedor(usuarioVendedor);
    while(desicion2!=1 && desicion2 !=2){
        cout<<endl<<endl<<"--Tipo de envio--";
        cout<<endl<<endl<<"1-Domicilio    2-Retira por local";
        cin>>desicion2;
    }
    if(desicion2==1){
        envio=true;
    }
    else{
        envio=false;
    }
    system("cls");
    while(desicion!= 1 && desicion!= 2 &&desicion!= 3 && desicion!= 4){
        cout<<endl<<"--Forma de pago--";
        cout<<endl<<endl<<"1-Efectivo   2-Credito   3-Debito   4-Cheque";
        cin>>desicion;
    }
    formapago=desicion;
}
void Venta::mostrar(){
    cout<<endl<<"ID de venta: "<<ID;
    cout<<endl<<"Fecha de venta: "<<endl;
    fechav.mostrar();
    cout<<endl<<"DNI del cliente: "<<id_cliente;
    cout<<endl<<"Vendedor: "<<id_vendedor;
    cout<<endl<<"Forma de pago: ";
    switch(formapago){
        case 1:
            cout<<"Efectivo";
            break;
        case 2:
            cout<<"Credito";
            break;
        case 3:
            cout<<"Debito";
            break;
        case 4:
            cout<<"Cheque";
            break;
    }
    cout<<endl<<"Envio: ";
    if(envio==true){
        cout<<"A domicilio"<<endl;
    }
    else{
        cout<<"Retira por local"<<endl;
    }
}
bool Venta::leer(int pos){
    bool leyo;
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Venta)*pos,SEEK_SET);
    leyo=fread(this,sizeof(Venta),1,p);
    fclose(p);
    return leyo;
}
bool Venta::escribir(){
    bool escribio;
    FILE *p;
    p=fopen("ventas.dat","ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return escribio;
}
bool Venta::escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("ventas.dat","wb");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Venta)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return escribio;
}

bool Venta::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Venta)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return escribio;
}

bool Venta::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/ventas.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return escribio;
}
