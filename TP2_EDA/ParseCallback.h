#ifndef CALLBACK_H_
#define CALLBACK_H_

#include "simulacion.h"
/* parseCallback:
1. Recibe:
	- (char*) key: La clave de una opción. Si es NULL, es un parámetro.
	- (char*) value: El valor de una opción o parámetro.
	- (void*) userData: Vector donde se irán guardando los datos recibidos.
2. Devuelve:
	- (int) 0 si hubo un error lógico.
	- (int) 1 si estuvo correcto.

Se trabaja con la estructura de userData user_t, donde se guarda el valor del apellido, legajo o dni
que se haya recibido en una unión keys_t, y un vector de parámetros.*/
int parseCallback(char* key, char* value, user_t* userData);

#endif