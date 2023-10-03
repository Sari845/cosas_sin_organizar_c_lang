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
    scanf("%s", &dato->nombre);
    printf("Ingrese el apellido del estudiante:");
    scanf("%s", &dato->apellido);
}

int main()
{
    struct guarda *datos;
    int i = 0;
    datos = malloc(sizeof(struct guarda));
    do
    {
        carga(&datos[i]);
        i++;
    } while (datos[i - 1].legajo != 0);
    for (int j = 0; j < i - 1; j++)
    {
        printf("Legajo: %ld\n", datos[j].legajo);
        printf("Nombre: %s\n", datos[j].nombre);
        printf("Apellido: %s\n", datos[j].apellido);
    }
    return 0;
}