#include <stdio.h>
#include <stdlib.h>

#ifndef fantasma_H_INCLUDED
#define fantasma_H_INCLUDED
typedef struct
{
    int id;
    char fecha[11];//10
    char tipo[20];
    int cantidad;
    float importe;
    char cuit[14];//13
}Fantasma;

Fantasma* newFantasma();
int deleteFantasma(Fantasma* this);
int getId(Fantasma* this,int* id);
int setId(Fantasma* this,int id);
int getFecha(Fantasma* this,char* fecha);
int setFecha(Fantasma* this,char* fecha);
int getTipo(Fantasma* this,char* tipo);
int setTipo(Fantasma* this,char* tipo);
int getCantidad(Fantasma* this,int* cantidad);
int setCantidad(Fantasma* this,int cantidad);
int getImporte(Fantasma* this,float* importe);
int setImporte(Fantasma* this,float importe);
int funcion1(void* elemento,float* floater);
int getCuit(Fantasma* this,char* cuit);
int setCuit(Fantasma* this,char* cuit);
#endif // fantasma_H_INCLUDED
