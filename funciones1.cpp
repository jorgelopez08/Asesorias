#include <iostream>
using namespace std;

/* void verObjetos(); */
float pagar(int descuento, float precio, float pago);

int main(int argc, char const *argv[])
{
    float precio, pago, cambio;
    cout<<"Precio: ";
    cin>>precio;
    cout<<"pago: ";
    cin>>pago;
    
    cambio = pagar(10, precio, pago);
    cout<<"Tu cambio fue de : "<<cambio<<endl;
    cout<<"Tu cambio fue de : "<<pagar(10,precio, pago);
    return 0;
}

float pagar(int descuento, float precio, float pago){
    float precioFinal;

    precioFinal = precio - ((precio * descuento)/100);
    
    return pago - precioFinal;
}

