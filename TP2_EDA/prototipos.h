#ifndef PROTO_H_
#define PROTO_H_

/*****************************************
INCLUDE
*****************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

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


#endif
