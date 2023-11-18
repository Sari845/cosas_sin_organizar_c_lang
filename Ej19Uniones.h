#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MENU 0
#define AGREGAR 1
#define BORRAR 2
#define MOSTRAR_LISTAS 3
#define LEER_OCTETO 4
#define CAMBIAR_DELIMITADOR 5
#define LEER_DELIMITADOR 6

char delimitador = '.';
int i = 0;

struct campo
{
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
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
    int numeroDeIp;
} ip;

struct nodo
{
    struct dirip ip;
    struct nodo *sig;
};

struct nodo* agregar(struct nodo *INI)
{
    struct nodo *aux;
    aux = (struct nodo *)malloc(sizeof(struct nodo));
    i++;
    printf("\nDigite un numero de 0 a 255 para el primer octeto.:");
    scanf("%hhu", &aux->ip.o1.B);
    printf("\nDigite un numero de 0 a 255 para el segundo octeto:");
    scanf("%hhu", &aux->ip.o2.B);
    printf("\nDigite un numero de 0 a 255 para el tercer octeto.:");
    scanf("%hhu", &aux->ip.o3.B);
    printf("\nDigite un numero de 0 a 255 para el cuarto octeto.:");
    scanf("%hhu", &aux->ip.o4.B);
    aux->ip.numeroDeIp = i;
    struct nodo *actual = NULL;
    actual = INI;
    if (INI)
    {
        while (actual->sig != NULL)
        {
            if (actual->sig != NULL)
            {
                actual = actual->sig;
            }
        }
        actual->sig = aux;
        // aux->ip.numeroDeIp = actual->ip.numeroDeIp + 1;
        aux->sig = NULL;
    }
    else
    {
        INI = aux;
        // INI->sig = NULL;
        return INI;
    }
}

void imprimir(struct nodo *INI)
{
    struct nodo *aux = INI;
    int loop = 0;
    printf("Listado:-------------------------------------");
    while (aux->sig != NULL)
    {
        printf("\nIP Nº%d:", aux->ip.numeroDeIp);
        printf("%d%c%d%c%d%c%d", aux->ip.o1.B, delimitador, aux->ip.o2.B, delimitador, aux->ip.o3.B, delimitador, aux->ip.o4.B);
        aux = aux->sig;
    }
    printf("\nIP Nº%d:", aux->ip.numeroDeIp);
    printf("%d%c%d%c%d%c%d", aux->ip.o1.B, delimitador, aux->ip.o2.B, delimitador, aux->ip.o3.B, delimitador, aux->ip.o4.B);
    printf("\n---------------------------------------------");
}

char cambiarDelimitador()
{
    char del;
    printf("Escriba el delmitador que desea usar para las direcciones:");
    scanf("\n%c", &del);
    return del;
}

void imprimirDelimitador(char delim)
{
    printf("\nEl delimitador es: \"");
    printf("%c\"", delim);
}

void deseaCambiar(unsigned char *octeto)
{
    char eleccion;
    printf("\nDesea cambiar ese valor? S/n");
    scanf(" %c", &eleccion);
    fflush(stdin);
    if (eleccion == 'S' || eleccion == 's')
    {
        printf("\nA que valor desea cambiar el octeto:");
        scanf(" %c", octeto);
        fflush(stdin);
        return;
    }
    if (eleccion == 'N' || eleccion == 'n')
    {
        printf("\nOK\n");
        return;
    }
}

