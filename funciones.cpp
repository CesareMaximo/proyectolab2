#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include <locale.h>
#include <fstream>


#include "Descuento.h"
#include "funciones.h"
#include"herramientas.h"
#include"gerente.h"
#include"cliente.h"
#include"venta.h"
#include"detalleventa.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
///                       MENUS-INGRESO                           ///
/////////////////////////////////////////////////////////////////////


//INGRESO
void ingreso_al_sistema(){
    int n;
    while(n!=-1){
        char usuario[50],clave[50];
        cout<<endl<<endl<<"********************************* LOGIN *********************************"<<endl<<endl<<endl;
        cout<<endl<<"[Ingresar nombre de usuario '0' para salir]"<<endl<<endl<<endl;
        cout<<"Ingresar usuario: ";
        cin>>usuario;
        cout<<"Ingresar clave: ";
        cin>>clave;
        system("cls");
        n=login(usuario,clave);
        switch(n){
            case 1:
                menu_gerencia();
                break;
            case 2:
                menu_vendedor(usuario);
                break;
            case 0:
                cout<<endl<<endl<<"<<ERROR-Usuario o clave no validos>>"<<endl<<endl;
                system("pause");
                system("cls");
                break;
        }
    }
}
//LOGIN
int login(char*usuario,char*clave){
    if(usuario[0]=='0'){
        return -1;
    }
    else{
        if(validarGerente(usuario,clave)){
            return 1;
        }
        else{
            if(validarVendedor(usuario,clave)){
                return 2;
            }
            else{
                return 0;
            }
        }
    }
    return false;
}
bool validarGerente(char*usuario,char*clave){
    int pos=0;
    Gerente obj;
    while(obj.leer(pos++)){
        if(strcmp(usuario,obj.getUsuario())==0){
            if(strcmp(clave,obj.getClave())==0){
                return true;
            }
        }
    }
    return false;
}
bool validarVendedor(char*usuario,char*clave){
    int pos=0;
    Vendedor obj;
    while(obj.leer(pos++)){
        if(strcmp(usuario,obj.getUsuario())==0){
            if(strcmp(clave,obj.getClave())==0){
                return true;
            }
        }
    }
    return false;
}
//MENUS
void menu_vendedor(char*usuario){
    char desicion='p';
    while(desicion!='0'){
        cout<<endl<<"****************MENU DE VENDEDOR****************"<<endl<<endl;
        cout<<endl<<"1-Nueva venta";
        cout<<endl<<"2-Editar datos del cliente";
        cout<<endl<<"3-Consultar producto";
        cout<<endl<<endl<<"0- Cerrar sesion";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                generar_nueva_venta(usuario);
                break;
            case '2':

                break;
            case '3':
                system("cls");
                menu_gerencia_buscarHerramientas();
                system("pause");
                break;
        }
        system("cls");
    }
}
void menu_gerencia(){
    char desicion='p';
    while(desicion!='0'){
        cout<<endl<<"****************MENU DE GERENCIA****************"<<endl<<endl;
        cout<<endl<<"1-Herramientas";
        cout<<endl<<"2-Vendedores";
        cout<<endl<<"3-Clientes";
        cout<<endl<<"4-Ventas";
        cout<<endl<<"5-Crear usuarios y registrar nuevos empleados";
        cout<<endl<<"6-Reportes";
        cout<<endl<<"7-Backup";
        cout<<endl<<"8-Csv";
        cout<<endl<<endl<<"0-Cerrar sesion";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                menu_herramientas_gerencia();
                break;
            case '2':
                system("cls");
                menu_vendedores_gerencia();
                break;
            case '3':
                system("cls");
                menu_clientes_gerencia();
                break;
            case '4':
                system("cls");
                menu_ventas_gerencia();
                break;
            case '5':
                system("cls");
                menu_usuarios_y_registrar_gerencia();
                break;
            case '6':
                system("cls");
                menu_reportes_gerencia();
                break;
            case '7':
                system("cls");
                menu_backup();
                break;
            case '8':
                system("cls");
                menu_csv();
                break;
        }
        system("cls");
    }
}


/////////////////////////////////////////////////////////////////////
///                         BACKUP                                ///
/////////////////////////////////////////////////////////////////////


//MENU BACKUP
void menu_backup(){
    char desicion='p';
    while(desicion!='0'){
        cout<<endl<<"****************MENU DE BACKUP****************"<<endl<<endl;
        cout<<endl<<"1-Backup venta";
        cout<<endl<<"2-Backup vendedores";
        cout<<endl<<"3-Backup herramienta";
        cout<<endl<<"4-Backup gerente";
        cout<<endl<<"5-Backup Detalle de venta";
        cout<<endl<<"6-Backup descuento";
        cout<<endl<<"7-Backup cliente";
        cout<<endl<<"8-Backup de todos los archivos";
        cout<<endl<<endl<<"0-Cerrar sesion";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                backup_venta();
                system("pause");
                break;
            case '2':
                system("cls");
                backup_vendedor();
                system("pause");
                break;
            case '3':
                system("cls");
                backup_herramienta();
                system("pause");
                break;
            case '4':
                system("cls");
                backup_gerente();
                system("pause");
                break;
            case '5':
                system("cls");
                backup_detalle_venta();
                system("pause");
                break;
            case '6':
                system("cls");
                backup_descuento();
                system("pause");
                break;
            case '7':
                system("cls");
                backup_cliente();
                system("pause");
                break;
            case '8':
                system("cls");
                backup_venta();
                backup_vendedor();
                backup_herramienta();
                backup_gerente();
                backup_detalle_venta();
                backup_descuento();
                backup_cliente();
                system("pause");
                break;
        }
        system("cls");
    }

}
//1
void backup_venta(){
    int pos=0;
    Venta reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
    cout<<endl<<"Backup ventas guardado con exito!";
    cout<<endl;
}
//2
void backup_vendedor(){
    int pos=0;
    Vendedor reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
     cout<<endl<<"Backup  vendedores guardado con exito!";
    cout<<endl;
}
//3
void backup_herramienta(){
    int pos=0;
    Herramientas reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
     cout<<endl<<"Backup herramientas guardado con exito!";
    cout<<endl;
}
//4
void backup_gerente(){
    int pos=0;
    Gerente reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
     cout<<endl<<"Backup gerentes guardado con exito!";
    cout<<endl;
}
//5
void backup_detalle_venta(){
    int pos=0;
    Detalleventa reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
     cout<<endl<<"Backup detalle de ventas guardado con exito!";
    cout<<endl;
}
//6
void backup_descuento(){
    int pos=0;
    Descuento reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
     cout<<endl<<"Backup descuentos guardado con exito!";
    cout<<endl;
}
//7
void backup_cliente(){
    int pos=0;
    Cliente reg;
    while(reg.leer(pos++)==true){
        reg.backup_escribir();
    }
     cout<<endl<<"Backup clientes guardado con exito!";
    cout<<endl;
}


/////////////////////////////////////////////////////////////////////
///                            CSV                                ///
/////////////////////////////////////////////////////////////////////

//MENU CSV
void menu_csv(){
    char desicion='p';
    while(desicion!='0'){
        cout<<endl<<"****************MENU CSV****************"<<endl<<endl;
        cout<<endl<<"1-Crear CSV venta";
        cout<<endl<<"2-Crear CSV vendedores";
        cout<<endl<<"3-Crear CSV herramienta";
        cout<<endl<<"4-Crear CSV gerente";
        cout<<endl<<"5-Crear CSV Detalle de venta";
        cout<<endl<<"6-Crear CSV descuento";
        cout<<endl<<"7-Crear CSV cliente";
        cout<<endl<<"8-Crear CSV de todos los archivos";
        cout<<endl<<endl<<"0-Cerrar sesion";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                csv_venta();
                system("pause");
                break;
            case '2':
                system("cls");
                csv_vendedor();
                system("pause");
                break;
            case '3':
                system("cls");
                csv_herramienta();
                system("pause");
                break;
            case '4':
                system("cls");
                csv_gerente();
                system("pause");
                break;
            case '5':
                system("cls");
                csv_detalle_venta();
                system("pause");
                break;
            case '6':
                system("cls");
                csv_descuento();
                system("pause");
                break;
            case '7':
                system("cls");
                csv_cliente();
                system("pause");
                break;
            case '8':
                system("cls");
                csv_venta();
                csv_vendedor();
                csv_herramienta();
                csv_gerente();
                csv_detalle_venta();
                csv_descuento();
                csv_cliente();
                system("pause");
                break;
        }
        system("cls");
    }

}
//1
void csv_venta(){
    int pos=0;
    Venta obj;
    ofstream File;
    File.open("csv/ventas.csv");
    File <<";"<<"CODIGO DE VENTA"<<";"<<"FECHA"<<";"<<"PAGO";
    File <<";"<<"DNI CLIENTE"<<";"<<"USUARIO VENDEDOR"<<";"<<"ENVIO"<<endl;
    while(obj.leer(pos++)){
        char envio[30];
        char formaPago[30];
        if(obj.getFormapago()==true){
            strcpy(envio,"domicilio");
        }
        else{
            strcpy(envio,"retira por local");
        }

        switch(obj.getFormapago()){
            case 1:
                strcpy(formaPago,"efectivo");
                break;
            case 2:
                strcpy(formaPago,"credito");
                break;
            case 3:
                strcpy(formaPago,"debito");
                break;
            case 4:
                strcpy(formaPago,"cheque");
                break;
        }
        File <<";"<<obj.getID()<<";"<<obj.getFechav().getDia()<<"/"<<obj.getFechav().getMes()<<"/"<<obj.getFechav().getAnio();
        File <<";"<<formaPago<<";"<<obj.getIDcliente()<<";"<<obj.getIDvendedor()<<";"<<envio<<endl;
    }
    cout<<endl<<"Archivo CSV ventas creado"<<endl;
}
//2
void csv_vendedor(){
    int pos=0;
    Vendedor obj;
    ofstream File;
    File.open("csv/vendedores.csv");
    File <<";"<<"NOMBRE"<<";"<<"APELLIDO"<<";"<<"DNI"<<";"<<"TELEFONO"<<";";
    File <<"FECHA DE INGRESO"<<";"<<"COMISION"<<";"<<"SUELDO"<<endl;
    while(obj.leer(pos++)){
        File <<";"<<obj.getnombre()<<";"<<obj.getapellido()<<";"<<obj.getdni()<<";"<<obj.gettelefono()<<";";
        File <<obj.getfecha().getDia()<<"/"<<obj.getfecha().getMes()<<"/"<<obj.getfecha().getAnio();
        File <<";"<<obj.getComision()<<"%"<<";"<<"$"<<obj.getsueldo()<<endl;
    }
    cout<<endl<<"Archivo CSV vendedores creado"<<endl;
}
//3
void csv_herramienta(){
    int pos=0;
    Herramientas obj;
    ofstream File;
    File.open("csv/herramientas.csv");
    File <<";"<<"CODIGO HERRAMIENTA"<<";"<<"NOMBRE"<<";"<<"PRECIO"<<";"<<"COD MARCA";
    File <<";"<<"FABRICADO"<<endl;
    while(obj.leer(pos++)){
        File <<";"<<obj.getID_Herramienta()<<";"<<obj.getNomherramienta();
        File <<";"<<"$"<<obj.getPrecio()<<";"<<obj.getID_marca()<<";";
        File <<obj.getFabricado().getDia()<<"/"<<obj.getFabricado().getMes()<<"/"<<obj.getFabricado().getAnio()<<endl;
    }
    cout<<endl<<"Archivo CSV herramientas creado"<<endl;
}
//4
void csv_gerente(){
    int pos=0;
    Gerente obj;
    ofstream File;
    File.open("csv/gerentes.csv");
    File <<";"<<"NOMBRE"<<";"<<"APELLIDO"<<";"<<"DNI"<<";"<<"TELEFONO"<<";";
    File <<"FECHA DE INGRESO"<<";"<<"SUELDO"<<endl;
    while(obj.leer(pos++)){
        File <<";"<<obj.getnombre()<<";"<<obj.getapellido()<<";"<<obj.getdni()<<";"<<obj.gettelefono()<<";";
        File <<obj.getfecha().getDia()<<"/"<<obj.getfecha().getMes()<<"/"<<obj.getfecha().getAnio();
        File <<";"<<"$"<<obj.getsueldo()<<endl;
    }
    cout<<endl<<"Archivo CSV gerentes creado"<<endl;
}
//5
void csv_detalle_venta(){
    int pos=0;
    Detalleventa obj;
    ofstream File;
    File.open("csv/DetalleDeVentas.csv");
    File <<";"<<"CODIGO DE VENTA"<<";"<<"CODIGO DE HERRAMIENTA"<<";"<<"PRECIO"<<";"<<"CANTIDAD"<<endl;
    while(obj.leer(pos++)){
        if(obj.getEstado()==true){
            File <<";"<<obj.getIDventa()<<";"<<obj.getIDherramienta()<<";"<<"$"<<obj.getPrecio()<<";"<<obj.getCantidad()<<endl;
        }
    }
    cout<<endl<<"Archivo CSV detalle de ventas creado"<<endl;
}
//6
void csv_descuento(){
    int pos=0;
    Descuento obj;
    ofstream File;
    File.open("csv/descuentos.csv");
    File <<";"<<"DNI DE CLIENTE"<<";"<<"PORCENTAJE"<<";"<<"MONTO"<<";"<<"USADO"<<endl;
    while(obj.leer(pos++)){
        char estado[30];
        if(obj.get_Estado()==true){
            strcpy(estado,"si");
        }
        else{
            strcpy(estado,"no");
        }
        File <<";"<<obj.get_DNI()<<";"<<obj.get_Porcentaje()<<"%"<<";"<<"$"<<obj.get_Monto_Descuento()<<";"<<estado<<endl;
    }
    cout<<endl<<"Archivo CSV descuentos creado"<<endl;
}
//7
void csv_cliente(){
    int pos=0;
    Cliente obj;
    ofstream File;
    File.open("csv/clientes.csv");
    File <<";"<<"NOMBRE"<<";"<<"APELLIDO"<<";"<<"DNI"<<";"<<"TELEFONO"<<";";
    File <<"DOMICILIO"<<";"<<"EMAIL"<<endl;
    while(obj.leer(pos++)){
        File <<";"<<obj.getnombre()<<";"<<obj.getapellido()<<";"<<obj.getdni()<<";"<<obj.gettelefono()<<";";
        File <<obj.getdomicilio()<<";"<<obj.getmail()<<endl;
    }
    cout<<endl<<"Archivo CSV clientes creado"<<endl;
}


