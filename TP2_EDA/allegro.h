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
#define ORIGENX 90
#define ORIGENY 90
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
void print_baldosas(ALLEGRO_DISPLAY* display, Piso_t piso, unsigned int width, unsigned int height);
void graph(graph_t* array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display);


/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/

ALLEGRO_FONT* set_font(unsigned int size);
#endif //ALLEGRO_H

