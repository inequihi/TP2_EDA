/***************************************************************************//**
  @file     +piso.h+
 ******************************************************************************/

#ifndef PISO_H
#define PISO_H

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

//BALDOSA
typedef struct
{
	unsigned int estado;				//Limpio o sucio
}Baldosa_t;

//PISO
typedef struct
{

	Baldosa_t* balsosas_arr;				//Arreglo de baldosas
	unsigned int width;
	unsigned int height;

}Piso_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

Piso_t* createFloor(unsigned int height, unsigned int width);

Baldosa_t* getBaldosa(Baldosa_t* pbald, unsigned int fil, unsigned int col);

void freeFloor(Piso_t* p);
#endif //PISO_H