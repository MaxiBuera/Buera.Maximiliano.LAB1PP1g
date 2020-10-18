#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id; //comienza en 5000
    char nombreColor[20];
    int isEmpty;
}eColor;

#endif // COLOR_H_INCLUDED

int color_inicializarArrayColores(eColor* arrayColores, int limite);

int color_altaForzada(eColor* arrayColores,int limite,char* nombreColor);

int color_imprimirColores(eColor* arrayColores,int limite);
