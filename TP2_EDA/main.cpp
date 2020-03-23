#include "piso.h"
#include "simulacion.h"
#include "allegro.h"
#include "parseCmd.h"
#include "prototipos.h"
#include "parseCallback.h"
#include "robot.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

/* DEBUG FUNCTIONS FOR DEVELOPMENT */
void printAllRobots(Robot_t* robs, int count);
void printFloor(Piso_t p, unsigned int height, unsigned int width);
using namespace std;

int main(int argc, char** argv)
{
	user_t Simulation_data;

	/* VALID KEYS: -robots -modo -ancho -alto */
	char test6a[] = "-robots";
	char test6b[] = "10";
	char test6c[] = "-alto";
	char test6d[] = "20";
	char test6e[] = "-ancho";
	char test6f[] = "20";
	char test6g[] = "-modo";
	char test6h[] = "2";

	argv[1] = test6a;
	argv[2] = test6b;
	argv[3] = test6c;
	argv[4] = test6d;
	argv[5] = test6e;
	argv[6] = test6f;
	argv[7] = test6g;
	argv[8] = test6h;

	if (parseCmdLine(9, argv, parseCallback, &Simulation_data))
	{
		unsigned int tickTemp, width, height, modo, robot_count;
		srand(time(NULL));

		robot_count = Simulation_data.cant_robots;
		width = Simulation_data.ancho;
		height = Simulation_data.alto;
		modo = Simulation_data.modo;

		ALLEGRO_DISPLAY* user_display = NULL;

		if (modo == MODO1)
		{

			Simulacion_t* simulation = createSim(robot_count, height, width, modo);

			user_display = allegro_create(user_display, width, height, modo);

			tickTemp = simulate(simulation);

			cout << "clean in " << tickTemp << endl;
			freeSim(simulation);
			allegro_shut(user_display);
		}

		else //MODO 2
		{
			bool modo2_done = false;
			double ticksTaken[400] = { 0.0 };
			double tickTemp = 0;
			unsigned int modo2_var;


			for (modo2_var = 1; modo2_done == false; modo2_var++)
			{
				unsigned int i = 0;
				Simulacion_t* simulation = createSim(modo2_var, height, width, modo);
				for (tickTemp = 0.0; i < 1000; i++)
				{
					if (simulation != NULL)
					{
						tickTemp += (double)simulate(simulation);
					}
					else
					{
						printf("Error en una simulacion\n");
					}
				}
				freeSim(simulation);

				ticksTaken[modo2_var - 1] = (tickTemp / 1000.0);			//Promedio de las 1000 simulaciones
				printf("%f\n", ticksTaken[modo2_var - 1]);

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

			user_display = allegro_create(user_display, WIDTH_G, HEIGHT_G, modo);
			graph(&ticksTaken[0], modo2_var, WIDTH_G, HEIGHT_G, user_display);
			//graph(grapharray, max_robottts, WIDTH_G, HEIGHT_G, user_display);
			al_rest(10.0);
			allegro_shut(user_display);


		}

	}

	
	/*// CHECKING IF FUNCTIONS WORK AS INTENDED
	Robot_t* robs = createRobots(ROBOT_COUNT, height, width);
	printAllRobots(robs, ROBOT_COUNT); //Check robots creation

	Piso_t p;
	p.baldosas_arr = createFloor(height, width);
	printFloor(p, height, width); // Check floor creation using getBaldosa

	cout << "Robot " << 0 << " is in (" << robs[0].x << ", " << robs[0].y << ")" << " direction " << robs[0].direccion << endl;
	moveRobot(&robs[0], width, height, &p);
	cout << "Moving robot 0..." << endl;
	cout << "Robot " << 0 << " is in (" << robs[0].x << ", " << robs[0].y << ")" << " direction " << robs[0].direccion << endl;
	printFloor(p, height, width); // Check Updated baldosa

	ALLEGRO_DISPLAY* user_display = NULL;*/
	return 0;
}


void printAllRobots(Robot_t* robs, int count) {
	int k = 0;
	for (k = 0; k < count; k++) {
		cout << "Robot " << k << " is in (" << robs[k].x << ", " << robs[k].y << ")" << " direction " << robs[k].direccion << endl;
	}
}

void printFloor(Piso_t p, unsigned int height, unsigned int width) {
	// 0 IGUAL SUCIA, 1 LIMPIA
	unsigned int i, j;
	for (i = 0; i < width; i++) {
		// Para da columna;
		for (j = 0; j < height; j++) {
			// Imprimo la columna
			cout << getBaldosa(p.baldosas_arr, i, j, width)->estado << " ";
		}
		cout << endl;
	}
}


/*
#define lblue al_map_rgb(0, 255, 255);
#define yellow al_map_rgb(255, 255, 0);
#define violeta al_map_rgb(128, 0, 128);
#define verde al_map_rgb(0, 255, 0);
#define azul al_map_rgb(0, 0, 255);
#define naranza al_map_rgb(255, 128, 0);
*/