#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int valores[10], copia[10], multiplicador;
    int comparacion;
    char* meses[12] ={"enero", } ;
    string mes, estacion;
    mes = meses[0]; 
    comparacion = 3<5;
    string nombre;
    if (comparacion)
    {
        cout<<"Hola";
    }
    
    cin>>nombre;
    cout<<nombre;
    for (int i = 0; i < 10; i++)
    {
        cout<<"Ingrese valor "<<i+1<<": ";
        cin>>valores[i];
    }
    cout<<"Ingresa un multiplicador: ";
    cin>>multiplicador;

    for (int i = 0; i < 10; i++)
    {
        copia[i]=valores[i]*multiplicador;
        cout<<"Res: "<<copia[i]<<endl;
    }
    
    
    return 0;
}
