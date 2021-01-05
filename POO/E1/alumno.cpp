#include "alumno.h"

void Alumno::setName(string n){
    nombre = n;
}

void Alumno::setCode(int c){
    codigo = c;
}

void Alumno::setProm(float p){
    promedio = p;
}

string Alumno::getName(){
    return nombre;
}

int Alumno::getCode(){
    return codigo;
}

float Alumno::getProm(){
    return promedio;
}