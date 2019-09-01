#include <stdio.h>
#include <stdlib.h>
#include "Ventas.h"
int controller_loadFromText(char* path, LinkedList* this);
int controller_writeText(char* path, LinkedList* this,int totalEntregas,int totalP,int totalG,int totalR,int totalBultos,float promedio1,float promedio2);
