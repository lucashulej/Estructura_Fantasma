#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Empleado.h"
#include "Parser.h"
int parser_empleadoFromText(FILE* pFile, LinkedList* this)
{
    int retorno=0;
    char auxId[10];
    char auxNombre[20];
    char auxHoras[10];
    Empleado auxEmpleado;
    Empleado* empleado=NULL;
    int flag=0;
    if(pFile!=NULL&&this!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras);
            if(flag==0)
            {
                flag=1;
                continue;
            }
            printf("%s",auxId);
            empleado=newEmpleado();
            if(empleado!=NULL)
            {
                if(isValidInter(auxId)&&isValidName(auxNombre)&&isValidInter(auxHoras))
                {

                    auxEmpleado.id=atoi(auxId);
                    strcpy(auxEmpleado.nombre,auxNombre);
                    auxEmpleado.horas=atoi(auxHoras);

                    if(setId(empleado,auxEmpleado.id)&&setNombre(empleado,auxEmpleado.nombre)&&setHoras(empleado,auxEmpleado.horas))
                    {
                        ll_add(this,empleado);
                    }
                    else
                    {
                        deleteEmpleado(empleado);
                    }
                    retorno=1;
                }
            }

        }
    }
    return retorno;
}

int parser_writeInfo(char* fileName,int totalEntregas,int nombreG,int nombreR,int nombreP,int totalBultos,float promedioBultos,float promedioImporte)
{
    int retorno=0;
    FILE* pFile=NULL;
    if(fileName!=NULL && totalEntregas>0 && totalEntregas>0 && nombreG>0 && nombreR>0 && nombreP>0 && totalBultos>0 && promedioBultos>0 && promedioImporte)
    {
        pFile=fopen(fileName,"w");
        if(pFile!=NULL)
        {
            retorno=1;
            fprintf(pFile,"********************\nInforme de ventas\n********************\n");
            fprintf(pFile,"- Horas total de entregas: %d\n",totalEntregas);
            fprintf(pFile,"- Horas de entregas por nombre: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n",nombreG,nombreR,nombreP);
            fprintf(pFile,"- Horas total de bultos entregados: %d\n",totalBultos);
            fprintf(pFile,"- Promedio de bultos por entrega: %.2f\n",promedioBultos);
            fprintf(pFile,"- Importe promedio por entrega: %.2f\n",promedioImporte);
            fprintf(pFile,"********************\n");
        }
        fclose(pFile);
    }
    return retorno;
}

