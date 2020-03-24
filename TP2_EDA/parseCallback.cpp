#include "parseCallback.h"

char validKeys[][MAXKEYLENGTH] = { "robots","modo","ancho","alto" };
int parseCallback(char* key, char* value, user_t* userData)
{
    int keyid;                  //keyid identifica al tipo de key
    int i, res = ERROR;               // res=resultado i=�ndice

    lowerstring(value);
    if (key != NULL)        //si key=NULL, error
    {                                          
        lowerstring(key);                                    //en este caso se recibe un key + un value
            for (i = 0; i < MAXKEYNUMBER; i++)
            {                                           //se verifica que el key recibido sea v�lido (apellido, legajo, o dni)
                if (!(strcmp(key, validKeys[i])))
                {
                    res = OK;
                    keyid = i;
                    break;
                }
            }

        if (res)
        {
            res = checkvalue(value, keyid);                                              //si key es v�lido se prosigue a verificar que value lo sea
            switch (keyid)
            {
            case (ROBOTS):
                if (res)
                    userData->cant_robots = atoi(value);
                break;

            case (MODO):
                if (res)
                    userData->modo = atoi(value);
                break;

            case (ANCHO):
                if (res)
                    userData->alto = atoi(value);
                break;
            case(ALTO):
                if (res)
                    userData->ancho = atoi(value);
                break;
            }
        }
    }

    return res;
}

int checkvalue(char* val, int keyid)                    //verifica que los valores recibidos sea adecuados seg�n el key al que se encuentran asociados
{                                                       //la verificaci�n depende de keyid
    int i = 0;
    int let = OK;

    switch (keyid)
    {
    case (MODO):
        if (((atoi(val)) <= 0) && ((atoi(val)) > 2))
            let = ERROR;
        break;

    case (ALTO):
        while (val[i])
        {
            if (!(isdigit(val[i])))
            {
                let = ERROR;
                break;
            }
            i++;
        }
        if ((atoi(val))> MAXALTO) 
        {
            let = ERROR;
            break;
        }
        break;

    case (ANCHO):
        while (val[i])
        {
            if (!(isdigit(val[i])))
            {
                let = ERROR;
                break;
            }
            i++;
        }
        if ((atoi(val)) > MAXANCHO)
        {
            let = ERROR;
            break;
        }

        if (i > MAXANCHO)
        {
            let = ERROR;
            break;
        }
        break;

    case(ROBOTS):
        while (val[i])
        {
            if (!(isdigit(val[i])))
            {
                let = ERROR;
                break;
            }
            i++;
        }

        if (i > MAXROBOTS)
        {
            let = ERROR;
            break;
        }
        break;

    default:
        break;
    }

    return let;
}

void lowerstring(char* s)
{                            //convierte strings a min�scula para poder comparar con la lista de keys o par�metros v�lidos...
    int i;
    for (i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}
