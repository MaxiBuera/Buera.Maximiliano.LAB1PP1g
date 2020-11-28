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

static int nextId();
static int cliente_nextId();

/** \brief  Formatea la cadena pasada por parametro (primer letra mayuscula)
 *
 * \param   cadena a formatear
 * \return
 *
 */
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

/** \brief  Para indicar que todas las posiciones estan vacias,
 *          esta funcion coloca el flag (isEmpty) en True en
 *          todas las posiciones del array
 *
 * \param   array de Mascotas
 * \param   limite del array de Mascotas
 *
 * \return 0 si la entrada es correcta, sino -1
 *
 */
int mascota_inicializarArrayMascotas(eMascota* arrayMascotas, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = 0;
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
    return retorno;
}

/** \brief Verifica si el id pasado por parametro se encuentra en el array
 *
 * \param   array de tipos
 * \param   limite del array de tipos
 * \param   id a buscar
 * \return  -1 si hay algun error, 0 si no
 *
 */
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

/** \brief Verifica si el id pasado por parametro se encuentra en el array
 *
 * \param   array de tipos
 * \param   limite del array de colores
 * \param   id a buscar
 * \return  -1 si hay algun error, 0 si no
 *
 */
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

/** \brief  agrega una mascota  al array. Validando los tipos y colores
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
int mascota_agregarMascota(eMascota* arrayMascotas,int limite,eTipo* arrayTipos ,int limiteTipos,eColor* arrayColores,int limiteColores,eCliente* arrayClientes,int limiteClientes, int indice){

    int retorno = -1;
    char nombreAux[20];
    int idTipoAux;
    int idColorAux;
    int edadAux;
    char cliente[20];
    int id;
    int idCliente;
    char sexoCliente;

    if(limite > 0 && arrayMascotas != NULL){

        retorno = -2;
        id = nextId();
        idCliente = cliente_nextId();

        if(getStringLetras("\nIngrese nombre de la mascota: ",nombreAux)){

            tipo_imprimirTipos(arrayTipos,limiteTipos);
            if(!getValidInt("\nIngrese ID del tipo: ","\nError\n",&idTipoAux,TIPO_MIN_ID,MAX,1) && (!verificarTipo(arrayTipos,limiteTipos,idTipoAux))){

                color_imprimirColores(arrayColores,limiteColores);
                if(!getValidInt("\nIngrese ID del color: ","\nError\n",&idColorAux,COLOR_MIN_ID,MAX,1) && (!verificarColor(arrayColores,limiteColores,idColorAux))){

                    if(!getValidInt("\nIngrese edad: ","\nError\n",&edadAux,0,35,2)){

                        if(getStringLetras("\nIngrese nombre del cliente: ",cliente)){

                            sexoCliente = getChar("\nIngrese su sexo [m - masculino | f - femenino]: ");
                            if(sexoCliente == 'm' || sexoCliente == 'M' || sexoCliente == 'f' || sexoCliente == 'F'){

                                mascota_normalizarCadena(nombreAux);
                                strcpy(arrayMascotas[indice].nombre,nombreAux);

                                arrayMascotas[indice].idTipo = idTipoAux;
                                arrayMascotas[indice].idColor = idColorAux;
                                arrayMascotas[indice].edad = edadAux;

                                mascota_normalizarCadena(cliente);
                                strcpy(arrayClientes[idCliente].nombre,cliente);

                                arrayClientes[idCliente].sexo = sexoCliente;
                                arrayMascotas[indice].isEmpty = OCUPADO;
                                arrayMascotas[indice].id = id;
                                printf("\n\tMascota Agregada...");
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if(retorno != 0){

        printf("\nError. Dato invalido\n");
    }

    return retorno;
}

/** \brief  Busca un espacio libre en el array
 *
 * \param   array de Mascotas
 * \param   limite del array
 * \return  -1 o -2 si hay algun error, 0 si no
 *
 */
