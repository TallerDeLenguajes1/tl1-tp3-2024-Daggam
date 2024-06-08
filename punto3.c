#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 5
void main()
{
    char *nombres[CANT];
    char *Buff = (char *)malloc(100 * sizeof(char));
    printf("Ingrese 5 nombres:\n");
    // Cargo el nombre
    for (int i = 0; i < CANT; i++)
    {
        printf("%d. ",i+1);
        gets(Buff);
        nombres[i] = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombres[i], Buff);
    }
    //libero, printeo y libero.
    free(Buff);
    puts("\nNombres ingresados:");
    for (int i = 0; i < CANT; i++)
    {
        printf("%d. %s\n",i+1,nombres[i]);
        free(nombres[i]);
    }
}