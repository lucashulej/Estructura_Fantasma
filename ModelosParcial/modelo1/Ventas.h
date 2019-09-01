#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct
{
    int id;
    char tipo[20];
    int cantidad;
    float importe;
}Venta;

Venta* newVenta();
int deleteVenta(Venta* this);
int getId(Venta* this,int* id);
int setId(Venta* this,int id);
int getTipo(Venta* this,char* tipo);
int setTipo(Venta* this,char* tipo);
int getCantidad(Venta* this,int* cantidad);
int setCantidad(Venta* this,int cantidad);
int getImporte(Venta* this,float* importe);
int setImporte(Venta* this,float importe);
int tipoG(void* this);
int tipoR(void* this);
int tipoP(void* this);
int contadorBultos(void* this);
float contadorImporte(void* this);

#endif // VENTAS_H_INCLUDED
