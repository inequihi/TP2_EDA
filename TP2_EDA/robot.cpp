#include "robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>       /* cos and sin */

#define PI 3.14159265
using namespace std;
int getNextMove(char cord, int val, int direccion);

Robot_t* createRobots(unsigned int count, unsigned int height, unsigned int width)
{
	unsigned int var_robots;
	Robot_t* robs = (Robot_t *) malloc(count * sizeof(Robot_t));
	if (robs != NULL)
	{
		for (var_robots = 0; var_robots < count; var_robots++)
		{
			robs[var_robots].x = (rand()+1) % (width);
			robs[var_robots].y = (rand()+1) % (height);
			robs[var_robots].direccion = rand() % 360;
		}
	}
	return robs;
}


void freeRobots(Robot_t* robs)
{
	free(robs);
}

void moveRobot(Robot_t* moving_rob, unsigned int width, unsigned int height)
{
	/*
		|
		X
		Se toma el angulo 0 grados en esa vertical e incrementa para la derecha
		Ej: X-- 90 grados
	*/

	Robot_t robot = *moving_rob;
	int newX, newY, newDirection;
	newX = getNextMove('X', robot.x, robot.direccion);
	newY = getNextMove('Y', robot.y, robot.direccion);
	newDirection = rand() % 360;
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

}

int getNextMove(char cord, int val, int direccion) {
	int newX, newY;
	if (cord == 'X') {
		newX = val + cos(PI * direccion / 180);
		return newX;
	}
	else {
		newY = val + sin(PI * direccion / 180);
		return newY;
	}
}