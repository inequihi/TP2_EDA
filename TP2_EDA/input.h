#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
/*****************************************
DEFINE
*****************************************/

#define MAXKEYLENGTH 15
#define MAXLENGTH 20

#define MAXUSERDATA 9
#define OK 1
#define ERROR 0
#define ROBOTS 0
#define MODO 1
#define ANCHO 2
#define ALTO 3
#define MAXKEYNUMBER 4

#define MAXALTO 100
#define MAXANCHO 70
#define MAXROBOTS 150

/*****************************************
TYPEDEF
*****************************************/
typedef struct {
    unsigned int cant_robots;
    unsigned int alto;
    unsigned int ancho;
    unsigned int modo;
} user_t;


#endif // INPUT_H_
