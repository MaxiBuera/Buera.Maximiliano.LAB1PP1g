#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "mascota.h"
#define MASCOTAS 20
#define TIPOS 5
#define COLORES 5
#define SERVICIOS 3
#define TRABAJOS 100

int main()
{

    int menu;
    int indice;
    int auxiliarId;
    int flag = 0;
    int flagAlta;

    eTipo arrayTipos[TIPOS];
    tipo_inicializarArrayTipos(arrayTipos,TIPOS);
    tipo_altaForzada(arrayTipos,TIPOS,"Ave");
    tipo_altaForzada(arrayTipos,TIPOS,"Perro");
    tipo_altaForzada(arrayTipos,TIPOS,"Gato");
    tipo_altaForzada(arrayTipos,TIPOS,"Roedor");
    tipo_altaForzada(arrayTipos,TIPOS,"Pez");

    eColor arrayColores[COLORES];
    color_inicializarArrayColores(arrayColores,COLORES);
    color_altaForzada(arrayColores,COLORES,"Negro");
    color_altaForzada(arrayColores,COLORES,"Blanco");
    color_altaForzada(arrayColores,COLORES,"Gris");
    color_altaForzada(arrayColores,COLORES,"Rojo");
    color_altaForzada(arrayColores,COLORES,"Azul");

    eServicio arrayServicios[SERVICIOS];
    servicio_inicializarArrayServicios(arrayServicios,SERVICIOS);
    servicio_altaForzada(arrayServicios,SERVICIOS,"Corte",250);
    servicio_altaForzada(arrayServicios,SERVICIOS,"Desparasitado",300);
    servicio_altaForzada(arrayServicios,SERVICIOS,"Castrado",400);

    /*eTrabajo arrayTrabajos[TRABAJOS];
    trabajo_inicializarArrayTrabbajos(arrayTrabajos,TRABAJOS);
    trabajo_altaForzada(arrayTrabajos,TRABAJOS,0,2000);*/

    eMascota arrayMascotas[MASCOTAS];
    mascota_inicializarArrayMascotas(arrayMascotas,MASCOTAS);

    //--------------------
    tipo_imprimirTipos(arrayTipos,TIPOS);
    printf("\n\n");
    color_imprimirColores(arrayColores,COLORES);
    printf("\n\n");
    servicio_imprimirServicios(arrayServicios,SERVICIOS);
    printf("\n\n");
    //--------------------

    mascota_altaForzada(arrayMascotas,MASCOTAS,"Pepe",5000,1000,2);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Fatiga",5002,1002,11);
    mascota_imprimirMascotas(arrayMascotas,MASCOTAS);

    printf("\n\n\n");
    printf("\t***** Veterinaria *****");

    do{

        getValidInt("\n\n1.Alta Mascota\n2.Modificar Mascota\n3.Baja Mascota\n4.Listar Mascotas\n5.Listar Tipos\n6.Listar Colores\n7.Listar Servicios\n8.Alta Trabajo\n9.Listar Trabajo\n10.Salir\n","\nNo valida\n",&menu,1,12,1);
        switch(menu)
        {
            case 1:

                indice = mascota_buscarLugarLibre(arrayMascotas,MASCOTAS);
                if(indice >= 0){
                    flagAlta = mascota_agregarMascota(arrayMascotas,MASCOTAS,arrayTipos,TIPOS,arrayColores,COLORES,indice);
                    if(flagAlta == 0)
                        flag = 1;
                }
                break;
             case 2:

                //if(flag!=0){
                    mascota_mostrarMascotaID(arrayMascotas,MASCOTAS);
                    getValidInt("\tID de Mascota a modificar: ","\nID No valido\n",&auxiliarId,0,MASCOTAS,2);
                    mascota_modificarMascota(arrayMascotas,MASCOTAS,auxiliarId,arrayTipos,TIPOS,arrayColores,COLORES);
               /*}
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }*/
                break;
             case 3:

                 /*if(flag!=0){
                    employee_orderByLastName(arrayEmployees,EMPLOYEES,0);
                    employee_orderBySector(arrayEmployees,EMPLOYEES,0);*/
                    mascota_mostrarMascotaID(arrayMascotas,MASCOTAS);
                    getValidInt("\nID de Mascota a eliminar: ","\nID No valido\n",&auxiliarId,0,MASCOTAS,2);
                    mascota_eliminarMascota(arrayMascotas,MASCOTAS,auxiliarId);
                /*}
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;
            case 4:

                /*if(flag!=0){
                */
                mascota_imprimirMascotas(arrayMascotas,MASCOTAS);
                /*}
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;
            case 5:

                /*if(flag!=0){
                */
                tipo_imprimirTipos(arrayTipos,TIPOS);
                /*}
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;
            case 6:

                /*if(flag!=0){
                */
                color_imprimirColores(arrayColores,COLORES);
                /*}
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;
            case 7:

                /*if(flag!=0){
                */
                servicio_imprimirServicios(arrayServicios,SERVICIOS);
                /*}
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;
            case 8:

                /*if(flag!=0){
                */
                //trabajo_imprimirTrabajos(arrayTrabajos,TRABAJOS);
                /*}
                else{

                    printf("\nDebe ingresar un empleado\n");
                }*/
                break;
        }
    }while(menu != 12);


    return 0;
}

