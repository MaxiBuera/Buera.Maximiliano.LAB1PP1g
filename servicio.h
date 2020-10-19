#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id; // comienza 20000
    char descripcion[25];
    float precio;
    int isEmpty;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int servicio_inicializarArrayServicios(eServicio* arrayServicios, int limite);

int servicio_altaForzada(eServicio* arrayServicios,int limite,char* nombreColor, float precio);

int servicio_imprimirServicios(eServicio* arrayServicios,int limite);

int servicio_mostrarServicioID(eServicio* arrayServicios,int limite);