void leerOcteto(struct nodo *INI)
{
    int loop = 1;
    int numeroParaLeer, numeroDeOcteto;
    struct nodo *aux = INI;
    printf("\nCual es el numero de IP que desea leer?....:");
    scanf("%d", &numeroParaLeer);
    printf("\nCual es el numero de octeto que desea leer?:");
    scanf("%d", &numeroDeOcteto);
    do
    {
        if (aux->ip.numeroDeIp == numeroParaLeer)
        {
            if (numeroDeOcteto == 1)
            {
                printf("\nLa IP en decimal es.....: \"%d\"", aux->ip.o1.B);
                printf("\nY su valor en binario es: %d%d%d%d%d%d%d%d\n", aux->ip.o1.bits.b0, aux->ip.o1.bits.b1, aux->ip.o1.bits.b2, aux->ip.o1.bits.b3, aux->ip.o1.bits.b4, aux->ip.o1.bits.b5, aux->ip.o1.bits.b6, aux->ip.o1.bits.b7);
                loop = 0;
                deseaCambiar(&aux->ip.o1.B);
            }
            if (numeroDeOcteto == 2)
            {
                printf("\nLa IP en decimal es.....: \"%d\"", aux->ip.o2.B);
                printf("\nY su valor en binario es: %d%d%d%d%d%d%d%d\n", aux->ip.o2.bits.b0, aux->ip.o2.bits.b1, aux->ip.o2.bits.b2, aux->ip.o2.bits.b3, aux->ip.o2.bits.b4, aux->ip.o2.bits.b5, aux->ip.o2.bits.b6, aux->ip.o2.bits.b7);
                loop = 0;
                deseaCambiar(&aux->ip.o2.B);
            }
            if (numeroDeOcteto == 3)
            {
                printf("\nLa IP en decimal es.....: \"%d\"", aux->ip.o3.B);
                printf("\nY su valor en binario es: %d%d%d%d%d%d%d%d\n", aux->ip.o3.bits.b0, aux->ip.o3.bits.b1, aux->ip.o3.bits.b2, aux->ip.o3.bits.b3, aux->ip.o3.bits.b4, aux->ip.o3.bits.b5, aux->ip.o3.bits.b6, aux->ip.o3.bits.b7);
                loop = 0;
                deseaCambiar(&aux->ip.o3.B);
            }
            if (numeroDeOcteto == 4)
            {
                printf("\nLa IP en decimal es.....: \"%d\"", aux->ip.o4.B);
                printf("\nY su valor en binario es: %d%d%d%d%d%d%d%d\n", aux->ip.o4.bits.b0, aux->ip.o4.bits.b1, aux->ip.o4.bits.b2, aux->ip.o4.bits.b3, aux->ip.o4.bits.b4, aux->ip.o4.bits.b5, aux->ip.o4.bits.b6, aux->ip.o4.bits.b7);
                loop = 0;
                deseaCambiar(&aux->ip.o4.B);
            }
        }
        if (aux->sig == NULL)
        {
            if (loop == 0)
            {
                break;
            }
            printf("\nNo se encontro al alumno\n");
            loop = 0;
            return;
        }
        aux = aux->sig;
    } while (loop == 1);
}

void borrar(struct nodo **INI)
{
    int numeroParaBorrar;
    struct nodo *aux;
    struct nodo *prev = NULL;
    aux = *INI;
    int ciclo = 1;
    printf("Cual es el numero de IP que desea borrar?:");
    scanf("%d", &numeroParaBorrar);

    if (*INI == NULL)
    {
        printf("\nNo hay alumnos agregados\n");
        return;
    }
    do
    {
        if (aux->ip.numeroDeIp == numeroParaBorrar)
        {
            printf("Se encontro la IP a borrar, procedo: ");
            if (prev == NULL)
            {
                *INI = (*INI)->sig;
                printf("%d%c%d%c%d%c%d", aux->ip.o1.B, delimitador, aux->ip.o2.B, delimitador, aux->ip.o3.B, delimitador, aux->ip.o4.B);
                ciclo = 0;
                struct nodo *aux2 = aux;
                while (aux->sig != NULL)
                {
                    aux->ip.numeroDeIp = aux->ip.numeroDeIp - 1;
                    aux = aux->sig;
                }
                aux->ip.numeroDeIp = aux->ip.numeroDeIp - 1;
                free(aux2);
                return;
            }
            else
            {
                prev->sig = aux->sig;
                printf("%d%c%d%c%d%c%d", aux->ip.o1.B, delimitador, aux->ip.o2.B, delimitador, aux->ip.o3.B, delimitador, aux->ip.o4.B);
                struct nodo *aux2 = aux;
                while (aux->sig != NULL)
                {
                    aux->ip.numeroDeIp = aux->ip.numeroDeIp - 1;
                    aux = aux->sig;
                }
                aux->ip.numeroDeIp = aux->ip.numeroDeIp - 1;
                free(aux2);
                return;
            }
        }
        if (aux->sig == NULL)
        {
            printf("No se encontrò al alumno\n");
            return;
        }
        prev = aux;
        aux = aux->sig;

    } while (ciclo == 1);
}

void menu()
{
    struct nodo *INI = NULL;
    int estado = 0;
    int loop = 1;
    int choice = 0;
    do
    {
        switch (estado)
        {
        case MENU:
            printf("\nElija que desea hacer:\n1: Agregar una ip\n2: Borrar una ip\n3: Mostrar todas las IPs\n4: Leer un octeto en especifico\n5: Cambiar el delimitador de las ips\n6: Leer el delimitador\n");
            scanf("%d", &choice);
            estado = choice;
            break;

        case AGREGAR:
            if(INI == NULL){
                INI = agregar(INI);
            }else{
            agregar(INI);
            }
            estado = 0;
            break;

        case BORRAR:
            borrar(&INI);
            i = i - 1;
            estado = 0;
            break;

        case MOSTRAR_LISTAS:
            if(INI != NULL){
                imprimir(INI);
            }
            estado = 0;
            break;

        case LEER_OCTETO:
            leerOcteto(INI); //
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

        case 7:
            return;
            break;
        }
    } while (loop == 1);
}