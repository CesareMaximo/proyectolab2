#pragma once
#include"herramientas.h"
#include"gerente.h"
#include"vendedor.h"
#include "cliente.h"
#include "detalleventa.h"
#include "venta.h"


/////////////////////////////////////////////////////////////////////
///                       MENUS-INGRESO                           ///
/////////////////////////////////////////////////////////////////////
//INGRESO
void ingreso_al_sistema();
//LOGIN
int login(char*,char*);
bool validarVendedor(char*,char*);
bool validarGerente(char*,char*);
//MENUS
void menu_vendedor(char*);
void menu_gerencia();


/////////////////////////////////////////////////////////////////////
///                    GERENCIA-BACKUP                            ///
/////////////////////////////////////////////////////////////////////

//MENU BACKUP
void menu_backup();
//1
void backup_venta();
//2
void backup_vendedor();
//3
void backup_marca();
//4
void backup_herramienta();
//5
void backup_gerente();
//6
void backup_detalle_venta();
//7
void backup_descuento();
//8
void backup_cliente();

/////////////////////////////////////////////////////////////////////
///                            CSV                                ///
/////////////////////////////////////////////////////////////////////

//MENU CSV
void menu_csv();


//1
void csv_venta();
//2
void csv_vendedor();
//3
void csv_herramienta();
//4
void csv_gerente();
//5
void csv_detalle_venta();
//6
void csv_descuento();
//7
void csv_cliente();

/////////////////////////////////////////////////////////////////////
///                           VENDEDORES                          ///
/////////////////////////////////////////////////////////////////////

////////MENU PARA AGREGAR VENTAS
bool generar_nueva_venta(char*);
//Validacion de cliente antes de llegar al menu para agregar ventas
bool validar_cliente_existente(int,char*);
int buscar_cliente(int,char*);
int registrar_cliente(char*);


////////OPCIONES DE MENU
void agregar_producto_a_venta(int,float&);
void quitar_o_editar_producto(int,int,float&);
bool eliminar_todos_productos(int);


//Agregar
void cargarVectorconProductos(Herramientas *vObj,char*);
int buscar_herramienta_por_nombre(int,char*);
//Modificar
void modificar_cantidad(int,float&);
//Quitar
bool eliminar_producto_de_lista_compra(int,float&);
//Finalizar venta
void descontar_stock(int);
//Descuento
bool ver_descuento_cliente(int,int&);
void aplicar_descuento(float&,int,int&);
//Complementos de opciones de menu
bool mostrar_productos_agregados(int);
int buscar_producto_en_lista_compra(int,int);


/////////////////////////////////////////////////////////////////////
///                    GERENCIA-HERRAMIENTAS                      ///
/////////////////////////////////////////////////////////////////////


//MENU HERRAMIENTAS
void menu_herramientas_gerencia();
//1
void agregar_producto();
bool filtrar_herramientas(int);
void listar_todas_herramientas();
//2
void menu_gerencia_modificarHerramientas();
bool modificar_precio_herramienta(int);
bool modificar_stock_herramienta(int);
//3
bool baja_logica_herramienta(int);
//4
void menu_gerencia_buscarHerramientas();
int buscar_herramienta_por_nombre();
int buscar_herramienta_por_codigo();
int buscar_herramienta_por_marca();
//5
void menu_gerencia_verHerramientas();
void ordenarHerramientas(int);
void ordenar_vectorHerramientas_porCodigo(Herramientas *vObj,int);
void ordenar_vectorHerramientas_porNombre(Herramientas *vObj,int);
void ordenar_vectorHerramientas_porPrecio(Herramientas *vObj,int);
void ordenar_vectorHerramientas_porFecha(Herramientas *vObj,int);

//Complementos 2-3
int menu_buscar_codigo_herramienta_por();
int buscar_herramienta_nombre();
int buscarCodigoHerramienta(int);
//Complementos 5
int cantidad_herramientas();
void cargar_vectorHerramientas(Herramientas *vObj);

/////////////////////////////////////////////////////////////////////
///                      GERENCIA-REPORTES                        ///
/////////////////////////////////////////////////////////////////////

//MENU REPORTES
void menu_reportes_gerencia();

//1
void recaudado_por_herramienta(int);
//2
void buscar_recaudado_por_marca();
int buscar_marca_herramienta(int);
//3
void recaudado_por_rango_edad();
int calcular_edad_cliente(int,int,int);
//4
void gastos_pagos_mensuales_a_vendedores();

