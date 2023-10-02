#include <stdio.h>
#include <malloc.h>

#define L 30
#define N 3

struct fecha {
	int dia;
	int mes;
	int anio;
};

typedef struct fecha fecha_t;

struct registro {
	int codigo;
	char nombre;
	char apellido;
	fecha_t fechaVisita;
	int tiempoEspera;
};

typedef struct registro registro_t;

registro_t* IngresoGuardia(registro_t *p, int* n, int i){
    printf("Ingrese el codigo del paciente.....................:");
    scanf(" %d", &(p+i)->codigo);
    printf("Ingrese el nombre del paciente.....................:");
    scanf(" %s", &(p+i)->nombre);
    printf("Ingrese el apellido del paciente...................:");
    scanf(" %s", &(p+i)->apellido);
    printf("Ingrese el dia de visita del paciente..............:");
    scanf(" %d", &(p+i)->fechaVisita.dia);
    if (fechaVisita.dia>31)
    {
        return 32;
    }else{
    printf("Ingrese el mes de visita del paciente..............:");
    scanf(" %d", &(p+i)->fechaVisita.mes);
    if (fechaVisita.mes>12)
    {
        return 38;
    }
    
    printf("Ingrese el año de visita del paciente..............:");
    scanf(" %d", &(p+i)->fechaVisita.anio);
    printf("Ingrese el tiempo de espera del paciente en minutos:");
    scanf(" %d", &(p+i)->tiempoEspera);
    
}


int main (void){
int n = N;
int i;
int sumaEspera;
int promedioEspera;
registro_t *pv = (registro_t*) malloc (sizeof(registro_t)*n);

for (i = 0; i < n; i++){
   IngresoGuardia(pv, &n,i); 
}

for (i=0; i<n; i++){
printf("%d \n",*&(pv+i)->codigo);
}

return 0;
}
