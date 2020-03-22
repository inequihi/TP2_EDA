#include "simulacion.h"
#include "piso.h"
Simulacion_t* createSim(unsigned int count, unsigned int height, unsigned int width,unsigned int MODE)
{
	Simulacion_t* psim;
	
	Piso_t* piso;
	piso->baldosas_arr = createFloor(height, width);
	psim->p = piso;

	psim->robs= createRobots(count, height, width);

	psim->tiempo = 0;
	psim->modo = MODE;
	psim->robotCount = count;
	psim->height = height;
	psim->width = width;

	return psim;
}

void freeSim(Simulacion_t* psim)
{
	free(psim->p->baldosas_arr);
	free(psim->robs);
}

unsigned int simulate(Simulacion_t* psim)
{
	unsigned long ticks = 0;
	unsigned int var_sim;
	
	while (!floorIsClean(psim->p,psim->width,psim->height))
	{
		for (var_sim = 0; psim->robotCount; var_sim++)
			moveRobot(&(psim->robs[var_sim]),psim->width,psim->height, psim->p); //Falta width y height?
		ticks++;
	}

	return ticks;
}



