/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "piso.h"
#include <stdlib.h>
#include <stdio.h>


 /*******************************************************************************
  *******************************************************************************
						 GLOBAL FUNCTION DEFINITIONS
  *******************************************************************************
  ******************************************************************************/

Baldosa_t* createFloor(unsigned int height, unsigned int width)
{
	unsigned long int  var_piso;
	Baldosa_t* baldosa_array = (Baldosa_t*) malloc(sizeof(Baldosa_t)*((height)+1)*(width+1));		//Multiplicamos size of balosa por el maximo valor de baldosas posibles
	if (baldosa_array != NULL)
	{
		for (var_piso = 0; var_piso < (height * width); var_piso++)
			baldosa_array[var_piso].estado = SUCIO;
	}
	return baldosa_array;
}

bool floorIsClean(Baldosa_t * p,unsigned int width,unsigned int height) {
	
	unsigned int i, j;
	bool state = true;
	
	for (i = 0; i < width && state; i++) {
		for (j = 0; j < height && state; j++) {

			if ((getBaldosa(p, j, i, width))->estado == SUCIO) {
				state = false;
			}
		}
	}
	return state;
}


Baldosa_t* getBaldosa(Baldosa_t* pbald, unsigned int col, unsigned int fil, unsigned int width)
{
	return &pbald[(fil) + (col*width)];
}
