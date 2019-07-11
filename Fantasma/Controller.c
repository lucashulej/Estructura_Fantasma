#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Fantasma.h"
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
            if(parser_fromText(pFile,this))
            {
                retorno=1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}
