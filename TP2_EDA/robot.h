/***************************************************************************//**
  @file     +robot.h+
 ******************************************************************************/
#ifndef ROBOT_H
#define ROBOT_H

#include "piso.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

//ROBOT
typedef struct
{
    float x;
	float y;
	int direccion;
}Robot_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Robot_t* createRobots(unsigned int count, unsigned int height, unsigned int width);

void freeRobots(Robot_t* frobots);

void moveRobot(Robot_t* moving_rob, unsigned int width, unsigned int height, Piso_t* p);

float getNextMove(char cord, float val, int direccion);

#endif //ROBOT_H