#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int i;
int j = 0;
int f;
int cont = 0;
struct listaAlumnos
{
    int dni;
    char apellido[30];
    char nombre[30];
    int pri;
    int seg;
    int recPri;
    int recSeg;
};

int main(void)
{
    struct listaAlumnos curso[TAM], auxi;
    while (i < 99)
    {
        for (i = 0; i < 99; i++)
        {
            printf("Ingrese el DNI del alumno:");
            scanf("%d", &auxi.dni);
            if (auxi.dni == 0)
            {
                f = i;
                i = 101;
                break;
            }

            printf("Ingrese el apellido del alumno:");
            scanf("%s", &auxi.apellido);
            printf("Ingrese el nombre del alumno:");
            scanf("%s", &auxi.nombre);
            printf("Ingrese la nota del primer parcial:");
            scanf("%d", &auxi.pri);
            printf("Ingrese la nota del segundo parcial:");
            scanf("%d", &auxi.seg);
            if (auxi.pri < 6)
            {
                printf("Ingrese la nota del primer recuperatorio:");
                scanf("%d", &auxi.recPri);
            }
            if (auxi.seg < 6)
            {
                printf("Ingrese la nota del segundo recuperatorio:");
                scanf("%d", &auxi.recSeg);
            }

            curso[cont] = auxi;
            cont++;
        }
    }

    for (int y = f; y > 0; y--)
    {
        printf("           El DNI del alumno Nº%d es:", j + 1);
        printf("%d\n", curso[j].dni);
        printf("      El apellido del alumno Nº%d es:", j + 1);
        printf("%d\n", curso[j].apellido);
        printf("        El nombre del alumno Nº%d es:", j + 1);
        printf("%d\n", curso[j].nombre);
        printf("El primer parcial del alumno Nº%d es:", j + 1);
        if (curso[j].pri < 6)
        {
            printf("%d\n", curso[j].recPri);
        }
        else
        {
            printf("%d\n", curso[j].pri);
        }
        printf("El segundo parcial del alumno Nº%d es:", j + 1);
        printf("%d", curso[j].seg);
        if (curso[j].seg < 6)
        {
            printf("%d\n", curso[j].recSeg);
        }
        else
        {
            printf("%d\n", curso[j].seg);
        }
        j = j + 1;
    }
}