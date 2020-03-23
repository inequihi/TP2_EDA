#include "allegro.h"
#include "piso.h"
#include "robot.h"
ALLEGRO_DISPLAY* allegro_create(ALLEGRO_DISPLAY* display, unsigned int width, unsigned int height)
{
	display = (ALLEGRO_DISPLAY*)malloc(sizeof(ALLEGRO_DISPLAY*));

	if (display != NULL)
	{
		if (!allegro_init())
		{
			printf("ERROR INICIALIZANDO ALLEGRO \n");
			return NULL;
		}

		display = al_create_display(TAMAÑOBAL * width, TAMAÑOBAL * height);
		if (!display)
		{
			printf("ERROR CREANDO DISPLAY \n");
			return NULL;
		}
		return display;

	}

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
					al_shutdown_ttf_addon;
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
	al_shutdown_ttf_addon;
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_destroy_display(display);

}

void print_baldosas( Piso_t piso, unsigned int width, unsigned int height)
{
	// 0 IGUAL SUCIO, 1 LIMPIO
	unsigned int col = 0;
	for (col; col < width; col++) {
		unsigned int fil = 0;
		for (fil; fil < height; fil++) {
			// Imprimo la columna,
			if ((getBaldosa(piso.baldosas_arr, fil, col, width)->estado) == SUCIO)
			{
				al_draw_filled_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(200, 200, 200));
				al_draw_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(0, 0, 0), 0);
			}
			else
				al_draw_filled_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(255, 255, 255));
		}
	}
}

void print_robots(Robot_t* robs, unsigned int count) {
	int i = 0;
	for (i; i < count; i++) {
		Robot_t robot = robs[i];
		al_draw_circle(robot.x * TAMAÑOBAL, robot.y * TAMAÑOBAL, 2.0, al_map_rgb(100, 100, 1), 2.0);
		al_draw_line(robot.x * TAMAÑOBAL, robot.y * TAMAÑOBAL, getNextMove('X', robot.x, robot.direccion) * TAMAÑOBAL, getNextMove('Y', robot.y, robot.direccion)  * TAMAÑOBAL, al_map_rgb(0, 0, 0), 2.0);
	}
	al_flip_display();
}

void graph(double* array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display)
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
	long int graph_var;
	al_draw_line(0.1 * width, 0.9 * height, 0.1 * width, 0.05 * height, al_map_rgb(255, 0, 0), 4);			//al_draw_line(20, 20, (array[0].cantidad_robots) * (0.1), 20, al_map_rgb(0, 0, 0), 4);
	al_draw_filled_triangle(0.1 * width, 0.04 * height, 0.09 * width, 0.09 * height, 0.11 * width, 0.09 * height, al_map_rgb(255, 0, 0));

	//labels
	comic_sans = set_font(30);

	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), 0.37 * width, 0.95 * height, 0, "ROBOTS");
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), 0.02 * width, 0.5 * height, 0, "TICK");
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), 0.01 * width, 0.55 * height, 0, "COUNT");


	comic_sans = set_font(20);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), width * 0.1, height * 0.92, ALLEGRO_ALIGN_CENTRE, "%u", 0);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), width * 0.5, height * 0.92, ALLEGRO_ALIGN_CENTER, "%u", max / 2);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), width * 0.9, height * 0.92, ALLEGRO_ALIGN_CENTER, "%u", max);


	//Imprimir barras

	int escala_x = (0.9 * width - 0.1 * width) / max;
	int escala_y = (float)((0.9 * height - 0.1 * height) / array[1]);

	for (graph_var = 0; graph_var < max; graph_var++)
	{
		al_draw_line(0.1 * width + ((graph_var + 1) * escala_x), 0.9 * height, 0.1 * width + ((graph_var + 1) * escala_x), (0.9 * height) - (array[graph_var]), al_map_rgb(128, 0, 128), 2);			//		al_draw_line(ORIGENX, ORIGENY + (graph_var * escala), (array.robot_count[graph_var]) + ORIGENX, ORIGENY + (graph_var * escala), al_map_rgb(128, 0, 128), 2);
	}

	al_flip_display();
}


ALLEGRO_FONT* set_font(unsigned int size)
{
	return al_load_ttf_font(COMICSANS, size, 0);
}