#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id; // autoincremental
    int idMascota; //debe existir. Validar
    int idServicio; //debe existir. Validar
    int isEmpty;
}eTrabajo;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha; //VALIDAR DIA MES Y A�o

#endif // TRABAJO_H_INCLUDED

int trabajo_inicializarArrayTrabajos(eTrabajo* arrayTrabajos, int limite);

int trabajo_altaForzada(eTrabajo* arrayTrabajos,int limite,int idMascota,int idServicio);

int trabajo_imprimirTrabajos(eTrabajo* arrayTrabajos,int limite);

int trabajo_agregarTrabajo(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas ,int limiteMascotas,eServicio* arrayServicios,int limiteServicios, int indice);

int trabajo_buscarLugarLibre(eTrabajo* arrayTrabajos,int limite);