/////////////////////////////////////////////////////////////////////
///                          VENDEDORES                           ///
/////////////////////////////////////////////////////////////////////

////////MENU PARA AGREGAR VENTAS
bool generar_nueva_venta(char*usuario){
    int dni,desicion_descuento;
    char nombreCliente[50];
    char desicion;
    float sub_total=0;
    cout<<"Ingresar DNI del cliente: ";
    cin>>dni;
    if(!validar_cliente_existente(dni,nombreCliente)){
        return 0;
    }
    Venta objVenta;
    system("cls");
    while(desicion!='0'){
        cout<<endl<<"*************** MENU DE VENTA ***************"<<endl;
        cout<<endl<<endl<<"Numero de Venta: "<<objVenta.getID();
        cout<<endl<<"Cliente: "<<nombreCliente<<endl<<endl;
        cout<<endl<<"1- Agregar producto";
        cout<<endl<<"2- Modificar cantidad del producto";
        cout<<endl<<"3- Quitar producto";
        cout<<endl<<"4- Finalizar venta";
        cout<<endl<<"5- Ver si el cliente tiene descuento";
        cout<<endl<<"0- Volver atras";
        cout<<endl<<endl<<"    --------------PRODUCTOS AGREGADOS HASTA EL MOMENTO--------------"<<endl;
        if(!mostrar_productos_agregados(objVenta.getID()) ){
            cout<<endl<<"<<Todavia no se agrego ningun producto>>";
        }
        cout<<endl<<endl<<"Monto total : $"<<sub_total;
        cout<<endl<<endl;
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                agregar_producto_a_venta(objVenta.getID(),sub_total);
                system("pause");
                break;
            case '2':
                system("cls");
                quitar_o_editar_producto(objVenta.getID(),1,sub_total);
                //system("pause");
                break;
            case '3':
                system("cls");
                quitar_o_editar_producto(objVenta.getID(),2,sub_total);
                //system("pause");
                break;
            case '4':
                system("cls");
                objVenta.cargar(dni,usuario);
                if(objVenta.escribir()){
                    system("cls");
                    cout<<endl<<endl<<"<<La venta se realizo con EXITO>>"<<endl<<endl<<endl;
                    descontar_stock(objVenta.getID());
                    desicion='0';

                    system("pause");
                }
                break;
            case '5':
                system("cls");
                int descAplicar;
                if(ver_descuento_cliente(dni,descAplicar)){
                    cout<<endl<<"Seguro que desea aplicar este descuento? 1=si =0no: ";
                    cin>>desicion_descuento;
                    switch(desicion_descuento){
                        case 1:
                            aplicar_descuento(sub_total,dni,descAplicar);
                            system("pause");
                            break;
                        case 0:
                            cout<<endl<<"Descuento no aplicado";
                            cout<<endl;
                            break;
                    }
                }
                else{
                    cout<<endl<<"No hay ningun descuento disponible para este cliente";
                    cout<<endl;
                }
                break;
            case '0':
                if( !eliminar_todos_productos(objVenta.getID()) ){
                    desicion='-1';
                }
                break;
        }
        system("cls");
    }

}

//Validacion de cliente antes de llegar al menu para agregar ventas
bool validar_cliente_existente(int dni,char*nombreCliente){
    int res;
    if(buscar_cliente(dni,nombreCliente)!=-1){
        return true;
    }
    else{
        system("cls");
        cout<<"<<El cliente no se encuentra registrado>>"<<endl<<endl<<endl;
        system("pause");
        system("cls");
        cout<<"--Ingresar datos del cliente--"<<endl<<endl<<endl;
        if(registrar_cliente(nombreCliente)!=-1){
            system("cls");
            cout<<"<<Se registro el cliente con exito>>"<<endl<<endl<<endl;
            system("pause");
            system("cls");
            return true;
        }
        else{
            system("cls");
            cout<<"<<El DNI ingresado ya se encuentra registrado>>"<<endl<<endl<<endl;
            system("pause");
            return false;
        }
    }
}
int buscar_cliente(int dni,char*nombreCliente){
    int pos=0;
    Cliente obj;
    while(obj.leer(pos++)){
        if(obj.getdni()==dni){
            strcpy(nombreCliente,obj.getnombre());
            return pos;
        }
    }
    return -1;
}
int registrar_cliente(char*nombreCliente){
    bool escribio;
    Cliente obj;
    obj.cargar();
    if(buscar_cliente(obj.getdni(),nombreCliente)!= -1){
        return -1;
    }
    strcpy(nombreCliente,obj.getnombre());
    escribio=obj.escribir();
    return escribio;
}


////////OPCIONES DE MENU
void agregar_producto_a_venta(int IDventa, float&sub_total){
    int cantidad=0,productoAgregar,productoCantidad;
    char nombreHerramienta[50];
    char desicion='p';
    cout<<endl<<"Ingresar nombre de la herramienta a buscar:";
    cin.ignore();
    cin.getline(nombreHerramienta,50);
    system("cls");

    cantidad=buscar_herramienta_por_nombre(cantidad,nombreHerramienta);
    Herramientas *vObj;
    vObj=new Herramientas[cantidad];
    cargarVectorconProductos(vObj,nombreHerramienta);

    for(int i=0;i<cantidad;i++){
        cout<<endl<<endl<<endl<<i+1<<"-      "<<vObj[i].getNomherramienta()<<"  $"<<vObj[i].getPrecio()<<"  Stock:"<<vObj[i].getStock();
    }
    cout<<endl<<endl<<"Cual producto desea agregar a la compra: "<<endl;
    cin>>productoAgregar;
    system("cls");
    if( (productoAgregar>=1) && (productoAgregar<=cantidad) ){
        if( buscar_producto_en_lista_compra(vObj[productoAgregar-1].getID_Herramienta(),IDventa) != -1 ){
            system("cls");
            cout<<endl<<endl<<"<<Este producto ya se encuentra en la lista>>"<<endl;
            cout<<"<<[ingresar a la opcion 2 del menu para modificarlo]>>"<<endl;
        }
        else{
            cout<<endl<<endl<<"Cantidad que desea llevar: "<<endl;
            cin>>productoCantidad;
            if( productoCantidad>vObj[productoAgregar-1].getStock() ){
                system("cls");
                cout<<endl<<endl<<"<<No hay stock disponible para esa cantidad>>"<<endl;
            }
            else{
                Detalleventa objDetalleVenta(IDventa,productoCantidad,vObj[productoAgregar-1].getPrecio(),vObj[productoAgregar-1].getID_Herramienta());
                while(desicion!='y' && desicion!='Y' &&desicion!='N' &&desicion!='n'){
                    system("cls");

                    cout<<endl<<endl<<"Desea confirmar(Y/N)"<<endl;
                    cin>>desicion;
                }
                if(desicion=='Y' || desicion =='y'){
                    sub_total+= productoCantidad *vObj[productoAgregar-1].getPrecio();
                    objDetalleVenta.escribir();
                }
            }
        }
    }
    else{
        cout<<endl<<endl<<"<<Opcion no valida>>"<<endl;
    }
    delete[] vObj;
}
void quitar_o_editar_producto(int IDventa,int desicion,float&sub_total){
    int buscarCod=1,posicion;
    while(buscarCod!=0){
        cout<<endl<<endl<<"--PRODUCTOS AGREGADOS HASTA EL MOMENTO--";
        if(!mostrar_productos_agregados(IDventa) ){
            cout<<endl<<endl<<"<<Todavia no se agrego ningun producto>>";
        }
        cout<<endl<<endl<<endl<<"           [Ingresar codigo 0 para volver atras]";
        cout<<endl<<"Ingrese el codigo del producto para efectuar el cambio en la lista: ";
        cin>>buscarCod;
        posicion=buscar_producto_en_lista_compra(buscarCod,IDventa);
        if(posicion<0 && buscarCod!= 0){
            system("cls");
            cout<<"<<El codigo ingresado no se encuentra en la lista de compra>>"<<endl;
        }
        else{
            if(buscarCod!=0){
                switch(desicion){
                case 1:
                    modificar_cantidad(posicion,sub_total);
                    break;
                case 2:
                    eliminar_producto_de_lista_compra(posicion,sub_total);
                    break;
                }

            }
        }
    }
}
bool eliminar_todos_productos(int IDventa){
    int pos=0,cont=0;
    bool e=false;
    char desicion;
    while(desicion!= 'y'&& desicion!= 'Y'&& desicion!= 'n'&& desicion!= 'N'){
        system("cls");
        cout<<"<<Si vuleve atras la compra se borarra>>"<<endl;
        cout<<"Seguro que desea volver atras?(Y/N)";
        cin>>desicion;
    }
    if(desicion=='N' || desicion=='n'){
        return false;
    }
    if(desicion=='y' || desicion=='Y'){
        Detalleventa obj;
        while(obj.leer(pos++)){
            if(obj.getEstado()==true){
                if(obj.getIDventa()==IDventa){
                    obj.setEstado(e);
                    obj.sobre_escribir(pos,9);
                }
            }
        }
    }
    return true;
}


//Agregar
void cargarVectorconProductos(Herramientas *vObj,char*nombreHerramienta){
    int pos=0,cont=0,contCoinciden=0,contador=0;
    char herramientaArchivo[50];
    Herramientas obj;
    system("cls");
    strlwr(nombreHerramienta);
    while(nombreHerramienta[cont]!='\0'){
        cont++;
    }
    while(obj.leer(pos++)){
        int i=0,x;
        if(obj.getEstado()==true){
            strcpy( herramientaArchivo,obj.getNomherramienta() );
            strlwr(herramientaArchivo);
            while(herramientaArchivo[i]!='\0'){
                if(herramientaArchivo[i]==nombreHerramienta[0]){
                    int contIguales=0;
                    x=i;
                    for(int j=0;j<cont;j++){
                        if(herramientaArchivo[x]== nombreHerramienta[j]){
                            contIguales++;
                        }
                        x++;
                    }
                    if(contIguales==cont){
                        vObj[contador]=obj;
                        contador++;
                    }
                }
                i++;
            }
        }
    }
}
int buscar_herramienta_por_nombre(int cantidad,char*nombreHerramienta){
    int pos=0,cont=0,contCoinciden=0,contador=0;
    char herramientaArchivo[50];
    cantidad = 0;
    Herramientas obj;
    strlwr(nombreHerramienta);
    while(nombreHerramienta[cont]!='\0'){
        cont++;
    }
    while(obj.leer(pos++)){
        int i=0,x;
        if(obj.getEstado()==true){
            strcpy( herramientaArchivo,obj.getNomherramienta() );
            strlwr(herramientaArchivo);
            while(herramientaArchivo[i]!='\0'){
                if(herramientaArchivo[i]==nombreHerramienta[0]){
                    int contIguales=0;
                    x=i;
                    for(int j=0;j<cont;j++){
                        if(herramientaArchivo[x]== nombreHerramienta[j]){
                            contIguales++;
                        }
                        x++;
                    }
                    if(contIguales==cont){
                        cantidad++;
                    }
                }
                i++;
            }
        }
    }
    return cantidad;
}
//Modificar
void modificar_cantidad(int posicion,float&sub_total){
    int cantidad,posicionHerramienta;
    system("cls");
    cout<<endl<<endl<<"Ingresar la cantidad que desea llevar: ";
    cin>>cantidad;
    system("cls");
    Detalleventa obj;
    obj.leer(posicion);
    posicionHerramienta=buscarCodigoHerramienta(obj.getIDherramienta());
    Herramientas objHerramienta;
    objHerramienta.leer(posicionHerramienta);
    if(cantidad>objHerramienta.getStock()){
        cout<<endl<<endl<<"<<No hay stock disponible para esa cantidad>>"<<endl;
        system("pause");
        system("cls");
    }
    else{
        sub_total-=obj.getPrecio()*obj.getCantidad();
        obj.setCantidad(cantidad);
        obj.sobre_escribir(posicion);
        sub_total+=obj.getPrecio()*obj.getCantidad();
    }
}
//Quitar
bool eliminar_producto_de_lista_compra(int posicion,float&sub_total){
    char desicion;
    while(desicion!='N' && desicion!='n' && desicion!='y' && desicion!='Y'){
        system("cls");
        cout<<endl<<"Seguro que desea quitar este producto de la lista?(Y/N)";
        cin>>desicion;
    }
    system("cls");
    if(desicion=='y' || desicion=='Y'){
        Detalleventa obj;

        obj.leer(posicion);
        obj.setEstado(false);
        obj.sobre_escribir(posicion);
        sub_total-=obj.getPrecio()*obj.getCantidad();
    }
}
//Finalizar venta
void descontar_stock(int IDventa){
    int pos=0,pos2=0,posicionHerramienta=0;
    Detalleventa obj;
    while(obj.leer(pos++)){
        if(obj.getIDventa()==IDventa && obj.getEstado()==true){
            Herramientas objHerramientas;
            while(objHerramientas.leer(pos2++)){
                if(objHerramientas.getID_Herramienta()==obj.getIDherramienta()){
                    objHerramientas.setStock(objHerramientas.getStock()-obj.getCantidad());
                    objHerramientas.sobre_escribir(posicionHerramienta);
                }
                posicionHerramienta++;
            }
            pos2=0;
            posicionHerramienta=0;
        }
    }
}
//Ver descuento del cliente
bool ver_descuento_cliente(int _dni,int&descAplicar){
    int pos=0,b=0,opcion=0;
    Descuento reg;
    while(reg.leer(pos++)==true){
        if(_dni==reg.get_DNI()){
            if(reg.get_Estado()==true){
                opcion++;
                cout<<endl<<endl<<"----------------------";
                cout<<endl<<"OPCION "<<opcion<<endl;
                reg.mostrar();
                b=1;
            }
        }
    }
    if(opcion>0){
        cout<<endl<<endl<<"Que opcion de descuento desea aplicar: ";
        cin>>descAplicar;
        system("cls");
    }
    if(b==1){
        return true;
    }
    else{
        return false;
    }
}
void aplicar_descuento(float&sub_total,int _dni,int&descAplicar){
    int pos=0,desCliente=1;
    float aux;
    Descuento reg;
    while(reg.leer(pos)==true){
        if(_dni==reg.get_DNI() && reg.get_Estado() == true){
            if(descAplicar==desCliente){
                if(reg.get_Porcentaje()==0 && reg.get_Estado()==true){
                    if(sub_total-reg.get_Monto_Descuento()>=0){
                        sub_total=sub_total-reg.get_Monto_Descuento();
                        reg.set_Estado(false);
                        reg.sobre_escribir(pos);
                    }
                    else{
                        system("cls");
                        cout<<endl<<endl<<"No se pudo aplicar descuento";
                        cout<<endl<<"El MONTO TOTAL debe ser igual o mayor a cero con el descuento aplicado"<<endl<<endl<<endl;
                        system("pause");
                        system("cls");
                    }
                    return;
                }
                if(reg.get_Monto_Descuento()==0 && reg.get_Estado()==true){
                    aux=sub_total*reg.get_Porcentaje()/100;
                    sub_total=sub_total-aux;
                    reg.set_Estado(false);
                    reg.sobre_escribir(pos);
                    return;
                }

            }
            desCliente++;
        }
        pos++;
    }
}
//Complementos de opciones de menu
bool mostrar_productos_agregados(int idVenta){
    int pos=0,posicionHerramienta;
    bool hay=false;
    Detalleventa obj;
    Herramientas objHerramienta;
    while(obj.leer(pos++)){
        if(obj.getIDventa()==idVenta && obj.getEstado() == true){
                hay=true;
                cout<<endl<<endl<<"Cod:"<<obj.getIDherramienta();
                posicionHerramienta=buscarCodigoHerramienta(obj.getIDherramienta());
                objHerramienta.leer(posicionHerramienta);
                cout<<"   "<<objHerramienta.getNomherramienta();
                cout<<"   $"<<obj.getPrecio()<<"    Cantidad:"<<obj.getCantidad();
        }
    }
    return hay;
}
int buscar_producto_en_lista_compra(int buscarCod,int IDventa){
    int pos=0,posicion=0;
    Detalleventa obj;
    while(obj.leer(pos++)){
        if(obj.getIDherramienta()==buscarCod && obj.getEstado()==true && obj.getIDventa()==IDventa){
            return posicion;
        }
        posicion++;
    }
    return -1;
}



