#include <iostream>
using namespace std;

class Persona{
    private:
        string nombre;
        int edad;
        int anio, mes, dia;
        int id;
    public:
        void setNombre(string name);
        void setEdad(int age);
        void setFechaNacimiento(int day, int month, int year);
        void setId(int id1);

        string getNombre();
        int getEdad();
        string getNacimiento();
        int getId();
};
