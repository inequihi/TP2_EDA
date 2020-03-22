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
    Piso_t* p;
	Robot_t* robs;
	unsigned int robotCount;
	
	unsigned int tiempo;
	unsigned int modo;
    unsigned int width;
    unsigned int height;

}Simulacion_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Simulacion_t* createSim(unsigned int count, unsigned int height, unsigned int width, unsigned int MODE);

void freeSim(Simulacion_t* psim);

unsigned int simulate(Simulacion_t* psim);

#endif //PROTOIPOS_H