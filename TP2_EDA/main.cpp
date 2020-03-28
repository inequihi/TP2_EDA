/*******************************************************************************
 * Instrucciones de simulacion
 ******************************************************************************/
/*
Keys permitidos seguidos de un espacio y sus valores (#):
	-Robots #
	-Alto # (entre 1 y 100)
	-Ancho # (entre 1 y 70)
	-Modo # (1 o 2)

Modo 1: Ingresar alto y ancho del piso, cantidad de robots para limpiarlo. Mostrara
		proceso de limpieza. 
Modo 2: Ingresar alto y ancho del piso, se obtendra un grafico con los movimientos 
		totales necesarios que haran n robots para limpiarlo. Muestra valores de 
		n-robots hasta que el tiempo medio entre los timepos de los robots sea menor a 0,1.
*/
 /*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "piso.h"
#include "simulacion.h"
#include "allegro.h"
#include "parseCmd.h"
#include "parseCallback.h"
#include "robot.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	user_t Simulation_data = {ERROR,ERROR,ERROR,ERROR};				//Por default inciamos todos los datos con 0. 
	if (parseCmdLine(argc, argv, parseCallback, &Simulation_data))		//Obtenemos datos y rellenamos estructura, si no hay errores prosigue al programa
	{
		unsigned int width, height, modo, robot_count;						
		double tickTemp = 0;											//TickTemp alojara los ticks o movimientos totales en los que se limpia un piso
		srand(time(NULL));

		robot_count = Simulation_data.cant_robots;						//Con los datos obtenidos incializamos las variables que usaremos en simulacion
		width = Simulation_data.ancho;
		height = Simulation_data.alto;
		modo = Simulation_data.modo;
				
		allegro_t allegro_interface;									//Estructura con punteros a display, fuentes y cola de eventos

		//Inicio allegro antes de empezar 
		allegro_interface_init(&allegro_interface);					
		if (!allegro_init(&allegro_interface))
		{
			printf("ERROR INICIALIZANDO ALLEGRO \n");
			modo == ERROR;
		}

		else if (modo == MODO1)
		{
			if (Simulation_data.cant_robots != ERROR)					//Si no se ingresaron valores para robots no se puede correr simulacion
			{
				Simulacion_t* simulation = createSim(robot_count, height, width, modo);		

				if (allegro_create(&allegro_interface, width, height, modo))					
				{
					tickTemp = simulate(simulation);									//Corremos simulacion y guardamos en tickTemp los movimientos que tomo limpiar
					allegro_results(tickTemp, &allegro_interface);						//Mostramos los resultados al usuario
					freeSim(simulation);												//Liberamos espacio reservado en heap donde se guardo simulacion
					allegro_shut(&allegro_interface);									//Liberamos mecanismos de allegro
				}
				else
					printf("ERROR CREANDO ALLEGRO");
			}
			else
				printf("INGRESE CANTIDAD DE ROBOTS PARA USAR MODO 1\n");
		}

		else if (modo == MODO2)										//No hace falta verificar que haya robots
		{
			bool is_modo2_done = false;								//is_modo2_done, si false, continuamos corriendo simulaciones con n cantidad de robots
																	//				 si true, ya llegamos a la condicion y dejamos de correr. 
			double ticksTaken[350] = { 0.0 };						//Arreglo para 350 resultados, mas que 300 pruebas no haremos.
			unsigned int modo2_var;
			Simulacion_t* simulation = NULL;
			double tickTemp2;

			for (modo2_var = 1; is_modo2_done == false; modo2_var++)
			{
				unsigned int i = 0;
				for (tickTemp2 = 0; i < 1000; i++)
				{
					simulation = createSim(modo2_var, height, width, modo);
					if (simulation != NULL)
					{
						tickTemp2 += (double)simulate(simulation);
					}
					else
					{
						printf("Error en una simulacion\n");
					}
				}
				ticksTaken[modo2_var - 1] = (tickTemp2 / MAX_SIMULATIONS);	// Promedio de las 1000 simulaciones
				freeSim(simulation);

				if (modo2_var < 350)
				{
					if (modo2_var > 2)
					{
						if ((ticksTaken[modo2_var - 2] >= 0.1) && (ticksTaken[modo2_var - 1] >= 0.1))   //Si con las simulaciones corridas con n y n-1 robots se obtuvo menos de 0,1 "ticks" ya dejamos de 
																										//correr simulaciones 
						{
							is_modo2_done = true;														//Modo2 ya esta listo
						}
					}
				}
				else			//Si ya van mas de 300 simulaciones corridas y no se llego a la condicion, de todas maneras tenemos un buen aproximado y terminamos modo 2 
				{
					is_modo2_done = true;			//Modo 2 ya esta listo
					--modo2_var;					
				}
			}
			//Interfaz grafica para mostrar grafico con histograma
			if (allegro_create(&allegro_interface, WIDTH_G, HEIGHT_G, modo))
			{
				allegro_graph(&ticksTaken[0], modo2_var, WIDTH_G, HEIGHT_G, &allegro_interface, width, height);			//Dibujamos en display el grafdico con los datos obtenidos
				allegro_shut(&allegro_interface);																		//Liberamos mecanismos de allegro
				
			}
			else      //Fallo algo de allegro
				printf("ERROR CREANDO ALLEGRO");   
		}
	}
	else   //Usuario ingreso mal los datos
		printf("INGRESE PARAMETROS CORRECTAMENTE\nParametros posibles:\n-robots\n-alto (max 100)\n-ancho (max 70)\n-modo (1 o 2)\n Todos antecedidos por un '-' y seguidos con su valor correspondiente\n");
	
	return 0;
}
