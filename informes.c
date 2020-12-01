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

//3.Informar la o las mascotas de menor edad.

int informes_mascotasDeMenorEdad(eMascota* arrayMascotas, int limiteMascotas){

    int retorno = -1;
    int i=0;
    int menorEdad;
    int flag=0;

    if(arrayMascotas != NULL && limiteMascotas > 0){

        retorno = 0;
        for(i=0;i<limiteMascotas;i++){

            if(arrayMascotas[i].isEmpty == OCUPADO){
                if(flag==0){

                    menorEdad = arrayMascotas[i].edad;
                    flag++;
                }

                if(menorEdad > arrayMascotas[i].edad){

                    menorEdad = arrayMascotas[i].edad;
                }
            }
        }

        printf("\n\n\tMascota(s) de menor edad:\n");
        for(i=0;i<limiteMascotas;i++){
            if(arrayMascotas[i].isEmpty == OCUPADO){
                if(arrayMascotas[i].edad == menorEdad){

                    printf("\n\t%s",arrayMascotas[i].nombre);
                }
            }
        }
    }

    return retorno;
}

//4. Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.

int informes_mascotasDeColorYTipo(eMascota* arrayMascotas, int limiteMascotas,eColor* arrayColores,int limiteColores, eTipo* arrayTipos, int limiteTipos){

    int retorno=-1;
    int idColorAux;
    int idTipoAux;
    char nombreColor[20];
    char nombreTipo[20];
    int i;
    int contadorColor=0;
    int contadorTipo=0;

    if(arrayMascotas != NULL && limiteMascotas > 0){

        retorno = 0;
        color_imprimirColores(arrayColores,limiteColores);
        if(!getValidInt("\nIngrese ID del color: ","\nError\n",&idColorAux,COLOR_MIN_ID,MAX,1) && (!verificarColor(arrayColores,limiteColores,idColorAux))){

            tipo_imprimirTipos(arrayTipos,limiteTipos);
            if(!getValidInt("\nIngrese ID del tipo: ","\nError\n",&idTipoAux,TIPO_MIN_ID,MAX,1) && (!verificarTipo(arrayTipos,limiteTipos,idTipoAux))){

                for(i=0;i<limiteMascotas;i++){

                    if(arrayMascotas[i].idColor == idColorAux){

                        contadorColor++;
                    }
                    if(arrayMascotas[i].idTipo == idTipoAux){

                        contadorTipo++;
                    }
                }

                for(i=0;i<limiteColores;i++){

                    if(arrayColores[i].id == idColorAux){

                        strcpy(nombreColor,arrayColores[i].nombreColor);
                    }
                }

                for(i=0;i<limiteTipos;i++){

                    if(arrayTipos[i].id == idTipoAux){

                        strcpy(nombreTipo,arrayTipos[i].descripcion);
                    }
                }

                printf("\n\nCantidad de mascotas del color y tipo seleccionado:");
                printf("\n\n\t%d del color: %s. %d del tipo: %s",contadorColor,nombreColor,contadorTipo,nombreTipo);
            }
        }
    }

    return retorno;
}

//6. Mostrar el o los colores con mas cantidad de mascotas
void resultadoCantidadMascotasSegunColor(eMascota* arrayMascotas, int limiteMascotas, eColor* arrayColores,int limiteColores, int contadorColorMAX){

    int i,j;
    int contador=0;

    printf("\nColor(es) con mas cantidad de mascotas: ");

    for(i=0;i<limiteColores;i++){

        for(j=0;j<limiteMascotas;j++){

            if(arrayColores[i].id == arrayMascotas[j].idColor){

                contador++;
            }
        }
        if(contador == contadorColorMAX){

            printf("%s ",arrayColores[i].nombreColor);
        }

        contador = 0;
    }

    printf("- %d mascota(s)",contadorColorMAX);
}

int informes_colorConMasMascotas(eMascota* arrayMascotas, int limiteMascotas, eColor* arrayColores,int limiteColores){

    int retorno = -1;
    int i,j;
    int contadorColor=0;
    int contadorColorMAX=-1;

    if(arrayColores != NULL && limiteColores > 0){

        retorno = 0;

        for(i=0;i<limiteColores;i++){

            for(j=0;j<limiteMascotas;j++){

                if(arrayColores[i].id == arrayMascotas[j].idColor){

                    contadorColor++;
                }
            }
            if(contadorColor > contadorColorMAX){

                contadorColorMAX = contadorColor;
            }
            contadorColor = 0;
        }

        resultadoCantidadMascotasSegunColor(arrayMascotas,limiteMascotas,arrayColores,limiteColores,contadorColorMAX);
    }


    return retorno;
}



