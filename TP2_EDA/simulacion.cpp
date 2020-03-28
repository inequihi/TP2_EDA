/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "simulacion.h"
#include "piso.h"
#include "allegro.h"
#include <math.h> 


 /*******************************************************************************
  *******************************************************************************
						 GLOBAL FUNCTION DEFINITIONS
  *******************************************************************************
  ******************************************************************************/
Simulacion_t* createSim(unsigned int count, unsigned int height, unsigned int width, unsigned int MODE)
{
	Simulacion_t* psim;
	psim = (Simulacion_t*)malloc(sizeof(Simulacion_t));
	if (psim != NULL)
	{
		Baldosa_t * piso = createFloor(height, width);
		if (piso != NULL)
		{
			psim->piso = piso;
			Robot_t* User_robs = createRobots(count, height, width, psim->piso);
			if (User_robs != NULL)
			{
				psim->robs = User_robs;
				psim->tiempo = 0;
				psim->modo = MODE;
				psim->robotCount = count;
				psim->height = height;
				psim->width = width;
			}
		}
	}
	else
	{
		printf("Error creado simulacion\n");
	}

	return psim;
}

void freeSim(Simulacion_t* psim)
{
	free(psim->piso);
	free(psim->robs);
	free(psim);
}

unsigned long int simulate(Simulacion_t* psim)
{
	unsigned long ticks = 0;
	unsigned int var_sim;

	while (!floorIsClean(psim->piso, psim->width, psim->height))
	{
		for (var_sim = 0; var_sim < psim->robotCount; var_sim++) {

			/* Muevo robot y limpio baldoza. Consultar moveRobot(...) en robot.cpp */
			moveRobot(&(psim->robs[var_sim]), psim->width, psim->height, psim->piso);
		}
		if ((psim->modo) == MODO1)
		{
			allegro_update_piso(psim);
			allegro_print_piso(psim);
		}
		ticks++;
	}
	return ticks;
}



