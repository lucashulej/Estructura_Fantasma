#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[100];
    int anio;
    char genero[100];
}Pelicula;

Pelicula* newPelicula();
int deletePelicula(Pelicula* this);
int getId(Pelicula* this,int* id);
int setId(Pelicula* this,int id);
int getNombre(Pelicula* this,char* nombre);
int setNombre(Pelicula* this,char* nombre);
int getAnio(Pelicula* this,int* anio);
int setAnio(Pelicula* this,int anio);
int getGenero(Pelicula* this,char* genero);
int setGenero(Pelicula* this,char* genero);
int idOrder(void* a,void* b);
int depurarPeliculas(LinkedList* this);
int funcionAccion(void* this);

#endif // PELICULAS_H_INCLUDED
