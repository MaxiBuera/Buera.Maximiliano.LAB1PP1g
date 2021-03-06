#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#define TIPO_ID_MIN 1000
#define MAX 10000
#define COLOR_ID_MIN 5000
#define OCUPADO 0
#define LIBRE 1

static int nextId();


/** \brief  Para indicar que todas las posiciones estan vacias,
 *          esta funcion coloca el flag (isEmpty) en True en
 *          todas las posiciones del array
 *
 * \param   array de Colores
 * \param   limite del array de Colores
 *
 * \return 0 si la entrada es correcta, sino -1
 *
 */
int color_inicializarArrayColores(eColor* arrayColores, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayColores != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayColores[i].id = -1;
            strcpy(arrayColores[i].nombreColor,"");
            arrayColores[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

/** \brief  Busca un espacio libre en el array
 *
 * \param   array de Colores
 * \param   limite del array de Colores
 * \return  -1 o -2 si hay algun error, 0 si no
 *
 */
int color_buscarLugarLibre(eColor* arrayColores,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayColores != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayColores[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief  Alta de un color, usando datos de los parametros
 *
 * \param   array de Colores
 * \param   limite del array de Colores
 * \param   nombreColor
 * \return  -1 si hay algun error, 0 si no
 *
 */
int color_altaForzada(eColor* arrayColores,int limite,char* nombreColor)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayColores != NULL)
    {
        i = color_buscarLugarLibre(arrayColores,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayColores[i].nombreColor,nombreColor);
            //------------------------------
            //------------------------------
            arrayColores[i].id = nextId();
            arrayColores[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief  Muestra la lista de Colores
 *
 * \param   array de Colores
 * \param   limite de Colores
 * \return  -1 si hay un error, 0 si no
 *
 */
int color_imprimirColores(eColor* arrayColores,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayColores != NULL)
    {
        retorno = 0;
        printf("\n\t***Colores***\n");
        printf("\n\tID Color\t\tColor");
        printf("\n\t--------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayColores[i].isEmpty)
            {

           		printf("\n%12d %24s",arrayColores[i].id,arrayColores[i].nombreColor);
           	}
        }
        printf("\n");
    }
    return retorno;
}

static int nextId()
{
    static int lastId = COLOR_ID_MIN-1;
    lastId++;
    return lastId;
}

