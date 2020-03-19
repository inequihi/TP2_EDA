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

//BALDOSA
typedef struct
{
	unsigned int estado;				//Limpio o sucio
} Baldosa_t;

//PISO
typedef struct
{
	Baldosa_t* balsosas_arr;				//Arreglo de baldosas
} Piso_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Baldosa_t* createFloor(unsigned int height, unsigned int width);

Baldosa_t* getBaldosa(Baldosa_t* pbald, unsigned int fil, unsigned int col);

void freeFloor(Piso_t* p);
#endif //PISO_H