#include <stdio.h>
#include <string.h>
int estado = 1;
struct campo
{
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
};

union direccion
{
    unsigned char B;
    struct campo bits;   
}dir;

struct dirip {
    union direccion o1;
    union direccion o2;
    union direccion o3;
    union direccion o4;
};

struct nodo{
    struct dirip ip;
    struct nodo *sig;
};

void menu(){
    
}

int main(){
   
}