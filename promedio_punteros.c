#include <stdio.h>

int main(){
    double promedio, auxi, suma;
    int TAM;
    printf("Ingrese la cantidad de numeros que quiere promediar:");
    scanf("%d", &TAM);
    double numeros[256];
    printf("Ingrese los numeros a promediar:");
    for (int i = 0; i < TAM; i++)
    {
        scanf("%lf", &auxi); 
        numeros[i]=auxi;
        suma += numeros[i];  
    }
    promedio = suma / TAM;
    printf("El promedio es igual a:%lf", promedio);
    
}