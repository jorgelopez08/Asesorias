#include <iostream>
using namespace std;

class Alumno{
    private:
        string nombre;
        int codigo;
        float promedio;
    public:
        void setName(string n);
        void setCode(int c);
        void setProm(float p);

        string getName();
        int getCode();
        float getProm();
};