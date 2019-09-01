#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

Empleado* newEmpleado()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

int deleteEmpleado(Empleado* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}
int getId(Empleado* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int setId(Empleado* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int getNombre(Empleado* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

int setNombre(Empleado* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int getHoras(Empleado* this,int* horas)
{
    int retorno=0;
    if(this!=NULL && horas!=NULL)
    {
        *horas=this->horas;
        retorno=1;
    }
    return retorno;
}

int setHoras(Empleado* this,int horas)
{
    int retorno=0;
    if(this!=NULL && horas>0)
    {
        this->horas=horas;
        retorno=1;
    }
    return retorno;
}

int getSueldo(Empleado* this,float* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}

int setSueldo(Empleado* this,float sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

int calculaSueldo(void* elemento)
{
    int retorno=0;
    Empleado* empleado;
    int horas;
    float sueldo=0;
    if(elemento!=NULL)
    {
        empleado = (Empleado*) elemento;
        getHoras(empleado,&horas);
        if(horas>=80 && horas<=240)
        {
            if(horas<=120)
            {
                sueldo = horas * 180;
            }
            else if(horas>120 && horas<=160)
            {
                sueldo = horas * 240;
            }
            else
            {
                sueldo = horas * 350;
            }
            setSueldo(empleado,sueldo);
            retorno=1;
        }
    }
    return retorno;
}
