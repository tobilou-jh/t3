#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu() {
    printf("Ingrese un opcion: \n");
    printf("1. Ingresar productos:\n");
    printf("2. Calcular el precio total del inventario: \n");
    printf("3. Encontrar el producto mas caro y el mas barato: \n");
    printf("4. Calcular el precio promedio de todos los productos: \n");
    printf("5. Buscar un producto: \n");
    printf("6. Salir\n");
    printf(">> ");
}

void lens(char str[]) {
    int len = strlen(str) - 1;
    if (len >= 0 && str[len] == '\n') {
        str[len] = '\0';
    }
}

int leeropc() {
    int opc, val;
    do {
        fflush(stdin);
        val = scanf("%d", &opc);
        if (val != 1) {
            printf("Dato invalido. Por favor, ingrese un numero entero.\n");
        }
    } while (val != 1);
    return opc;
}

float validar_precio() {
    float precio;
    int val;
    do {
        printf("Ingrese el precio del producto: ");
        fflush(stdin);
        val = scanf("%f", &precio);
        if (val != 1 || precio <= 0) {
            printf("Dato invalido.\n");
        }
    } while (val != 1 || precio <= 0);
    return precio;
}

float calcular_total(float precios[], int cont) {
    float total = 0;
    for (int i = 0; i < cont; i++) {
        total += precios[i];
    }
    return total;
}

void producto_extremo(char nombres[][30], float precios[], int cont) {
    float max = precios[0];
    float min = precios[0];
    char max_nombre[30], min_nombre[30];
    strcpy(max_nombre, nombres[0]);
    strcpy(min_nombre, nombres[0]);

    for (int i = 1; i < cont; i++) {
        if (precios[i] > max) {
            max = precios[i];
            strcpy(max_nombre, nombres[i]);
        }
        if (precios[i] < min) {
            min = precios[i];
            strcpy(min_nombre, nombres[i]);
        }
    }
    printf("El producto mas caro es: %s con un precio de %.2f\n", max_nombre, max);
    printf("El producto mas barato es: %s con un precio de %.2f\n", min_nombre, min);
}

void buscar_producto(char nombres[][30], float precios[], int cont) {
    char buscar[30];
    printf("Ingrese el nombre del producto a buscar: \n");
    fflush(stdin);
    fgets(buscar, 30, stdin);
    lens(buscar);
    int encontrado = 0;

    for (int i = 0; i < cont; i++) {
        if (strcmp(buscar, nombres[i]) == 0) {
            printf("Producto encontrado: %s, Precio: %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}