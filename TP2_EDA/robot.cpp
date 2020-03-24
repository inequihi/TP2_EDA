#include "robot.h"
#include "piso.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>       /* cos and sin */

#define PI 3.14159265
using namespace std;

Robot_t* createRobots(unsigned int count, unsigned int height, unsigned int width, Piso_t* p)
{
	unsigned int var_robots;
	Robot_t* robs = (Robot_t *) malloc(count * sizeof(Robot_t));
	if (robs != NULL)
	{
		for (var_robots = 0; var_robots < count; var_robots++)
		{
			robs[var_robots].x = (rand() % width) + ((float) (rand() % 10 ) / 10);
			robs[var_robots].y = (rand() % height) + ((float)(rand() % 10) / 10);
			robs[var_robots].direccion = rand() % 360;

			/* Limpio baldozas donde coloco mis Robots */
			if (height == 1 && width == 1) {
				// si tengo el caso de 1 sola baldosa si o si mis robots van a apuntar afuera
			}
			else
			{ //Sino busco efectivamente que apunten adentro
				while (getNextMove('X', robs[var_robots].x, robs[var_robots].direccion) < 0 ||
					getNextMove('X', robs[var_robots].x, robs[var_robots].direccion) > width ||
					getNextMove('Y', robs[var_robots].y, robs[var_robots].direccion) < 0 ||
					getNextMove('Y', robs[var_robots].y, robs[var_robots].direccion) > height
					)
				{
					robs[var_robots].direccion = rand() % 360;
				}
			}

			Baldosa_t* b = getBaldosa(p->baldosas_arr, floor(robs[var_robots].y), floor(robs[var_robots].x), width);
			b->estado = LIMPIO;
		}
	}
	else
	{
		free(robs);
		robs = NULL;
	}
	return robs;
}


void freeRobots(Robot_t* robs)
{
	free(robs);
}

void moveRobot(Robot_t* moving_rob, unsigned int width, unsigned int height, Piso_t *p)
{
	/*	|
		X
		Se toma el angulo 0 grados en esa vertical e incrementa para la derecha
		Ej: X-- 90 grados */
	
	Robot_t robot = *moving_rob;
	float newX, newY;
	int newDirection = moving_rob->direccion;
	newX = getNextMove('X', robot.x, robot.direccion);
	newY = getNextMove('Y', robot.y, robot.direccion);

	/* condicional para cambiar de direccion si estoy por salirme del tablero
	   sino mantengo la dirección */

	while ( getNextMove('X', newX, newDirection) < 0 ||
			getNextMove('X', newX, newDirection) > width ||
			getNextMove('Y', newY, newDirection) < 0 ||
			getNextMove('Y', newY, newDirection) > height
			) 
	{
		newDirection = rand() % 360;
	}

	moving_rob->x = newX;
	moving_rob->y = newY;
	moving_rob->direccion = newDirection;

	Baldosa_t* b = getBaldosa(p->baldosas_arr, floor(newY), floor(newX), width);
	b->estado = LIMPIO;
}

float getNextMove(char cord, float val, int direccion) {
	float newX, newY;
	if (cord == 'X') {
		newX = val + sin(PI * direccion / 180);
		return newX;
	}
	else {
		newY = val + cos(PI * direccion / 180);
		return newY;
	}
}