#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 5
void main()
{
    char *nombres[CANT];
    char *Buff = (char *)malloc(100 * sizeof(char));

    // Cargo el nombre
    for (int i = 0; i < CANT; i++)
    {
        gets(Buff);
        nombres[i] = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombres[i], Buff);
        // Printeo el nombre
        puts(nombres[i]);
    }
    free(Buff);
    for (int i = 0; i < CANT; i++)
    {
        free(nombres[i]);
    }
}