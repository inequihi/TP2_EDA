/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "piso.h"
#include "simulacion.h"
#include "allegro.h"
#include "parseCmd.h"
#include "input.h"
#include "parseCallback.h"
#include "robot.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	user_t Simulation_data;
	if (parseCmdLine(argc, argv, parseCallback, &Simulation_data))
	{
		unsigned int width, height, modo, robot_count;
		double tickTemp=0;
		srand(time(NULL));

		robot_count = Simulation_data.cant_robots;
		width = Simulation_data.ancho;
		height = Simulation_data.alto;
		modo = Simulation_data.modo;

		allegro_t allegro_interface;

		allegro_interface_init(&allegro_interface);

		if (!allegro_init(&allegro_interface))
		{
			printf("ERROR INICIALIZANDO ALLEGRO \n");
			return NULL;
		}

		else if (modo == MODO1)
		{
			Simulacion_t* simulation = createSim(robot_count, height, width, modo);
			if (allegro_create(&allegro_interface, width, height, modo))
			{
				tickTemp = simulate(simulation);
				allegro_results(tickTemp, &allegro_interface);
				allegro_wait4exit(&allegro_interface);
				freeSim(simulation);
				allegro_shut(&allegro_interface);
			}
			else
				printf("ERROR CREANDO ALLEGRO");
		}

		else if (modo == MODO2)
		{
			bool modo2_done = false;
			double ticksTaken[400] = { 0.0 };
			unsigned int modo2_var;

			for (modo2_var = 1; modo2_done == false; modo2_var++)
			{
				unsigned int i = 0;
				Simulacion_t* simulation = createSim(modo2_var, height, width, modo);
				for (tickTemp = 0; i < 1000; i++)
				{
					if (simulation != NULL)
					{
						tickTemp += simulate(simulation);
					}
					else
					{
						printf("Error en una simulacion\n");
					}
				}
				freeSim(simulation);

				ticksTaken[modo2_var - 1] = (tickTemp / 1000.0);	// Promedio de las 1000 simulaciones

				if (modo2_var > 2)
				{
					if ((ticksTaken[modo2_var - 2] - ticksTaken[modo2_var - 1]) >= 0.1)
					{
						modo2_done = false;
					}
					else
					{
						modo2_done = true;
					}
				}
			}
			if (allegro_create(&allegro_interface, WIDTH_G, HEIGHT_G, modo))
			{
				allegro_graph(&ticksTaken[0], modo2_var, WIDTH_G, HEIGHT_G, &allegro_interface, width, height);
				allegro_wait4exit(&allegro_interface);
				allegro_shut(&allegro_interface);

			}
			else
				printf("ERROR CREANDO ALLEGRO");
		}
	}
	return 0;
}
