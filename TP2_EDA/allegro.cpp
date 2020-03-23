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


void graph(int* array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display)
//Funcion que recibe un arreglo con los 1000 variaciones para robots y el tic correspondiente a cada uno. Estructura se encuentra en simulacion.h
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	ALLEGRO_FONT* comic_sans;
	int axis_size_y = width * TAMAÑOBAL * 0.95;
	int axis_size_x = height * TAMAÑOBAL * 0.95;

	//x axis
	al_draw_line(ORIGENX, ORIGENY, ORIGENX, height * (TAMAÑOBAL * 0.95) + 40, al_map_rgb(0, 0, 0), 4);
	al_draw_filled_triangle(ORIGENX, axis_size_x + 50, ORIGENX - 10, axis_size_x+30, ORIGENX + 10, axis_size_x+30, al_map_rgb(0, 0, 0));

	//y axis
	int graph_var;
	al_draw_line(ORIGENX, ORIGENY,axis_size_y+20, ORIGENY, al_map_rgb(255, 0, 0), 4);			//al_draw_line(20, 20, (array[0].cantidad_robots) * (0.1), 20, al_map_rgb(0, 0, 0), 4);
	al_draw_filled_triangle(axis_size_y+50,ORIGENY,axis_size_y+20,ORIGENY+10,axis_size_y+20,ORIGENY-10, al_map_rgb(255, 0, 0));

	//labels
	comic_sans = set_font(60);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), ORIGENX - 7 * TAMAÑOBAL, ((height * TAMAÑOBAL) / 2) - 120, 0, "ROBOTS");
	al_draw_textf(comic_sans, al_map_rgb(255, 0, 0), (width * TAMAÑOBAL) / 2, ORIGENY - 2 * TAMAÑOBAL, ALLEGRO_ALIGN_CENTER, "TICK COUNT");
	comic_sans = set_font(30);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), (ORIGENX - TAMAÑOBAL), ORIGENY, 0, "%u", 0);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), (ORIGENX - 2 * TAMAÑOBAL), (axis_size_x / 2), 0, "%u", max / 2);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), (ORIGENX - 2 * TAMAÑOBAL), (axis_size_x), 0, "%u", max);


	//Imprimir barras

	int escala = (height * (TAMAÑOBAL * 0.95)) / max;

	for (graph_var = 0; graph_var < max; graph_var++)
	{
		al_draw_line(ORIGENX, ORIGENY + (graph_var * escala), (array[graph_var]) + ORIGENX, ORIGENY + (graph_var * escala), al_map_rgb(128, 0, 128), 2);			//		al_draw_line(ORIGENX, ORIGENY + (graph_var * escala), (array.robot_count[graph_var]) + ORIGENX, ORIGENY + (graph_var * escala), al_map_rgb(128, 0, 128), 2);
	}
	al_flip_display();

}

ALLEGRO_FONT* set_font(unsigned int size)
{
	return al_load_ttf_font(COMICSANS, size, 0);
}