/////////////////////////////////////////////////////////////////////
///                     GERENCIA-VENDEDORES                       ///
/////////////////////////////////////////////////////////////////////

//MENU VENDEDORES
void menu_vendedores_gerencia();
//1
void cantidad_ventas_vendedor();
//2
void recaudacion_vendedor();
//3
void modificar_vendedor();
void cambiar_telefono();
void cambiar_dni();
void nombre_apellido_vendedor();
//4
void aumentar_sueldo();
//5
void consultar_vendedor();
//6
void submenu_listados_vendedores();
void ordenar_vendedor_Apellido(Vendedor *vObj,int );
void ordenar_vendedor_usuario(Vendedor *vObj,int);
//7
void dar_comision_vendedor();
//8
void ver_comision_mes();

//complementos
float cant_vendido(int );
void cargar_vector_venta(Venta *vObj,char *);
float buscar_comision(char*);
int cant_reg_vendedores();//////////ESTE
void vector_vendedores(Vendedor* vObj);
int posicion_vendedor(char*);
int verificar_vendedor_existente(char*);
int cantidad_vendedor_ID(char*);


/*
int can_registros_vendedores();
void listar_vendedores();
*/

/////////////////////////////////////////////////////////////////////
///                      GERENCIA-CLIENTES                        ///
/////////////////////////////////////////////////////////////////////


//MENU CLIENTES
void menu_clientes_gerencia();

//1
void cantidad_compras_cliente();
//2
void recaudacion_cliente();
//3
void modificar_datos_cliente();
void cambiar_dni_cliente();
void cambiar_telefono_cliente();
void nombre_apellido_cliente();
//4
void dar_descuento_cliente();
void dar_pocentaje(int);
void dar_monto(int);
//5
void buscar_cliente_dni();
//6
void listado_clientes();
void cliente_ordenado_codigo(Cliente* vObj,int);
void cliente_orneado_apellido(Cliente *vObj,int);


//complementos
int cantidad_cliente_dni(int);
int verificar_dni(int);
int posicion_cliente(int);
int cant_reg_clientes();
void vector_clientes(Cliente * vObj);



/////////////////////////////////////////////////////////////////////
///                       GERENCIA-VENTAS                         ///
/////////////////////////////////////////////////////////////////////


//MENU VENTAS
void menu_ventas_gerencia();

//1
void cantidad_venta();
//2
void recaudacion_venta();
void recaudacion_anual();
void recaudacion_mensual();
//3
void submenu_modificar_venta();
void mod_envio();
void mod_forma_pago();
//4
void submenu_consulta_venta();
void consulta_venta_cliente();
void consulta_venta_fecha();
bool comparar_fechas(int,int,int,int,int,int);
bool es_mayor_a_fecha1(int,int,int,int,int,int);
bool es_menor_a_fecha2(int,int,int,int,int,int);
void consulta_venta_ID();
//5
void listado_venta_fecha();


//complementos
int buscar_pos_venta(int);
int verificar_ID_venta(int);
void vector_detalle(Detalleventa * vObj);
int cant_detalleventa();



/////////////////////////////////////////////////////////////////////
///        GERENCIA-CREAR USUARIO Y REGISTRAR EMPLEADOS           ///
/////////////////////////////////////////////////////////////////////

//MENU CREAR Y REGISTRAR
void menu_usuarios_y_registrar_gerencia();

//1
void registrar_vendedor();
//2
void registrar_gerente();
//3
void modificar_cuenta_vendedor();
void modificar_cuenta_gerente();
int buscar_posicion_vendedor_por_dni(int);
int buscar_posicion_gerente_por_dni(int);


//Validaciones de USUARIO en setUsuario() en GERENTE y VENDEDOR
bool filtrar_vendedor(char*);
bool filtrar_gerente(char*);

//Validaciones de DNI en setDni() en PERSONA
bool filtrar_dni_gerente(int);
bool filtrar_dni_vendedor(int);



/////////////////////////////////////////////////////////////////////
///                             FECHA                             ///
/////////////////////////////////////////////////////////////////////

bool validar_fecha(int,int,int);
bool validar_con_fecha_actual(int,int,int);


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////SECCION MAXI////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
///                          VENDEDORES                           ///
/////////////////////////////////////////////////////////////////////
//Crear



//Ordenamiento
void ordenar_por_codigo(int);
void cargar_vectorvendedor(Vendedor* obj);
void ordenarvectorVendedorporApellido(Vendedor* obj, int);
void ordenarvectorVendedorporCodigo(Vendedor* obj, int);
