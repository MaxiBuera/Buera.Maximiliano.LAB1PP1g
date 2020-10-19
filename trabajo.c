#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "trabajo.h"
#define MASCOTAS 20
#define SERVICIOS 2000
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
        printf("\n\t**** Trabajos ****\n");
        printf("\n\tID Trabajo\tID Mascota\tID Servicio");
        printf("\n\t-----------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayTrabajos[i].isEmpty)
            {

           		printf("\n%12d%15d\t\t%d",arrayTrabajos[i].id,arrayTrabajos[i].idMascota,arrayTrabajos[i].idServicio);
           	}
        }
        printf("\n");
    }
    return returnValue;
}

int verificarMascota(eMascota* arrayMascotas, int limiteMascotas, int idMascotas){

    int i;
    int retorno = -1;

    for(i=0;i<limiteMascotas;i++){

        if(idMascotas == arrayMascotas[i].id){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}

int verificarServicio(eServicio* arrayServicios, int limiteServicios, int idServicios){

    int i;
    int retorno = -1;

    for(i=0;i<limiteServicios;i++){

        if(idServicios == arrayServicios[i].id){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}

//Se dará de alta cada ocurrencia de trabajo pidiéndole al usuario que elija una mascota y un Servicio
int trabajo_agregarTrabajo(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas ,int limiteMascotas,eServicio* arrayServicios,int limiteServicios, int indice){

    int returnValue = -1;
    int idMascotaAux;
    int idServicioAux;
    int id;

    if(limite > 0 && arrayTrabajos != NULL){

        returnValue = -2;
        id = nextId();

        mascota_mostrarMascotaID(arrayMascotas,limiteMascotas);
        if(!getValidInt("\nIngrese ID de Mascota: ","\nError\n",&idMascotaAux,0,MASCOTAS,2) && (!verificarMascota(arrayMascotas,limiteMascotas,idMascotaAux))){

            servicio_mostrarServicioID(arrayServicios,limiteServicios);
            if(!getValidInt("\nIngrese ID del Servicio: ","\nError\n",&idServicioAux,SERVICIOS,SERVICIOS+3,2) && (!verificarServicio(arrayServicios,limiteServicios,idServicioAux))){

                arrayTrabajos[indice].idMascota = idMascotaAux;
                arrayTrabajos[indice].idServicio = idServicioAux;
                arrayTrabajos[indice].isEmpty = OCUPADO;
                arrayTrabajos[indice].id = id;
                printf("\n\tTrabajo Agregado...");
                returnValue = 0;
            }
        }
    }

    if(returnValue != 0){

        printf("\nID no valido\n");
    }

    return returnValue;
}

static int nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}

