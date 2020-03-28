/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>       /* cos and sin */

#define PI 3.14159265
using namespace std;

/*******************************************************************************
 *******************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
Robot_t* createRobots(unsigned int count, unsigned int height, unsigned int width, Baldosa_t* p)
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

			if (height == 1 && width == 1) {
				/* si tengo el caso de 1 sola baldosa si o si mis robots van a apuntar afuera 
				   y ademas con existir al menos 1 robot la baldoza queda limpia en tiempo 0 */
			}
			else
			{   /* Caso contrario, busco efectivamente que mi robot apunte inicialmente hacia el interior del piso */
				while (getNextMove('X', robs[var_robots].x, robs[var_robots].direccion) < 0 ||
					getNextMove('X', robs[var_robots].x, robs[var_robots].direccion) > width ||
					getNextMove('Y', robs[var_robots].y, robs[var_robots].direccion) < 0 ||
					getNextMove('Y', robs[var_robots].y, robs[var_robots].direccion) > height
					)
				{
					robs[var_robots].direccion = rand() % 360;
				}
			}

			/* Limpio baldozas en donde arrancan los robots */
			Baldosa_t* b = getBaldosa(p, floor(robs[var_robots].y), floor(robs[var_robots].x), width);
			b->estado = LIMPIO;
		}
	}
	return robs;
}

void moveRobot(Robot_t* moving_rob, unsigned int width, unsigned int height, Baldosa_t *p)
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

	/* En el mismo movimiento del robot limpio la baldoza en la que caigo */
	Baldosa_t* b = getBaldosa(p, floor(newY), floor(newX), width);
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