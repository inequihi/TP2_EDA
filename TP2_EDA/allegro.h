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
#define COMICSANS "font2.ttf"
#define WIDTH_G 1500
#define HEIGHT_G 1000

#define MAXFPS  50000
#define FPS 0.5
#define MINFPS 0.2

#define ESCALA 2
typedef struct
{
    unsigned int timeTaken;
    unsigned int cantidad_robots;
}graph_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
ALLEGRO_DISPLAY* allegro_create(ALLEGRO_DISPLAY* display, unsigned int width, unsigned int height,unsigned int modo);

bool allegro_init(void);
void allegro_shut(ALLEGRO_DISPLAY* display);
void graph(double* array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display, unsigned int width2, unsigned int height2);
void al_final(double tickTemp,ALLEGRO_DISPLAY* display);
void update_piso(Simulacion_t* psim);
void print_piso(Simulacion_t* psim);

/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/

ALLEGRO_FONT* set_font(unsigned int size);
#endif //ALLEGRO_H

