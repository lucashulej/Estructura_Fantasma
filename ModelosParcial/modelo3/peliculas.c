#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"

Pelicula* newPelicula()
{
    return (Pelicula*) malloc(sizeof(Pelicula));
}

int deletePelicula(Pelicula* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}
int getId(Pelicula* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int setId(Pelicula* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int getNombre(Pelicula* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

int setNombre(Pelicula* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int getAnio(Pelicula* this,int* anio)
{
    int retorno=0;
    if(this!=NULL && anio!=NULL)
    {
        *anio=this->anio;
        retorno=1;
    }
    return retorno;
}

int setAnio(Pelicula* this,int anio)
{
    int retorno=0;
    if(this!=NULL && anio>0)
    {
        this->anio=anio;
        retorno=1;
    }
    return retorno;
}


int getGenero(Pelicula* this,char* genero)
{
    int retorno=0;
    if(this!=NULL && genero!=NULL)
    {
        strcpy(genero,this->genero);
        retorno=1;
    }
    return retorno;
}

int setGenero(Pelicula* this,char* genero)
{
    int retorno=0;
    if(this!=NULL && genero!=NULL)
    {
        strcpy(this->genero,genero);
        retorno=1;
    }
    return retorno;
}

int idOrder(void* a,void* b)
{
    int retorno;
    Pelicula* aa = (Pelicula*) a;
    Pelicula* bb = (Pelicula*) b;
    if(aa->id > bb->id)
    {
        retorno=1;
    }
    else if(aa->id < bb->id)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}


int depurarPeliculas(LinkedList* this)
{
    int retorno=0;
    void* elementoA;
    void* elementoB;
    Pelicula* peliculaA;
    Pelicula* peliculaB;
    int i;
    int j;
    char conexion[100];
    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            strcpy(conexion,"|");
            elementoA=ll_get(this,i);
            peliculaA = (Pelicula*) elementoA;
            for(j=i+1;j<ll_len(this);j++)
            {
                elementoB=ll_get(this,j);
                peliculaB = (Pelicula*) elementoB;
                if(strcmp(peliculaA->nombre,peliculaB->nombre)==0)
                {
                    strcpy(conexion,"|");
                    strcat(conexion,peliculaB->genero);
                    strcat(peliculaA->genero,conexion);
                    ll_remove(this,j);
                    j--;
                }
            }
        }
    }
    return retorno;
}

int funcionAccion(void* this)
{
    int retorno=0;
    Pelicula* peli = (Pelicula*) this;
    if(strcmp("Accion",peli->genero)==0)
    {
        retorno=1;
    }
    return retorno;
}
