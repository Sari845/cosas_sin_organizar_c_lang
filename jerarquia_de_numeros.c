#include <stdio.h>

int main(void){

    int mayor;
    int prim,seg,terc;

    printf("Introduzca el primer numero:");
    scanf("%d", &prim);
    printf("Introduzca el segundo numero:");
    scanf("%d", &seg);
    printf("Introduzca el tercer numero:");
    scanf("%d", &terc);

    if(prim>seg){
        if(prim>terc){ mayor=prim; } 
            else{mayor=terc;}
    }else{ if(seg>terc){mayor=seg;}
            else{mayor=terc;}}
    printf("El mayor numero es:");
    printf("%d\n",mayor);

    return 1;
    }