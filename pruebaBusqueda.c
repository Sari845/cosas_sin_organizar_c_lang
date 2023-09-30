#include <stdio.h>
#include <stdlib.h>
char palabraaBuscar[30] = "hola";
int coincidencia=0;
int alumnonumero=-1;
int flag = 1;
struct alumno{
    char nombre[30];
}*al;

int main(){
    al = (struct alumno*) malloc (sizeof(struct alumno)*10);
    for(int i=0; i<10; i++){
        printf("Ingrese el nombre del alumno:");
        scanf("%s", al[i].nombre);
        printf("%s", al[i].nombre);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (al[i].nombre[j]== palabraaBuscar[j])
            {
                coincidencia++;
            }
            if (coincidencia==30 && flag ==1)
            {
                alumnonumero=i;
                flag = 0;
            }
            
        }
        coincidencia=0;
    }
    if (alumnonumero==-1)
    {
        printf("\nNo se encontró al alumno\n\n");
    }else{
    printf("\nEl alumno a buscar es el Nº: %d\n\n", alumnonumero+1); 
    }  

}