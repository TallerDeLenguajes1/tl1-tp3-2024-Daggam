#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM1 5
#define DIM2 12

void main()
{
    int matriz_productiva[DIM1][DIM2];
    srand(time(NULL));
    printf("Impresion de la matriz:\n");
    for (int i = 0; i < DIM1; i++)
    {
        for (int j = 0; j < DIM2; j++)
        {
            matriz_productiva[i][j] = rand() % 40001 + 10000;
            printf("[%d][%d]: %d\n", i, j, matriz_productiva[i][j]);
        }
    }
    // Promedio por año
    float prom;
    for (int i = 0; i < DIM1; i++)
    {
        prom = 0;
        for (int j = 0; j < DIM2; j++)
        {
            prom += matriz_productiva[i][j];
        }
        prom /= DIM2;
        printf("El promedio de ganancia del anio N-%d es: $%.2f\n", i + 1, prom);
    }

    int maxVal[3]; // 0:Valor,1:mes,2:año
    int minVal[3];
    maxVal[0] = matriz_productiva[0][0];
    minVal[0] = maxVal[0];
    maxVal[1] = 1;
    maxVal[2] = 1;
    minVal[1] = 1;
    minVal[2] = 1;

    for (int i = 1; i < DIM1; i++)
    {
        for (int j = 1; j < DIM2; j++)
        {
            if (maxVal[0] < matriz_productiva[i][j])
            {
                maxVal[0] = matriz_productiva[i][j];
                maxVal[1] = j + 1;
                maxVal[2] = i + 1;
            }
            if (minVal[0] > matriz_productiva[i][j])
            {
                minVal[0] = matriz_productiva[i][j];
                minVal[1] = j + 1;
                minVal[2] = i + 1;
            }
        }
    }
    printf("En el anio %d, mes %d, la maxima ganancia obtenida es de: $%d\n", maxVal[2], maxVal[1], maxVal[0]);
    printf("En el anio %d, mes %d, la minima ganancia obtenida es de: $%d\n", minVal[2], minVal[1], minVal[0]);
}