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
#define MAX_SIMULATIONS 1000

//SIMULACION
typedef struct
{
	Robot_t* robs;
	unsigned int robotCount;
	Piso_t* piso;
	unsigned int tiempo;
	unsigned int modo;
    unsigned int width;
    unsigned int height;

}Simulacion_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Simulacion_t* createSim(unsigned int count, unsigned int height, unsigned int width,unsigned int modo);

void freeSim(Simulacion_t* psim);

unsigned int simulate(Simulacion_t* psim);

#endif //PROTOIPOS_H