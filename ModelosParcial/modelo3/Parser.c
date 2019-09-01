#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "peliculas.h"
#include "Parser.h"
int parser_peliculaFromText(FILE* pFile, LinkedList* this)
{
    int retorno=0;
    char auxId[10];
    char auxNombre[100];
    char auxAnio[10];
    char auxGenero[100];
    char nada[1000];
    Pelicula auxPelicula;
    Pelicula* pelicula=NULL;
    int flag=0;
    if(pFile!=NULL&&this!=NULL)
    {
        while(!feof(pFile))
        {
            if(flag==0)
            {
                fscanf(pFile,"%[^\n]\n",nada);
                flag=1;
                continue;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxAnio,auxGenero);
            printf("%s %s %s %s\n",auxId,auxNombre,auxAnio,auxGenero);
            pelicula=newPelicula();
            if(pelicula!=NULL)
            {


                    auxPelicula.id=atoi(auxId);
                    strcpy(auxPelicula.nombre,auxNombre);
                    auxPelicula.anio=atoi(auxAnio);
                    strcpy(auxPelicula.genero,auxGenero);

                    if(setId(pelicula,auxPelicula.id)&&
                       setNombre(pelicula,auxPelicula.nombre)&&
                       setAnio(pelicula,auxPelicula.anio)&&
                       setGenero(pelicula,auxPelicula.genero))
                    {
                        ll_add(this,pelicula);
                    }
                    else
                    {
                        deletePelicula(pelicula);
                    }

                    retorno=1;
            }
        }
        printf("TERMINADO\n");
    }
    return retorno;
}

int parser_writeInfo(char* fileName,int totalEntregas,int tipoG,int tipoR,int tipoP,int totalBultos,float promedioBultos,float promedioImporte)
{
    int retorno=0;
    FILE* pFile=NULL;
    if(fileName!=NULL && totalEntregas>0 && totalEntregas>0 && tipoG>0 && tipoR>0 && tipoP>0 && totalBultos>0 && promedioBultos>0 && promedioImporte)
    {
        pFile=fopen(fileName,"w");
        if(pFile!=NULL)
        {
            retorno=1;
            fprintf(pFile,"********************\nInforme de ventas\n********************\n");
            fprintf(pFile,"- Cantidad total de entregas: %d\n",totalEntregas);
            fprintf(pFile,"- Cantidad de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n",tipoG,tipoR,tipoP);
            fprintf(pFile,"- Cantidad total de bultos entregados: %d\n",totalBultos);
            fprintf(pFile,"- Promedio de bultos por entrega: %.2f\n",promedioBultos);
            fprintf(pFile,"- Importe promedio por entrega: %.2f\n",promedioImporte);
            fprintf(pFile,"********************\n");
        }
        fclose(pFile);
    }
    return retorno;
}

