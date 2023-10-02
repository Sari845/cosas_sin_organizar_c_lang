#include <stdlib.h>
#include <stdio.h>


int pedirValores(int dividendo,int divisor){
    printf("Ingrese el numero a dividir");
    scanf("%d", &dividendo);
    printf("Ingrese el numero que actuara como divisor");
    scanf("%d", &divisor);
}
int hacerCalculo(){};
struct ini{
    int divisor;
    int dividendo;
};

struct fin{
    int resto;
    int cociente;
};

int main(){
    struct ini aux;

    pedirValores(aux.dividendo,aux.divisor);
    printf("%d \n %d", aux.dividendo, aux.divisor);
    hacerCalculo();
}