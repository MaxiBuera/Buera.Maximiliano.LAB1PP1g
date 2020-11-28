#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "mascota.h"
#include "trabajo.h"
#include "informes.h"
#define MASCOTAS 20
#define TIPOS 5
#define COLORES 5
#define SERVICIOS 3
#define TRABAJOS 10
#define CLIENTES 20
#define OCUPADO 0
#define LIBRE 0


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

    eMascota arrayMascotas[MASCOTAS];
    mascota_inicializarArrayMascotas(arrayMascotas,MASCOTAS);

    //--------------------
    /*tipo_imprimirTipos(arrayTipos,TIPOS);
    printf("\n\n");
    color_imprimirColores(arrayColores,COLORES);
    printf("\n\n");
    servicio_imprimirServicios(arrayServicios,SERVICIOS);
    printf("\n\n");*/
    //--------------------

    eCliente arrayClientes[CLIENTES];
    cliente_inicializarArrayClientes(arrayClientes,CLIENTES);
    cliente_altaForzada(arrayClientes,CLIENTES,"Alberto",'m');
    cliente_altaForzada(arrayClientes,CLIENTES,"Florencia",'f');
    cliente_altaForzada(arrayClientes,CLIENTES,"Guillermo",'m');

    cliente_imprimirClientes(arrayClientes,CLIENTES);

    /*arrayClientes[CLIENTES]=
    {
        {0,"Alberto",'m',OCUPADO},
        {1,"Florencia",'f',OCUPADO},
        {2,"Guillermo",'m',OCUPADO},
    };*/

    mascota_altaForzada(arrayMascotas,MASCOTAS,"Pepe",5000,1000,2,0);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Fatiga",5002,1002,11,1);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Pedro",5004,1000,12,2);
    mascota_altaForzada(arrayMascotas,MASCOTAS,"Roco",5001,1001,2,0);
    //mascota_imprimirMascotas(arrayMascotas,MASCOTAS,arrayTipos,TIPOS,arrayColores,COLORES,arrayClientes,CLIENTES);

    eTrabajo arrayTrabajos[TRABAJOS];
    trabajo_inicializarArrayTrabajos(arrayTrabajos,TRABAJOS);
    trabajo_altaForzada(arrayTrabajos,TRABAJOS,0,20000);
    trabajo_altaForzada(arrayTrabajos,TRABAJOS,1,20002);

    //trabajo_imprimirTrabajos(arrayTrabajos,TRABAJOS,arrayMascotas,MASCOTAS,arrayServicios,SERVICIOS);
    //printf("\n\n");

    printf("\n\n\n");
    printf("\t***** Veterinaria *****");
    printf("\n");
    do{

        getValidInt("\n\n1.Alta Mascota\n2.Modificar Mascota\n3.Baja Mascota\n4.Listar Mascotas\n5.Listar Tipos\n6.Listar Colores\n7.Listar Servicios\n8.Alta Trabajo\n9.Listar Trabajo\n\n**** Informes *****\n\n10.Mostrar las mascotas del color seleccionado\n11.Mostrar las mascotas del tipo seleccionado\n12.Mostrar mascota de menor edad\n13.Cantidad de mascotas de cierto color y tipo\n15.Salir\n","\nNo valida\n",&menu,1,15,1);
        switch(menu)
        {
            case 1:

                indice = mascota_buscarLugarLibre(arrayMascotas,MASCOTAS);
                if(indice >= 0){
                    flagAlta = mascota_agregarMascota(arrayMascotas,MASCOTAS,arrayTipos,TIPOS,arrayColores,COLORES,arrayClientes,CLIENTES,indice);
                    if(flagAlta == 0)
                        flag = 1;
                }
                cliente_imprimirClientes(arrayClientes,CLIENTES);
                break;
             case 2:

                if(flag!=0){
                    mascota_mostrarMascotaID(arrayMascotas,MASCOTAS);
                    getValidInt("\tID de Mascota a modificar: ","\nID No valido\n",&auxiliarId,0,MASCOTAS,2);
                    mascota_modificarMascota(arrayMascotas,MASCOTAS,auxiliarId,arrayTipos,TIPOS,arrayColores,COLORES);
               }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
             case 3:

                 if(flag!=0){
                    mascota_mostrarMascotaID(arrayMascotas,MASCOTAS);
                    getValidInt("\nID de Mascota a eliminar: ","\nID No valido\n",&auxiliarId,0,MASCOTAS,2);
                    mascota_eliminarMascota(arrayMascotas,MASCOTAS,auxiliarId);
                    trabajo_mascotaEliminada(arrayTrabajos,TRABAJOS,arrayMascotas,MASCOTAS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 4:

                //if(flag!=0){

                    mascota_ordernarPorTipo(arrayMascotas,MASCOTAS,0);
                    mascota_ordernarPorNombre(arrayMascotas,MASCOTAS,0);
                    mascota_imprimirMascotas(arrayMascotas,MASCOTAS,arrayTipos,TIPOS,arrayColores,COLORES,arrayClientes,CLIENTES);
                /*}
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }*/
                break;
            case 5:

                if(flag!=0){

                    tipo_imprimirTipos(arrayTipos,TIPOS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 6:

                if(flag!=0){

                    color_imprimirColores(arrayColores,COLORES);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 7:

                if(flag!=0){

                    servicio_imprimirServicios(arrayServicios,SERVICIOS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 8:

                if(flag!=0){

                indice = trabajo_buscarLugarLibre(arrayTrabajos,TRABAJOS);
                if(indice >= 0)
                    trabajo_agregarTrabajo(arrayTrabajos,TRABAJOS,arrayMascotas,MASCOTAS,arrayServicios,SERVICIOS,indice);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 9:

                if(flag!=0){

                    trabajo_imprimirTrabajos(arrayTrabajos,TRABAJOS,arrayMascotas,MASCOTAS,arrayServicios,SERVICIOS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 10:
                if(flag!=0){

                    informes_mostrarMascotasPorColorSeleccionado(arrayMascotas,MASCOTAS,arrayColores,COLORES);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 11:
                if(flag!=0){

                    informes_mostrarMascotasPorTipoSeleccionado(arrayMascotas,MASCOTAS,arrayTipos,TIPOS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 12:
                if(flag!=0){

                informes_mascotasDeMenorEdad(arrayMascotas,MASCOTAS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            case 13:
                if(flag!=0){

                    informes_mascotasDeColorYTipo(arrayMascotas,MASCOTAS,arrayColores,COLORES,arrayTipos,TIPOS);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;
            /*case 14:
                if(flag!=0){

                informes_colorConMasMascotas(arrayMascotas,MASCOTAS,arrayColores,COLORES);
                }
                else{

                    printf("\nDebe ingresar almenos una mascota\n");
                }
                break;*/
        }
    }while(menu != 15);


    return 0;
}

