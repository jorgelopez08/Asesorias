#include "persona.cpp"

int main(){
    Persona persona[3];
    int numPer, aux, mes, dia, anio;
    char aux1[100];
    numPer = 0;
    cout<<"Ingrese nombre: ";
    fgets(aux1, 100, stdin);
    persona[numPer].setNombre(aux1);
    cout<<"Ingrese edad: ";
    cin>>aux;
    persona[numPer].setEdad(aux);
    cout<<"Ingrese mes: ";
    cin>>mes;
    cout<<"Ingrese anio: ";
    cin>>anio;
    cout<<"Ingrese dia: ";
    cin>>dia;
    persona[numPer].setFechaNacimiento(dia,mes, anio);
    cout<<"Ingrese id: ";
    cin>>aux;
    persona[numPer++].setId(aux);

    for (int i = 0; i < numPer; i++)
    {
        cout<<"Nombre: "<<persona[i].getNombre();
        cout<<"Edad: "<<persona[i].getEdad()<<endl;
        cout<<"Fecha de nacimiento: "<<persona[i].getNacimiento()<<endl;
        cout<<"Id: "<<persona[i].getId()<<endl;
    }
    
    return 0;
}