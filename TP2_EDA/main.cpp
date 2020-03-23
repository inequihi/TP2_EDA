#include "piso.h"
#include "simulacion.h"
#include "allegro.h"
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
	//Simulacion_t* simulation;
	unsigned int tickTemp, width, height, modo, ROBOT_COUNT;
	srand(time(NULL));

	width = 10;
	height = 10;
	ROBOT_COUNT = 10;
	modo = 1;

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
	ALLEGRO_DISPLAY* user_display = NULL;

	if (modo == MODO1)
	{

		Simulacion_t* simulation = createSim(ROBOT_COUNT, height, width, modo);

		user_display = allegro_create(user_display, width, height,modo);

		tickTemp = simulate(simulation);

		cout << "clean" << endl;
		freeSim(simulation);
		allegro_shut(user_display);
	}

	else //MODO 2
	{
		bool modo2_done = false;
		double ticksTaken[400] = { 0.0 };
		double tickTemp=0;
		unsigned int modo2_var;

		for (modo2_var = 1; modo2_done == false; modo2_var++)
		{
			for (tickTemp = 0.0; modo2_var < 1000; modo2_var++)
			{
				Simulacion_t* simulation = createSim(modo2_var, height, width, modo);
				if (simulation != NULL)
				{
					tickTemp += (double)simulate(simulation);
					freeSim(simulation);
				}
				else
				{
					printf("Error en una simulacion\n");
				}
			}

			ticksTaken[modo2_var - 1] = tickTemp /1000.0;			//Promedio de las 1000 simulaciones
			printf("%f\n", ticksTaken[modo2_var]);

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
		
		
			user_display=allegro_create(user_display, WIDTH_G, HEIGHT_G,modo);
			graph(ticksTaken,modo2_var, WIDTH_G, HEIGHT_G, user_display);
			//graph(grapharray, max_robottts, WIDTH_G, HEIGHT_G, user_display);
			al_rest(5.0);
			allegro_shut(user_display);


	}

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