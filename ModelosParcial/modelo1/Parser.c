#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Ventas.h"
#include "Parser.h"
int parser_ventaFromText(FILE* pFile, LinkedList* this)
{
    int retorno=0;
    char auxId[10];
    char auxTipo[20];
    char auxCantidad[10];
    char auxImporte[10];
    Venta auxVenta;
    Venta* venta=NULL;
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
            venta=newVenta();
            if(venta!=NULL)
            {
                if(isValidInter(auxId)&&isValidInter(auxCantidad)&&isValidFloat(auxImporte))
                {

                    auxVenta.id=atoi(auxId);
                    strcpy(auxVenta.tipo,auxTipo);
                    auxVenta.cantidad=atoi(auxCantidad);
                    auxVenta.importe=atof(auxImporte);

                    if(setId(venta,auxVenta.id)&&setTipo(venta,auxVenta.tipo)&&setCantidad(venta,auxVenta.cantidad)&&setImporte(venta,auxVenta.importe))
                    {
                        ll_add(this,venta);
                    }
                    else
                    {
                        deleteVenta(venta);
                    }

                    retorno=1;
                }
            }
        }
    }
    return retorno;
}

