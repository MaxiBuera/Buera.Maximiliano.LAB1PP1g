#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id; // autoincremental
    int idMascota; //debe existir. Validar
    int idServicio; //debe existir. Validar
}eTrabajo;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha; //VALIDAR DIA MES Y Año

#endif // TRABAJO_H_INCLUDED
