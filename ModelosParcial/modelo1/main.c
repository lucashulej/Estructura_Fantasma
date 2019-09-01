#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Ventas.h"
#include "Parser.h"
#include "Controller.h"
int main()
{
    LinkedList* listaVentas = ll_newLinkedList();
    int totalEntregas=0;
    int totalP=0;
    int totalG=0;
    int totalR=0;
    int totalBultos=0;
    float promedio1=0;
    float totalImporte=0;
    float promedio2=0;

    if(listaVentas!=NULL)
    {
        if(controller_loadFromText("data.csv",listaVentas))
        {
            totalEntregas=ll_len(listaVentas);
            ll_count(listaVentas,tipoG,&totalG);
            ll_count(listaVentas,tipoP,&totalP);
            ll_count(listaVentas,tipoR,&totalR);
            ll_countInt(listaVentas,contadorBultos,&totalBultos);
            promedio1 = (float)totalBultos/totalEntregas;
            ll_countFloat(listaVentas,contadorImporte,&totalImporte);
            promedio2 = totalImporte/totalEntregas;
            controller_writeText("informes.txt",listaVentas,totalEntregas,totalP,totalG,totalR,totalBultos,promedio1,promedio2);
            printf("TODO DE FIESTA\n");
        }
    }
    return 0;
}
