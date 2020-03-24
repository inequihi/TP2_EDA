#include "allegro.h"
#include "piso.h"
#include "robot.h"
ALLEGRO_DISPLAY* allegro_create(ALLEGRO_DISPLAY* display, unsigned int width, unsigned int height, unsigned int modo)
{
	display = (ALLEGRO_DISPLAY*)malloc(sizeof(ALLEGRO_DISPLAY*));

	if (display != NULL)
	{
		if (!allegro_init())
		{
			printf("ERROR INICIALIZANDO ALLEGRO \n");
			return NULL;
		}
		switch (modo) 
		{
			case MODO1:
				display = al_create_display(TAMAÑOBAL * width, TAMAÑOBAL * height);
				break;
			case MODO2:
				display = al_create_display(width, height);
				break; 
		}

		if (!display)
		{
			printf("ERROR CREANDO DISPLAY \n");
			return NULL;
		}		
	}
	return display;
}

bool allegro_init()
{
	if (al_init())
	{
		if (al_init_primitives_addon())
		{
			if (al_install_keyboard())
			{
				if (al_init_font_addon())
				{
					if (al_init_ttf_addon())
					{
						if (al_init_image_addon())
						{
							return true;
						}
						else
							printf("ERROR INICIALIZANDO IMAGE ADDON");
						al_shutdown_image_addon();
					}
					else
						printf("ERROR INICIALIZANDO TTF ADDON");
					al_shutdown_ttf_addon();
				}
				else
					printf("ERROR INICIALIZANDO FONT ADDON");
				al_shutdown_font_addon();
			}
			else
				printf("ERROR INSTALANDO TECLADO\n");
			al_shutdown_primitives_addon();
		}
		else
			printf("ERROR INICIALIZANDO PRIMITIVES ADDON \n");
	}
	else
		printf("ERROR INICIALIZANDO ALLEGRO \n");
	return false;
}

void allegro_shut(ALLEGRO_DISPLAY* display)
{
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_destroy_display(display);

}

void update_piso(Simulacion_t* psim)
{
	al_flip_display();
	unsigned int dimension;
	if ((psim->robotCount) < 50)
	{
		dimension = (psim->height) * (psim->width);
		if (dimension < 1200 && dimension >= 800)
			al_rest(1 / MAXFPS);
		else if (dimension < 800 && dimension >= 200)
			al_rest(FPS);
		else if (dimension < 400)
			al_rest(MINFPS);
	}
}

void print_piso(Simulacion_t* psim)
{
	// IMPRIMIMOS BALDOSAS
	unsigned int i, col = 0;
	for (col; col < (psim->width); col++) {
		unsigned int fil = 0;
		for (fil; fil < (psim->height); fil++) {
			// Imprimo la columna,
			if ((getBaldosa(psim->piso->baldosas_arr, fil, col, psim->width)->estado) == SUCIO)
			{
				al_draw_filled_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(200, 200, 200));
				al_draw_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(0, 0, 0), 0);
			}
			else
				al_draw_filled_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(255, 255, 255));
		}
	}

	//IMPRIMIMOS ROBOTS
	for (i = 0; i < (psim->robotCount); i++) {
		Robot_t robot = psim->robs[i];
		al_draw_circle(robot.x * TAMAÑOBAL, robot.y * TAMAÑOBAL, 2.0, al_map_rgb(100, 100, 1), 2.0);
		al_draw_line(robot.x * TAMAÑOBAL, robot.y * TAMAÑOBAL, getNextMove('X', robot.x, robot.direccion) * TAMAÑOBAL, getNextMove('Y', robot.y, robot.direccion) * TAMAÑOBAL, al_map_rgb(0, 0, 0), 2.0);
	}

}


void graph(double* array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display, unsigned int width2, unsigned int height2)
//Funcion que recibe un arreglo con los 1000 variaciones para robots y el tic correspondiente a cada uno. Estructura se encuentra en simulacion.h
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	ALLEGRO_FONT* comic_sans;
	int axis_size_y = width * 0.80;
	int axis_size_x = height * 0.80;

	//x axis
	al_draw_line(0.1 * width, 0.9 * height, 0.95 * width, 0.9 * height, al_map_rgb(0, 0, 0), 4);
	al_draw_filled_triangle(0.96 * width, 0.9 * height, 0.93 * width, 0.91 * height, 0.93 * width, 0.89 * height, al_map_rgb(0, 0, 0));


	//y axis
	unsigned int graph_var;
	al_draw_line(0.1 * width, 0.9 * height, 0.1 * width, 0.05 * height, al_map_rgb(255, 0, 0), 4);			
	al_draw_filled_triangle(0.1 * width, 0.04 * height, 0.09 * width, 0.09 * height, 0.11 * width, 0.09 * height, al_map_rgb(255, 0, 0));

	//labels
	comic_sans = set_font(45);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), 0.4 * width, 0.05 * height, 0, "CALCULATIONS FOR BOARD SIZE %u x %u",width2,height2 );
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), 0.37 * width, 0.95 * height, 0, "ROBOTS");
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), 0.007 * width, 0.5 * height, 0, "TICK");
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), 0.007 * width, 0.55 * height, 0, "COUNT");


	comic_sans = set_font(25);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), width * 0.1, height * 0.92, ALLEGRO_ALIGN_CENTRE, "%u", 0);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), width * 0.5, height * 0.92, ALLEGRO_ALIGN_CENTER, "%u", max / 2);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), width * 0.9, height * 0.92, ALLEGRO_ALIGN_CENTER, "%u", max);

	//Imprimir barras
	double escala_x = (0.9 * width - 0.1 * width) / max;
	double escala_y = (double)((0.8 * height - 0.1 * height) / array[0]);   //Divido tamaño del eje y entre el maximo valor de ticks

	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), width * 0.075, height * 0.87, ALLEGRO_ALIGN_CENTER, "%.1f", 0.0);
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), width * 0.075, height * 0.45, ALLEGRO_ALIGN_CENTER, "%.1f", array[max/2]);
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), width * 0.075, height * 0.1, ALLEGRO_ALIGN_CENTER, "%.1f", array[0]);

	for (graph_var = 0; graph_var < max; graph_var++)
	{
		al_draw_line(0.1 * width + (((double)graph_var) + 1) * escala_x, 0.9 * height, 0.1 * width + (((double)graph_var + 1) * escala_x), 0.8*height - ((array[graph_var])*escala_y) , al_map_rgb(0, 0,0), 3);			
	}
	
	al_flip_display();
}


void al_final(double ticksTotal, ALLEGRO_DISPLAY*display)
{

	al_resize_display(display, 700, 700);
	al_clear_to_color(al_map_rgb(0, 255, 255));
	ALLEGRO_FONT* comic_sans;
	int width, height;
	width = al_get_display_width(display);
	height = al_get_display_height(display);

	comic_sans = set_font(60);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), 0.5 * width, 0.3 * height, ALLEGRO_ALIGN_CENTER, "TOTAL TICKS");
	comic_sans = set_font(70);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), 0.5 * width, 0.5 * height, ALLEGRO_ALIGN_CENTER, "%.0f",ticksTotal);
	al_flip_display();
	al_rest(5);
}

ALLEGRO_FONT* set_font(unsigned int size)
{
	return al_load_ttf_font(COMICSANS, size, 0);
}

