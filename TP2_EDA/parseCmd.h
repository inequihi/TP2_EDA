#ifndef PARSECMD_H_
#define PARSECMD_H_

#include "input.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef int (*pCallback) (char*, char*, user_t*);


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*parseCmdLine:
1. Recibe:
	- (int) argC: Cantidad de par�metros, keys y opciones.
	- (char*) argV: Vector con los par�metros, keys y opciones.
	- (*pCallback) parseCallback: Funci�n de callback a la cual referirse al encontrar un
	par�metro, key u opci�n.
	- (void*) userData: Vector que le transferir� a parseCallback para guardar los datos.
2. Devuelve:
	- (int) -1 si se encontraron errores de forma o errores l�gicos (detectados por parseCallback).
	- (int) Suma de par�metros y opciones. */

int parseCmdLine(int argC, char* argV[], pCallback parseCallback,  user_t* userData);

#endif