#include <stdio.h>

void encontrarMaxMin(const double *secuencia, int cantidad, double *maximo, double *minimo, int verificado)
{
    *maximo = *minimo = secuencia[0];
    for (int i = 1; i < cantidad; i++)
    {
        if (verificado == 0)
        {
            if (secuencia[i] < *minimo)
            {
                *minimo = secuencia[i];
            }
        }
        else
        {
            if (secuencia[i] > *maximo)
            {
                *maximo = secuencia[i];
            }
        }
    }
}

int main()
{
    double numeros[] = {3.14, 1.0, 2.71, -5.0, 0.0, 10.0};
    int cantidad = sizeof(numeros) / sizeof(numeros[0]);
    double maximo, minimo;
    int ver;

    printf("Si desea calcular el minimo escriba '0', en cambio si desea el maximo escriba '1'");
    scanf("%d", &ver);
    encontrarMaxMin(numeros, cantidad, &maximo, &minimo, ver);
    if (ver == 0)
    {
        printf("El valor mínimo es: %lf\n", minimo);
    }else{
         printf("El valor máximo es: %lf\n", maximo);
    }
    
    return 0;
}