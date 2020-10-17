#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#define TIPO_ID_MIN 1000
#define TIPO_ID_MAX 2000
#define COLOR_ID_MIN 5000
#define COLOR_ID_MAX 6000
#define OCUPADO 0
#define LIBRE 1

static int nextId();

void mascota_normalizarCadena(char cadena[]){

    int j,i;
    i = strlen(cadena);

    for(j=0;j<i;j++){

        if(j==0){

            cadena[j] = toupper(cadena[j]);
        }
        else{

            cadena[j] = tolower(cadena[j]);
        }
    }
}

int mascota_inicializarArrayMascotas(eMascota* arrayMascotas, int limite){

    int returnValue = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        returnValue = 0;
        for(i=0;i<limite;i++)
        {
            arrayMascotas[i].id = -1;
            strcpy(arrayMascotas[i].nombre,"");
            arrayMascotas[i].idTipo = -1;
            arrayMascotas[i].idColor = -1;
            arrayMascotas[i].edad = -1;
            arrayMascotas[i].isEmpty = LIBRE;
        }
    }
    return returnValue;
}

int verificarTipo(eTipo* arrayTipos, int limiteTipos, int idTipo){

    int i;
    int retorno = -1;

    for(i=0;i<limiteTipos;i++){

        if(idTipo == arrayTipos[i].id){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}

int verificarColor(eColor* arrayColores, int limiteColores, int idColor){

    int i;
    int retorno = -1;

    for(i=0;i<limiteColores;i++){

        if(idColor == arrayColores[i].id){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}

int mascota_agregarMascota(eMascota* arrayMascotas,int limite,eTipo* arrayTipos ,int limiteTipos,eColor* arrayColores,int limiteColores, int indice){

    int returnValue = -1;
    char nombreAux[20];
    int idTipoAux;
    int idColorAux;
    int edadAux;
    int id;

    if(limite > 0 && arrayMascotas != NULL){

        returnValue = -2;
        id = nextId();

        if(getStringLetras("\nIngrese nombre: ",nombreAux)){

            if(!getValidInt("Ingrese ID del tipo: ","\nError\n",&idTipoAux,TIPO_ID_MIN,TIPO_ID_MAX,2) && (!verificarTipo(arrayTipos,limiteTipos,idTipoAux))){

                if(!getValidInt("Ingrese ID del color: ","\nError\n",&idColorAux,COLOR_ID_MIN,COLOR_ID_MAX,2) && (!verificarColor(arrayColores,limiteColores,idColorAux))){

                    if(!getValidInt("Ingrese edad: ","\nError\n",&edadAux,0,35,2)){

                        mascota_normalizarCadena(nombreAux);
                        strcpy(arrayMascotas[indice].nombre,nombreAux);

                        arrayMascotas[indice].idTipo = idTipoAux;
                        arrayMascotas[indice].idColor = idColorAux;
                        arrayMascotas[indice].isEmpty = OCUPADO;
                        arrayMascotas[indice].id = id;
                        printf("\n\tMascota Agregada...");
                        returnValue = 0;
                    }
                }
            }
        }
    }

    if(returnValue != 0){

        printf("\nError\n");
    }

    return returnValue;
}

int mascota_buscarLugarLibre(eMascota* arrayMascotas,int limite)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayMascotas[i].isEmpty == LIBRE)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int mascota_altaForzada(eMascota* arrayMascotas,int limite,char* nombre,int idColor, int idTipo,int edad)
{
    int returnValue = -1;
    int i;

    if(limite > 0 && arrayMascotas != NULL)
    {
        i = mascota_buscarLugarLibre(arrayMascotas,limite);
        if(i >= 0)
        {
            returnValue = 0;
            strcpy(arrayMascotas[i].nombre,nombre);
            arrayMascotas[i].idColor = idColor;
            arrayMascotas[i].idTipo = idTipo;
            arrayMascotas[i].edad = edad;
            //------------------------------
            //------------------------------
            arrayMascotas[i].id = nextId();
            arrayMascotas[i].isEmpty = OCUPADO;
        }
        returnValue = 0;
    }
    return returnValue;
}

int mascota_buscarMascotaPorId(eMascota* arrayMascotas,int limite, int id)
{
    int returnValue = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        returnValue = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayMascotas[i].isEmpty == OCUPADO && arrayMascotas[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

void mascota_menuModificacion(eMascota* arrayMascotas, int indice, eTipo* arrayTipos ,int limiteTipos,eColor* arrayColor,int limiteColores){

    int opc;
    int idTipoAux;
    int edadAux;


    printf("\nMascota a Modificar: %s ",arrayMascotas[indice].nombre);

    do{

        getValidInt("\n\n\t1.Modificar Tipo\n\t2.Modificar Edad\n\t3.Listo\n","\nNo valida\n",&opc,1,3,1);
        switch(opc)
        {
            case 1:
                if(!getValidInt("Ingrese ID del tipo: ","\nError\n",&idTipoAux,TIPO_ID_MIN,TIPO_ID_MAX,2) && (!verificarTipo(arrayTipos,limiteTipos,idTipoAux))){

                    arrayMascotas[indice].idTipo = idTipoAux;
                    printf("\nTipo de Mascota Modificado...");
                }
                break;
            case 2:
                if(!getValidInt("Ingrese edad: ","\nError\n",&edadAux,0,35,2)){

                    arrayMascotas[indice].edad = edadAux;
                    printf("\nEdad de la Mascota Modificado...");
                }
                break;
        }
    }while(opc != 5);

}

int mascota_modificarMascota(eMascota* arrayMascotas, int indice, eTipo* arrayTipos ,int limiteTipos,eColor* arrayColor,int limiteColores){

    int i;
    int returnValue = -1;

    i = mascota_buscarMascotaPorId(arrayMascotas,limite,indice);
    if(i >= 0)
    {
        mascota_menuModificacion(arrayMascotas,i,arrayTipos,limiteTipos,arrayColor,limiteColores);
        arrayMascotas[i].isEmpty = OCUPADO;
        returnValue = 0;
    }
    else{

        printf("\nError");
    }
    return returnValue;
}

int mascota_eliminarMascota(eMascota* arrayMascotas, int limite,int indice){

    int returnValue = -1;
    int i;
    char confirmacion;
    i = mascota_buscarMascotaPorId(arrayMascotas,limite,indice);
    if(i >= 0)
    {
        printf("\nMascota a eliminar: %s",arrayMascotas[i].nombre);
        confirmacion = getChar("\n¿Desea eliminar la mascota? [s/n]: ");
        if(confirmacion == 's' || confirmacion == 'S'){
            arrayMascotas[i].isEmpty = LIBRE;
            printf("\n\n\tMascota Eliminada...");
            returnValue = 0;
        }
        else if(confirmacion == 'n' || confirmacion == 'N'){

            printf("\n\tMascota No Eliminada...");
            return returnValue;
        }
    }
    else{

        printf("\nID no encontrado");
    }
    return returnValue;
}

static int nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}
