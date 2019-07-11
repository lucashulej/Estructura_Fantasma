#include <stdio.h>
#include <stdlib.h>

#ifndef fantasma_H_INCLUDED
#define fantasma_H_INCLUDED
typedef struct
{
    int id;
    char tipo[20];
    int cantidad;
    float importe;
}Fantasma;

Fantasma* newFantasma();

int deleteFantasma(Fantasma* this);

int getId(Fantasma* this,int* id);
int setId(Fantasma* this,int id);

int getTipo(Fantasma* this,char* tipo);
int setTipo(Fantasma* this,char* tipo);

int getCantidad(Fantasma* this,int* cantidad);
int setCantidad(Fantasma* this,int cantidad);

int getImporte(Fantasma* this,float* importe);
int setImporte(Fantasma* this,float importe);

#endif // fantasma_H_INCLUDED
