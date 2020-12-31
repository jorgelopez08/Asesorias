#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nombre[40];
    int codigo;
    float promedio;
}Alumno;

int main(int argc, char const *argv[])
{
    Alumno alumnos[10];
    int opc,repetir = 1, j=0, i;
    do
    {
        printf("1. Ingresar alumno\n2. Mostrar alumnos\n3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            if (j!=11)
            {
                printf("Alumno no.%d\n", j+1);
                printf("Ingrese el nombre: ");
                getchar();
                fgets(alumnos[j].nombre, 40, stdin);
                printf("Ingrese codigo: ");
                scanf("%d", &alumnos[j].codigo);
                printf("Ingrese promedio: ");
                scanf("%f", &alumnos[j].promedio);
                j++;
            }else{
                printf("No se puede ingresar otro alumno\n");
            }
            break;
        case 2:
            i=0;
            if (j!=0)
            {
                while (i<j)
                {
                    printf("Nombre: %s", alumnos[i].nombre);
                    printf("Codigo: %d\n", alumnos[i].codigo);
                    printf("Promedio: %.2f\n\n", alumnos[i++].promedio);
                }
            }
            break;
        case 3:
            repetir=0;
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (repetir);
    
    return 0;
}
