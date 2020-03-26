#ifndef CALLBACK_H_
#define CALLBACK_H_

#include "prototipos.h"
/* parseCallback:
1. Recibe:
	- (char*) key: La clave de una opci�n. Si es NULL, es un par�metro.
	- (char*) value: El valor de una opci�n o par�metro.
	- (void*) userData: Vector donde se ir�n guardando los datos recibidos.
2. Devuelve:
	- (int) 0 si hubo un error l�gico.
	- (int) 1 si estuvo correcto.

Se trabaja con la estructura de userData user_t, donde se guarda el valor del apellido, legajo o dni
que se haya recibido en una uni�n keys_t, y un vector de par�metros.*/
int parseCallback(char* key, char* value, user_t* userData);

void lowerstring(char* s);								// Convierte a min�scula todas las may�sculas de una palabra.

int checkvalue(char* val, int keyid);                   //verifica que los valores recibidos sea adecuados seg�n el key al que se encuentran asociados

#endif