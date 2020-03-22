#include "piso.h"
#include <stdlib.h>
#include <stdio.h>

Baldosa_t* createFloor(unsigned int height, unsigned int width)
{
	unsigned int  var_piso;
	Baldosa_t* baldosa_array = (Baldosa_t*) malloc(height*width*sizeof(Baldosa_t));
	if (baldosa_array != NULL)
	{
		for (var_piso = 0; var_piso < (height * width); var_piso++)
			baldosa_array[var_piso].estado = SUCIO;
	}
	return baldosa_array;
}

bool floorIsClean(Piso_t * p,unsigned int width,unsigned int height) {
	
	int i, j;
	bool state = true;
	
	for (i = 0; i < width && state; i++) {
		for (j = 0; j < height && state; j++) {

			if ((getBaldosa(p->baldosas_arr, i, j, width))->estado == SUCIO) {
				state = false;

			}

		}

	}
	return state;
}
Baldosa_t* getBaldosa(Baldosa_t* pbald, unsigned int col, unsigned int fil, unsigned int width)
{

	return &pbald[(fil*width) + col];
}

void freeFloor(Piso_t* p)
{
	free(p->baldosas_arr);
}
