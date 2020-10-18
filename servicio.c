#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#define TIPO_ID_MIN 1000
#define TIPO_ID_MAX 2000
#define COLOR_ID_MIN 5000
#define COLOR_ID_MAX 6000
#define SERVICIO_ID_MIN 2000
#define SERVICIO_ID_MAX 3000
#define OCUPADO 0
#define LIBRE 1

static int nextId();

int servicio_inicializarArrayServicios(eServicio* arrayServicios, int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        returnValue = 0;
        for(i=0;i<limite;i++)
        {
            arrayServicios[i].id = -1;
            strcpy(arrayServicios[i].descripcion,"");
            arrayServicios[i].precio = -1;
            arrayServicios[i].isEmpty = LIBRE;
        }
    }
    return returnValue;
}

int servicio_buscarLugarLibre(eServicio* arrayServicios,int limite)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayServicios[i].isEmpty == LIBRE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int servicio_altaForzada(eServicio* arrayServicios,int limite,char* descripcion,float precio)
{
    int returnValue = -1;
    int i;

    if(limite > 0 && arrayServicios != NULL)
    {
        i = servicio_buscarLugarLibre(arrayServicios,limite);
        if(i >= 0)
        {
            returnValue = 0;
            strcpy(arrayServicios[i].descripcion,descripcion);
            arrayServicios[i].precio = precio;
            //------------------------------
            //------------------------------
            arrayServicios[i].id = nextId();
            arrayServicios[i].isEmpty = OCUPADO;
        }
        returnValue = 0;
    }
    return returnValue;
}

int servicio_imprimirServicios(eServicio* arrayServicios,int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        returnValue = 0;
        printf("\n\tID Color\tServicio\t\tPrecio");
        printf("\n\t-----------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayServicios[i].isEmpty)
            {

           		printf("\n%12d %24s \t\t$%.2f",arrayServicios[i].id,arrayServicios[i].descripcion,arrayServicios[i].precio);
           	}
        }
    }
    return returnValue;
}

static int nextId()
{
    static int lastId = SERVICIO_ID_MIN-1;
    lastId++;
    return lastId;
}