/////////////////////////////////////////////////////////////////////
///                    GERENCIA-HERRAMIENTAS                      ///
/////////////////////////////////////////////////////////////////////


//MENU HERRAMIENTAS
void menu_herramientas_gerencia(){
    char desicion='p';
    int codigoHerramienta,posicion;
    while(desicion!='0'){
        cout<<endl<<"****************MENU HERRAMIENTAS****************"<<endl<<endl;
        cout<<endl<<"1-Agregar herramienta";
        cout<<endl<<"2-Modificar herramienta";
        cout<<endl<<"3-Dar de baja herramienta";
        cout<<endl<<"4-Buscar herramienta";
        cout<<endl<<"5-Ver herramientas";

        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                agregar_producto();
                system("pause");
                break;
            case '2':
                system("cls");
                menu_gerencia_modificarHerramientas();
                break;
            case '3':
                codigoHerramienta=menu_buscar_codigo_herramienta_por();
                if(codigoHerramienta>=0){
                    posicion=buscarCodigoHerramienta(codigoHerramienta);
                    system("cls");
                    if(baja_logica_herramienta(posicion)){
                        cout<<endl<<endl<<"<<SE DIO DE BAJA CORRECTAMENTE>>"<<endl<<endl;
                    }
                    else{
                        cout<<endl<<endl<<"<<NO SE DIO LA BAJA>>"<<endl<<endl;
                    }
                    system("pause");
                }
                break;
            case '4':
                system("cls");
                menu_gerencia_buscarHerramientas();
                break;
            case '5':
                system("cls");
                menu_gerencia_verHerramientas();
                break;
        }
        system("cls");
    }
}


