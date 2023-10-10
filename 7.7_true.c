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

void ordenamiento(struct guarda *dato){
    struct guarda aux;
    int bandera = 0;int i=0;
    do
    {
        if((dato+i)->apellido[1]>(dato+i)->apellido[1]){
            aux = dato[i];
            dato[i] = dato[i+1];
            dato[i+1] = aux;
        }
        i++;
        if(i>5){bandera=0;}
    } while (bandera != 0);
    
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
    ordenamiento(&datos);
    for (int j = 0; j < i - 1; j++)
    {
        printf("Legajo: %ld\n", datos[j].legajo);
        printf("Nombre: %s\n", datos[j].nombre);
        printf("Apellido: %s\n", datos[j].apellido);
    }
    return 0;
}