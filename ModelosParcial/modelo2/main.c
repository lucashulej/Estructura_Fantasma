#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {
        if(controller_loadFromText("data.csv",listaEmpleados))
        {
            ll_map(listaEmpleados,calculaSueldo);
            controller_writeText("sueldos.csv",listaEmpleados);
            printf("ESTA TODO DE FIESTA\n");
        }
    }
    return 0;
}
