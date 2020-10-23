#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#define TIPO_ID_MIN 1000
#define MAX  10000
#define COLOR_ID_MIN 5000
#define OCUPADO 0
#define LIBRE 1

static int nextId();

/** \brief  Para indicar que todas las posiciones estan vacias,
 *          esta funcion coloca el flag (isEmpty) en True en
 *          todas las posiciones del array
 *
 * \param   array de Tipos
 * \param   limite del array de Tipos
 *
 * \return 0 si la entrada es correcta, sino -1
 *
 */
int tipo_inicializarArrayTipos(eTipo* arrayTipos, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayTipos != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayTipos[i].id = -1;
            strcpy(arrayTipos[i].descripcion,"");
            arrayTipos[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

/** \brief  Busca un espacio libre en el array
 *
 * \param   array de Tipos
 * \param   limite del array de Tipos
 * \return  -1 o -2 si hay algun error, 0 si no
 *
 */
int tipo_buscarLugarLibre(eTipo* arrayTipos,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayTipos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayTipos[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief  Alta de un tipo, usando datos de los parametros
 *
 * \param   array de Tipos
 * \param   limite del array de Tipos
 * \param   descripcion
 * \return  -1 si hay algun error, 0 si no
 *
 */
int tipo_altaForzada(eTipo* arrayTipos,int limite,char* descripcion)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayTipos != NULL)
    {
        i = tipo_buscarLugarLibre(arrayTipos,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayTipos[i].descripcion,descripcion);
            //------------------------------
            //------------------------------
            arrayTipos[i].id = nextId();
            arrayTipos[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief  Muestra la lista de Tipos
 *
 * \param   array de Tipos
 * \param   limite de Tipos
 * \return  -1 si hay un error, 0 si no
 *
 */
int tipo_imprimirTipos(eTipo* arrayTipos,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayTipos != NULL)
    {
        retorno = 0;
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
    return retorno;
}

static int nextId()
{
    static int lastId = TIPO_ID_MIN-1;
    lastId++;
    return lastId;
}

