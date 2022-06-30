#include <iostream>
#include<stdio.h>

#include"fecha.h"
#include"funciones.h"
#include"herramientas.h"
#include"gerente.h"
#include"cliente.h"
#include"venta.h"
#include"detalleventa.h"
#include "Descuento.h"
using namespace std;
/*
    PONER VALIDACIONES DE ID O HACER AUTO INCREMENTO DE ID(si se hace autoncremento no se dabe hacer un set del ID):
        de cada clase hacer la validacion de su id en el set de ese ID,
        y en el cargar de esa clase pedir el id con el set para que se valide
*/
int main(){
    system("color 1A");
    ingreso_al_sistema();
    return 0;
}
