#include <stdio.h>
#include <string.h>

char archivo[30];
int i = 0;
char c;
char *token;
const char s[2] = ",";
int main()
{
    FILE *fp;
    fp = fopen("miarch.txt", "r");
    while (fp != NULL)
    {
        archivo[i] = fgetc(fp);
        i++;
        if (feof(fp))
        {
            break;
        }
    }
        token = strtok(archivo,s);
        while (token!=NULL)
        {
        printf("%d: %s\n",i, token);
        token = strtok(NULL,s);    
        }
     return 0;   
        
}