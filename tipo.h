#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id; //comienza en 1000
    char descripcion[20];
    int isEmpty;
}eTipo;

#endif // TIPO_H_INCLUDED

int tipo_inicializarArrayTipos(eTipo* arrayTipos, int limite);
int tipo_altaForzada(eTipo* arrayTipos,int limite,char* descripcion);
int tipo_imprimirTipos(eTipo* arrayTipos,int limite);
