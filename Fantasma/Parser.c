#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Fantasma.h"
#include "Parser.h"
int parser_fromText(FILE* pFile, LinkedList* this)
{
    int retorno=0;
    char auxId[10];
    char auxTipo[20];
    char auxCantidad[10];
    char auxImporte[10];

    Fantasma auxFantasma;
    Fantasma* fantasma=NULL;
    int flag=0;
    if(pFile!=NULL&&this!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxTipo,auxCantidad,auxImporte);
            if(flag==0)
            {
                flag=1;
                continue;
            }
            //printf("%4s %15s %15s %15s\n",auxId,auxTipo,auxCantidad,auxImporte);
            fantasma=newFantasma();
            if(fantasma!=NULL)
            {
                if(isValidInter(auxId)&&isValidName(auxTipo)&&isValidInter(auxCantidad)&&isValidFloat(auxImporte))
                {

                    auxFantasma.id=atoi(auxId);
                    strcpy(auxFantasma.tipo,auxTipo);
                    auxFantasma.cantidad=atoi(auxCantidad);
                    auxFantasma.importe=atof(auxImporte);

                    if(setId(fantasma,auxFantasma.id)&&

                       setTipo(fantasma,auxFantasma.tipo)&&
                       setCantidad(fantasma,auxFantasma.cantidad)&&
                       setImporte(fantasma,auxFantasma.importe))
                    {
                        ll_add(this,fantasma);
                    }
                    else
                    {
                        deleteFantasma(fantasma);
                    }

                    retorno=1;
                }
            }
        }
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

