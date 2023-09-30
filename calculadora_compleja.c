#include <stdio.h>

float val1;
float val2;
char op;
float res;
int factor;
int main (void){

printf("Bienvenido, que ecuacion requiere usar? Suma= + Resta= - Division= / Multiplicaciòn= * Factorial= ! FUncion exponencial= ^ Sen= s ArcSen= S Cos= c ArCos= C Tan= t ArcTan=T\n");
scanf(" %c", &op);


if(op == '+')
{
    printf("Ingrese el primer valor:\n");
    scanf("%f", &val1);
    printf("Ingrese el segundo valor:\n");
    scanf("%f", &val2);
    res=val1+val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '-')
{
    printf("Ingrese el primer valor:\n");
    scanf("%f", &val1);
    printf("Ingrese el segundo valor:\n");
    scanf("%f", &val2);
    res=val1-val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '/')
{
    printf("Ingrese el numerador:\n");
    scanf("%f", &val1);
    printf("Ingrese el divisor:\n");
    scanf("%f", &val2);
    res=val1/val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '*')
{
    printf("Ingrese el primer valor:\n");
    scanf("%f", &val1);
    printf("Ingrese el segundo valor:\n");
    scanf("%f", &val2);
    res=val1*val2;
    printf("El resultado es: ");
    printf("%f",res);
} else if (op == '!')
{
    printf("Ingrese el numero deseado:\n");
    scanf("%d", &factor);
    for (int b = 1; b > factor; b++){ //HELP
    factor = factor * b;
}
    printf("El numero factorial es:");
    printf("%d", factor);
} else if (op == '^')
{

} else if (op == 's')
{
    
} else if (op == 'S')
{
   
} else if (op == 'c')
{
    /* code */
} else if (op == 'C')
{
    /* code */
} else if (op == 't')
{
    /* code */
} else if (op == 'T')
{
    /* code */
} /*else if (op =!'+' || op=!'-' || op=!'*' || op=!'/')
{
    printf("Operacion no valida");
}
*/
}