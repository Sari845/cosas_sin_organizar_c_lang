#include <stdio.h>

int main(void) {

int base=1;
int altura=1;
int area=1;

printf("Ingrese la base del triangulo:");
scanf("%d",&base);
if(base <= 0){ 
    printf("La altura tiene un valor negativo");
    return 0;
}

printf("Ingrese la altura del triangulo:");
scanf("%d",&altura);
if(altura <= 0){ 
    printf("La altura tiene un valor negativo");
    return 0;
}

area = (base*altura)/2;
printf("El area del triangulo es de: ");
printf("%d\n",area);

}