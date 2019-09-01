#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
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
            if(parser_empleadoFromText(pFile,this))
            {
                retorno=1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int controller_writeText(char* path,LinkedList* this)
{
    int retorno=0;
    FILE *pFile=NULL;
    int i;
    void* elemento;
    Empleado* empleado;
    int id;
    char nombre[20];
    int horas;
    float sueldo;
    if(path!=NULL && this!=NULL)
    {
        pFile = fopen(path,"w");
        if(pFile!=NULL)
        {
            fprintf(pFile,"ID,NOMBRE,HORAS,SUELDO\n");
            for(i=0;i<ll_len(this);i++)
            {
                elemento=ll_get(this,i);
                if(elemento!=NULL)
                {
                    empleado = (Empleado*) elemento;
                    if(getId(empleado,&id)&&getNombre(empleado,nombre)&&getHoras(empleado,&horas)&&getSueldo(empleado,&sueldo))
                    {
                        fprintf(pFile,"%d,%s,%d,%.2f\n",id,nombre,horas,sueldo);
                    }
                }
           }
        retorno=1;
        }
        fclose(pFile);
    }
    return retorno;
}
