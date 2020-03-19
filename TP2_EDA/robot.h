/***************************************************************************//**
  @file     +robot.h+
 ******************************************************************************/
#ifndef ROBOT_H
#define ROBOT_H


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

//ROBOT
typedef struct
{
	unsigned int x;
	unsigned int y;
	int direccion;
}Robot_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Robot_t* createRobots(unsigned int count, unsigned int height, unsigned int width);

void freeRobots(Robot_t* frobots);

void moveRobot(Robot_t* moving_rob, unsigned int width, unsigned int height);
#endif //ROBOT_H