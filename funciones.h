#ifndef FUNCIONES_H
#define FUNCIONES_H

void menu();
void lens(char str[]);
int leeropc();
float validar_precio();
float calcular_total(float precios[], int cont);
void producto_extremo(char nombres[][30], float precios[], int cont);
void buscar_producto(char nombres[][30], float precios[], int cont);

#endif