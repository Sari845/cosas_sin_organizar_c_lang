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
    FILE *fp;
    fp = open("archivo.txt", "r");
    const char s[2] = ','
    char *token;
    char archivo[31];

    while(fp!=NULL){
        archivo[i]=fgetc(fp);
        i++
        if (feof(fp))
        {
            break;
        }
    }
    token = strtok(archivo,s);
    while(token!=NULL){
        token = strtok(NULL,s);
    }
    return 0;
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
        carga(&datos[i]);
        flag = fin(&datos, i);
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