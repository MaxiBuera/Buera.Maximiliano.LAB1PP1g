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

int color_inicializarColor(eColor* arrayColor, int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayColor != NULL)
    {
        returnValue = 0;
        for(i=0;i<limite;i++)
        {
            arrayColor[i].id = -1;
            strcpy(arrayColor[i].nombreColor,"");
            arrayColor[i].isEmpty = LIBRE;
        }
    }
    return returnValue;
}

int color_buscarLugarLibre(eColor* arrayColor,int limite)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayColor != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayColor[i].isEmpty == LIBRE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int color_altaForzada(eColor* arrayColor,int limite,char* nombreColor)
{
    int returnValue = -1;
    int i;

    if(limite > 0 && arrayColor != NULL)
    {
        i = color_buscarLugarLibre(arrayColor,limite);
        if(i >= 0)
        {
            returnValue = 0;
            strcpy(arrayColor[i].nombreColor,nombreColor);
            //------------------------------
            //------------------------------
            arrayColor[i].id = nextId();
            arrayColor[i].isEmpty = OCUPADO;
        }
        returnValue = 0;
    }
    return returnValue;
}

int color_imprimirColores(eColor* arrayColor,int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayColor != NULL)
    {
        returnValue = 0;
        printf("\n\tID Color\t\tColor");
        printf("\n\t--------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayColor[i].isEmpty)
            {

           		printf("\n%12d %24s",arrayColor[i].id,arrayColor[i].nombreColor);
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

