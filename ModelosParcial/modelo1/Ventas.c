#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ventas.h"

Venta* newVenta()
{
    return (Venta*) malloc(sizeof(Venta));
}

int deleteVenta(Venta* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}

int getId(Venta* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int setId(Venta* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int getTipo(Venta* this,char* tipo)
{
    int retorno=0;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(tipo,this->tipo);
        retorno=1;
    }
    return retorno;
}

int setTipo(Venta* this,char* tipo)
{
    int retorno=0;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(this->tipo,tipo);
        retorno=1;
    }
    return retorno;
}

int getCantcantidadad(Venta* this,int* cantidad)
{
    int retorno=0;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=1;
    }
    return retorno;
}

int setCantidad(Venta* this,int cantidad)
{
    int retorno=0;
    if(this!=NULL && cantidad>0)
    {
        this->cantidad=cantidad;
        retorno=1;
    }
    return retorno;
}

int getImporte(Venta* this,float* importe)
{
    int retorno=0;
    if(this!=NULL && importe!=NULL)
    {
        *importe=this->importe;
        retorno=1;
    }
    return retorno;
}

int setImporte(Venta* this,float importe)
{
    int retorno=0;
    if(this!=NULL && importe>0)
    {
        this->importe=importe;
        retorno=1;
    }
    return retorno;
}

int tipoG(void* this)
{
    int retorno=0;
    Venta* venta;
    if(this!=NULL)
    {
        venta = (Venta*) this;
        if(strcmp(venta->tipo,"GOLD")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}
int tipoR(void* this)
{
    int retorno=0;
    Venta* venta;
    if(this!=NULL)
    {
        venta = (Venta*) this;
        if(strcmp(venta->tipo,"REGULAR")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}
int tipoP(void* this)
{
    int retorno=0;
    Venta* venta;
    if(this!=NULL)
    {
        venta = (Venta*) this;
        if(strcmp(venta->tipo,"PLUS")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int contadorBultos(void* this)
{
    int retorno=0;
    Venta* venta;
    if(this!=NULL)
    {
        venta = (Venta*) this;
        retorno=venta->cantidad;
    }
    return retorno;
}

float contadorImporte(void* this)
{
    float retorno=0;
    Venta* venta;
    if(this!=NULL)
    {
        venta = (Venta*) this;
        retorno=venta->importe;
    }
    return retorno;
}
