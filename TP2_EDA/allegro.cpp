#include "allegro.h"
#include "piso.h"
ALLEGRO_DISPLAY* allegro_create(ALLEGRO_DISPLAY* display, unsigned int width, unsigned int height)
{
	display = (ALLEGRO_DISPLAY*)malloc(sizeof(ALLEGRO_DISPLAY*));

	if (display != NULL)
	{
		if (!allegro_init())
		{
			printf("ERROR INICIALIZANDO ALLEGRO \n");
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
	free(display);

}

void print_baldosas(ALLEGRO_DISPLAY* display, Piso_t piso, unsigned int width, unsigned int height)
{
	// 0 IGUAL SUCIO, 1 LIMPIO
	unsigned int col = 0;
	for (col; col < width; col++) {
		unsigned int fil = 0;
		for (fil; fil < height; fil++) {
			// Imprimo la columna,
			if ((getBaldosa(piso.baldosas_arr, fil, col, width)->estado) == SUCIO)
			{
				al_draw_filled_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(220, 220, 220));
				al_draw_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) *TAMAÑOBAL, al_map_rgb(0, 0, 0), 0);
			}	
			else
				al_draw_filled_rectangle(col * TAMAÑOBAL, fil * TAMAÑOBAL, (col + 1) * TAMAÑOBAL, (fil + 1) * TAMAÑOBAL, al_map_rgb(255, 255, 255));
		}
	}
	al_flip_display();
}


void graph(graph_t array[1000], unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display)
//Funcion que recibe un arreglo con los 1000 variaciones para robots y el tic correspondiente a cada uno. Estructura se encuentra en simulacion.h
{
	al_clear_to_color(al_map_rgb(0, 0, 255));

	//Imprimir arreglo y generar tabla


	al_flip_display();
	al_rest(5.0f);

}