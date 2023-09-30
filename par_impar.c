#include <stdio.h>
int val;
int res;

int main (void){
printf("Ingrese un numero:  ");
scanf("%d", &val);
res = val %2;
if(res == 0){
    printf("\nFelicidades, el numero ingresado es par\n\n");
} else {
    printf("\nMal ahì, el numero ingresado es impar\n\n");
}
return 0;
}