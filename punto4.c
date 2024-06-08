#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct Producto
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} Cliente;

Producto *generarProductos(int cantidad);
float calcularCosto(Producto *prod);

void main()
{
    Cliente *clientesVisitados;
    int nCliente;
    srand(time(NULL));

    do
    {
        printf("Ingrese la cantidad de clientes que visita el preventista: ");
        scanf("%d", &nCliente);
        if (nCliente > 5 || nCliente <= 0)
            printf("Los datos ingresados no son correctos. Intentelo de nuevo.");
    } while (nCliente > 5 || nCliente <= 0);

    clientesVisitados = (Cliente *)malloc(sizeof(Cliente) * nCliente);

    for (int i = 0; i < nCliente; i++)
    {
        printf("---- CARGA DEL CLIENTE %d ----");
        clientesVisitados[i].ClienteID = i;
        printf("Ingrese el nombre del cliente: ");
        gets(clientesVisitados[i].NombreCliente);
        clientesVisitados[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientesVisitados[i].Productos = generarProductos(clientesVisitados[i].CantidadProductosAPedir);
    }
    // Liberar clientesVisitados y Productos;
}

Producto *generarProductos(int cantidad)
{
    Producto *productos = (Producto *)malloc(cantidad * sizeof(Producto));
    for (int i = 0; i < cantidad; i++)
    {
        productos[i].ProductoID = i;
        productos[i].Cantidad = rand() % 10 + 1;
        productos[i].TipoProducto = TiposProductos[rand() % 5];
        productos[i].PrecioUnitario = rand() % 91 + 10;
    }

    return productos;
}

float calcularCosto(Producto *prod)
{
    return prod->Cantidad * prod->PrecioUnitario;
}