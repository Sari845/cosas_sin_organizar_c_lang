#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct alumno{
    char nombre[50];
    char apellido[50];
    long legajo;
    float notaP1;
    float notaP2;
    float notaProyecto;
};

struct nodo{
    struct alumno al;
    struct nodo *sig;
};

FILE *fp;

struct nodo *ingreso(struct nodo *INI){
    struct nodo *aux1;
    int flag = 0, loop = 1;
    aux1 = (struct nodo *) malloc(sizeof(struct nodo));
    printf("\nNombre: ");
    setbuf(stdin,NULL);
    fgets(aux1->al.nombre,50,stdin);
    aux1->al.nombre[strlen(aux1->al.nombre)-1] = 0;
    printf("\nApellido: ");
    setbuf(stdin,NULL);
    fgets(aux1->al.apellido,50,stdin);
    aux1->al.apellido[strlen(aux1->al.apellido)-1] = 0;
    printf("\nLegajo: ");
    scanf(" %ld", &aux1->al.legajo);
    printf("\nNota primer parcial: ");
    scanf(" %f",&aux1->al.notaP1);
    printf("\nNota segundo parcial: ");
    scanf(" %f",&aux1->al.notaP2);
    printf("\nNota proyecto: ");
    scanf(" %f",&aux1->al.notaProyecto);
    printf("\n%p\n",INI);
    struct nodo *actual = NULL;
    struct nodo *prev = NULL;
    actual = INI;
    printf("\nactual: %p\n",actual);
    printf("\naux: %p\n",aux1);
    if(INI){
        do{
            printf("\nLlego\n");
            if(aux1->al.legajo >= actual->al.legajo){
                prev = actual;
                actual = actual->sig;
                flag = 1;
            }else{
                aux1->sig = actual;
                prev->sig = aux1;
                loop = 0;
                if (flag!=0){
                    INI = aux1;
                }
            }
            if(actual->sig == NULL){
                actual->sig = aux1;
                aux1->sig = NULL;
            }
        }while(loop == 1 && actual->sig != NULL);
    }else{
        INI = aux1;
        aux1->sig = NULL;
    }
}

void buscar(char search, struct nodo *INI){
    struct nodo *aux;
    aux = INI;
    int loop = 1;
    do{
        if(aux->al.legajo == search){
            printf("\n------ ENCONTRADO ------\n");
            printf("Nombre: %s\n",aux->al.nombre);
            printf("Apellido: %s\n",aux->al.apellido);
            printf("Legajo: %ld\n",aux->al.legajo);
            printf("Nota 1: %lf\n",aux->al.notaP1);
            printf("Nota 2: %lf\n",aux->al.notaP2);
            printf("Nota proyecto: %lf\n",aux->al.notaProyecto);
            return;
        }
        if(aux->sig == NULL){
            printf("No se encontró el alumno\n");
            return;
        }
        aux = aux->sig;
    }while(loop == 1);
}

void borrar(struct nodo **INI, long delete){
    struct nodo *aux;
    struct nodo *prev = NULL;
    aux = *INI;
    int loop = 1;
    
    do{
        if(aux->al.legajo == delete){
            printf("\nEncontro\n");
            if(prev == NULL){
                *INI = (*INI)->sig;
                printf("\nAlumno eliminado1: %ld\n",aux->al.legajo);
                free(aux);
                loop=0;
                return;
            }
            else{
                prev->sig = aux->sig;
                printf("\nAlumno eliminado2: %ld\n",aux->al.legajo);
                free(aux);
                return;
            }
        }
        if(aux->sig == NULL){
            printf("No se encontró el alumno\n");
            return;
        }
        prev = aux;
        aux = aux->sig;
    }while(loop == 1);
    
    /*struct nodo *p;
    printf("%s",(*lsp)->al.apellido);
    p = *lsp;
    *lsp = (*lsp)->sig;

    free(p);*/
    
}

