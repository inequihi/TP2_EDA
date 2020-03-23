/***************************************************************************//**
  @file     +allegro.h+
 ******************************************************************************/
#ifndef ALLEGRO_H
#define ALLEGRO_H

#include <allegro5/allegro.h> 
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h> 
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h> 
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include "simulacion.h"


 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  ******************************************************************************/
#define COMICSANS "comici.ttf"
#define WIDTH_G 1500
#define HEIGHT_G 1000
#define ESCALA 2
typedef struct
{
    unsigned int timeTaken;
    unsigned int cantidad_robots;
}graph_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
ALLEGRO_DISPLAY* allegro_create(ALLEGRO_DISPLAY* display, unsigned int width, unsigned int height);

bool allegro_init(void);
void allegro_shut(ALLEGRO_DISPLAY* display);
void print_baldosas( Piso_t piso, unsigned int width, unsigned int height);
void print_robots(Robot_t* robs, unsigned int count);
void graph(double* array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display);


/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/

ALLEGRO_FONT* set_font(unsigned int size);
#endif //ALLEGRO_H

