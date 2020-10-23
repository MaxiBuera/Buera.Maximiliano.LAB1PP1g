#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#define TIPO_MIN 1000
#define MAX 10000
#define COLOR_ID_MIN 5000
#define SERVICIO_ID_MIN 20000
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
int servicio_inicializarArrayServicios(eServicio* arrayServicios, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayServicios[i].id = -1;
            strcpy(arrayServicios[i].descripcion,"");
            arrayServicios[i].precio = -1;
            arrayServicios[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

/** \brief  Busca un espacio libre en el array
 *
 * \param   array de Servicios
 * \param   limite del array
 * \return  -1 o -2 si hay algun error, 0 si no
 *
 */
int servicio_buscarLugarLibre(eServicio* arrayServicios,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayServicios[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief  Alta de un servicio, usando datos de los parametros
 *
 * \param   array de servicios
 * \param   limite del array de servicios
 * \param   descripcion
 * \param   precio
 * \return  -1 si hay algun error, 0 si no
 *
 */
int servicio_altaForzada(eServicio* arrayServicios,int limite,char* descripcion,float precio)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayServicios != NULL)
    {
        i = servicio_buscarLugarLibre(arrayServicios,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayServicios[i].descripcion,descripcion);
            arrayServicios[i].precio = precio;
            //------------------------------
            //------------------------------
            arrayServicios[i].id = nextId();
            arrayServicios[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief  Muestra la lista de servicios
 *
 * \param   array de servicios
 * \param   limite de servicios
 * \return  -1 si hay un error, 0 si no
 *
 */
int servicio_imprimirServicios(eServicio* arrayServicios,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        retorno = 0;
        printf("\n\t***Servicios***\n");
        printf("\n\tID Color\tServicio\t\tPrecio");
        printf("\n\t-----------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayServicios[i].isEmpty)
            {

           		printf("\n%12d %24s\t\t$%.2f",arrayServicios[i].id,arrayServicios[i].descripcion,arrayServicios[i].precio);
           	}
        }
        printf("\n");
    }
    return retorno;
}

/** \brief  Muestra la lista de las Servicios ( Nombre y id)
 *
 * \param   array de Servicios
 * \param   limite del array de Servicios
 * \return  -1 si hay un error, 0 si no
 *
 */
int servicio_mostrarServicioID(eServicio* arrayServicios,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayServicios != NULL)
    {
        retorno = 0;
        printf("\n\t**** Lista de Servicios ****\n");
        printf("\n\tID\t\tServicio");
        printf("\n\t-------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayServicios[i].isEmpty)
            {

           		printf("\n%12d %24s",arrayServicios[i].id,arrayServicios[i].descripcion);
           	}
        }
        printf("\n");
    }
    return retorno;
}

static int nextId()
{
    static int lastId = SERVICIO_ID_MIN-1;
    lastId++;
    return lastId;
}

