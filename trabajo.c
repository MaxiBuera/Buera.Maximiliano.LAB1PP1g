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


/** \brief  Para indicar que todas las posiciones estan vacias,
 *          esta funcion coloca el flag (isEmpty) en True en
 *          todas las posiciones del array
 *
 * \param   array de Trabajos
 * \param   limite del array de Mascotas
 *
 * \return 0 si la entrada es correcta, sino -1
 *
 */
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

/** \brief  Busca un espacio libre en el array
 *
 * \param   array de Trabajo
 * \param   limite del array
 * \return  -1 o -2 si hay algun error, 0 si no
 *
 */
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

/** \brief  Alta de un trabajo, usando datos de los parametros
 *
 * \param   array de trabajos
 * \param   limite del array de trabajos
 * \param   idMascota
 * \param   idServicio
 * \return  -1 si hay algun error, 0 si no
 *
 */
int trabajo_altaForzada(eTrabajo* arrayTrabajos,int limite,int idMascota,int idServicio,int dia, int mes, int anio)
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
            arrayTrabajos[i].fecha.dia = dia;
            arrayTrabajos[i].fecha.mes  = mes;
            arrayTrabajos[i].fecha.anio  = anio;
            //------------------------------
            //------------------------------
            arrayTrabajos[i].id = nextId();
            arrayTrabajos[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief  Muestra la lista de Trabajos
 *
 * \param   array de Trabajos
 * \param   limite de Trabajos
 * \param   array de Mascotas
 * \param   limite del array de Mascotas
 * \param   array de Servicios
 * \param   limite del array de servicios
 * \return  -1 si hay un error, 0 si no
 *
 */
int trabajo_imprimirTrabajos(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas,int limiteMascotas,eServicio* arrayServicios,int limiteServicios){

    int retorno = -1;
    int i,j,k;
    char nombreMascota[20];
    char nombreServicio[25];
    if(limite > 0 && arrayTrabajos != NULL)
    {
        retorno = 0;
        printf("\n\t**** Trabajos ****\n");
        printf("\n\tID Trabajo\tMascota\t\tServicio\tFecha de Trabajo");
        printf("\n\t----------------------------------------------------------------");
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

           		printf("\n%12d%15s\t\t%s%12d-%d-%d",arrayTrabajos[i].id,nombreMascota,nombreServicio,arrayTrabajos[i].fecha.dia,arrayTrabajos[i].fecha.mes,arrayTrabajos[i].fecha.anio);
           	}
        }
        printf("\n");
    }
    return retorno;
}

/** \brief Verifica si el id pasado por parametro se encuentra en el array
 *
 * \param   array de mascotas
 * \param   limite del array de mascotas
 * \param   id a buscar
 * \return  -1 si hay algun error, 0 si no
 *
 */
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

/** \brief Verifica si el id pasado por parametro se encuentra en el array
 *
 * \param   array de Servicios
 * \param   limite del array de Servicios
 * \param   id a buscar
 * \return  -1 si hay algun error, 0 si no
 *
 */
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

/** \brief  agrega un trabajo  al array. Validando las mascotas y servicios
 *
 * \param   array de Mascotas
 * \param   limite del array de mascotas
 * \param   array de Tipos
 * \param   limite del array de tipos
 * \param   array de Colores
 * \param   limite del array de Colores
 * \param   indice de lugar libre en el array
 * \return  -1 si hay algun error, 0 si no
 *
 */
int trabajo_agregarTrabajo(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas ,int limiteMascotas,eServicio* arrayServicios,int limiteServicios, int indice){

    int retorno = -1;
    int idMascotaAux;
    int idServicioAux;
    int diaAux,mesAux,anioAux;
    int id;

    if(limite > 0 && arrayTrabajos != NULL){

        retorno = -2;
        id = nextId();

        mascota_mostrarMascotaID(arrayMascotas,limiteMascotas);
        if(!getValidInt("\nIngrese ID de Mascota: ","\nError\n",&idMascotaAux,0,MASCOTAS,1) && (!verificarMascota(arrayMascotas,limiteMascotas,idMascotaAux))){

            servicio_mostrarServicioID(arrayServicios,limiteServicios);
            if(!getValidInt("\nIngrese ID del Servicio: ","\nError\n",&idServicioAux,SERVICIOS,SERVICIOS+3,1) && (!verificarServicio(arrayServicios,limiteServicios,idServicioAux))){

                printf("\nIngrese Fecha de Trabajo: ");
                if(!getValidInt("\nIngrese anio: ","\nMes No Valido\n",&anioAux,2000,2099,1)){

                    if(!getValidInt("\nIngrese mes: ","\nMes No Valido\n",&mesAux,1,12,1)){

                        if(mesAux == 1 || mesAux == 3 || mesAux == 5 || mesAux == 7 || mesAux == 8 || mesAux == 10 || mesAux == 12){

                            if(!getValidInt("\nIngrese dia: ","\nDia No Valido\n",&diaAux,1,31,1)){

                                arrayTrabajos[indice].idMascota = idMascotaAux;
                                arrayTrabajos[indice].idServicio = idServicioAux;
                                arrayTrabajos[indice].fecha.dia= diaAux;
                                arrayTrabajos[indice].fecha.mes= mesAux;
                                arrayTrabajos[indice].fecha.anio= anioAux;
                                arrayTrabajos[indice].isEmpty = OCUPADO;
                                arrayTrabajos[indice].id = id;
                                printf("\n\tTrabajo Agregado...");
                                retorno = 0;
                            }
                        }
                        else if(mesAux == 4 || mesAux == 6 || mesAux == 9 || mesAux == 11){

                            if(!getValidInt("\nIngrese dia: ","\nDia No Valido\n",&diaAux,1,30,1)){

                                arrayTrabajos[indice].idMascota = idMascotaAux;
                                arrayTrabajos[indice].idServicio = idServicioAux;
                                arrayTrabajos[indice].fecha.dia= diaAux;
                                arrayTrabajos[indice].fecha.mes= mesAux;
                                arrayTrabajos[indice].fecha.anio= anioAux;
                                arrayTrabajos[indice].isEmpty = OCUPADO;
                                arrayTrabajos[indice].id = id;
                                printf("\n\tTrabajo Agregado...");
                                retorno = 0;
                            }
                        }
                        else{
                            if(!getValidInt("\nIngrese dia: ","\nDia No Valido\n",&diaAux,1,28,1)){

                                arrayTrabajos[indice].idMascota = idMascotaAux;
                                arrayTrabajos[indice].idServicio = idServicioAux;
                                arrayTrabajos[indice].fecha.dia= diaAux;
                                arrayTrabajos[indice].fecha.mes= mesAux;
                                arrayTrabajos[indice].fecha.anio= anioAux;
                                arrayTrabajos[indice].isEmpty = OCUPADO;
                                arrayTrabajos[indice].id = id;
                                printf("\n\tTrabajo Agregado...");
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if(retorno != 0){

        printf("\nID no valido\n");
    }

    return retorno;
}

/** \brief  Baja logica de un trabajo al eliminar una mascota
 *
 * \param   array de trabajos
 * \param   limite del array de trabajos
 * \param   array de Mascotas
 * \param   limite del array de mascotas
 * \return  -1 si hay algun error, 0 si no
 *
 */
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

