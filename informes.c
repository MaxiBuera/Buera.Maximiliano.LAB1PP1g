#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "mascota.h"
#define TIPO_MIN_ID 1000
#define MAX 10000
#define COLOR_MIN_ID 5000
#define OCUPADO 0
#define LIBRE 1


//1- Mostrar las mascotas del color seleccionado por el usuario.

int informes_mostrarMascotasPorColorSeleccionado(eMascota* arrayMascotas, int limiteMascotas, eColor* arrayColores, int limiteColores){

    int retorno = -1;
    int i;
    int idColorAux;

    if(arrayMascotas != NULL && limiteMascotas > 0){

        color_imprimirColores(arrayColores,limiteColores);
        if(!getValidInt("\nIngrese ID del color: ","\nError\n",&idColorAux,COLOR_MIN_ID,MAX,1) && (!verificarColor(arrayColores,limiteColores,idColorAux))){

            printf("\n\t*** Mascotas del color seleccionado***");
            printf("\n\t--------------------------------");
            retorno=0;
            for(i=0;i<limiteMascotas;i++){

                if(idColorAux == arrayMascotas[i].idColor){

                   printf("\n\t%s",arrayMascotas[i].nombre);
                }
            }
        }
    }

    return retorno;
}



//2- Mostrar mascotas de un tipo seleccionado.

int informes_mostrarMascotasPorTipoSeleccionado(eMascota* arrayMascotas, int limiteMascotas, eTipo* arrayTipos, int limiteTipos){

    int retorno = -1;
    int i;
    int idTipoAux;

    if(arrayMascotas != NULL && limiteMascotas > 0){

        tipo_imprimirTipos(arrayTipos,limiteTipos);
        if(!getValidInt("\nIngrese ID del tipo: ","\nError\n",&idTipoAux,TIPO_MIN_ID,MAX,1) && (!verificarTipo(arrayTipos,limiteTipos,idTipoAux))){

            printf("\n\t*** Mascotas del tipo seleccionado***");
            printf("\n\t--------------------------------");
            retorno=0;
            for(i=0;i<limiteMascotas;i++){

                if(idTipoAux == arrayMascotas[i].idTipo){

                   printf("\n\t%s",arrayMascotas[i].nombre);
                }
            }
        }
    }

    return retorno;
}
