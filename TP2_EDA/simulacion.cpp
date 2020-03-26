#include "simulacion.h"
#include "piso.h"
#include "allegro.h"


Simulacion_t* createSim(unsigned int count, unsigned int height, unsigned int width, unsigned int MODE)
{
	Simulacion_t* psim;
	psim = (Simulacion_t*)malloc(sizeof(Simulacion_t));
	if (psim != NULL)
	{
		psim->piso = (Piso_t*)malloc(sizeof(Piso_t));
		psim->piso->baldosas_arr = createFloor(height, width);
		if (psim->piso->baldosas_arr != NULL)
		{
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
	free(psim->piso->baldosas_arr);
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

			moveRobot(&(psim->robs[var_sim]), psim->width, psim->height, psim->piso); //Falta width y height?
		}
		if ((psim->modo) == MODO1)
		{
			update_piso(psim);
			print_piso(psim);
		}
		ticks++;
	}
	return ticks;
}



