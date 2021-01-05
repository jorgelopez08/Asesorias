#include "alumno.h"

bool menuPrincipal();
void menuAgregar();
void menuMostrar();
int numAlumno;

int main(int argc, char const *argv[])
{
    Alumno alumno[10];
    int menu;
    
    
    return 0;
}

bool menuPrincipal(){
    int opc;
    bool repeat;
    cout<<"1. Agregar alumno"<<endl<<"2. Mostrar alumno"<<endl<<"3. Salir"<<endl<<"Seleccione una opcion: ";
    cin>>opc;
    switch (opc)
    {
    case 1:
        menuAgregar();
        break;
    case 2:
        menuMostrar();
        break;
    case 3:
        repeat = false;
    default:
        break;
    }
    return true;
}
void menuAgregar(){
    string nombre;
    int codigo;
    float prom;
    cout<<"Ingresa el nombre del alumnno "<<numAlumno+1<<": ";
    cin>>nombre;
    cout<<"Ingresa el codigo del alumnno "<<numAlumno+1<<": ";
    cin>>codigo;
    cout<<"Ingresa el promedio del alumnno "<<numAlumno+1<<": ";
    cin>>prom;
    alumno[numAlumno].
}