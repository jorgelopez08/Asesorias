#include "persona.h"
void Persona::setNombre(string name){
    nombre = name;
}

void Persona::setEdad(int age){
    edad = age;
}

void Persona::setFechaNacimiento(int day, int month, int year){
    anio = year;
    mes = month;
    dia = day;
}

void Persona::setId(int id1){
    id = id1;
}

string Persona::getNombre(){
    return nombre;
}

int Persona::getEdad(){
    return edad;
}

string Persona::getNacimiento(){
    string fecha;
    fecha += to_string(dia);
    fecha += "/";
    fecha += to_string(mes);
    fecha += "/";
    fecha += to_string(anio);
    return fecha;
}

int Persona::getId(){
    return id;
}