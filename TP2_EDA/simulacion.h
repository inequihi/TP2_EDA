/***************************************************************************//**
  @file     +simulacion.h+
 ******************************************************************************/

#ifndef SIMULACION_H
#define SIMULACION_H

#include <stdio.h>
#include <stdlib.h>
#include "robot.h"
#include "piso.h"
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

#define MODO1 1
#define MODO2 2

//SIMULACION
typedef struct
{
	Robot_t* robs;
	unsigned int robotCount;
	Baldosa_t* piso;
	unsigned int tiempo;
	unsigned int modo;
    unsigned int width;
    unsigned int height;

}Simulacion_t;

typedef struct
{
    unsigned int timeTaken;
    unsigned int cantidad_robots;
}graph_t;
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Simulacion_t* createSim(unsigned int count, unsigned int height, unsigned int width);

void freeSim(Simulacion_t* psim);

unsigned int simulate(Simulacion_t* psim);

#endif //PROTOIPOS_H