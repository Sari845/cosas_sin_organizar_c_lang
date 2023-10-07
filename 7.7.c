#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


struct guarda
{
    long legajo;
    char apellido[31];
    char nombre[31];
};

void carga(struct guarda *dato)
{
    FILE *fp;
    struct stat fpstat;
    fp = fopen("archivo.txt", "r");
    stat("archivo.txt", &fpstat);
    const char s[2] = ",";
    char *token;
    char *archivo;
    int i = 0;
    int j = 1;
    int x = 0;
    dato = (struct guarda *) malloc(sizeof(struct guarda));
    archivo = (char *)malloc((size_t)fpstat.st_size);
    while (fp != NULL)
    {
        archivo[i] = fgetc(fp);
        i++;
        if (feof(fp))
        {
            break;
        }
    }
    token = strtok(archivo, s);
    while (token != NULL)
    {
        dato = (struct guarda *) realloc(dato, sizeof(struct guarda)*(j + 1));
        strcpy((dato + j)->nombre, token);
        token = strtok(NULL, s);
        printf("%s\n", (dato + j)->nombre);
        j++;
    }
}

int fin(struct guarda *dato, int i)
{
    if (dato[i - 1].legajo != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct guarda *datos = NULL;
    int i = 0;
    int flag = 0;
    datos = realloc(datos, (i + 1) * sizeof(struct guarda));
    do
    {
        carga(datos);
        flag = fin(datos, i);
        i++;
    } while (flag == 0);
    for (int j = 0; j < i - 1; j++)
    {
        printf("Legajo: %ld\n", datos[j].legajo);
        printf("Nombre: %s\n", datos[j].nombre);
        printf("Apellido: %s\n", datos[j].apellido);
    }
    free(datos);
    return 0;
}