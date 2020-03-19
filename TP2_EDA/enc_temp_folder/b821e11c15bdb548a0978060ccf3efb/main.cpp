#include "piso.h"
#include "simulacion.h"
#include "robot.h"
#include "allegro5/allegro.h"

/****************************************************************
 *						ALLEGRO  								*
/****************************************************************/
void graph(graph_t* arr,unsigned int width, unsigned int height);

int main(int argc, char** argv)
{
	Simulacion_t* simulation;
	double timeTaken[1000] = { 0.0 };
	unsigned int tickTemp, i;
	int width, height,modo;

	width = atoi(argv[1]);
	height = atoi(argv[2]);
	modo = atoi(argv[3]);
	
	if (modo == MODO1)
	{

	}
	else //MODO 2
	{
		graph_t tabla[1000];
		/* 
		for (i = 1, "A CRITERIO"; i++)
		{
			user_simulation = createSim(i, height, width);
			if (user_simulation != NULL)
			{
				tickTemp = simulate(user_simulation);
			}
			timeTaken[i - 1] += tickTemp;
			freeSim(user_simulation);
		}
		*/
		graph(tabla,width,height);

	}
	
	return 0;
}

void graph(graph_t array[1000], unsigned int width, unsigned int height)		
//Funcion que recibe un arreglo con los 1000 variaciones para robots y el tic correspondiente a cada uno. Estructura se encuentra en simulacion.h
{
	al_init();
	al_create_display(width, height);
	al_clear_to_color(al_map_rgb(0, 0, 255));
	
	//Imprimir arreglo y generar tabla

	al_flip_display();
	al_rest(5.0f);

}
/*
#define lblue al_map_rgb(0, 255, 255);
#define yellow al_map_rgb(255, 255, 0);
#define violeta al_map_rgb(128, 0, 128);
#define verde al_map_rgb(0, 255, 0);
#define azul al_map_rgb(0, 0, 255);
#define naranza al_map_rgb(255, 128, 0);
*/