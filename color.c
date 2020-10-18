#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#define TIPO_ID_MIN 1000
#define TIPO_ID_MAX 2000
#define COLOR_ID_MIN 5000
#define COLOR_ID_MAX 6000
#define OCUPADO 0
#define LIBRE 1

static int nextId();

int color_inicializarArrayColores(eColor* arrayColores, int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayColores != NULL)
    {
        returnValue = 0;
        for(i=0;i<limite;i++)
        {
            arrayColores[i].id = -1;
            strcpy(arrayColores[i].nombreColor,"");
            arrayColores[i].isEmpty = LIBRE;
        }
    }
    return returnValue;
}

int color_buscarLugarLibre(eColor* arrayColores,int limite)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayColores != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayColores[i].isEmpty == LIBRE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int color_altaForzada(eColor* arrayColores,int limite,char* nombreColor)
{
    int returnValue = -1;
    int i;

    if(limite > 0 && arrayColores != NULL)
    {
        i = color_buscarLugarLibre(arrayColores,limite);
        if(i >= 0)
        {
            returnValue = 0;
            strcpy(arrayColores[i].nombreColor,nombreColor);
            //------------------------------
            //------------------------------
            arrayColores[i].id = nextId();
            arrayColores[i].isEmpty = OCUPADO;
        }
        returnValue = 0;
    }
    return returnValue;
}

int color_imprimirColores(eColor* arrayColores,int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayColores != NULL)
    {
        returnValue = 0;
        printf("\n\tID Color\t\tColor");
        printf("\n\t--------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayColores[i].isEmpty)
            {

           		printf("\n%12d %24s",arrayColores[i].id,arrayColores[i].nombreColor);
           	}
        }
    }
    return returnValue;
}

static int nextId()
{
    static int lastId = COLOR_ID_MIN-1;
    lastId++;
    return lastId;
}

