#include<stdio.h>

int dec_bin(int);
int dec_oct(int);
int dec_hex(int);
#define INICIO 0
#define DEC_BIN 1
#define DEC_OCT 2
#define DEC_HEX 3

int main(void){
    
    int val;
    int tipo;
    int menu;

    printf("Ingrese el tipo de valor a traducir: (1 = dec a binario || 2 = dec a octal || 3 = dec a hex || 4 = binario a dec || 5 = binario a octal || 6 = binario a hex || 7 = octal a decimal || 8 = octal a binario || 9 = octal a hex || 10 = hex a dec || 11 = hex a binario || 12 = hex a octal)");
    scanf("%d", &tipo);
    printf("Ingrese un valor para traducir:");
    scanf("%d", &val);
    menu = tipo;
    printf("%d", menu);

    switch(menu){
        case DEC_BIN:
            dec_bin(val);
            break;
        
        case DEC_OCT:
            dec_oct(val);
            break;

        case DEC_HEX:
            dec_hex(val);
            break;
    }
}

int dec_bin(int val){
    int i, f;
    int objeto[50];
    for ( i = 0; i < 100; i++) {
        objeto[i] = val % 2;
        val = val / 2;
        
        if (val == 1/2) {
            f = i;
            //printf("%d", f);
            i = 101;
        }
        
    }
    printf("Su valor en binario es:");
    for ( f; f > -1; f--) {
        printf("%d", objeto[f]);
    }
    printf("\n\n");
}

int dec_oct(int val){
    int i, f;
    int objeto[50];
    for ( i = 0; i < 100; i++) {
        objeto[i] = val % 8;
        val = val / 8;
        
        if (val == 1/2) {
            f = i;
            //printf("%d", f);
            i = 101;
        }
        
    }
    printf("Su valor en octal es:");
    for ( f; f > -1; f--) {
        printf("%d", objeto[f]);
    }
    printf("\n\n");
}

int dec_hex(int val){
    int i, f;
    char objeto[50];

    for ( i = 0; i < 100; i++) {
        objeto[i] = val % 16;
        val = val / 16;
        
        if (val < 16) {
            f = i;
            //printf("%d", f);
            i = 101;
        }
        
    }
    printf("Su valor en hexadecimal es:");
    for ( f; f > -1; f--) {
        if (objeto[f]==10){
            objeto[f]= 'A';
        }
        if (objeto[f]==11){
            objeto[f]= 'B';
        }
        if (objeto[f]==12){
            objeto[f]= 'C';
        }
        if (objeto[f]==13){
            objeto[f]= 'D';
        }
        if (objeto[f]==14){
            objeto[f]= 'E';
        }
        if (objeto[f]==15){
            objeto[f]= 'F';
        }
        printf("%c", objeto[f]);

    }
    printf("\n\n");
}