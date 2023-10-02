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

struct ini pedirValores()
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
    if(valores.divisor==0){
        printf("No se puede dividir por cero.\n");
        return 1;
    }
    resultado->cociente = valores.dividendo / valores.divisor;
    resultado->resto = valores.dividendo % valores.divisor;
    return 0;
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
    return 0;
}


