#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char delimitador = '.';

#define MENU 0
#define AGREGAR 1
#define BORRAR 2
#define MOSTRAR_LISTAS 3
#define CAMBIAR_OCTETO 4
#define LEER_OCTETO 5
#define CAMBIAR_DELIMITADOR 6
#define LEER_DELIMITADOR 7

struct campo
{
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

union direccion
{
    unsigned char B;
    struct campo bits;
} dir;

typedef struct dirip
{
    union direccion o1;
    union direccion o2;
    union direccion o3;
    union direccion o4;
} ip;

struct nodo
{
    struct dirip ip;
    struct nodo *sig;
};

ip *agregar(struct nodo *INI)
{
    struct nodo *aux;
    aux = (struct nodo *)malloc(sizeof(struct nodo));

    printf("\nDigite un numero de 0 a 255 para el primer octeto.:");
    scanf("%hhu", &aux->ip.o1.B);
    printf("\nDigite un numero de 0 a 255 para el segundo octeto:");
    scanf("%hhu", &aux->ip.o2.B);
    printf("\nDigite un numero de 0 a 255 para el tercer octeto.:");
    scanf("%hhu", &aux->ip.o3.B);
    printf("\nDigite un numero de 0 a 255 para el cuarto octeto.:");
    scanf("%hhu", &aux->ip.o4.B);
    struct nodo *actual = NULL;
    if (INI)
    {
        actual = INI;
        while (actual->sig != NULL)
        {
            if (actual->sig != NULL)
            {
                actual = actual->sig;
            }
        }
        actual->sig = aux;
        aux->sig = NULL;
    }
    else
    {
        INI = aux;
        // INI->sig = NULL;
    }
}

void imprimir(struct nodo *INI)
{
    struct nodo *aux = INI;
    printf("Listado:-------------------------------------");
    while (aux->sig != NULL)
    {
        printf("\nIP:");
        printf("%d%c%d%c%d%c%d", aux->ip.o1.B, delimitador, aux->ip.o2.B, delimitador, aux->ip.o3.B, delimitador, aux->ip.o4.B);
        aux = aux->sig;
    }

    printf("\n---------------------------------------------");
}

char cambiarDelimitador()
{
    char del;
    printf("Escriba el delmitador que desea usar para las direcciones:");
    scanf("\n%c", &del);
    return del;
}

void imprimirDelimitador(char delim){
    printf("\nEl delimitador es: \"");
    printf("%c\"", delim);
}

void cambiarOcteto(){
    
}

void menu(struct nodo *INI)
{
    int estado = 0;
    int loop = 1;
    do
    {
        switch (estado)
        {
        case MENU:
            int choice;
            printf("\nElija que desea hacer:\n1: Agregar una ip\n2: Borrar una ip\n3: Mostrar todas las IPs\n4: Cambiar un octeto especifico de una ip\n5: Leer un octeto en especifico\n6: Cambiar el delimitador de las ips\n7: Leer el delimitador\n");
            scanf("%d", &choice);
            estado = choice;
            break;

        case AGREGAR:
            agregar(INI);
            estado = 0;
            break;

        case BORRAR:
            estado = 0;
            break;

        case MOSTRAR_LISTAS:
            imprimir(INI);
            estado = 0;
            break;

        case CAMBIAR_OCTETO:
            cambiarOcteto();
            estado = 0;
            break;

        case LEER_OCTETO:
            estado = 0;
            break;

        case CAMBIAR_DELIMITADOR:
            delimitador = cambiarDelimitador();
            estado = 0;
            break;

        case LEER_DELIMITADOR:
            imprimirDelimitador(delimitador);
            estado = 0;
            break;
        }
    } while (loop = 1);
}

int main()
{

    struct nodo *INI = NULL;
    INI = (struct nodo *)malloc(sizeof(struct nodo));
    menu(INI);
}