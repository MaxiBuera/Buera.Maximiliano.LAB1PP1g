#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#define MASCOTAS 20
#define TIPOS 5
#define COLORES 5

int main()
{

    int menu;
    int indice;
    int auxiliarId;
    int flag = 0;
    int flagAlta;

    eTipo arrayTipos[TIPOS];
    tipo_inicializarTipo(arrayTipos,TIPOS);
    tipo_altaForzada(arrayTipos,TIPOS,"Ave");
    tipo_altaForzada(arrayTipos,TIPOS,"Perro");
    tipo_altaForzada(arrayTipos,TIPOS,"Gato");
    tipo_altaForzada(arrayTipos,TIPOS,"Roedor");
    tipo_altaForzada(arrayTipos,TIPOS,"Pez");

    eColor arrayColores[COLORES];
    color_altaForzada(arrayColores,COLORES,"Negro");
    color_altaForzada(arrayColores,COLORES,"Blanco");
    color_altaForzada(arrayColores,COLORES,"Gris");
    color_altaForzada(arrayColores,COLORES,"Rojo");
    color_altaForzada(arrayColores,COLORES,"Azul");

    eMascota arrayMascotas[MASCOTAS];
    mascota_inicializarArrayMascotas(arrayMascotas,MASCOTAS);



    do{

        getValidInt("\n\n1.Alta Mascota\n2.Modificar Mascota\n3.Baja Mascota\n4.Listar Mascotas\n5.Listar Mascotas\n6.Listar Tipos\n7.Listar Colores\n8.Listar Servicios\n9.Alta Trabajo\n11.Listar Trabajo\n12.Salir\n","\nNo valida\n",&menu,1,12,1);
        /*switch(menu)
        {

            case 1:

                indice = mascota_buscarLugarLibre(arrayMascotas,MASCOTAS);
                if(indice >= 0){
                    flagAlta = mascota_agregarMascota(arrayMascotas,MASCOTAS,arrayTipos,TIPOS,arrayColores,COLORES,indice);
                    if(flagAlta == 0)
                        flag = 1;
                }
                break;
        }*/
    }while(menu != 12);


    return 0;
}

