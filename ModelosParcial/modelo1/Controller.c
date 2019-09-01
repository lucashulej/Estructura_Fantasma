#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Ventas.h"
#include "Controller.h"
#include "Parser.h"
int controller_loadFromText(char* path, LinkedList* this)
{
    int retorno=0;
    FILE *pFile=NULL;
    if(path!=NULL && this!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(parser_ventaFromText(pFile,this))
            {
                retorno=1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int controller_writeText(char* path, LinkedList* this,int totalEntregas,int totalP,int totalG,int totalR,int totalBultos,float promedio1,float promedio2)
{
    int retorno=0;
    FILE *pFile=NULL;
    if(path!=NULL && this!=NULL)
    {
        pFile = fopen(path,"w");
        if(pFile!=NULL)
        {
            fprintf(pFile,"********************\nInforme de ventas\n********************\n");
            fprintf(pFile,"- Cantidad total de entregas: %d\n",totalEntregas);
            fprintf(pFile,"- Cantidad de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n",totalG,totalR,totalP);
            fprintf(pFile,"- Cantidad total de bultos entregados: %d\n",totalBultos);
            fprintf(pFile,"- Promedio de bultos por entrega: %d\n",totalBultos);
            fprintf(pFile,"- Promedio de bultos por entrega: %.2f\n",promedio1);
            fprintf(pFile,"- Importe promedio por entrega: %.2f\n********************\n",promedio2);
            retorno=1;
        }
        fclose(pFile);
    }
    return retorno;
}