int mascota_buscarLugarLibre(eMascota* arrayMascotas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayMascotas[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief  Alta de una mascota, usando datos de los parametros
 *
 * \param   array de mascotas
 * \param   limite del array de mascotas
 * \param   nombre
 * \param   idColor
 * \param   idTipo
 * \param   edad
 * \return  -1 si hay algun error, 0 si no
 *
 */
int mascota_altaForzada(eMascota* arrayMascotas,int limite,char* nombre,int idColor, int idTipo,int edad, int idCliente)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayMascotas != NULL)
    {
        i = mascota_buscarLugarLibre(arrayMascotas,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayMascotas[i].nombre,nombre);
            arrayMascotas[i].idColor = idColor;
            arrayMascotas[i].idTipo = idTipo;
            arrayMascotas[i].edad = edad;
            arrayMascotas[i].idCliente = idCliente;
            //------------------------------
            //------------------------------
            arrayMascotas[i].id = nextId();
            arrayMascotas[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Busca una mascota por id dentro del array
 * \param array de mascotas
 * \param limite de array de mascotas
  * \param id a buscar
 * \return -1 o -2 si falla
 */
int mascota_buscarMascotaPorId(eMascota* arrayMascotas,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayMascotas[i].isEmpty == OCUPADO && arrayMascotas[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief  Menu al modificar una mascota
 *
 * \param   array de mascotas
 * \param   indice de mascota a modificar
 * \param   array de tipos. Verifica el tipo en el array de mascotas
 * \param   limite del array de tipos
 * \param   array de colores. Verifica el color en el array de mascotas
 * \param   limite del array de colores
 * \return  -
 *
 */
void mascota_menuModificacion(eMascota* arrayMascotas, int indice, eTipo* arrayTipos ,int limiteTipos,eColor* arrayColor,int limiteColores){

    int opc;
    int idTipoAux;
    int edadAux;


    printf("\n\tMascota a Modificar: %s ",arrayMascotas[indice].nombre);

    do{

        getValidInt("\n\n\t1.Modificar Tipo\n\t2.Modificar Edad\n\t3.Listo\n","\nNo valida\n",&opc,1,3,1);
        switch(opc)
        {
            case 1:
                tipo_imprimirTipos(arrayTipos,limiteTipos);
                if(!getValidInt("\n\n\tIngrese ID del tipo de mascota: ","\nError. ID no encontrado\n",&idTipoAux,TIPO_MIN_ID,MAX,2) && (!verificarTipo(arrayTipos,limiteTipos,idTipoAux))){

                    arrayMascotas[indice].idTipo = idTipoAux;
                    printf("\nTipo de Mascota Modificado...");
                }
                break;
            case 2:
                if(!getValidInt("Ingrese edad: ","\nError\n",&edadAux,0,35,2)){
                    arrayMascotas[indice].edad = edadAux;
                    printf("\nEdad de la Mascota Modificada...");
                }
                break;
        }
    }while(opc != 3);

}
int mascota_modificarMascota(eMascota* arrayMascotas, int limite, int indice, eTipo* arrayTipos ,int limiteTipos,eColor* arrayColor,int limiteColores){

    int i;
    int retorno = -1;


    i = mascota_buscarMascotaPorId(arrayMascotas,limite,indice);
    if(i >= 0)
    {
        mascota_menuModificacion(arrayMascotas,i,arrayTipos,limiteTipos,arrayColor,limiteColores);
        arrayMascotas[i].isEmpty = OCUPADO;
        retorno = 0;
    }
    else{
        printf("\nID No encotrado");
    }
    return retorno;
}

/** \brief  Baja logica de una mascota
 *
 * \param   array de mascotas
 * \param   limite del array de macotas
 * \param   indice de la mascota
 * \return  -1 si hay algun error, 0 si no
 *
 */
int mascota_eliminarMascota(eMascota* arrayMascotas, int limite,int indice){

    int retorno = -1;
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
            retorno = 0;
        }
        else if(confirmacion == 'n' || confirmacion == 'N'){

            printf("\n\tMascota No Eliminada...");
            return retorno;
        }
        else{
            printf("\nError. Vuelva a Intentar");
        }
    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

/** \brief  Muestra la lista de mascotas
 *
 * \param   array de Mascotas
 * \param   limite de Mascotas
 * \param   array de Tipos
 * \param   limite del array de tipos
 * \param   array de Colores
 * \param   limite del array de colores
 * \return  -1 si hay un error, 0 si no
 *
 */
int mascota_imprimirMascotas(eMascota* arrayMascotas,int limite,eTipo* arrayTipos, int limiteTipos,eColor* arrayColores,int limiteColores,eCliente* arrayClientes, int limiteClientes){

    int retorno = -1;
    int i,j;
    char nombreTipo[20];
    char nombreColor[20];
    char nombreCliente[20];

    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = 0;
        printf("\n\t***Mascotas***\n");
        printf("\n\tNombre\t\tColor\t\tTipo\t\tEdad\t\tID\t   Duenio");
        printf("\n\t-----------------------------------------------------------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayMascotas[i].isEmpty)
            {
                for(j=0;j<limiteTipos;j++){

                    if(arrayMascotas[i].idTipo == arrayTipos[j].id){
                        strcpy(nombreTipo,arrayTipos[j].descripcion);
                        continue;
                    }
                }
                for(j=0;j<limiteColores;j++){

                    if(arrayMascotas[i].idColor == arrayColores[j].id){
                        strcpy(nombreColor,arrayColores[j].nombreColor);
                        continue;
                    }
                }
                for(j=0;j<limiteClientes;j++){

                    if(arrayMascotas[i].idCliente == arrayClientes[j].id){
                        strcpy(nombreCliente,arrayClientes[j].nombre);
                        continue;
                    }
                }

           		printf("\n%15s %14s %15s %13d %12d %16s",arrayMascotas[i].nombre,nombreColor,nombreTipo,arrayMascotas[i].edad,arrayMascotas[i].id,nombreCliente);
           	}
        }
        printf("\n");
    }
    return retorno;
}

/** \brief  Muestra la lista de las mascotas ( Nombre y id)
 *
 * \param   array de Mascotas
 * \param   limite del array de Mascotas
 * \return  -1 si hay un error, 0 si no
 *
 */
int mascota_mostrarMascotaID(eMascota* arrayMascotas,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = 0;
        printf("\n\t**** Lista de Mascotas ****\n");
        printf("\n\tNombre\t\t\tID");
        printf("\n\t----------------------------------");
        for(i=0;i<limite;i++)
        {
        	if(!arrayMascotas[i].isEmpty)
            {

           		printf("\n%15s %17d",arrayMascotas[i].nombre,arrayMascotas[i].id);
        	}
        }
    }
    printf("\n\n");
    return retorno;
}

/** \brief  Ordena el array de mascotas por nombre
 *
 * \param   array de Mascotas
 * \param   limite del array de mascotas
 * \param   criterio de ordenacion
 * \return  -1 si hay un error, 0 si no
 *
 */
int mascota_ordernarPorNombre(eMascota* arrayMascotas,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eMascota auxiliar;

    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(arrayMascotas[i].isEmpty == OCUPADO && arrayMascotas[i+1].isEmpty == OCUPADO )
                {
                    if((strcmp(arrayMascotas[i].nombre,arrayMascotas[i+1].nombre) > 0 && !orden) || (strcmp(arrayMascotas[i].nombre,arrayMascotas[i+1].nombre) < 0 && orden)) //<------------
                    {
                        auxiliar = arrayMascotas[i];
                        arrayMascotas[i] = arrayMascotas[i+1];
                        arrayMascotas[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}

/** \brief  Ordena el array de mascotas por tipo
 *
 * \param   array de Mascotas
 * \param   limite del array de mascotas
 * \param   criterio de ordenacion
 * \return  -1 si hay un error, 0 si no
 *
 */
int mascota_ordernarPorTipo(eMascota* arrayMascotas,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eMascota auxiliar;

    if(limite > 0 && arrayMascotas != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(arrayMascotas[i].isEmpty == OCUPADO && arrayMascotas[i+1].isEmpty == OCUPADO )
                {
                    if((arrayMascotas[i].idTipo < arrayMascotas[i+1].idTipo && !orden) || (arrayMascotas[i].idTipo > arrayMascotas[i+1].idTipo && orden)) //<------------
                    {

                        auxiliar = arrayMascotas[i];
                        arrayMascotas[i] = arrayMascotas[i+1];
                        arrayMascotas[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}

static int nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}

int cliente_inicializarArrayClientes(eCliente* arrayClientes, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayClientes[i].id = -1;
            strcpy(arrayClientes[i].nombre,"");
            arrayClientes[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int cliente_buscarLugarLibre(eCliente* arrayCliente,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayCliente != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayCliente[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_altaForzada(eCliente* arrayClientes,int limite,char* nombre,char sexo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayClientes != NULL)
    {
        i = cliente_buscarLugarLibre(arrayClientes,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayClientes[i].nombre,nombre);
            arrayClientes[i].sexo = sexo;
            //------------------------------
            //------------------------------
            arrayClientes[i].id = cliente_nextId();
            arrayClientes[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_imprimirClientes(eCliente* arrayClientes,int limite)
{
    int retorno = -1;

    if(limite > 0 && arrayClientes != NULL)
    {
        int i;
        retorno = 0;
        printf("\n\t**** Clientes ****\n");
        printf("\n\tID Cliente\tNombre\t\tSexo");
        printf("\n\t-----------------------------------------------");
        for(i=0;i<limite;i++)
        {

            if(arrayClientes[i].isEmpty != LIBRE){

                printf("\n%12d%15s\t\t%c",arrayClientes[i].id,arrayClientes[i].nombre,arrayClientes[i].sexo);
            }
        }
    }

    return retorno;
}

static int cliente_nextId()
{
    static int lastId = -1;
    lastId++;
    return lastId;
}
