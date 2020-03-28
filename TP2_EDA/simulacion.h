/***************************************************************************//**
  @file     +simulacion.h+
 ******************************************************************************/

#ifndef SIMULACION_H
#define SIMULACION_H
#include "robot.h"
#include "piso.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
#define MODO1 1
#define MODO2 2
#define MAX_SIMULATIONS 1000.0

#define MAXKEYLENGTH 15
#define MAXLENGTH 20

#define MAXUSERDATA 9
#define OK 1
#define ERROR 0
#define ROBOTS 0
#define MODO 1
#define ANCHO 2
#define ALTO 3
#define MAXKEYNUMBER 4

#define MAXALTO 100
#define MAXANCHO 70
#define MAXROBOTS 150

typedef struct {
    unsigned int cant_robots;
    unsigned int alto;
    unsigned int ancho;
    unsigned int modo;
} user_t;

typedef struct
{
	Robot_t* robs;
    Baldosa_t* piso;
	unsigned int robotCount;
//	Piso_t* piso;
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

unsigned long int simulate(Simulacion_t* psim);

#endif //PROTOIPOS_H