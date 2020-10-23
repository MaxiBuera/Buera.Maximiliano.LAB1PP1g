#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo; //validar
    int idColor; //validar
    int edad;
    int isEmpty;
}eMascota;

#endif // MASCOTA_H_INCLUDED

int mascota_inicializarArrayMascotas(eMascota* arrayMascotas, int limite);

int mascota_agregarMascota(eMascota* arrayMascotas,int limite,eTipo* arrayTipos ,int limiteTipos,eColor* arrayColores,int limiteColores, int indice);

int mascota_buscarLugarLibre(eMascota* arrayMascotas,int limite);

int mascota_altaForzada(eMascota* arrayMascotas,int limite,char* nombre,int idColor, int idTipo,int edad);

int mascota_imprimirMascotas(eMascota* arrayMascotas,int limite,eTipo* arrayTipos, int limiteTipos,eColor* arrayColores,int limiteColores);

int mascota_mostrarMascotaID(eMascota* arrayMascotas,int limite);

int mascota_eliminarMascota(eMascota* arrayMascotas, int limite,int indice);

int mascota_modificarMascota(eMascota* arrayMascotas, int limite, int indice, eTipo* arrayTipos ,int limiteTipos,eColor* arrayColor,int limiteColores);

int mascota_ordernarPorNombre(eMascota* arrayMascotas,int limite, int orden);

int mascota_ordernarPorTipo(eMascota* arrayMascotas,int limite, int orden);
