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

		display = al_create_display(TAMA�OBAL * width, TAMA�OBAL * height);
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
				al_draw_filled_rectangle(col * TAMA�OBAL, fil * TAMA�OBAL, (col + 1) * TAMA�OBAL, (fil + 1) * TAMA�OBAL, al_map_rgb(220, 220, 220));
				al_draw_rectangle(col * TAMA�OBAL, fil * TAMA�OBAL, (col + 1) * TAMA�OBAL, (fil + 1) *TAMA�OBAL, al_map_rgb(0, 0, 0), 0);
			}	
			else
				al_draw_filled_rectangle(col * TAMA�OBAL, fil * TAMA�OBAL, (col + 1) * TAMA�OBAL, (fil + 1) * TAMA�OBAL, al_map_rgb(255, 255, 255));
		}
	}
	al_flip_display();
}


void graph(graph_t*array, unsigned int max, unsigned int width, unsigned int height, ALLEGRO_DISPLAY* display)
//Funcion que recibe un arreglo con los 1000 variaciones para robots y el tic correspondiente a cada uno. Estructura se encuentra en simulacion.h
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	ALLEGRO_FONT* comic_sans;
	comic_sans = (ALLEGRO_FONT*)malloc(sizeof(ALLEGRO_FONT*));

	comic_sans = set_font(30);

	//x axis
	al_draw_line(ORIGENX,ORIGENY, ORIGENX, height*(TAMA�OBAL*0.95), al_map_rgb(0,0,0), 4);

	//y axis
	int graph_var;
	
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), (ORIGENX -TAMA�OBAL) , ORIGENY, 0, "%u",0 );
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), (ORIGENX -2*TAMA�OBAL), ORIGENY+ ((height * (TAMA�OBAL * 0.95))/2)-20, 0, "%u", max/2);
	al_draw_textf(comic_sans, al_map_rgb(0, 0, 0), (ORIGENX - 2*TAMA�OBAL), ORIGENY + (height * (TAMA�OBAL * 0.95))-120, 0, "%u", max );

	al_draw_line(ORIGENX, ORIGENY, width*(TAMA�OBAL*0.95), ORIGENY, al_map_rgb(255, 0, 0), 4);			//al_draw_line(20, 20, (array[0].cantidad_robots) * (0.1), 20, al_map_rgb(0, 0, 0), 4);
	//Imprimir arreglo y generar tabla
	al_flip_display();
	//free(comic_sans);

}

ALLEGRO_FONT* set_font(unsigned int size)
{
	return al_load_ttf_font(COMICSANS, size, 0);
}