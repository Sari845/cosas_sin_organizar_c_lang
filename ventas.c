#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

struct nodo{
    struct venderdores{
        char nombre[20];
        char apellido[20];
        long id;
        char tipo_de_tienda;
    };

    struct ventas{
        char ingresoBruto;
        char ingresoFinal;
        int cantidadDeVentas;
    };
};