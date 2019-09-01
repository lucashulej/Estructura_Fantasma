#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    int horas;
    float sueldo;
}Empleado;

Empleado* newEmpleado();
int deleteEmpleado(Empleado* this);
int getId(Empleado* this,int* id);
int setId(Empleado* this,int id);
int getNombre(Empleado* this,char* nombre);
int setNombre(Empleado* this,char* nombre);
int getHoras(Empleado* this,int* horas);
int setHoras(Empleado* this,int horas);
int getSueldo(Empleado* this,float* sueldo);
int setSueldo(Empleado* this,float sueldo);
int calculaSueldo(void* elemento);

#endif // EMPLEADO_H_INCLUDED
