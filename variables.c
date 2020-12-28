#include <stdio.h>
#define IVA 16
int main(int argc, char const *argv[])
{
    int i, j,calificacion, calificiacionAct;
    float promedio;
    char* mes[12] = {"Enero", "Febrero", "Marzo"};
    char caracter = 'a';
    char cadena[10];
    i=0;
    j=5;
    calificacion = 10; //hardcodear Y definiar
    printf("%d\n", calificacion);
    /* scanf("%d", &calificacion); */
    printf("%d\n", calificacion);
    calificacion = (calificacion * 5) + 5 - 15;
    printf("%d\n", calificacion);

    printf("var %d %d\n", ++i, j);
    for (i ; i < j; i++)
    {
        if (i==3 || j!=7)
        {
            printf("Hola\n");
        }
        i==3?printf("Si es 3\n"):printf("No es 3\n");
        printf("var %d %d\n",i, j);
    }
    
    printf("%s", mes[1]);
    return 0;
}
