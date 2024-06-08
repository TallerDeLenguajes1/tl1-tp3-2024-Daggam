#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    //REALIZO EJERCICIO 5.
    
    int cantidad;
    do{
        puts("Cual es la cantidad de nombres a ingresar:");
        scanf("%d",&cantidad);
        if(cantidad<=0) puts("cantidad invalida.");
    }while(cantidad<=0);

    char **nombres = (char**)malloc(cantidad*sizeof(char*));
    char *Buff = (char *)malloc(100 * sizeof(char));
    
    
    printf("Ingrese los nombres:\n");
    fflush(stdin);
    // Cargo el nombre
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d. ",i+1);
        gets(Buff);
        nombres[i] = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombres[i], Buff);
    }
    //libero, printeo y libero.
    free(Buff);
    puts("\nNombres ingresados:");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d. %s\n",i+1,nombres[i]);
        free(nombres[i]);
    }
    free(nombres);
}