#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha; //VALIDAR DIA MES Y Año

typedef struct{
    int id; // autoincremental
    int idMascota; //debe existir. Validar
    int idServicio; //debe existir. Validar
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int trabajo_inicializarArrayTrabajos(eTrabajo* arrayTrabajos, int limite);

int trabajo_altaForzada(eTrabajo* arrayTrabajos,int limite,int idMascota,int idServicio,int dia, int mes, int anio);

int trabajo_imprimirTrabajos(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas,int limiteMascotas,eServicio* arrayServicios,int limiteServicios);

int trabajo_agregarTrabajo(eTrabajo* arrayTrabajos,int limite,eMascota* arrayMascotas ,int limiteMascotas,eServicio* arrayServicios,int limiteServicios, int indice);

int trabajo_buscarLugarLibre(eTrabajo* arrayTrabajos,int limite);

int trabajo_mascotaEliminada(eTrabajo* arrayTrabajos, int limite, eMascota* arrayMascotas, int limiteMascotas);

int verificarMascota(eMascota* arrayMascotas, int limiteMascotas, int idMascotas);

int verificarServicio(eServicio* arrayServicios, int limiteServicios, int idServicios);
