#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
int main()
{
    LinkedList* listaPeliculas = ll_newLinkedList();
    LinkedList* listaDepurada = ll_newLinkedList();
    LinkedList* listaFilter;
    int opcion;
    int i;
    void* elemento;
    Pelicula* peli;
    do
    {
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                controller_loadFromText("datosMF1.csv",listaPeliculas);
                controller_loadFromText("datosMF1.csv",listaDepurada);
                break;
            case 2:
                ll_sort(listaPeliculas,idOrder,1);

                for(i=0;i<ll_len(listaPeliculas);i++)
                {
                    elemento=ll_get(listaPeliculas,i);
                    peli = (Pelicula*) elemento;
                    printf("%d %s %d %s\n",peli->id,peli->nombre,peli->anio,peli->genero);
                }
                break;
            case 3:
                ll_sort(listaDepurada,idOrder,1);
                depurarPeliculas(listaDepurada);
                for(i=0;i<ll_len(listaDepurada);i++)
                {
                    elemento=ll_get(listaDepurada,i);
                    peli = (Pelicula*) elemento;
                    printf("%d %s %d %s\n",peli->id,peli->nombre,peli->anio,peli->genero);
                }
                break;
            case 4:
                listaFilter=ll_filter(listaPeliculas,funcionAccion);
                for(i=0;i<ll_len(listaFilter);i++)
                {
                    elemento=ll_get(listaFilter,i);
                    peli = (Pelicula*) elemento;
                    printf("%d %s %d %s\n",peli->id,peli->nombre,peli->anio,peli->genero);
                }
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;
        }
    }while(opcion!=6);
    return 0;
}
