#include <stdlib.h>
#include <stdio.h>

struct guarda
{
    long legajo;
    char apellido[31];
    char nombre[31];
};

void carga(struct guarda *dato)
{
    printf("Ingrese el legajo del estudiante  :");
    scanf(" %ld", &dato->legajo);
    printf("Ingrese el nombre del estudiante  :");
    scanf("%s", dato->nombre);
    printf("Ingrese el apellido del estudiante:");
    scanf("%s", dato->apellido);
}

void ordenamiento(struct guarda *dato, int f)
{
    struct guarda aux;
    int bandera = 1;
    int i = 0;
    int contador = 0;
    printf("f:%d\n\n\n", f);
    do
    {
        if (dato[i].apellido[0] > dato[i + 1].apellido[0])
        {
            aux = dato[i];
            dato[i] = dato[i + 1];
            dato[i + 1] = aux;
            printf("COntador:%d\n", contador);
            contador++;
        }
        printf("i:%d\n", i);
        i++;
        if (i == f && contador == 0)
        {
            bandera = 0;
        } 
        if (i==f && contador != 0)
        {
            i=0;contador=0;
        }
        
    } while (bandera != 0);
    for (int j = 0; j < f - 1; j++)
    {
        printf("Legajo: %ld\n", dato[j].legajo);
        printf("Nombre: %s\n", dato[j].nombre);
        printf("Apellido: %s\n", dato[j].apellido);
    }
}

int main()
{
    struct guarda *datos;
    int i = 0;
    int j = 1;
    size_t a;
    datos = (struct guarda *)malloc(sizeof(struct guarda));
    do
    {
        carga(&datos[i]);
        a = sizeof(struct guarda) * (j + 1);
        printf("\n%ld\n", (long)a);
        datos = (struct guarda *)realloc(datos, a);
        i++;
        j++;
    } while (datos[i - 1].legajo != 0);
    ordenamiento(datos, i);
    /*for (int j = 0; j < i - 1; j++)
    {
        printf("Legajo: %ld\n", datos[j].legajo);
        printf("Nombre: %s\n", datos[j].nombre);
        printf("Apellido: %s\n", datos[j].apellido);
    }*/
    return 0;
}