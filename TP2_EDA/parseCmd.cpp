/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "parseCmd.h"


 /*******************************************************************************
  *******************************************************************************
                         GLOBAL FUNCTION DEFINITIONS
  *******************************************************************************
  ******************************************************************************/

int parseCmdLine(int argC, char* argV[], pCallback parseCallback, user_t* userData)
{
    int i, res = OK, j;
    for (i = 1; i < argC; i++)  //Desde i=1 (salteando nombre del ejecutable) chequea los valores recibidos.
    {
        if (*argV[i] == '-')    // Si comienza con '-', se encontró una opción.
        {
            for (j = 0; argV[i][j]; j++)
                argV[i][j] = argV[i][j + 1];

            if (!*(argV[i] + 1) || ((i + 1) == argC) || ((argV[i+1][0])=='-')) // Detecta errores de forma
            {
                res = ERROR;   // El resultado pasa a ser -1, porque hubo un error.
                break;
            }
            else if (parseCallback(argV[i], argV[i + 1], userData))              
               i++;                                                    //salteo el valor y leo siguiente key
        }
        else
        {
            res = ERROR;
            break;
        }
    }
    if (i > MAXUSERDATA || i<=1)
        res = ERROR;

    return res;         // Devuelve el resultado de la suma.
}
