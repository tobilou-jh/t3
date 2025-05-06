#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    int opc = 0;
    char nombre[10][30];
    float precio[10];
    int cont = 0;
    float total = 0;

    do {
        menu();
        opc = leeropc();
        switch (opc) {
            case 1:
                if (cont >= 10) {
                    printf("Limite de productos alcanzado.\n");
                    break;
                } else {
                    int nombre_valido = 0;
                    while (!nombre_valido) {
                        printf("Ingrese el nombre del producto: \n");
                        fflush(stdin);
                        fgets(nombre[cont], 30, stdin);
                        lens(nombre[cont]);
                        nombre_valido = 1; 
                        for (int i = 0; i < cont; i++) {
                            if (strcmp(nombre[i], nombre[cont]) == 0) {
                                printf("El producto ya existe. Intente con otro nombre.\n");
                                nombre_valido = 0;
                                break;
                            }
                        }
                    }
                    precio[cont] = validar_precio();
                    printf("Producto ingresado: %s, Precio: %.2f\n", nombre[cont], precio[cont]);
                    cont++;
                }
                break;
            case 2:
                if (cont == 0) {
                    printf("No hay productos en el inventario.\n");
                    break;
                } else {
                    total = calcular_total(precio, cont);
                    printf("El precio total del inventario es: %.2f\n", total);
                }
                break;
            case 3:
                if (cont == 0) {
                    printf("No hay productos en el inventario.\n");
                    break;
                } else {
                    producto_extremo(nombre, precio, cont);
                }
                break;
            case 4:
                if (cont == 0) {
                    printf("No hay productos en el inventario.\n");
                    break;
                } else {
                    total = calcular_total(precio, cont);
                    float promedio = total / cont;
                    printf("El precio promedio de los productos es: %.2f\n", promedio);
                }
                break;
            case 5:
                if (cont == 0) {
                    printf("No hay productos en el inventario.\n");
                    break;
                } else {
                    buscar_producto(nombre, precio, cont);
                }
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opc != 6);

    return 0;
}
// gcc main.c funciones.c -o t3-1 y ./t3-1