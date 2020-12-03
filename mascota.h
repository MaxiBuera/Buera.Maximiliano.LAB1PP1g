#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo; //validar
    int idColor; //validar
    int edad;
    int idCliente;
    int isEmpty;
}eMascota;

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;
#endif // MASCOTA_H_INCLUDED

int mascota_inicializarArrayMascotas(eMascota* arrayMascotas, int limite);

int mascota_agregarMascota(eMascota* arrayMascotas,int limite,eTipo* arrayTipos ,int limiteTipos,eColor* arrayColores,int limiteColores,eCliente* arrayClientes,int limiteClientes, int indice);

int mascota_buscarLugarLibre(eMascota* arrayMascotas,int limite);

int mascota_altaForzada(eMascota* arrayMascotas,int limite,char* nombre,int idColor, int idTipo,int edad, int idCliente);

int mascota_imprimirMascotas(eMascota* arrayMascotas,int limite,eTipo* arrayTipos, int limiteTipos,eColor* arrayColores,int limiteColorese,eCliente* arrayClientes, int limiteClientes);

int mascota_mostrarMascotaID(eMascota* arrayMascotas,int limite);

int mascota_buscarMascotaPorId(eMascota* arrayMascotas,int limite, int id);

int mascota_eliminarMascota(eMascota* arrayMascotas, int limite,int indice);

int mascota_modificarMascota(eMascota* arrayMascotas, int limite, int indice, eTipo* arrayTipos ,int limiteTipos,eColor* arrayColor,int limiteColores);

int mascota_ordernarPorNombre(eMascota* arrayMascotas,int limite, int orden);

int mascota_ordernarPorTipo(eMascota* arrayMascotas,int limite, int orden);

int verificarColor(eColor* arrayColores, int limiteColores, int idColor);

int verificarTipo(eTipo* arrayTipos, int limiteTipos, int idTipo);

int cliente_altaForzada(eCliente* arrayClientes,int limite,char* nombre,char sexo);

int cliente_inicializarArrayClientes(eCliente* arrayClientes, int limite);

int cliente_imprimirClientes(eCliente* arrayClientes,int limite);
