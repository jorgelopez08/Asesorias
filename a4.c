/*
   SeisOcho
   Actividad 4
   a4pro3520a
   Tiempo=00:43
*/
#include <stdio.h>
#include <stdlib.h>

//Porcentajes a considerar para la evaluación
#define PORCENTAJE_TAREAS 7
#define PORCENTAJE_ACTIVIDADES 63
#define PORCENTAJE_EXAMENES_PARCIALES 30
//Declaración y definición de constantes
#define MAX_ASISTENCIA 34
#define RETARDOS_POR_FALTA 3
#define MAX_TAREAS 10
#define MAX_EXAMENES 3
#define MAX_ACTIVIDADES 9
#define C_100 100


int main()
{
    //Declaración y definición por defecto de variables
    float actividad,examen,tareas,faltas,retardos;
    //Declaración de variables para cómputo
    int i;
    float numRetardoFalta,sumaExamen,sumaActividad;
    float totalAsistencias,totalActividad,totalTarea,totalExamen;
    float porcentajeAsistencias,calificacionFinal;
    printf("Evaluador del Curso de Programación v1.0\n\n");
    //Entrada de datos
    printf("Cuántas faltas acumulaste? ");
    scanf("%f",&faltas);
    printf("Cuántos retardos acumulaste? ");
    scanf("%f",&retardos);
    printf("Cuántas tareas realizaste? ");
    scanf("%f",&tareas);
    sumaActividad=0;
    for(i=1;i<=MAX_ACTIVIDADES;i++){
        printf("Cuánto obtuviste en la actividad %d? ",i);
        scanf("%f",&actividad);
        sumaActividad=actividad+sumaActividad;
    }
    sumaExamen=0;
    for(i=1;i<=MAX_EXAMENES;i++){
        printf("Cu�nto obtuviste en el examen parcial %d? ",i);
        scanf("%f",&examen);
        sumaExamen=sumaExamen+examen;
    }
    //Cómputo de Asistencias
    numRetardoFalta=retardos/RETARDOS_POR_FALTA;
    totalAsistencias=MAX_ASISTENCIA-faltas-numRetardoFalta;
    porcentajeAsistencias=(totalAsistencias/MAX_ASISTENCIA)*C_100;
    //Cómputo de Tareas
    totalTarea=(tareas*PORCENTAJE_TAREAS)/MAX_TAREAS;
    //Cómputo de Actividades
    totalActividad=(sumaActividad*PORCENTAJE_ACTIVIDADES)/(MAX_ACTIVIDADES*C_100);
    //Cómputo de Ex�menes Parciales
    totalExamen=(sumaExamen*PORCENTAJE_EXAMENES_PARCIALES)/(MAX_EXAMENES*C_100);
    //Cómputo de Puntos Finales
    calificacionFinal=totalTarea+totalActividad+totalExamen;
    //Salida de datos
    printf("Tareas     Actividades     Exámenes\n");
    printf(" %.2f       %.2f           %.2f\n", totalTarea,totalActividad,totalExamen);
    printf("Total de asistencias=       %.2f\n",totalAsistencias);
    printf("Porcentaje de asistencias=  %.2f\n",porcentajeAsistencias);
    printf("Calificación Final=         %.2f\n",calificacionFinal);
    printf("\nPresione entrar para terminar...\n");
    getchar();
    return 0;
}
