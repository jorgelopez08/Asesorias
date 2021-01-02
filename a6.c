/*
   SeisOcho
   Actividad 6
   a6pro3520a
   TiempoTraduccion=03:45
*/
#include <stdio.h>
#include <stdlib.h>
// Los porcentajes a considerar para la evaluación del curso 
#define PORCENTAJE_TAREAS 7
#define PORCENTAJE_ACTIVIDADES 63
#define PORCENTAJE_EXAMENES_PARCIALES 30
//Declaración y definición de constantes 
#define MAX_ASISTENCIA 34
#define RETARDOS_POR_FALTA 3
#define MAX_TAREAS 10
#define MAX_EXAMENES 3
#define MAX_ACTIVIDADES 9
#define MAX_NOMBRE_MATERIA 20
#define MAX_NOMBRE_ACRONIMO 20
#define MAX_DIAS_CLASE 3
#define TITULO_PROGRAMA "\t\tEvaluador del Curso v1.0"
#define C_100 100
#define C_0 0
#define C_1 1

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
// Declaración y definición por defecto de variables (a usar para entrada de datos) 
typedef struct
{
    char materia[MAX_NOMBRE_MATERIA],acronimo[MAX_NOMBRE_ACRONIMO],dia[MAX_DIAS_CLASE];
    int horaInicnio,horaFin,tarea;
    float actividades[MAX_ACTIVIDADES],examenes[MAX_EXAMENES];
    float totalAsistencia;
}Evaluacion;
typedef struct
{
    int falta,retardo;
}Faltas;
Faltas faltas;
Evaluacion evaluacion;
void capturaMaterias();
void capturaAsistencias();
void capturaEvaluacion();
float evaluacionFaltas(int falta,int retardo);
float evaluacionExamen(float calificaciones[]);
float evaluacionAct(float calificaciones[]);
float evaluacionTarea(int tarea);
float evaluacionFinal(float act, float tarea, float examen);
void mostrarDatos();
void mostrarResultados();


int main(){
    printf("%s\n\n",TITULO_PROGRAMA);
    //Entrada de datos 
    capturaMaterias();
    capturaAsistencias();
    capturaEvaluacion();
    system(CLEAR);
    //Salida de datos
    mostrarDatos();
    mostrarResultados();
    printf("\nPresione entrar para terminar...\n");
    getchar();
    getchar();
    return 0;
}


void capturaMaterias()
{
    printf("Ingrese el nombre de la materia a evaluar: ");
    scanf("%s",&evaluacion.materia);
    printf("Ingrese el acr%cnimo de la materia: ",162);
    scanf("%s",&evaluacion.acronimo);
    printf("Ingrese los d%cas de la clase: ",161);
    scanf("%s",&evaluacion.dia);
    printf("Ingrese la hora de inicio de la clase: ");
    scanf("%d",&evaluacion.horaInicnio);
    printf("Ingrese la hora de fin de la clase: ");
    scanf("%d",&evaluacion.horaFin);
}
void capturaAsistencias()
{
    printf("Cu%cntas faltas acumulaste? ",160);
    scanf("%d",&faltas.falta);
    printf("Cu%cntos retardos acumulaste? ",160);
    scanf("%d",&faltas.retardo);
    ;
}
void capturaEvaluacion()
{
    int j,i,sumaActividad,sumaExamen;
    do{
        printf("Cu%cntas tareas realizaste? ",160);
        scanf("%d",&evaluacion.tarea);
        j=C_1;
        if(evaluacion.tarea<C_0||evaluacion.tarea>MAX_TAREAS){
            printf("Ingrese de nuevo cuantas tareas realizaste: ");
            scanf("%d",&evaluacion.tarea);
        }
        else{
            j=C_0;
        }
    }while (j);
    for(i=C_0;i<MAX_ACTIVIDADES;i++){
        printf("Cu%cnto obtuviste en la actividad %d? ",160,i+1);
        scanf("%f",&evaluacion.actividades[i]);
        j=C_1;
        do{
            if (evaluacion.actividades[i]<C_0||evaluacion.actividades[i]>C_100){
                printf("Ingrese de nuevo lo obtuvido en la actividad %d: ",i+1);
                scanf("%f",&evaluacion.actividades[i]);
            }
            else{
                j=C_0;
            }
        }while(j);
    }
    for(i=C_0;i<MAX_EXAMENES;i++){
        do{
            printf("Cu%cnto obtuviste en el examen parcial %d? ",160,i+1);
            scanf("%f",&evaluacion.examenes[i]);
            j=C_1;
            if (evaluacion.examenes[i]<C_0||evaluacion.examenes[i]>C_100){
                printf("Ingrese de nuevo lo obtuvido en en examen %d: ",i+1);
                scanf("%f",&evaluacion.examenes[i]);
            }
            else{
                j=C_0;
            }
        }while (j);
    }
}