//1
void agregar_producto(){
    Herramientas objHerramienta;

    objHerramienta.cargar();
    if( filtrar_herramientas(objHerramienta.getID_Herramienta()) ){
        if(objHerramienta.getPrecio()>0&&objHerramienta.getStock()>=0){
            objHerramienta.mostrar();
            if(objHerramienta.escribir()){
                system("cls");
                cout<<endl<<endl<<"<<Se guardo con exito>>"<<endl<<endl;
                system("pause");
                system("cls");
        }
            else{
                system("cls");
                cout<<endl<<endl<<"<<Fallo al guardar>>"<<endl<<endl;
                system("pause");
                system("cls");
            }

        }
        else{
            if(objHerramienta.getPrecio()<=0){
                cout<<endl<<"<<Precio ingresado invalido>>";
                cout<<endl;
            }
            else{
                 cout<<endl<<"<<Stock ingresado invalido>>";
                 cout<<endl;
            }
        }


    }
    else{
        system("cls");
        cout<<endl<<endl<<"<<La herramienta ya se encuentra en el archivo>>"<<endl<<endl;
        system("pause");
        system("cls");
    }
}
bool filtrar_herramientas(int codHerramienta){
    int pos=0;
    Herramientas objHerramientas;
    FILE *p;
    p=fopen("herramientas.dat","rb");
    if(p==NULL){
        return true;
    }
    while(objHerramientas.leer(pos++)){
        if(codHerramienta==objHerramientas.getID_Herramienta()){
            return false;
        }
    }
    return true;
}
void listar_todas_herramientas(){
    int pos=0;
    Herramientas objHerramientas;
    while(objHerramientas.leer(pos++)){
        objHerramientas.mostrar();
        cout<<endl<<endl<<"-----------------------------------------------"<<endl<<endl;
    }
}
//2
void menu_gerencia_modificarHerramientas(){
    int codigoHerramienta,posicion,desicion=-1;
    while(desicion!=0){
        cout<<endl<<endl<<"******MENU MODIFICACION DE HERRAMIENTAS******"<<endl<<endl;
        cout<<endl<<"1- Modificar precio";
        cout<<endl<<"2- Modificar stock";
        cout<<endl<<endl<<"0- Volver atras";
        cin>>desicion;
        switch(desicion){
            case 1:
                codigoHerramienta=menu_buscar_codigo_herramienta_por();
                cout<<endl<<codigoHerramienta;
                system("pause");
                if(codigoHerramienta>=0){
                    posicion=buscarCodigoHerramienta(codigoHerramienta);
                    if(modificar_precio_herramienta(posicion)){
                        cout<<endl<<endl<<"<<PRECIO GUARDADO CON EXITO>>"<<endl<<endl;
                    }
                    else{
                        cout<<endl<<endl<<"<<NO SE MODIFICO>>"<<endl<<endl;
                    }
                    system("pause");
                    desicion=0;
                }
                else{
                    if(codigoHerramienta==-1){
                        cout<<endl<<endl<<"<<ESE PRODUCTO NO SE ENCUENTRA EN EL INVENTARIO>>"<<endl<<endl;
                        system("pause");
                        desicion=0;
                    }
                }
                break;
            case 2:
                codigoHerramienta=menu_buscar_codigo_herramienta_por();

                if(codigoHerramienta>=0){
                    posicion=buscarCodigoHerramienta(codigoHerramienta);
                    if(modificar_stock_herramienta(posicion)){
                        cout<<endl<<endl<<"<<SE MODIFICO CON EXITO>>"<<endl<<endl;
                    }
                    else{
                        cout<<endl<<endl<<"<<NO SE MODIFICO>>"<<endl<<endl;
                    }
                    system("pause");
                    desicion=0;
                }
                else{
                    if(codigoHerramienta==-1){
                        cout<<endl<<endl<<"<<ESE PRODUCTO NO SE ENCUENTRA EN EL INVENTARIO>>"<<endl<<endl;
                        system("pause");
                        desicion=0;
                    }
                }
                break;
        }
        system("cls");
    }
}
bool modificar_precio_herramienta(int posicion){
    float precioNuevo;
    bool escribio;
    bool val = true;

    while(val){
         cout<<endl<<endl<<"Ingresar el precio que desea establecer: ";
            cin>>precioNuevo;
            if(precioNuevo>0){
                val = false;
            }
            else{
                cout<<endl<<endl<<"Precio ingresado menor a 0, por favor vuelva a ingresar un precio valido ";
            }
    }

    system("cls");
    Herramientas obj;
    obj.leer(posicion);
    obj.setPrecio(precioNuevo);
    escribio=obj.sobre_escribir(posicion);
    return escribio;
}
bool modificar_stock_herramienta(int posicion){
    char desicion;
    int stockNuevo;
    bool escribio;
    Herramientas obj;
    bool val = true;
    obj.leer(posicion);
    while(desicion!='1' && desicion !='2'){
        cout<<endl<<"--Que desea hacer--"<<endl<<endl;
        cout<<"1-Agregar stock      2-Quitar stock";
        cin>>desicion;
    }
    if(desicion=='1'){

            while(val){
                cout<<endl<<endl<<"Cantidad de stock a agregar: ";
                cin>>stockNuevo;
                if(stockNuevo>0){
                    val = false;
                }
                else{
                    cout<<endl<<endl<<"Stock ingresado invalido, por favor vuelva a ingresar ";
                }
            }

        obj.setStock(obj.getStock()+stockNuevo);
        escribio=obj.sobre_escribir(posicion);
    }
    else{

         while(val){
                cout<<endl<<endl<<"Cantidad de stock a agregar: ";
                cin>>stockNuevo;
                if(stockNuevo>0){
                    val = false;
                }
                else{
                    cout<<endl<<endl<<"Stock ingresado invalido, por favor vuelva a ingresar ";
                }
            }

        if(obj.getStock()>=stockNuevo){
            obj.setStock(obj.getStock()-stockNuevo);
            escribio=obj.sobre_escribir(posicion);
        }
        else{
            cout<<"[ERROR] El stock a quitar es mayor al actual";
        }
    }
    return escribio;
}
//3
bool baja_logica_herramienta(int posicion){
    char desicion;
    bool escribio=false;
    system("cls");
    while(desicion!='y' && desicion!='Y'&& desicion!='n' && desicion!='N'){
        cout<<"Esta seguro que desea dar de baja esta herramienta? (Y/N)";
        cin>>desicion;
    }
    if(desicion=='y' || desicion=='Y'){
        Herramientas obj;
        obj.leer(posicion);
        obj.setEstado(false);
        escribio=obj.sobre_escribir(posicion);
        return escribio;
    }
    return escribio;
}
//4
void menu_gerencia_buscarHerramientas(){
    char desicion='p';
    while(desicion!='0'){
        cout<<endl<<endl<<"****MENU BUSCAR HERRAMIENTAS****"<<endl<<endl;
        cout<<endl<<"1-Buscar por nombre";
        cout<<endl<<"2-Buscar por codigo de herramienta";
        cout<<endl<<"3-Buscar por codigo de marca";
        cout<<endl<<endl<<"0-Volver atras";
        cin>>desicion;
        switch(desicion){
        case '1':
            system("cls");
            if(buscar_herramienta_por_nombre()<0){
                cout<<endl<<endl<<"<<No se encuentra dentro del archivo>>"<<endl<<endl;
            }
            system("pause");
            break;
        case '2':
            system("cls");
            if(buscar_herramienta_por_codigo()<0){
                cout<<endl<<endl<<"<<No se encuentra dentro del archivo>>"<<endl<<endl;
            }
            system("pause");
            break;
        case '3':
            system("cls");
            if(buscar_herramienta_por_marca()<0){
                cout<<endl<<endl<<"<<No se encuentra dentro del archivo>>"<<endl<<endl;
            }
            system("pause");
            break;
        }
        system("cls");
    }
}
int buscar_herramienta_por_nombre(){
    int pos=0,cont=0,contCoinciden=0,contador=0;
    char nombreHerramienta[50],herramientaArchivo[50];
    Herramientas obj;
    cout<<endl<<"Ingresar nombre de la herramienta a buscar:";
    cin.ignore();
    cin.getline(nombreHerramienta,50);
    system("cls");
    strlwr(nombreHerramienta);
    while(nombreHerramienta[cont]!='\0'){
        cont++;
    }
    while(obj.leer(pos++)){
        int i=0,x;
        strcpy( herramientaArchivo,obj.getNomherramienta() );
        strlwr(herramientaArchivo);
        while(herramientaArchivo[i]!='\0'){
            if(herramientaArchivo[i]==nombreHerramienta[0]){
                int contIguales=0;
                x=i;
                for(int j=0;j<cont;j++){
                    if(herramientaArchivo[x]== nombreHerramienta[j]){
                        contIguales++;
                    }
                    x++;
                }
                if(contIguales==cont){
                    contador++;
                    obj.mostrar();
                    cout<<endl<<endl<<"------------------------"<<endl<<endl;
                }
            }
            i++;
        }
    }
    if(contador==0){
        return false;
    }
    else{
        return true;
    }
}
int buscar_herramienta_por_codigo(){
    int codigoHerramienta,pos=0;
    bool aux = true;

    while(aux){
        cout<<endl<<endl<<"Ingresar codigo de herramienta: ";
        cin>>codigoHerramienta;
        if(codigoHerramienta>0){
            aux= false;
        }
        else{
            cout<<endl<<endl<<"Codigo de herramienta invalido, por favor ingrese de nuevo ";
        }
    }
    system("cls");
    Herramientas obj;
    while(obj.leer(pos++)){
        if(obj.getID_Herramienta()==codigoHerramienta){
            obj.mostrar();
             cout<<endl<<endl<<"------------------------"<<endl<<endl;
            return true;
        }
    }
    return false;
}
int buscar_herramienta_por_marca(){
    int codigoMarca,pos=0,cont=0;
    bool val = true;
    while(val){
         cout<<endl<<endl<<"Ingresar codigo de marca: ";
        cin>>codigoMarca;

        if(codigoMarca>0){
            val = false;

        }
        else{
            cout<<endl<<endl<<"Codigo de marca invalido, por favor vuelva a ingresar el codigo ";
        }

    }


    system("cls");
    Herramientas obj;
    while(obj.leer(pos++)){
        if(obj.getID_marca()==codigoMarca){
            obj.mostrar();
            cout<<endl<<endl<<"----------------------------"<<endl<<endl;
            cont++;
        }
    }
    if(cont==0){
        return false;
    }
    else{
        return true;
    }
}
//5
void menu_gerencia_verHerramientas(){
    char desicion='p';
    while(desicion!='0'){
        cout<<endl<<endl<<"****MENU DE VIZUALISACION DE HERRAMIENTAS****"<<endl<<endl;
        cout<<endl<<"1-Ordenadas por fecha de alta";
        cout<<endl<<"2-Ordenadas por nombre";
        cout<<endl<<"3-Ordenadas por precio";
        cout<<endl<<"4-Ordenadas por codigo";
        cout<<endl<<endl<<"0-Volver atras";
        cin>>desicion;
        switch(desicion){
        case '1':
            system("cls");
            ordenarHerramientas(4);
            system("pause");
            break;
        case '2':
            system("cls");
            ordenarHerramientas(2);
            system("pause");
            break;
        case '3':
            system("cls");
            ordenarHerramientas(3);
            system("pause");
            break;
        case '4':
            system("cls");
            ordenarHerramientas(1);
            system("pause");
            break;
        }
        system("cls");
    }
}
void ordenarHerramientas(int desicion){
    int cantidad;
    cantidad=cantidad_herramientas();
    Herramientas *vObj,obj;
    vObj=new Herramientas[cantidad];
    cargar_vectorHerramientas(vObj);
    switch(desicion){
    case 1:
        ordenar_vectorHerramientas_porCodigo(vObj,cantidad);
        break;
    case 2:
        ordenar_vectorHerramientas_porNombre(vObj,cantidad);
        break;
    case 3:
        ordenar_vectorHerramientas_porPrecio(vObj,cantidad);
        break;
    case 4:
        ordenar_vectorHerramientas_porFecha(vObj,cantidad);
        break;
    }
    for(int i=0;i<cantidad;i++){
        vObj[i].mostrar();
        cout<<endl<<endl<<"----------------------------------"<<endl<<endl;
    }
    delete[] vObj;
}
void ordenar_vectorHerramientas_porNombre(Herramientas *vObj, int cantidad){
    int posMax;
    Herramientas aux;
    for(int i=0;i<cantidad-1;i++){
        posMax=i;
        for(int j=i+1;j<cantidad;j++){
            if( _strcmpi(vObj[j].getNomherramienta(),vObj[posMax].getNomherramienta()) < 0 ){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Herramientas ordenadas por Nombre********"<<endl<<endl;
}
void ordenar_vectorHerramientas_porPrecio(Herramientas *vObj, int cantidad){
    int posMax;
    Herramientas aux;
    for(int i=0;i<cantidad-1;i++){
        posMax=i;
        for(int j=i+1;j<cantidad;j++){
            if(vObj[j].getPrecio()<vObj[posMax].getPrecio()){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Herramientas ordenadas por Precio********"<<endl<<endl;
}
void ordenar_vectorHerramientas_porCodigo(Herramientas *vObj, int cantidad){
    int posMax;
    Herramientas aux;
    for(int i=0;i<cantidad-1;i++){
        posMax=i;
        for(int j=i+1;j<cantidad;j++){
            if(vObj[j].getID_Herramienta() < vObj[posMax].getID_Herramienta()){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Herramientas ordenadas por Codigo********"<<endl<<endl;
}
void ordenar_vectorHerramientas_porFecha(Herramientas *vObj, int cantidad){
    int posMax;
    Herramientas aux;
    for(int i=0;i<cantidad-1;i++){
        posMax=i;
        for(int j=i+1;j<cantidad;j++){
            if( vObj[j].getFabricado().getAnio() < vObj[posMax].getFabricado().getAnio() ){
                posMax=j;
            }
            else{
                if ( vObj[j].getFabricado().getAnio() ==  vObj[posMax].getFabricado().getAnio()){
                    if( vObj[j].getFabricado().getMes() <  vObj[posMax].getFabricado().getMes()){
                        posMax=j;
                    }
                    else{
                        if( vObj[j].getFabricado().getMes() ==  vObj[posMax].getFabricado().getMes()){
                            if( vObj[j].getFabricado().getDia() <  vObj[posMax].getFabricado().getDia()){
                                posMax=j;
                            }
                        }
                    }
                }
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Herramientas ordenadas por Fecha********"<<endl<<endl;
}

//Complementos 2-3
// CODIGO HERRAMIENTA ARREGLADO
int menu_buscar_codigo_herramienta_por(){
    char desicion='p',codigoHerramienta;
    int cod;
    while(desicion!='0'){
        system("cls");
        cout<<endl<<endl<<"****MENU BUSCAR HERRAMIENTAS****"<<endl<<endl;
        cout<<endl<<"1-Buscar por nombre";
        cout<<endl<<"2-Buscar por codigo de herramienta";
        cout<<endl<<endl<<"0-Volver atras";
        cin>>desicion;
        switch(desicion){
        case '1':
            system("cls");
            codigoHerramienta=buscar_herramienta_nombre();
            return codigoHerramienta;
            break;
        case '2':
            system("cls");
            bool aux = true;
            while(aux){
                cout<<"Ingresar codigo de herramienta: ";
                cin>>cod;

                if(cod>0){
                    aux=false;
                }
                else{
                    cout<<"El codigo de herramienta menor a 0, por favor vuelva a ingresarlo ";
                }

            }

            return cod;
            break;
        }
        system("cls");
    }
    return-2;
}

// BUSCADOR POR NOMBRE ARREGLADO
int buscar_herramienta_nombre(){
    int cantidad,eleccion;
    char nombreHerramienta[50];
    bool aux= true;
    cout<<endl<<endl<<"Ingrese el nombre de la herramienta:";
    cin.ignore();
    cin.getline(nombreHerramienta,50);

    cantidad=buscar_herramienta_por_nombre(cantidad,nombreHerramienta);
    Herramientas *vObj;
    cout<<cantidad;

    vObj=new Herramientas[cantidad];
    cargarVectorconProductos(vObj,nombreHerramienta);
    for(int i=0;i<cantidad;i++){
        cout<<endl<<i+1<<"-    "<<vObj[i].getNomherramienta()<<"   $"<<vObj[i].getPrecio()<<"   Stock:"<<vObj[i].getStock()<<"   Codigo:"<<vObj[i].getID_Herramienta();
    }
    cout<<endl<<endl<<"Que numero desea elegir:";
    cin>>eleccion;
    while(eleccion>cantidad){
        system("cls");
        for(int i=0;i<cantidad;i++){
        cout<<endl<<i+1<<"-    "<<vObj[i].getNomherramienta()<<"   $"<<vObj[i].getPrecio()<<"   Stock:"<<vObj[i].getStock()<<"   Codigo:"<<vObj[i].getID_Herramienta();
        }
        cout<<endl<<endl<<"Que numero desea elegir:";
        cin>>eleccion;
    }
    return vObj[eleccion-1].getID_Herramienta();
}
int buscarCodigoHerramienta(int codigoHerramienta){
    int pos=0,posicion=0;
    Herramientas obj;
    while(obj.leer(pos++)){
        if(obj.getID_Herramienta()== codigoHerramienta){
            return posicion;
        }
        posicion++;
    }
    return -1;
}

//Complementos 5
int cantidad_herramientas(){
    int cantidad;
    FILE *p;
    p=fopen("herramientas.dat","rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Herramientas);
    fclose(p);
    return cantidad;
}
void cargar_vectorHerramientas(Herramientas *vObj){
    int pos=0,i=0;
    Herramientas obj;
    while(obj.leer(pos++)){
        vObj[i]=obj;
        i++;
    }
}

/////////////////////////////////////////////////////////////////////
///        GERENCIA-CREAR USUARIO Y REGISTRAR EMPLEADOS           ///
/////////////////////////////////////////////////////////////////////

//MENU CREAR Y REGISTRAR
void menu_usuarios_y_registrar_gerencia(){
    char desicion='p';
    int codigoHerramienta,posicion;
    while(desicion!='0'){
        cout<<endl<<"****************MENU CREAR USUARIOS Y REGISTRAR EMPLEADOS****************"<<endl<<endl;
        cout<<endl<<"1-Registrar nuevo vendedor";
        cout<<endl<<"2-Registrar nuevo gerente";
        cout<<endl<<"3-Modificar usuario y clave de vendedor";
        cout<<endl<<"4-Modificar usuario y clave de gerente";
        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                registrar_vendedor();
                system("pause");
                break;
            case '2':
                system("cls");
                registrar_gerente();
                system("pause");
                break;
            case '3':
                system("cls");
                modificar_cuenta_vendedor();
                break;
            case '4':
                system("cls");
                modificar_cuenta_gerente();
                break;
        }
        system("cls");
    }
}
//1
void registrar_vendedor(){
    bool validado;
    Vendedor obj;
    obj.cargar();
    obj.escribir();
    /*
    if(registrar_usuario(obj.getUsuario())){
        if(obj.escribir()){
            cout<<endl<<endl<<"<<Se guardo correctamente>>"<<endl<<endl;
        }
        else{
            cout<<endl<<endl<<"<<ERROR-No se pudo guardar>>"<<endl<<endl;
        }
    }
    */
}
//2
void registrar_gerente(){
    Gerente obj;
    obj.cargar();
    obj.escribir();
    /*
    if(registrar_usuario(obj.getUsuario())){
        if(obj.escribir()){
            cout<<endl<<endl<<"<<Se guardo correctamente>>"<<endl<<endl;
        }
        else{
            cout<<endl<<endl<<"<<ERROR-No se pudo guardar>>"<<endl<<endl;
        }
    }
    */
}
//3
void modificar_cuenta_vendedor(){
    int posicion,dni;
    bool validado=false;
    char usuarioNuevo[30],claveNueva[30];
    cout<<"Ingresar el numero de DNI del usuario:";
    cin>>dni;
    posicion=buscar_posicion_vendedor_por_dni(dni);
    if(posicion<0){
        system("cls");
        cout<<endl<<endl<<"<<NO HAY USUARIOS REGISTRADOS CON ESE DNI>>"<<endl;
        system("pause");
        return;
    }
    Vendedor obj;
    obj.leer(posicion);
    while(validado==false){
        system("cls");
        cout<<endl<<"Ingresar nuevo nombre de usuario: ";
        cin>>usuarioNuevo;
        if(obj.setUsuario(usuarioNuevo)){
            validado=true;
        }
    }
    cout<<endl<<"Ingresar nueva clave: ";
    cin>>claveNueva;
    system("cls");
    obj.setClave(claveNueva);
    if(obj.sobre_escribir(posicion)){
        cout<<endl<<endl<<"<<Se guardo con EXITO>>"<<endl<<endl;
        system("pause");
    }
    else{
        cout<<endl<<endl<<"<<Fallo al guardar>>"<<endl<<endl;
        system("pause");
    }

}
int buscar_posicion_vendedor_por_dni(int dni){
    int pos=0,posicion=0;
    Vendedor obj;
    while(obj.leer(pos++)){
        if(dni==obj.getdni()){
            return posicion;
        }
        posicion++;
    }
    return -1;
}
//4
void modificar_cuenta_gerente(){
    int posicion,dni;
    char usuarioNuevo[30],claveNueva[30];
    bool validado=false;
    cout<<"Ingresar el numero de DNI del usuario:";
    cin>>dni;
    posicion=buscar_posicion_gerente_por_dni(dni);
    if(posicion<0){
        system("cls");
        cout<<endl<<endl<<"<<NO HAY USUARIOS REGISTRADOS CON ESE DNI>>"<<endl;
        system("pause");
        return;
    }
    Gerente obj;
    obj.leer(posicion);
    while(validado==false){
        system("cls");
        cout<<endl<<"Ingresar nuevo nombre de usuario: ";
        cin>>usuarioNuevo;
        if(obj.setUsuario(usuarioNuevo)){
            validado=true;
        }
    }
    cout<<endl<<"Ingresar nueva clave: ";
    cin>>claveNueva;
    system("cls");
    obj.setClave(claveNueva);
    if(obj.sobre_escribir(posicion)){
        cout<<endl<<endl<<"<<Se guardo con EXITO>>"<<endl<<endl;
        system("pause");
    }
    else{
        cout<<endl<<endl<<"<<Fallo al guardar>>"<<endl<<endl;
        system("pause");
    }

}
int buscar_posicion_gerente_por_dni(int dni){
    int pos=0,posicion=0;
    Gerente obj;
    while(obj.leer(pos++)){
        if(dni==obj.getdni()){
            return posicion;
        }
        posicion++;
    }
    return -1;
}


//Validaciones de USUARIO en setUsuario() en GERENTE y VENDEDOR
bool filtrar_gerente(char*usuario){
    int pos=0;
    bool disponible=true;
    Gerente aux;
    while(aux.leer(pos++)){
        if( strcmp( aux.getUsuario(),usuario) == 0){
            disponible=false;
        }
    }
    return disponible;
}
bool filtrar_vendedor(char*usuario){
    int pos = 0;
    Vendedor reg;
    while (reg.leer(pos++) == true) {
        if (strcmp(usuario,reg.getUsuario())==0) {
            return false;
        }
    }
    return true;
}

//Validaciones de DNI en setDni() en PERSONA
bool filtrar_dni_gerente(int dni){
    int pos=0;
    Gerente aux;
    while(aux.leer(pos++)){
        if( aux.getdni()==dni){
            return false;
        }
    }
    return true;
}
bool filtrar_dni_vendedor(int dni){
    int pos = 0;
    Vendedor reg;
    while (reg.leer(pos++) == true) {
        if (reg.getdni()==dni){
            return false;
        }
    }
    return true;
}


/////////////////////////////////////////////////////////////////////
///                      GERENCIA-REPORTES                        ///
/////////////////////////////////////////////////////////////////////
void menu_reportes_gerencia(){
    char desicion='p';
    int posicionCodHerramienta;
    while(desicion!='0'){
        cout<<endl<<"****************MENU DE REPORTES****************"<<endl<<endl;
        cout<<endl<<"1-Recaudado por herramienta en un rango de fechas";
        cout<<endl<<"2-Recaudacion por marca en un rango de fechas";
        cout<<endl<<"3-Recaudado por rango de edad de clientes en un rango de fecha";
        cout<<endl<<"4-Gastos por pagos mensuales a sueldos de empleados por anio, incluyendo comisiones";
        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                posicionCodHerramienta=menu_buscar_codigo_herramienta_por();
                if(posicionCodHerramienta==-1){
                    cout<<endl<<endl<<"No se encontro la herramienta";
                }
                if(posicionCodHerramienta>=0){
                    recaudado_por_herramienta(posicionCodHerramienta);
                }
                system("pause");
                break;
            case '2':
                system("cls");
                buscar_recaudado_por_marca();
                system("pause");
                break;
            case '3':
                system("cls");
                recaudado_por_rango_edad();
                break;
            case '4':
                system("cls");
                gastos_pagos_mensuales_a_vendedores();
                break;
        }
        system("cls");
    }
}
//1
void recaudado_por_herramienta(int posicionCodHerramienta){
    int codigoHerramienta,diaI,mesI,anioI,diaF,mesF,anioF,validacion,posicionVenta,pos=0;
    bool validarFecha1,validarFecha2;
    bool validacionMayor,validacionMenor;
    float acuRecaudado=0;
    system("cls");
    cout<<endl<<"--Ingresar fecha de inicio--";
    cout<<endl<<"Dia: ";
    cin>>diaI;
    cout<<endl<<"Mes: ";
    cin>>mesI;
    cout<<endl<<"Anio: ";
    cin>>anioI;
    system("cls");
    cout<<endl<<"--Ingresar fecha de fin--";
    cout<<endl<<"Dia: ";
    cin>>diaF;
    cout<<endl<<"Mes: ";
    cin>>mesF;
    cout<<endl<<"Anio: ";
    cin>>anioF;
    validarFecha1=validar_fecha(diaI,mesI,anioI);
    validarFecha2=validar_fecha(diaF,mesF,anioF);
    system("cls");
    if(validarFecha1==true && validarFecha2==true){
        validacion=comparar_fechas(diaI,mesI,anioI,diaF,mesF,anioF);
        if(validacion==0){
            cout<<endl<<endl<<"[ERROR]- La primer fecha ingresada es mayor a la segunda";
            system("pause");
        }
        if(validacion==-1){
            cout<<endl<<endl<<"[ERROR]- Ambas fechas son iguales";
            system("pause");
        }
        if(validacion==1){
            Herramientas obj;
            obj.leer(posicionCodHerramienta-1);
            Detalleventa objDetalleV;
            while(objDetalleV.leer(pos++)){
                if( (obj.getID_Herramienta()==objDetalleV.getIDherramienta()) && (objDetalleV.getEstado()==true) ){
                    posicionVenta=buscar_pos_venta(objDetalleV.getIDventa());
                    Venta objVenta;
                    objVenta.leer(posicionVenta);
                    validacionMayor=es_mayor_a_fecha1( diaI,mesI,anioI,objVenta.getFechav().getDia(),objVenta.getFechav().getMes(),objVenta.getFechav().getAnio() );
                    validacionMenor=es_menor_a_fecha2( diaF,mesF,anioF,objVenta.getFechav().getDia(),objVenta.getFechav().getMes(),objVenta.getFechav().getAnio() );
                    if(validacionMayor==true && validacionMenor==true){
                        acuRecaudado+=objDetalleV.getPrecio()*objDetalleV.getCantidad();
                    }
                }
            }
            cout<<endl<<endl<<"Total recaudado por esta herramienta: $"<<acuRecaudado<<endl<<endl<<endl;
        }
    }
    else{
        if(validarFecha1==false){
            cout<<endl<<endl<<"[ERROR]-La primer fecha que ingresaste no es real";
        }
        if(validarFecha2==false){
            cout<<endl<<endl<<"[ERROR]-La segunda fecha que ingresaste no es real";
        }
        system("pause");
        system("cls");
    }
}
//2
void buscar_recaudado_por_marca(){
    int pos=0,codMarca,codMarcaHerramientaArchivo,posicionVenta;
    int diaI,mesI,anioI,diaF,mesF,anioF,validacion;
    bool validarFecha1,validarFecha2,validacionMayor,validacionMenor;
    float acuRecaudado=0;
    cout<<endl<<endl<<"Ingresar codigo de marca: ";
    cin>>codMarca;
    system("cls");
    cout<<endl<<endl<<"--Ingresar Fecha de Inicio--"<<endl<<endl;
    cout<<"Dia: ";
    cin>>diaI;
    cout<<"Mes: ";
    cin>>mesI;
    cout<<"Anio: ";
    cin>>anioI;

    system("cls");
    cout<<endl<<endl<<"--Ingresar Fecha de Final--"<<endl<<endl;
    cout<<"Dia: ";
    cin>>diaF;
    cout<<"Mes: ";
    cin>>mesF;
    cout<<"Anio: ";
    cin>>anioF;
    validarFecha1=validar_fecha(diaI,mesI,anioI);
    validarFecha2=validar_fecha(diaF,mesF,anioF);
    system("cls");
    if(validarFecha1==true && validarFecha2==true){
        validacion=comparar_fechas(diaI,mesI,anioI,diaF,mesF,anioF);
        if(validacion==0){
            cout<<endl<<endl<<"[ERROR]- La primer fecha ingresada es mayor a la segunda";
            system("pause");
        }
        if(validacion==-1){
            cout<<endl<<endl<<"[ERROR]- Ambas fechas son iguales";
            system("pause");
        }
        if(validacion==1){
            Detalleventa objD;
            while(objD.leer(pos++)){
                if(objD.getEstado()==true){
                    posicionVenta=buscar_pos_venta(objD.getIDventa());
                    Venta objV;
                    objV.leer(posicionVenta);
                    validacionMayor=es_mayor_a_fecha1( diaI,mesI,anioI,objV.getFechav().getDia(),objV.getFechav().getMes(),objV.getFechav().getAnio() );
                    validacionMenor=es_menor_a_fecha2( diaF,mesF,anioF,objV.getFechav().getDia(),objV.getFechav().getMes(),objV.getFechav().getAnio() );
                    if(validacionMayor==true && validacionMenor==true){
                        codMarcaHerramientaArchivo=buscar_marca_herramienta(objD.getIDherramienta());
                        if(codMarca==codMarcaHerramientaArchivo){
                            acuRecaudado+=objD.getCantidad()*objD.getPrecio();
                        }
                    }
                }
            }
            cout<<endl<<endl<<"Total recaudado por esta marca: $"<<acuRecaudado<<endl<<endl<<endl;
        }
    }
    else{
        if(validarFecha1==false){
            cout<<endl<<endl<<"[ERROR]-La primer fecha que ingresaste no es real";
        }
        if(validarFecha2==false){
            cout<<endl<<endl<<"[ERROR]-La segunda fecha que ingresaste no es real";
        }
        system("pause");
        system("cls");
    }



}
int buscar_marca_herramienta(int ID_herramienta){
    int pos=0,codMarca;
    Herramientas obj;
    while(obj.leer(pos++)){
        if(obj.getID_Herramienta()==ID_herramienta){
            return obj.getID_marca();
        }
    }
    return -1;
}
//3
void recaudado_por_rango_edad(){
    int edadInicio,edadFin,pos=0,edadCliente,pos2=0,pos3=0;
    int diaI,mesI,anioI,diaF,mesF,anioF;
    bool validarFecha1,validarFecha2,validacionMayor,validacionMenor;
    float acuRecaudado=0;
    cout<<endl<<endl<<"----Ingresar rango de edades----"<<endl<<endl;
    cout<<endl<<endl<<"Ingresar desde que edad(edad comienzo de rango): ";
    cin>>edadInicio;
    cout<<"Ingresar hasta que edad(edad fin de rango): ";
    cin>>edadFin;
    system("cls");

    cout<<endl<<endl<<"********Ingresar rango de Fecha********"<<endl<<endl;
    cout<<"--Ingresar desde que fecha--"<<endl<<endl;
    cout<<"Dia: ";
    cin>>diaI;
    cout<<"Mes: ";
    cin>>mesI;
    cout<<"Anio: ";
    cin>>anioI;

    cout<<endl<<endl<<"--Ingresar hasta que edad(edad finde rango)--"<<endl<<endl;
    cout<<"Dia: ";
    cin>>diaF;
    cout<<"Mes: ";
    cin>>mesF;
    cout<<"Anio: ";
    cin>>anioF;

    validarFecha1=validar_fecha(diaI,mesI,anioI);
    validarFecha2=validar_fecha(diaF,mesF,anioF);
    if(validarFecha1==true && validarFecha2==true){
        Cliente objC;
        while(objC.leer(pos++)){
            edadCliente=calcular_edad_cliente(objC.getfecha().getDia(),objC.getfecha().getMes(),objC.getfecha().getAnio());
            if(edadCliente>=edadInicio && edadCliente<=edadFin){
                Venta objV;
                while(objV.leer(pos2++)){
                    if(objC.getdni()==objV.getIDcliente()){
                        validacionMayor=es_mayor_a_fecha1( diaI,mesI,anioI,objV.getFechav().getDia(),objV.getFechav().getMes(),objV.getFechav().getAnio() );
                        validacionMenor=es_menor_a_fecha2( diaF,mesF,anioF,objV.getFechav().getDia(),objV.getFechav().getMes(),objV.getFechav().getAnio() );
                        if(validacionMayor==true && validacionMenor==true){
                            Detalleventa objD;
                            while(objD.leer(pos3++)){
                                if(objV.getID()==objD.getIDventa() && objD.getEstado()==true){
                                    acuRecaudado+=objD.getCantidad()*objD.getPrecio();
                                }
                            }
                            pos3=0;
                        }
                    }
                }
                pos2=0;
            }
        }

        cout<<endl<<endl<<"Recaudado: $"<<acuRecaudado<<endl<<endl<<endl;
        system("pause");
    }
    else{
        if(validarFecha1==false){
            cout<<endl<<endl<<"[ERROR]-La primer fecha que ingresaste no es real";
        }
        if(validarFecha2==false){
            cout<<endl<<endl<<"[ERROR]-La segunda fecha que ingresaste no es real";
        }
        system("pause");
        system("cls");
    }
}
int calcular_edad_cliente(int dia,int mes,int anio){
    int diaActual,mesActual,anioActual,edadCliente;
    time_t fecha_actual = time(0);
    tm*time = localtime(&fecha_actual);

    diaActual=time->tm_mday;
    mesActual=time->tm_mon+1;
    anioActual=time->tm_year+1900;

    edadCliente=anioActual-anio-1;
    if(mesActual>mes){
        edadCliente+=1;
    }
    else{
        if(mesActual==mes){
            if(diaActual>=dia){
                edadCliente++;
            }
        }
    }
    return edadCliente;
}
//4
void gastos_pagos_mensuales_a_vendedores(){
    int pos=0,anio,pos2=0,pos3=0;
    float acuTotal,comision;
    cout<<"Ingresar anio que desea buscar: ";
    cin>>anio;
    system("pause");
    system("cls");
    Vendedor objVendedor;
    while(objVendedor.leer(pos++)){
        float acuMes[12]={};
        Venta objVenta;
        while(objVenta.leer(pos2++)){
            if(strcmp(objVendedor.getUsuario(),objVenta.getIDvendedor())==0){
                if(objVenta.getFechav().getAnio()==anio){
                    Detalleventa objD;
                    while(objD.leer(pos3++)){
                        if(objVenta.getID()==objD.getIDventa()){
                            acuMes[objVenta.getFechav().getMes()-1]+= objD.getCantidad()*objD.getPrecio();
                        }
                    }
                    pos3=0;
                }
            }
        }
        pos2=0;
        cout<<endl<<endl<<"Vendedor: "<<objVendedor.getnombre()<<" "<<objVendedor.getapellido()<<endl<<endl;
        comision=objVendedor.getComision()/100;
        for(int i=0;i<12;i++){
            cout<<endl<<endl<<endl<<endl<<"Mes: "<<i+1;
            cout<<endl<<"---------";
            cout<<endl<<"Gasto por sueldo: $"<<objVendedor.getsueldo();
            cout<<endl<<"Gasto por comision: $"<<comision*acuMes[i];
            cout<<endl<<"Gasto total por vendedor: $"<<float(objVendedor.getsueldo())+(comision*acuMes[i]);
        }
        cout<<endl<<endl<<"-------------------------------------------"<<endl;
    }
    system("pause");
}
/////////////////////////////////////////////////////////////////////
///                             FECHA                             ///
/////////////////////////////////////////////////////////////////////
/*
struct tm {
   int tm_sec;   // seconds of minutes from 0 to 61
   int tm_min;   // minutes of hour from 0 to 59
   int tm_hour;  // hours of day from 0 to 24
   int tm_mday;  // day of month from 1 to 31
   int tm_mon;   // month of year from 0 to 11
   int tm_year;  // year since 1900
   int tm_wday;  // days since sunday
   int tm_yday;  // days since January 1st
   int tm_isdst; // hours of daylight savings time
}
*/

bool validar_fecha(int _dia,int _mes,int _anio){
    bool validar=true;
    int diaActual,mesActual,anioActual;
    if(_mes<1 || _mes >12){
        validar=false;
    }
    else{
        if( (_dia<1 || _dia>31 && _mes==1) || (_dia<1 || _dia>31 && _mes==3) ||(_dia<1 || _dia>31 && _mes==5) || (_dia<1 || _dia>31 && _mes==7) || (_dia<1 || _dia>31 && _mes==8) || (_dia<1 || _dia>31 && _mes==10)|| (_dia<1 || _dia>31 && _mes==12)){
            validar=false;
        }
        else{
            if( (_dia<1 || _dia>30 && _mes==4) || (_dia<1 || _dia>30 && _mes==6) || (_dia<1 || _dia>30 && _mes==9) || (_dia<1 || _dia>30 && _mes==11) ){
                validar=false;
            }
            else{
                if(_mes==2 && _anio%4 == 0){
                    if(_dia<1 || _dia>29){
                        validar=false;
                    }
                }
                else{
                    if( _dia<1 || _dia>28 && _mes== 2 ){
                        validar=false;
                    }
                }
            }
        }
    }
    return validar;
}
bool validar_con_fecha_actual(int _dia,int _mes,int _anio){
    bool validar=true;
    int diaActual,mesActual,anioActual;
    ////Validar con fecha actual////
    time_t fecha_actual = time(0);
    tm*time = localtime(&fecha_actual);
    diaActual=time->tm_mday;
    mesActual=time->tm_mon+1;
    anioActual=time->tm_year+1900;
    if( _anio < anioActual){
        validar=false;
    }
    else{
        if(_anio==anioActual){
            if(_mes<mesActual){
                validar=false;
            }
            else{
                if(_mes==mesActual){
                    if(_dia<diaActual){
                        validar=false;
                    }
                }
            }
        }
    }

    return validar;
}
//////////////////////////////   FIN FECHA  //////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/////                                  SECCION MAXIMO                                  /////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
///                     GERENCIA-VENDEDORES                       ///
/////////////////////////////////////////////////////////////////////


//MENU VENDEDORES
void menu_vendedores_gerencia(){
    char desicion='p';
    int codigoHerramienta,posicion;
    while(desicion!='0'){
        cout<<endl<<"****************MENU VENDEDORES****************"<<endl<<endl;
        cout<<endl<<"1-Cantidad de ventas de vendedores";
        cout<<endl<<"2-Recaudacion de vendedor";
        cout<<endl<<"3-Modificar datos de vendedor";
        cout<<endl<<"4-Aumentar sueldo a vendedor";
        cout<<endl<<"5-Buscar vendedor";
        cout<<endl<<"6-Ver vendedores";
        cout<<endl<<"7-Dar porcentaje comision a vendedor";
        cout<<endl<<"8-Ver comision de vendedor por mes";
        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                cantidad_ventas_vendedor();
                system("pause");
                break;
            case '2':
                system("cls");
                recaudacion_vendedor();
                system("pause");
                break;
            case '3':
                 system("cls");
                modificar_vendedor();
                system("pause");
                break;
            case '4':
                system("cls");
                aumentar_sueldo();
                system("pause");
                break;
            case '5':
                system("cls");
                consultar_vendedor();
                system("pause");
                break;
            case '6':
                system("cls");
                submenu_listados_vendedores();
                system("pause");
                break;
            case '7':
                system("cls");
                dar_comision_vendedor();
                system("pause");
                break;
            case '8':
                system("cls");
                ver_comision_mes();
                system("pause");
                break;
        }
        system("cls");
    }
}

//1
void cantidad_ventas_vendedor(){
    char usu[50];
    Venta reg;
    int pos=0,cantventas=0;
    cout<< endl<< "Ingrese el usuario a buscar";
    cout<<endl;
    cin>>usu;
    if(verificar_vendedor_existente(usu)==1){
        while(reg.leer(pos++)==true){
            if(strcmp(reg.getIDvendedor(),usu)==0){

                cantventas++;
            }

        }
        cout<<endl<< "El vendedor "<< usu<< " tuvo "<<cantventas<< " ventas";
        cout<<endl;
    }
    else{
        cout<<endl<< "Vendedor "<<usu<< " no existente";
        cout<<endl<< "Por favor verifique los datos ingresados";
        cout<<endl;
        return;
    }
}
//2
void recaudacion_vendedor(){
    char usu[50];
    int cant,pos=0,x=0,aux=0;
    float acumulador=0;
    Venta reg,* vec;
    cout<< endl<< "Ingrese el usuario a buscar";
    cout<<endl;
    cin>>usu;
    cant=cantidad_vendedor_ID(usu);
    vec= new Venta[cant];
    while(reg.leer(pos)==true){
        if(strcmp(reg.getIDvendedor(),usu)==0){
            vec[aux]=reg;
            aux++;
        }
        pos++;
    }
    Detalleventa obj;
    int pos2=0;
    while(obj.leer(pos++)==true){
        for(x=0;x<cant;x++){
            if(vec[x].getID()==obj.getIDventa()&&obj.getEstado()==true){
                acumulador+=obj.getPrecio()*obj.getCantidad();
            }
        }
    }
    cout<<endl<< "El vendedor "<< usu << " recaudo $"<< acumulador;
    cout <<endl<< "Desea ver todos los datos de cada venta? 1=si 0=no";
    int va;
    cin>>va;
    switch(va){
        case 1:
            for(x=0;x<cant;x++){
                vec[x].mostrar();
            }
            break;
        case 2:
            delete[] vec;
            return;
        break;
    }
    delete[] vec;

}
//3
void modificar_vendedor(){
    cout<<endl<<"****************DATOS A MODIFICAR****************"<<endl<<endl;
    cout<<endl<<"1-Nombre y Apellido";
    cout<<endl<<"2-DNI";
    cout<<endl<<"3-TELEFONO";
    cout<<endl<<endl<<"0- Volver";
    int desicion;
    cin>>desicion;
    switch(desicion){
        case 1:
            nombre_apellido_vendedor();
            break;
        case 2:
            cambiar_dni();
            break;
        case 3:
            cambiar_telefono();
            break;
        case 0:
            return;
            break;
    }
}
void cambiar_telefono(){
    char usu[50];
    Vendedor obj;
    cout << endl<< "Ingrese el usuario a buscar";
    cin>>usu;
    if(verificar_vendedor_existente(usu)==1){
        int aux;
        bool ok;
        aux=posicion_vendedor(usu);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){
            char t[20];
            cout << endl<< "Ingrese el telefono a cambiar";
            cin>>t;
            obj.settelefono(t);
            ok=obj.sobre_escribir(aux);
        }
    }
    else{
        cout << endl<< "Vendedor no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}
void cambiar_dni(){
    char usu[50];
    Vendedor obj;
    bool val = true;
    int DOC;
    cout << endl<< "Ingrese el usuario a buscar";
    cin>>usu;
    if(verificar_vendedor_existente(usu)==1){
        int aux;
        bool ok;
        aux=posicion_vendedor(usu);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){


            while(val){
                cout << endl<< "Ingrese el dni a cambiar";
                cin>>DOC;
                if(DOC>0){
                    val= false;
                }
                else{
                     cout << endl<< "Documento invalido, vuelve a ingresar";
                }
            }

            obj.setdni(DOC);
            ok=obj.sobre_escribir(aux);
        }
    }
    else{
        cout << endl<< "Vendedor no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}
void nombre_apellido_vendedor(){
    char usu[50];
    Vendedor obj;
    cout << endl<< "Ingrese el usuario a buscar";
    cin>>usu;
    if(verificar_vendedor_existente(usu)==1){
        int aux;
        bool ok;
        aux=posicion_vendedor(usu);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){
            char a[50],n[50];
            cout<< endl<< "Ingrese el nuevo Apellido";
            cin>>a;
            cout << endl<< "Ingrese el nuevo Nombre";
            cin>>n;
            obj.setapellido(a);
            obj.setnombre(n);
            ok=obj.sobre_escribir(aux);
        }
    }
    else{
        cout << endl<< "Vendedor no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}
//4
void aumentar_sueldo(){
    char usu[50];
    Vendedor obj;
    cout << endl<< "Ingrese el usuario a buscar";
    cin>>usu;
    if(verificar_vendedor_existente(usu)==1){
        int aux;
        bool ok;
        aux=posicion_vendedor(usu);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){
            float s;
            bool aux =true;
            while(aux){
                cout << endl<< "Ingrese el nuevo sueldo del vendedor";
                cin>>s;

                if(s>obj.getsueldo()){
                    aux=false;
                }
                else{
                    cout << endl<< "Sueldo ingresado es menor que el anterior, por favor vuelva a ingresar  ";
                }
            }

            obj.setsueldo(s);
            ok=obj.sobre_escribir(aux);
            cout << endl<< "< SUELDO MODIFICADO CON EXITO>";
            cout<<endl;


        }
    }
    else{
        cout << endl<< "Vendedor no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}
//5
void consultar_vendedor(){
    char usu[50];
    int aux,pos=0;
    Vendedor reg;
    cout << endl<< "Ingrese el usuario a buscar";
    cin>>usu;
    if(verificar_vendedor_existente(usu)==1){
        while(reg.leer(pos++)==true){
            if(strcmp(usu,reg.getUsuario())==0){
                reg.mostrar();
            }
        }
    }
    else{
        cout << endl << "Usuario no encontrado";
        cout << endl << "Verifique los datos";
        cout << endl;
    }

}
//6
void submenu_listados_vendedores(){
    int cant,aux;
    int x=0;
    Vendedor obj;
    Vendedor * vec;
    cant= cant_reg_vendedores();
    vec= new Vendedor[cant];
    vector_vendedores(vec);
    cout<<endl<<"****************LISTADOS VENDEDORES****************"<<endl<<endl;
    cout<<endl<<"1-Listado ordenado por Apellido";
    cout<<endl<<"2-Listado ordenado por Usuario";
    cin>>aux;
    switch(aux){
        case 1:
            ordenar_vendedor_Apellido(vec,cant);
            break;
        case 2:
            ordenar_vendedor_usuario(vec,cant);
            break;
    }
    for(x=0;x<cant;x++){
        vec[x].mostrar();
        cout<<"------------------------------------------------------"<<endl;
    }
}
void ordenar_vendedor_Apellido(Vendedor *vObj,int cant){
    int posMax;
    Vendedor aux;
    for(int i=0;i<cant-1;i++){
        posMax=i;
        for(int j=i+1;j<cant;j++){
            if( _strcmpi(vObj[j].getapellido(),vObj[posMax].getapellido()) < 0 ){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Vendedores Ordenados por Apellido********"<<endl<<endl;
}
void ordenar_vendedor_usuario(Vendedor *vObj,int cant){
    int posMax;
    Vendedor aux;
    for(int i=0;i<cant-1;i++){
        posMax=i;
        for(int j=i+1;j<cant;j++){
            if( _strcmpi(vObj[j].getUsuario(),vObj[posMax].getUsuario()) < 0 ){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Vendedores Ordenados por Usuario********"<<endl<<endl;

}
//7
void dar_comision_vendedor(){
int pos=0;
float comision;
bool aux = true;
Vendedor reg;
 char usu[50];
    cout<<endl<<"Ingrese el usuario del vendedor: ";
    cin>>usu;
   while(reg.leer(pos)==true){
    if(strcmp(usu,reg.getUsuario())==0){

        while(aux){
                    cout<<endl<<"Ingrese la comision a agregar (1 al 100) : ";
                    cin>>comision;
                    if(comision>0 and comision<100){
                        aux=false;
                    }
                    else{
                        cout<<endl<<"Por favor, ingrese un porcentaje valido ";
                    }
        }
        reg.setComision(comision);
        reg.sobre_escribir(pos);
        cout<<endl<<"<PORCENTAJE GUARDADO CON EXITO> ";
        cout<<endl;

    }
    pos++;
   }

}
//8
void ver_comision_mes(){
    char nombre[50];
    float acumulador=0,porcentaje,comision_total;
    int cantVentas,mes,anio,x=0;
    Venta obj, *vec;
    cout<<endl<<"Ingrese el usuario del vendedor: ";
    cin>>nombre;
        cantVentas=cantidad_vendedor_ID(nombre);
        vec= new Venta[cantVentas];
        cargar_vector_venta(vec,nombre);
        if(vec==NULL){return;}
        if(verificar_vendedor_existente(nombre)==1){
            porcentaje=buscar_comision(nombre);
            cout<<endl<<"Ingrese el anio que busca: ";
            cin>>anio;
            cout<<endl<<"Ingrese el mes que busca: ";
            cin>>mes;
            for(x=0;x<cantVentas;x++){
                if(vec[x].getFechav().getAnio()==anio && vec[x].getFechav().getMes()==mes){
                    acumulador+=cant_vendido(vec[x].getID());
                }
            }

        }
        comision_total=acumulador*porcentaje/100;
        cout<<endl<<"La comision total del vendedor "<<nombre<<" en el mes "<<mes<<" del anio "<<anio<< " fue: $"<<comision_total;
        cout<<endl;
    delete vec;
}
//complementos
float cant_vendido(int _id){
    Detalleventa reg;
    float acu=0;
    int pos=0;
    while(reg.leer(pos++)==true){
        if(reg.getIDventa()==_id && reg.getEstado()==true){
            acu+=reg.getCantidad()*reg.getPrecio();
        }
    }
    return acu;
}
void cargar_vector_venta(Venta *vObj,char *usu){
    int pos=0,i=0;
    Venta obj;
    while(obj.leer(pos++)){
        if(strcmp(obj.getIDvendedor(),usu)==0){
            vObj[i]=obj;
            i++;
        }
    }
}
float buscar_comision(char*nom){
    Vendedor reg;
    float aux;
    int pos=0;
    while(reg.leer(pos++)==true){
        if(strcmp(nom,reg.getUsuario())==0){
            aux=reg.getComision();
        }
    }
    return aux;
}
int cant_reg_vendedores(){
    int aux;
    FILE *p;
    p=fopen("vendedores.dat","rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    aux=ftell(p)/sizeof(Vendedor);
    fclose(p);
    return aux;
}
void vector_vendedores(Vendedor *vObj){
    int pos=0,i=0;
    Vendedor obj;
    while(obj.leer(pos++)){
        vObj[i]=obj;
        i++;
    }
}
int posicion_vendedor(char* usu){
    int pos=0,posvendedor=0;
    Vendedor reg;
    while(reg.leer(pos++)==true){
        if(strcmp(usu,reg.getUsuario())==0){
            return posvendedor;
        }
        posvendedor++;
    }
    return -1;
}
int verificar_vendedor_existente(char* usu){
    Vendedor reg;
    int pos=0;
    while(reg.leer(pos++)==true){
        if(strcmp(reg.getUsuario(),usu)==0){
            return 1;
        }
    }
    return 0;
}
int cantidad_vendedor_ID(char* usu){
    Venta reg;
    int pos=0,cantventas=0;
    if(verificar_vendedor_existente(usu)==1){
        while(reg.leer(pos++)==true){
            if(strcmp(reg.getIDvendedor(),usu)==0){
                cantventas++;
            }
        }
    }
    return cantventas;
}


/////////////////////////////////////////////////////////////////////
///                      GERENCIA-CLIENTES                        ///
/////////////////////////////////////////////////////////////////////


////falta opcion 4//////////////////////////////

//MENU CLIENTES
void menu_clientes_gerencia(){
    char desicion='p';
    int codigoHerramienta,posicion;
    while(desicion!='0'){
        cout<<endl<<"****************MENU CLIENTES****************"<<endl<<endl;
        cout<<endl<<"1-Cantidad de compras de cliente";
        cout<<endl<<"2-Recaudacion de cliente";
        cout<<endl<<"3-Modificar datos de cliente";
        cout<<endl<<"4-Dar descuento a cliente";
        cout<<endl<<"5-Buscar cliente";
        cout<<endl<<"6-Ver clientes";
        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                cantidad_compras_cliente();
                system("pause");
                break;
            case '2':
                system("cls");
                recaudacion_cliente();
                system("pause");
                break;
            case '3':
                system("cls");
                modificar_datos_cliente();
                system("pause");
                break;
            case '4':
                system("cls");
                dar_descuento_cliente();
                system("pause");
                break;
            case '5':
                system("cls");
                buscar_cliente_dni();
                system("pause");
                break;
            case '6':
                system("cls");
                listado_clientes();
                system("pause");
                break;
        }
        system("cls");
    }
}


//1
void cantidad_compras_cliente(){
    int d,cantcompras=0,pos=0,pos2=0;
    Venta obj;
    Cliente reg;
    char n[50];
    cout<< endl << "Ingrese el DNI de cliente ";
    cin>>d;
    if(verificar_dni(d)==1){
        while(obj.leer(pos++)==true){
            if(d==obj.getIDcliente()){
                cantcompras++;
            }
        }
        while(reg.leer(pos2++)==true){
            if(d==reg.getdni()){
                strcpy(n,reg.getnombre());
            }
        }
        cout<< endl<< "La cantidad de compras del cliente "<<n << " fue: "<< cantcompras;
        cout<<endl;
    }
    else{
        cout<<endl<< "DNI de cliente no registrado, verifique los datos";
        cout << endl;
    }
}
//2
void recaudacion_cliente(){
    int _dni;
    int cant,pos=0,x=0,aux=0;
    float acumulador=0;
    Venta reg,* vec;
    char nom[50];
    bool val = true;

    while(val){
         cout<< endl<< "Ingrese el DNI a buscar";
        cout<<endl;
        cin>>_dni;

        if(_dni>0){
            val = false;
        }
        else{
              cout<< endl<< "DNI ingresado invalido, por favor vuelva a ingresar ";
        }
    }

    cant=cantidad_cliente_dni(_dni);
    vec= new Venta[cant];
    while(reg.leer(pos)==true){
        if(_dni==reg.getIDcliente()){
            vec[aux]=reg;
            aux++;
        }
        pos++;
    }
    Detalleventa obj;
    int pos2=0;
    while(obj.leer(pos++)==true){
        for(x=0;x<cant;x++){
            if(vec[x].getID()==obj.getIDventa()){
                acumulador+=obj.getPrecio();
            }
        }
    }
    Cliente objcliente;
    int pos3=0;
    while(objcliente.leer(pos3++)==true){
        if(objcliente.getdni()==_dni){
            strcpy(nom,objcliente.getnombre());
        }
    }
    cout<<endl<< "Lo gastado por el cliente "<<nom << " fue: $"<<acumulador;
    cout <<endl<< "Desea ver todos los datos de cada venta? 1=si 0=no";
    int va;
    cin>>va;
    switch(va){
        case 1:
            for(x=0;x<cant;x++){
                vec[x].mostrar();
                cout<<endl<< "--------------------------------------";
            }
            break;
        case 2:
            delete[] vec;
            return;
            break;
    }
}
//3
void modificar_datos_cliente(){
    cout<<endl<<"****************DATOS A MODIFICAR****************"<<endl<<endl;
    cout<<endl<<"1-Nombre y Apellido";
    cout<<endl<<"2-DNI";
    cout<<endl<<"3-TELEFONO";
    cout<<endl<<endl<<"0- Volver";
    int desicion;
    cin>>desicion;
    switch(desicion){
        case 1:
            nombre_apellido_cliente();
            break;
        case 2:
            cambiar_dni_cliente();
            break;
        case 3:
            cambiar_telefono_cliente();
            break;
        case 0:
        return;
        break;
    }
}
void cambiar_telefono_cliente(){
    int _dni;
    Cliente obj;
    bool val=true;
    char tel[20];
    cout << endl<< "Ingrese el usuario a buscar";
    cin>>_dni;
    if(verificar_dni(_dni)){
        int aux;
        bool ok;
        aux=posicion_cliente(_dni);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){

            while(val){
                cout << endl<< "Ingrese el telefono a cambiar";
                cin>>tel;

                if(tel>0){
                    val = false;
                }
                else{
                     cout << endl<< "Numero invalido, vuelva a ingresar el numero";
                }
           }
            obj.settelefono(tel);
            ok=obj.sobre_escribir(aux);
        }
    }
    else{
        cout << endl<< "Vendedor no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}

void cambiar_dni_cliente(){
    int _dni;
    Cliente obj;
    bool val = true;
    int DOC;
    cout << endl<< "Ingrese el DNI a buscar";
    cin>>_dni;
    if(verificar_dni(_dni)==1){
        int aux;
        bool ok;
        aux=posicion_cliente(_dni);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){


                while(val){
                cout << endl<< "Ingrese el dni a cambiar";
                cin>>DOC;

                if(DOC>0){
                    val = false;
                }
                else{
                     cout << endl<< "Numero invalido, vuelva a ingresar el numero";
                }
           }




            obj.setdni(DOC);
            ok=obj.sobre_escribir(aux);
        }
    }
    else{
        cout << endl<< "Cliente no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}
void nombre_apellido_cliente(){
    int _dni;
    Cliente obj;
    cout << endl<< "Ingrese el DNI a buscar";
    cin>>_dni;
    if(verificar_dni(_dni)==1){
        int aux;
        bool ok;
        aux=posicion_cliente(_dni);
        obj.leer(aux);
        obj.mostrar();
        if(aux>=0){
            char a[50],n[50];
            cout<< endl<< "Ingrese el nuevo Apellido";
            cin>>a;
            cout << endl<< "Ingrese el nuevo Nombre";
            cin>>n;
            obj.setapellido(a);
            obj.setnombre(n);
            ok=obj.sobre_escribir(aux);

        }
    }
    else{
        cout << endl<< "Cliente no existente";
        cout<<endl<< "Verifique los datos";
        cout<< endl;
    }
}
//4
void dar_descuento_cliente(){
    int _dni,pos_cliente=0;
    char desicion='p';
    Descuento reg;
    cout<<endl<<"Ingrese el DNI del cliente para darle descuento: ";
    cin>>_dni;
    pos_cliente=posicion_cliente(_dni);

    while(desicion!='0'){
        cout<<endl<<"****************MENU CLIENTES****************"<<endl<<endl;
        cout<<endl<<"1-Dar descuento por porcentaje";
        cout<<endl<<"2-Dar descuento por monto";
        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                dar_pocentaje(_dni);

                break;
            case '2':
                system("cls");
                dar_monto(_dni);

                break;
        }
    }
}
void dar_pocentaje(int _dni){
    float des=-1;
    Descuento reg;
    while(des<0 || des>100){
        cout<<endl<<"Ingrese el porcentaje de descuento (1 a 100): %";
        cin>>des;
    }
    reg.set_Estado(true);
    reg.set_Porcentaje(des);
    reg.set_Monto_Descuento(0);
    reg.set_DNI(_dni);
    if(reg.escribir()!=false){
        system("cls");
        cout<<endl<<"Monto guardado con exito!";
        cout<<endl<<endl;
        system("pause");
        system("cls");
    }
}
void dar_monto(int _dni){
    Descuento reg;
    float des=-1;
    bool val = true;
    while(val){
         cout<<endl<<"Ingrese el monto de descuento : $";
        cin>>des;
        if(des>0){
            val=false;
        }
        else{
             cout<<endl<<"Descuento menor a 0, por favor vuelva a ingresar un monto valido";
        }
    }

    reg.set_Estado(true);
    reg.set_Monto_Descuento(des);
    reg.set_Porcentaje(0);
    reg.set_DNI(_dni);
    if(reg.escribir()!=false){
        system("cls");
        cout<<endl<<"Monto guardado con exito!";
        cout<<endl<<endl;
        system("pause");
        system("cls");

    }
}
//5
void buscar_cliente_dni(){
    Cliente reg;
    int pos=0,d;
    cout<<endl<<"Ingrese el DNI a buscar";
    cout<<endl;
    cin>>d;
    if(verificar_dni(d)==1){
        while(reg.leer(pos++)==true){
            if(d==reg.getdni()){
                reg.mostrar();
                cout<<endl;
            }
        }
    }
    else{
        cout<< endl<< "DNI de cliente no registrado, por favor verifique los datos";
        cout<<endl;
    }
}
// 6
void listado_clientes(){
    cout<<endl<<"****************LISTADO DE CLIENTES ****************"<<endl<<endl;
    cout<<endl<<"1-Por codigo de cliente";
    cout<<endl<<"2-Por Apellido";
    cout<<endl<<endl<<"0- Volver";
    int aux;
    cin>>aux;
    int cant;
    Cliente obj,* vec;
    cant=cant_reg_clientes();

    vec= new Cliente[cant];
    vector_clientes(vec);
    switch(aux){
        case 1:
            cliente_ordenado_codigo(vec,cant);
            break;
        case 2:
            cliente_orneado_apellido(vec,cant);
            break;
    }
    int x=0;
    for(x=0;x<cant;x++){
        vec[x].mostrar();
        cout<<endl<<"-----------------------------------------------------"<<endl;

    }
    delete[] vec;

}
void cliente_orneado_apellido(Cliente * vObj,int cant){
    int posMax;
    Cliente aux;
    for(int i=0;i<cant-1;i++){
        posMax=i;
        for(int j=i+1;j<cant;j++){
            if( _strcmpi(vObj[j].getapellido(),vObj[posMax].getapellido()) < 0 ){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********Clientes Ordenados por Apellido********"<<endl<<endl;
}
void cliente_ordenado_codigo(Cliente * vObj, int cant){
    int posMax;
    Cliente aux;
    for(int i=0;i<cant-1;i++){
        posMax=i;
        for(int j=i+1;j<cant;j++){
            if(vObj[j].getdni() < vObj[posMax].getdni()){
                posMax=j;
            }
        }
        aux=vObj[i];
        vObj[i]=vObj[posMax];
        vObj[posMax]=aux;
    }
    cout<<endl<<endl<<"********clientes ordenados por Codigo********"<<endl<<endl;
}


//Complemento
void vector_clientes(Cliente *vObj){
    int pos=0,i=0;
    Cliente obj;
    while(obj.leer(pos++)){
        vObj[i]=obj;
        i++;
    }
}
int cant_reg_clientes(){
    int aux;
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    aux=ftell(p)/sizeof(Cliente);
    fclose(p);
    return aux;
}
int posicion_cliente(int d){
    int pos=0,posvendedor=0;
    Cliente reg;
    while(reg.leer(pos++)==true){
        if(d==reg.getdni()){
            return posvendedor;
        }
        posvendedor++;
    }
    return -1;
}
int cantidad_cliente_dni(int d){
    int aux=0,pos=0;
    Venta reg;
    while(reg.leer(pos++)==true){
        if(d==reg.getIDcliente()){
            aux++;
        }
    }
    return aux;
}
int verificar_dni(int d){
    Cliente reg;
    int pos=0;
    while(reg.leer(pos++)==true){
        if(d==reg.getdni()){
            return 1;
        }
    }
    return -1;
}



/////////////////////////////////////////////////////////////////////
///                       GERENCIA-VENTAS                         ///
/////////////////////////////////////////////////////////////////////

//MENU VENTAS
void menu_ventas_gerencia(){
    char desicion='p';
    int codigoHerramienta,posicion;
    while(desicion!='0'){
        cout<<endl<<"****************MENU VENTAS****************"<<endl<<endl;
        cout<<endl<<"1-Cantidad de ventas";
        cout<<endl<<"2-Recaudacion de ventas";
        cout<<endl<<"3-Modificar datos de venta";
        cout<<endl<<"4-Buscar venta";
        cout<<endl<<"5-Listado de ventas ordenado por fecha y numero de venta";
        cout<<endl<<endl<<"0- Volver";
        cin>>desicion;
        switch(desicion){
            case '1':
                system("cls");
                cantidad_venta();
                system("pause");
                break;
            case '2':
                system("cls");
                recaudacion_venta();
                system("pause");
                break;
            case '3':
                system("cls");
                submenu_modificar_venta();
                system("pause");
                break;
            case '4':
                system("cls");
                submenu_consulta_venta();
                system("pause");
                break;
            case '5':
                system("cls");
                listado_venta_fecha();
                system("pause");
                break;

        }
        system("cls");
    }
}


//1
void cantidad_venta(){
    int vec[12]{},pos=0,x=0,a;

    bool aux;
    bool val = true;

    while(val){
        cout<<endl<< "Ingrese el año de venta que busca: ";
        cin>>a;
        if(a>0){
            val = false;
        }
        else{
            cout<<endl<< "Anio invalido, vuelva a ingresar un anio";
        }
    }

    Venta reg;
    while(reg.leer(pos++)==true){
        if(reg.getFechav().getAnio()==a){
            vec[reg.getFechav().getMes()-1]++;
        }
    }
    for(x=0;x<12;x++){
        cout<< endl<< "La cantidad de ventas del mes "<<x+1<<" del anio "<<a<<" fue: "<< vec[x];
        cout<<endl<<"-------------------------------------------------------------------------";
        cout << endl;
    }
}
//2
void recaudacion_venta(){
    int aux;
    cout<<endl<<"****************RECAUDACIONES****************"<<endl<<endl;
    cout<<endl<<"1-Recaudaciion anual";
    cout<<endl<<"2-Recaudacion de mensual";
    cout<<endl<<"0-Volver";
    cout<<endl;
    cin>>aux;
    switch(aux){
        case 1:
            system("cls");
            recaudacion_anual();
            break;
        case 2:
            system("cls");
            recaudacion_mensual();
            break;
        case 0:
            break;
    }
}
void recaudacion_anual(){
    int cant,aux,pos=0,x=0;
    float anio=0;
    Detalleventa obj,* vec;
    Venta reg;
    bool val = true;
    cant= cant_detalleventa();
    vec= new Detalleventa[cant];
    vector_detalle(vec);
    while(val){
            cout<< endl<< "Ingrese el anio que busca ";
            cout<<endl;
            cin>>aux;

            if(aux>0){
                val= false;
            }
            else{
                cout<< endl<< "Anio invalido, vuelva a ingresar un anio valido ";
                cout<<endl;
            }

    }

    while(reg.leer(pos++)==true){
        for(x=0;x<cant;x++){
            if(reg.getFechav().getAnio()==aux&&reg.getID()==vec[x].getIDventa()){
                if(vec[x].getPrecio()!=0&&vec[x].getEstado()==true){
                    anio+=vec[x].getPrecio();
                }
            }
        }
    }
    cout<<"************************************************************"<<endl;
    cout << endl << "En el anio "<<aux << " se recaudo: $"<<anio;
    cout<<endl;
    cout<<"************************************************************"<<endl;
    delete [] vec;
}
void recaudacion_mensual(){
    int cant,aux,pos=0,x=0;
    float mes[12]{};
    Detalleventa obj,* vec;
    Venta reg;
    cant= cant_detalleventa();
    vec= new Detalleventa[cant];
    vector_detalle(vec);
    cout<< endl<< "Ingrese el anio y mostrara la recaudacion por mes ";
    cout<<endl;
    cin>>aux;
    while(reg.leer(pos++)==true){
        for(x=0;x<cant;x++){
            if(reg.getFechav().getAnio()==aux){
                if(reg.getID()==vec[x].getIDventa()&&vec[x].getEstado()==true){
                    mes[reg.getFechav().getMes()-1]+=vec[x].getPrecio();
                }
            }
        }
    }
    for(x=0;x<12;x++){
        cout<< endl<< "En el mes "<< x+1 << " se recaudoo: $"<< mes[x];
        cout<<endl<< "------------------------------------------------";
        cout<< endl;
    }
    delete [] vec;
}
//3
void submenu_modificar_venta(){
    cout<<endl<<"****************MODIFICAR VENTAS****************"<<endl<<endl;
    cout<<endl<<"1-Modificar envio";
    cout<<endl<<"2-Modificar forma de pago";
    cout<<endl<<"0-Salir";
    int aux;
    cout<<endl;
    cin>>aux;
    switch(aux){
        case 1:
            system("cls");
            mod_envio();
            break;
        case 2:
            system("cls");
            mod_forma_pago();
            break;
        case 0:
            break;
    }
}
void mod_envio(){
    int _ID,pos_venta,desicion=0;
    bool aux;
    cout<<endl<<"Ingrese el ID de venta a modificar";
    cout<<endl;
    cin>>_ID;
    Venta obj;
    if(verificar_ID_venta(_ID)==1){
        pos_venta=buscar_pos_venta(_ID);
        obj.leer(pos_venta);
        while(desicion!=1 && desicion !=2){
            cout<<endl<<endl<<"--Tipo de envio--";
            cout<<endl<<endl<<"1-Domicilio    2-Retira por local";
            cin>>desicion;
        }
        if(desicion==1){
            obj.setEnvio(true);
        }
        else{
            obj.setEnvio(false);
        }
        obj.sobre_escribir(pos_venta);
    }
    else{
        cout<<endl<<"ID de venta inexistente, verifique los datos";
        cout<<endl;
    }
}
void mod_forma_pago(){
    int _ID,pos_venta,desicion=0;
    bool aux;
    cout<<endl<<"Ingrese el ID de venta a modificar";
    cout<<endl;
    cin>>_ID;
    Venta obj;
    if(verificar_ID_venta(_ID)==1){
        pos_venta=buscar_pos_venta(_ID);
        obj.leer(pos_venta);
        while(desicion!= 1 && desicion!= 2 &&desicion!= 3 && desicion!= 4){
            cout<<endl<<"--Forma de pago--";
            cout<<endl<<endl<<"1-Efectivo   2-Credito   3-Debito   4-Cheque";
            cin>>desicion;
        }
        obj.setFormapago(desicion);
        obj.sobre_escribir(pos_venta);
    }
    else{
        cout<<endl<<"ID de venta inexistente, verifique los datos";
        cout<<endl;
    }
}
//4
void submenu_consulta_venta(){
    cout<<endl<<"****************CONSULTA VENTA****************"<<endl<<endl;
    cout<<endl<<"1-Por rango de fecha";
    cout<<endl<<"2-Por cliente";
    cout<<endl<<"3-Por codigo de venta";
    int aux;
    cout<<endl;
    cin>>aux;
        switch(aux){
            case 1:
                system("cls");
                consulta_venta_fecha();
                break;
            case 2:
                system("cls");
                consulta_venta_cliente();
                break;
            case 3:
                system("cls");
                consulta_venta_ID();
                break;
        }
}
void consulta_venta_cliente(){
    int _dni,cant,pos=0,aux=0,pos2=0,pos3=0;
    cout << endl << "Ingrese el DNI del cliente a buscar";
    cout << endl;
    cin>>_dni;
    cant=cantidad_cliente_dni(_dni);
    Venta obj, * vec;
    vec= new Venta[cant];
    Cliente obj2;
    char n[50];
    if(verificar_dni(_dni)){
        //Solo para mostrar nombre
        while(obj2.leer(pos2++)==true){
            if(_dni==obj2.getdni()){
                strcpy(n,obj2.getnombre());
            }
        }
        cout << "**********************************************"<<endl<<endl;
        cout<< " Cliente: "<<n<<endl;
        cout << "**********************************************"<<endl;
        //carga las ventas con el documento ingresado
        while(obj.leer(pos++)==true){
            if(obj.getIDcliente()==_dni){
                vec[aux]=obj;
                aux++;
            }
        }
        for(pos=0;pos<cant;pos++){
            vec[pos].mostrar();
            cout<<endl<<"-------------------------------";
            cout<<endl;
        }
    }
    else{
        cout<<endl<<" DNI no registrado";
        cout<<endl<<"Verifique los datos";
        cout<<endl;
    }
    cout << "**********************************************"<<endl;
    cout <<endl;
    cout<< "Desea ver los productos de una venta? 1=si 0=no";
    cout <<endl;
    cout << "**********************************************"<<endl;
    int de;
    cin>>de;
    Detalleventa objdet;
    switch(de){
        case 1:
            int idventa;
            cout<<endl<<"Ingrese el ID de venta que desea buscar";
            cout<<endl;
            cin>>idventa;
            while(objdet.leer(pos3++)==true){
                if(idventa==objdet.getIDventa()&&objdet.getEstado()==true){
                    cout << "**********************************************"<<endl;
                    objdet.mostrar();
                    cout <<endl;
                    cout << "**********************************************"<<endl;
                }
            }
            break;
        case 0:
            break;
    }
    delete[] vec;
}
void consulta_venta_fecha(){
    int d1,m1,a1;
    int d2,m2,a2;
    int pos=0,validacion;
    bool validarFecha1,validarFecha2,validacionMayor,validacionMenor;
    cout <<endl<< "Ingrese desde que fecha(fecha de inicio):";
    cout<<endl;
    cout<< endl<<"Dia : ";
    cin>>d1;
    cout<<endl<<"Mes : ";
    cin>>m1;
    cout<<endl<<"Anio : ";
    cin>>a1;

    cout <<endl<< "Ingrese hasta que fecha (fecha de fin):";
    cout<<endl;
    cout<< endl<<"Dia : ";
    cin>>d2;
    cout<<endl<<"Mes : ";
    cin>>m2;
    cout<<endl<<"Anio : ";
    cin>>a2;
    system("cls");
    validarFecha1=validar_fecha(d1,m1,a1);
    validarFecha2=validar_fecha(d2,m2,a2);
    if(validarFecha1==true && validarFecha2==true){
        validacion=comparar_fechas(d1,m1,a1,d2,m2,a2);
        if(validacion==0){
            cout<<endl<<endl<<"[ERROR]- La primer fecha ingresada es mayor a la segunda";
            system("pause");
        }
        if(validacion==-1){
            cout<<endl<<endl<<"[ERROR]- Ambas fechas son iguales";
            system("pause");
        }
        if(validacion==1){
            Venta obj;
            while(obj.leer(pos++)){
                validacionMayor=es_mayor_a_fecha1( d1,m1,a1,obj.getFechav().getDia(),obj.getFechav().getMes(),obj.getFechav().getAnio() );
                validacionMenor=es_menor_a_fecha2( d2,m2,a2,obj.getFechav().getDia(),obj.getFechav().getMes(),obj.getFechav().getAnio() );
                if(validacionMayor==true && validacionMenor==true){
                    obj.mostrar();
                    cout<<endl<<endl<<"----------------------------------------";
                }
            }
        }
    }
    else{
        if(validarFecha1==false){
            cout<<endl<<endl<<"[ERROR]-La primer fecha que ingresaste no es real";
        }
        if(validarFecha2==false){
            cout<<endl<<endl<<"[ERROR]-La segunda fecha que ingresaste no es real";
        }
        system("pause");
        system("cls");
    }

}
bool comparar_fechas(int d1,int m1,int a1,int d2,int m2,int a2){
    if(a1>a2){
        return 0;
    }
    else{
        if(a1==a2){
            if(m1>m2){
                return 0;
            }
            else{
                if(m1==m2){
                    if(d1>d2){
                        return 0;
                    }
                    else{
                        return -1;
                    }
                }
            }
        }
    }
    return 1;
}
bool es_mayor_a_fecha1(int diaI,int mesI,int anioI,int diaObj,int mesObj,int anioObj){
    if(anioObj<anioI){
        return false;
    }
    else{
        if(anioObj==anioI){
            if(mesObj<mesI){
                return false;
            }
            else{
                if(mesObj==mesI){
                    if(diaObj<diaI){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool es_menor_a_fecha2(int diaI,int mesI,int anioI,int diaObj,int mesObj,int anioObj){
    if(anioObj>anioI){
        return false;
    }
    else{
        if(anioObj==anioI){
            if(mesObj>mesI){
                return false;
            }
            else{
                if(mesObj==mesI){
                    if(diaObj>diaI){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void consulta_venta_ID(){
    int _ID,pos3=0,de,pos=0;;
    cout <<endl<<"Ingrese el ID de venta a buscar";
    cout <<endl;
    cin>>_ID;
    Venta reg;
    while(reg.leer(pos++)==true){
        if(reg.getID()==_ID){
            cout << "**********************************************"<<endl;
            reg.mostrar();
            cout <<endl;
            cout << "**********************************************"<<endl;
        }
    }
    cout <<"**********************************************"<<endl;
    cout <<endl;
    cout<< "Desea ver los productos de la venta? 1=si 0=no";
    cout <<endl;
    cout << "**********************************************"<<endl;
    cin>>de;
    Detalleventa objdet;
    switch(de){
        case 1:
            while(objdet.leer(pos3++)==true){
                if(_ID==objdet.getIDventa()&&objdet.getEstado()==true){
                    cout << "**********************************************"<<endl;
                    objdet.mostrar();
                    cout <<endl;
                    cout << "**********************************************"<<endl;
                }
            }
            break;
        case 0:
        break;
    }
}
//5
void listado_venta_fecha(){
    int pos=0;
    Venta reg;
    cout<<endl<<"************************************************";
    cout<<endl;
    cout<<endl<<"*********Ventas ordenadas por fecha*************";
    cout<<endl;
    cout<<endl<<"************************************************";
    while(reg.leer(pos++)==true){
        reg.mostrar();
        cout<<endl<<"**************************************";
        cout<<endl;

    }
}


//complementos
int buscar_pos_venta(int _ID){
    int pos=0,aux=0;
    Venta reg;
    while(reg.leer(pos++)==true){
        if(reg.getID()==_ID){
            return aux;
        }
        aux++;
    }
}
int verificar_ID_venta(int _ID){
    Venta reg;
    int pos=0;
    while(reg.leer(pos++)==true){
        if(reg.getID()==_ID){
            return 1;
        }

    }
return -1;
}
void vector_detalle(Detalleventa * vObj){
    int pos=0,i=0;
    Detalleventa obj;
    while(obj.leer(pos++)){
        vObj[i]=obj;
        i++;
    }
}
int cant_detalleventa(){
    int aux;
    FILE *p;
    p=fopen("detallesVenta.dat","rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    aux=ftell(p)/sizeof(Detalleventa);
    fclose(p);
    return aux;
}

