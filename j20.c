/*
    SeisOcho
    Ejercicio 20
    j20pro3520a
    Tiempo=01:12
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numMes,dia;
    char mes[11],estacion[11];
    printf("Ingrese el número del mes: ");
    scanf("%d",&numMes);
    printf("Ingrese el número del día: ");
    scanf("%d",&dia);
    if((dia>= 1 && dia<=31)&&(numMes>=1 && numMes<=12)){
    switch (numMes)
    {
        case 1:
            strcpy(mes,"enero");
            strcpy(estacion,"invierno");
            break;
        case 2:
            strcpy(mes,"febrero");
            strcpy(estacion,"invierno");
            break;
        case 3:
            strcpy(mes,"marzo");
            if (dia>20)
            {
                strcpy(estacion,"primavera");
            }
            else
            {
                strcpy(estacion,"invierno");
            }
            break;
        case 4:
            strcpy(mes,"abril");
            strcpy(estacion,"primavera");
            break;
        case 5:
            strcpy(mes,"mayo");
            strcpy(estacion,"primavera");
            break;
        case 6:
            strcpy(mes,"junio");
            if (dia>21)
            {
                strcpy(estacion,"verano");
            }
            else
            {
                strcpy(estacion,"primavera");
            }
            break;
        case 7:
            strcpy(mes,"julio");
            strcpy(estacion,"verano");
            break;
        case 8:
            strcpy(mes,"agosto");
            strcpy(estacion,"verano");
            break;
        case 9:
            strcpy(mes,"septiembre");
            if (dia>21)
            {
                strcpy(estacion,"otoño");
            }
            else
            {
                strcpy(estacion,"verano");
            }
            break;
        case 10:
            strcpy(mes,"octubre");
            strcpy(estacion,"otoño");
            break;
        case 11:
            strcpy(mes,"noviembre");
            strcpy(estacion,"otoño");
            break;
        case 12:
            strcpy(mes,"diciembre");
            if (dia>20)
            {
                strcpy(estacion,"invierno");
            }
            else
            {
                strcpy(estacion,"otoño");
            }
            break;
        default:
            break;
        }
    printf("\nEl mes es %s y la estación es %s\n",mes,estacion);
    }
    else
    {
        printf("Fecha no valida\n");
    }
    getchar();
    return 0;
}
