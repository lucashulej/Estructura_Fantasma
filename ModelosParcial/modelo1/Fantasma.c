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

int getCantcantidadad(Fantasma* this,int* cantidad)
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

int getFecha(Fantasma* this,char* fecha)
{
    int retorno=0;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=1;
    }
    return retorno;
}

int setFecha(Fantasma* this,char* fecha)
{
    int retorno=0;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=1;
    }
    return retorno;
}

int getCuit(Fantasma* this,char* cuit)
{
    int retorno=0;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=1;
    }
    return retorno;
}

int setCuit(Fantasma* this,char* cuit)
{
    int retorno=0;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=1;
    }
    return retorno;
}

int funcion1(void* elemento,float* floater)
{
    int retorno=0;
    Fantasma* fantasma=NULL;
    fantasma=(Fantasma*) elemento;
    if(floater!=NULL && fantasma!=NULL)
    {
        *floater=fantasma->importe;
        //printf("%.2f\n",fantasma->importe);
        retorno=1;
    }
    return retorno;
}
