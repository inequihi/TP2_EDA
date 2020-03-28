#ifndef PARSECMD_H_
#define PARSECMD_H_

#include "simulacion.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef int (*pCallback) (char*, char*, user_t*);


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*parseCmdLine:
1. Recibe:
	- (int) argC: Cantidad de parámetros, keys y opciones.
	- (char*) argV: Vector con los parámetros, keys y opciones.
	- (*pCallback) parseCallback: Función de callback a la cual referirse al encontrar un
	parámetro, key u opción.
	- (void*) userData: Vector que le transferirá a parseCallback para guardar los datos.
2. Devuelve:
	- (int) -1 si se encontraron errores de forma o errores lógicos (detectados por parseCallback).
	- (int) Suma de parámetros y opciones. */

int parseCmdLine(int argC, char* argV[], pCallback parseCallback,  user_t* userData);

#endif