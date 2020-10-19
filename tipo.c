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

int tipo_inicializarArrayTipos(eTipo* arrayTipos, int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayTipos != NULL)
    {
        returnValue = 0;
        for(i=0;i<limite;i++)
        {
            arrayTipos[i].id = -1;
            strcpy(arrayTipos[i].descripcion,"");
            arrayTipos[i].isEmpty = LIBRE;
        }
    }
    return returnValue;
}

int tipo_buscarLugarLibre(eTipo* arrayTipos,int limite)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayTipos != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayTipos[i].isEmpty == LIBRE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int tipo_altaForzada(eTipo* arrayTipos,int limite,char* descripcion)
{
    int returnValue = -1;
    int i;

    if(limite > 0 && arrayTipos != NULL)
    {
        i = tipo_buscarLugarLibre(arrayTipos,limite);
        if(i >= 0)
        {
            returnValue = 0;
            strcpy(arrayTipos[i].descripcion,descripcion);
            //------------------------------
            //------------------------------
            arrayTipos[i].id = nextId();
            arrayTipos[i].isEmpty = OCUPADO;
        }
        returnValue = 0;
    }
    return returnValue;
}

int tipo_imprimirTipos(eTipo* arrayTipos,int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayTipos != NULL)
    {
        returnValue = 0;
        printf("\n\t***Tipos de Mascotas***\n");
        printf("\n\tID\t\tTipo");
        printf("\n\t-----------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayTipos[i].isEmpty)
            {

           		printf("\n%12d %15s",arrayTipos[i].id,arrayTipos[i].descripcion);
           	}
        }
        printf("\n");
    }
    return returnValue;
}

static int nextId()
{
    static int lastId = TIPO_ID_MIN-1;
    lastId++;
    return lastId;
}

