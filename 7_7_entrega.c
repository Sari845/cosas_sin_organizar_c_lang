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
    printf("Ingrese el legajo del estudiante: ");
    scanf("%ld", &dato->legajo);
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", dato->nombre);
    printf("Ingrese el apellido del estudiante: ");
    scanf("%s", dato->apellido);
}

int compararApellidos(char apellido1[], char apellido2[])
{
    int i = 0;
    while (apellido1[i] != '\0' && apellido2[i] != '\0')
    {
        if (apellido1[i] != apellido2[i])
        {
            return (apellido1[i] - apellido2[i]);
        }
        i++;
    }
    return (apellido1[i] - apellido2[i]);
}

void ordenamiento(struct guarda *dato, int f)
{
    struct guarda aux;
    int bandera = 1;
    while (bandera)
    {
        bandera = 0;
        for (int i = 0; i < f - 1; i++)
        {
            if (compararApellidos(dato[i].apellido, dato[i + 1].apellido) > 0)
            {
                aux = dato[i];
                dato[i] = dato[i + 1];
                dato[i + 1] = aux;
                bandera = 1;
            }
        }
    }
    for (int j = 0; j < f; j++)
    {
        printf("Legajo: %ld\n", dato[j].legajo);
        printf("Nombre: %s\n", dato[j].nombre);
        printf("Apellido: %s\n", dato[j].apellido);
    }
}

int main()
{
    struct guarda *datos = NULL;
    int i = 0;
    int j = 1;
    size_t a;

    datos = (struct guarda *)malloc(sizeof(struct guarda));
    if (datos == NULL)
    {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    do
    {
        carga(&datos[i]);
        a = sizeof(struct guarda) * (j + 1);
        printf("\n%ld\n", (long)a);
        struct guarda *temp = (struct guarda *)realloc(datos, a);
        if (temp == NULL)
        {
            printf("Error: No se pudo asignar memoria.\n");
            free(datos);
            return 1;
        }
        datos = temp;
        i++;
        j++;
    } while (datos[i - 1].legajo != 0);

    ordenamiento(datos, i);

    free(datos);
    return 0;
}
