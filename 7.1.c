#include <stdlib.h>
#include <stdio.h>

struct ini
{
    int divisor;
    int dividendo;
};

struct fin
{
    int resto;
    int cociente;
};

struct pedirValores()
{
    struct ini valor;
    printf("Ingrese el numero a dividir:");
    scanf("%d", &valor.dividendo);
    printf("Ingrese el numero que actuara como divisor:");
    scanf("%d", &valor.divisor);
    return valor;
}

int hacerCalculo(struct ini valores, struct fin *resultado)
{
    if(valor.divisor==0){
        
    }
}

int main()
{
    struct ini valores = pedirValores();
    struct fin resultado;

    int error = hacerCalculo(valores, &resultado);

    if (error == 0){
        printf("Cociente:%d\n", resultado.cociente);
        printf("Resto   :%d\n\n", resultado.resto);
    }
}


