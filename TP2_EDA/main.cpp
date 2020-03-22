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
	Simulacion_t* simulation;
	double timeTaken[1000] = { 0.0 };
	unsigned int tickTemp, i, width, height, modo, ROBOT_COUNT;
	srand(time(NULL));

	width = 30;
	height = 30;
	ROBOT_COUNT = 10;
	modo = 1;

	// CHECKING IF FUNCTIONS WORK AS INTENDED
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


	ALLEGRO_DISPLAY* user_display = NULL;
	user_display = allegro_create(user_display, width, height);

	if (modo == MODO1)
	{
		print_baldosas(user_display, p, width, height);
		al_rest(7.0);
		//allegro_shut(user_display);
	}
	else //MODO 2
	{
		/* /
		for (i = 1, "A CRITERIO"; i++)
		{
			user_simulation = createSim(i, height, width);
			if (user_simulation != NULL)
			{
				tickTemp = simulate(user_simulation);
			}
			timeTaken[i - 1] += tickTemp;
			freeSim(user_simulation);
		}
		*/

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
	int i = 0;
	for (i; i <width; i++) {
		// Para da columna
		int j = 0;
		for (j; j<height; j++) {
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