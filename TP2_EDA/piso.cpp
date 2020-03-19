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


Baldosa_t* getBaldosa(Baldosa_t* pbald, unsigned int fil, unsigned int col)
{
	return &pbald[fil*col];
}

void freeFloor(Piso_t* p)
{
	free(p->balsosas_arr);
}