float evaluacionFaltas(int falta,int retardo)
{//Declaración de variables (para cómputo) 
    float porcentajeAsistencia,numRetardoFalta;
    //Cómputo de Asistencias 
    numRetardoFalta=retardo/RETARDOS_POR_FALTA;
    evaluacion.totalAsistencia=MAX_ASISTENCIA-falta-numRetardoFalta;
    porcentajeAsistencia=(evaluacion.totalAsistencia/MAX_ASISTENCIA)*C_100;
    return porcentajeAsistencia;
}
float evaluacionExamen(float calificaciones[])
{//Declaración de variables (para cómputo) 
    float totalExamen,sumaExamen;
    sumaExamen=0;
    //Cómputo de Exámenes Parciales
    for(int i=C_0;i<MAX_EXAMENES;i++){
        sumaExamen+=calificaciones[i];
    }
    totalExamen=(sumaExamen*PORCENTAJE_EXAMENES_PARCIALES)/(MAX_EXAMENES*C_100);
    return totalExamen;
}
float evaluacionAct(float calificaciones[])
{//Declaración de variables (para cómputo) 
    float totalActividad,sumaActividad;
    //Cómputo de Actividades
    for(int i=C_0;i<MAX_ACTIVIDADES;i++)
    {
        sumaActividad+=calificaciones[i];
    }
    totalActividad=(sumaActividad*PORCENTAJE_ACTIVIDADES)/(MAX_ACTIVIDADES*C_100);
    return totalActividad;
}
float evaluacionTarea(int tarea)
{//Declaración de variables (para cómputo) 
    float totalTarea;
    //Cómputo de Tareas
    totalTarea=(tarea*PORCENTAJE_TAREAS)/MAX_TAREAS;
    return totalTarea;
}
float evaluacionFinal(float act, float tarea, float examen)
{//Declaración de variables (para cómputo) 
    float caliFinal;
    //Cómputo de Puntos Finales
    caliFinal=act+tarea+examen;
    return caliFinal;
}


void mostrarDatos()
{
    int i;
    printf("Evaluador del Curso v1.0 - %s (%s) ",evaluacion.materia,evaluacion.acronimo);
    printf("%s %da%d\n\n",evaluacion.dia,evaluacion.horaInicnio,evaluacion.horaFin);
    printf("Cu%cntas faltas acumulaste: %.0f\n",160,faltas.falta);
    printf("Cu%cntos retardos acumulaste: %.0f\n",160,faltas.retardo);
    printf("Cu%cntas tareas realizaste: %.0f\n",160,evaluacion.tarea);
    for (i=C_0;i<MAX_ACTIVIDADES; i++)
    {
        printf("Cu%cnto obtuviste en la actividad %d: %.0f\n",160,i+C_1,evaluacion.actividades[i]);
    }
    for (i=C_0;i<MAX_EXAMENES; i++)
    {
         printf("Cu%cnto obtuviste en el examen parcial %d: %.0f\n",160,i+C_1,evaluacion.examenes[i]);
    }
}
void mostrarResultados()
{
    float tarea,actividades,examenes,porcentajeAsistencias,calificacionFinal;
    tarea=evaluacionTarea(evaluacion.tarea);
    actividades=evaluacionAct(evaluacion.actividades);
    examenes=evaluacionExamen(evaluacion.examenes);
    porcentajeAsistencias=evaluacionFaltas(faltas.falta,faltas.retardo);
    calificacionFinal=evaluacionFinal(actividades,tarea,examenes);
    printf("Tareas     Actividades     Ex%cmenes\n",160);
    printf("%.2f       %.2f            %.2f\n",tarea,actividades,examenes);
    printf("Total de asistencias=        %.0f\n",evaluacion.totalAsistencia);
    printf("Porcentaje de asistencias=   %.2f\n",porcentajeAsistencias);
    printf("Calificaci%cn final=          %.2f\n",162,calificacionFinal);
}
