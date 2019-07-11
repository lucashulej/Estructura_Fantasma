#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fantasma.h"

Fantasma* newFantasma()
{
    return (Fantasma*) malloc(sizeof(Fantasma));
}

int deleteFantasma(Fantasma* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}
int getId(Fantasma* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int setId(Fantasma* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int getTipo(Fantasma* this,char* tipo)
{
    int retorno=0;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(tipo,this->tipo);
        retorno=1;
    }
    return retorno;
}

int setTipo(Fantasma* this,char* tipo)
{
    int retorno=0;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(this->tipo,tipo);
        retorno=1;
    }
    return retorno;
}

int getCantidad(Fantasma* this,int* cantidad)
{
    int retorno=0;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=1;
    }
    return retorno;
}

int setCantidad(Fantasma* this,int cantidad)
{
    int retorno=0;
    if(this!=NULL && cantidad>0)
    {
        this->cantidad=cantidad;
        retorno=1;
    }
    return retorno;
}

int getImporte(Fantasma* this,float* importe)
{
    int retorno=0;
    if(this!=NULL && importe!=NULL)
    {
        *importe=this->importe;
        retorno=1;
    }
    return retorno;
}
int setImporte(Fantasma* this,float importe)
{
    int retorno=0;
    if(this!=NULL && importe>0)
    {
        this->importe=importe;
        retorno=1;
    }
    return retorno;
}


/*
int getCaracter(Fantasma* this,char* caracter)
{
    int retorno=0;
    if(this!=NULL&&caracter!=NULL)
    {
        *caracter=this->caracter;
        retorno=1;
    }
    return retorno;
}

int setCaracter(Fantasma* this,char caracter)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->caracter=caracter;
        retorno=1;
    }
    return retorno;
}
*/
