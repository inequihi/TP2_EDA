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
#include "prototipos.h"


 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  ******************************************************************************/
#define COMICSANS "font2.ttf"
#define WIDTH_G 1500
#define HEIGHT_G 1000

#define MAXFPS  50000
#define FPS 0.2
#define MINFPS 0.1

#define ESCALA 2
typedef struct
{
    unsigned int timeTaken;
    unsigned int cantidad_robots;
}graph_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

typedef struct {
    ALLEGRO_DISPLAY* user_display;
    ALLEGRO_FONT* font;
    ALLEGRO_EVENT_QUEUE* event_queue;
}allegro_t;

bool allegro_create(allegro_t*, unsigned int width, unsigned int height, unsigned int modo);
void allegro_interface_init(allegro_t* allegro_interface);
bool allegro_init(allegro_t*);
void allegro_shut(allegro_t*);
void allegro_wait4exit(allegro_t* allegro_interface);
void allegro_results(double tickTemp, allegro_t* allegro_interface);

void graph(double* array, unsigned int max, unsigned int width, unsigned int height,allegro_t* allegro_interface, unsigned int width2, unsigned int height2);
void update_piso(Simulacion_t* psim);
void print_piso(Simulacion_t* psim);
ALLEGRO_FONT* set_font(unsigned int size);
/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/


#endif //ALLEGRO_H

