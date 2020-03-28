/***************************************************************************//**
  @file     +piso.h+
 ******************************************************************************/

#ifndef PISO_H
#define PISO_H

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

#define SUCIO false
#define LIMPIO true
#define TAMAÑOBAL 25

//BALDOSA
typedef struct
{
	unsigned int estado;				//Limpio o sucio
} Baldosa_t;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Baldosa_t* createFloor(unsigned int height, unsigned int width);

Baldosa_t* getBaldosa(Baldosa_t* pbald, unsigned int fil, unsigned int col, unsigned int width);

bool floorIsClean(Baldosa_t* p, unsigned int width, unsigned int height);
#endif //PISO_H