float promedios(struct nodo *INI){
    struct nodo *aux;
    aux = INI;
    int loop = 1, aprobados = 0,recuperan = 0;
    float promedio = 0;

    do{
        if(aux->al.notaP1 >= 4 && aux->al.notaP2 >= 4 && aux->al.notaProyecto >= 4){
            aprobados++;
            promedio = promedio + (aux->al.notaP1 + aux->al.notaP2 + aux->al.notaProyecto)/3;
        }else{
            recuperan++;
        }
        if(aux->sig == NULL){
            printf("\n%d\n",loop);
            loop = 0;
        }else{
            aux = aux->sig;
        }
    }while(aux->sig != NULL || loop == 1);
    printf("\nAprobados: %d\n",aprobados);
    printf("\nDesaprobados: %d\n",recuperan);
    printf("\npromedio de aprobacion: %f\n",promedio/aprobados);
}

void guardar(struct nodo *INI){
    int flag = 0;
    struct nodo *aux = INI;
    FILE *pf;
    remove("datosAlumnos.txt");
    pf = fopen("datosAlumnos.txt", "w+");
    do{
        if(aux->sig == NULL){
            flag = 1;
        }
        fputs(aux->al.nombre,pf);
        fputc(',',pf);
        fputs(aux->al.apellido,pf);
        fputc(',',pf);
        fprintf(pf,"%ld",aux->al.legajo);
        fputc(',',pf);
        fprintf(pf,"%.1f",aux->al.notaP1);
        fputc(',',pf);
        fprintf(pf,"%.1f",aux->al.notaP2);
        fputc(',',pf);
        fprintf(pf,"%.1f",aux->al.notaProyecto);
        if(flag == 0){
            fputc(',',pf);
            aux = aux->sig;
        }
    }while(aux->sig != NULL || flag == 0);
    fclose(pf);
}

int menu(struct nodo *INI){
    int i = 0,loop = 1;
    long legajoSel;
    while(loop != 0){
    printf("\n¿Que desea hacer?:\n1: Agregar alumno\n2: Buscar alumno\n3: Borrar alumno\n4: Dar promedios\n5: Salir\n");
    scanf(" %d",&i);
    switch(i){
        case 1:
        ingreso(INI);
        //printf(" %s\n",INI->al.nombre);
        break;

        case 2:
        printf("\nNumero de legajo a buscar: ");
        scanf(" %ld",&legajoSel);
        buscar(legajoSel, INI);
        //printf("Hola");
        break;

        case 3:
        printf("\nNumero de legajo a eliminar: ");
        scanf(" %ld",&legajoSel);
        borrar(&INI,legajoSel);
        break;

        case 4:
        promedios(INI);
        break;

        case 5:
        guardar(INI);
        loop = 0;
        break;
    }
    }

}

struct nodo *carga(){
    char archivo [2048], *token;
    const char s[2] = ",";
    int i=0,j=0,flag = 0;;
    struct nodo *INI;
    struct nodo *aux2 = NULL;
    struct nodo *prev = NULL;
    //aux2 = (struct nodo *) malloc(sizeof(struct nodo));
    FILE *fp;

    fp = fopen("datosAlumnos.txt", "r");
    while(fp != NULL){
        archivo[i] = fgetc(fp);
        i++;
        if (feof(fp)){
            break;
        }
    }
    token = strtok(archivo,s);
    printf("%s",token);
    while(token != NULL){
        prev = aux2;
        aux2 = (struct nodo *) malloc(sizeof(struct nodo));
        strcpy(aux2->al.nombre,token);
        token = strtok(NULL,s);
        strcpy(aux2->al.apellido,token);
        token = strtok(NULL,s);
        aux2->al.legajo = atol(token);
        token = strtok(NULL,s);
        aux2->al.notaP1 = atof(token);
        token = strtok(NULL,s);
        aux2->al.notaP2 = atof(token);
        token = strtok(NULL,s);
        aux2->al.notaProyecto = atof(token);
        if(flag == 0){
            aux2->sig = NULL;
            INI = aux2;
            flag = 1;
        }else{
            prev->sig = aux2;
        }
        printf("\nDireccion: %p",aux2);
        printf("\nAnterior: %p",prev);
        j++;
        token = strtok(NULL,s);
        if(token == NULL){
            aux2->sig = NULL;
        }
    }
    //fclose(fp);
    return INI;
}

int main(){
    struct nodo *INI = NULL;
    INI = carga();
    printf("\n %p",INI);
    menu(INI);
}