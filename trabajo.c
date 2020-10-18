#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "trabajo.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#define MASCOTAS
#define OCUPADO 0
#define LIBRE 1

static int nextId();

int trabajo_inicializarArrayTrabajos(eTrabajo* arrayTrabajos, int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayTrabajos != NULL)
    {
        returnValue = 0;
        for(i=0;i<limite;i++)
        {
            arrayTrabajos[i].id = -1;
            arrayTrabajos[i].idMascota = -1;
            arrayTrabajos[i].idServicio = -1;
            arrayTrabajos[i].isEmpty = LIBRE;
        }
    }
    return returnValue;
}

int trabajo_buscarLugarLibre(eTrabajo* arrayTrabajos,int limite)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayTrabajos != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayTrabajos[i].isEmpty == LIBRE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int trabajo_altaForzada(eTrabajo* arrayTrabajos,int limite,int idMascota,int idServicio)
{
    int returnValue = -1;
    int i;

    if(limite > 0 && arrayTrabajos != NULL)
    {
        i = trabajo_buscarLugarLibre(arrayTrabajos,limite);
        if(i >= 0)
        {
            returnValue = 0;
            arrayTrabajos[i].idMascota = idMascota;
            arrayTrabajos[i].idServicio = idServicio;
            //------------------------------
            //------------------------------
            arrayTrabajos[i].id = nextId();
            arrayTrabajos[i].isEmpty = OCUPADO;
        }
        returnValue = 0;
    }
    return returnValue;
}

int trabajo_imprimirTrabajos(eTrabajo* arrayTrabajos,int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayTrabajos != NULL)
    {
        returnValue = 0;
        printf("\n\t***Trabajos***\n");
        printf("\n\tID Trabajo\tID Mascota\t\tID Servicio");
        printf("\n\t-----------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayTrabajos[i].isEmpty)
            {

           		printf("\n%12d%24d\t\t%d",arrayTrabajos[i].id,arrayTrabajos[i].idMascota,arrayTrabajos[i].idServicio);
           	}
        }
    }
    return returnValue;
}

static int nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}

