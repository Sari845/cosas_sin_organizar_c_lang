#include <stdio.h>
int main (void) {
    int a,b,c;
    printf("por favor ingrese el numero a");
    scanf("%d",&a);

        printf("por favor ingrese el numero b");
    scanf("%d",&b);

        printf("por favor ingrese el numero c");
    scanf("%d",&c);

    if (a>b) {

        if (a>c) {
            printf("el mayor numero entero es: ", &a);
        } else {
            printf("el mayor numero entero es: ",&c);
        }

    } else {
        if (b>c) {
            printf("el mayor numero entero es: ", &b);
        } else {
            printf("el mayor numero entero es: ",&c);
        }
    }
return 0;
}