#include <stdio.h>

float val1;
float val2;
char op;
float res;

int main (void){

printf("Ingrese el primer valor:\n");
scanf("%f", &val1);
printf("Ingrese el segundo valor:\n");
scanf("%f", &val2);
printf("Ingrese el tipo de operación a realizar, * para multiplicar, / para dividir, + para sumar y - para restar:\n");
scanf(" %c", &op);

if(op == '+')
{
    res=val1+val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '-')
{
    res=val1-val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '/')
{
    res=val1/val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '*')
{
    res=val1*val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op =!'+' || op=!'-' || op=!'*' || op=!'/')
{
    printf("Operacion no valida");
}

}
