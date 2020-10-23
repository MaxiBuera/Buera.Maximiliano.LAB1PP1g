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
#define SERVICIOS 20000
#define OCUPADO 0
#define LIBRE 1

static int nextId();

int trabajo_inicializarArrayTrabajos(eTrabajo* arrayTrabajos, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayTrabajos != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayTrabajos[i].id = -1;
            arrayTrabajos[i].idMascota = -1;
            arrayTrabajos[i].idServicio = -1;
            arrayTrabajos[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int trabajo_buscarLugarLibre(eTrabajo* arrayTrabajos,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayTrabajos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayTrabajos[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int trabajo_altaForzada(eTrabajo* arrayTrabajos,int limite,int idMascota,int idServicio)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayTrabajos != NULL)
    {
        i = trabajo_buscarLugarLibre(arrayTrabajos,limite);
        if(i >= 0)
        {
            retorno = 0;
            arrayTrabajos[i].idMascota = idMascota;
            arrayTrabajos[i].idServicio = idServicio;
            //------------------------------
            //------------------------------
            arrayTrabajos[i].id = nextId();
            arrayTrabajos[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int trabajo_imprimirTrabajos(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas,int limiteMascotas,eServicio* arrayServicios,int limiteServicios){

    int retorno = -1;
    int i,j,k;
    char nombreMascota[20];
    char nombreServicio[25];
    if(limite > 0 && arrayTrabajos != NULL)
    {
        retorno = 0;
        printf("\n\t**** Trabajos ****\n");
        printf("\n\tID Trabajo\tID Mascota\tID Servicio");
        printf("\n\t-----------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayTrabajos[i].isEmpty)
            {
                for(j=0;j<limiteMascotas;j++){

                    if(arrayTrabajos[i].idMascota == arrayMascotas[j].id){
                        strcpy(nombreMascota,arrayMascotas[j].nombre);
                        continue;
                    }
                }
                for(k=0;k<limiteServicios;k++){

                    if(arrayTrabajos[i].idServicio == arrayServicios[k].id){
                        strcpy(nombreServicio,arrayServicios[k].descripcion);
                        continue;
                    }
                }

           		printf("\n%12d%15d\t\t%d - %s - %s",arrayTrabajos[i].id,arrayTrabajos[i].idMascota,arrayTrabajos[i].idServicio,nombreMascota,nombreServicio);
           	}
        }
        printf("\n");
    }
    return retorno;
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

    int retorno = -1;
    int idMascotaAux;
    int idServicioAux;
    int id;

    if(limite > 0 && arrayTrabajos != NULL){

        retorno = -2;
        id = nextId();

        mascota_mostrarMascotaID(arrayMascotas,limiteMascotas);
        if(!getValidInt("\nIngrese ID de Mascota: ","\nError\n",&idMascotaAux,0,MASCOTAS,1) && (!verificarMascota(arrayMascotas,limiteMascotas,idMascotaAux))){

            servicio_mostrarServicioID(arrayServicios,limiteServicios);
            if(!getValidInt("\nIngrese ID del Servicio: ","\nError\n",&idServicioAux,SERVICIOS,SERVICIOS+3,1) && (!verificarServicio(arrayServicios,limiteServicios,idServicioAux))){

                arrayTrabajos[indice].idMascota = idMascotaAux;
                arrayTrabajos[indice].idServicio = idServicioAux;
                arrayTrabajos[indice].isEmpty = OCUPADO;
                arrayTrabajos[indice].id = id;
                printf("\n\tTrabajo Agregado...");
                retorno = 0;
            }
        }
    }

    if(retorno != 0){

        printf("\nID no valido\n");
    }

    return retorno;
}

int trabajo_mascotaEliminada(eTrabajo* arrayTrabajos, int limite, eMascota* arrayMascotas, int limiteMascotas){

    int retorno = -1;
    int i,j;

    if(arrayMascotas != NULL && limiteMascotas < 0){

        for(i=0;i<limite;i++){

            for(j=0;j<limiteMascotas;j++){

                if(arrayTrabajos[i].idMascota == arrayMascotas[j].id && arrayMascotas[j].isEmpty == 0){

                    arrayTrabajos[i].isEmpty = LIBRE;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

static int nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}

