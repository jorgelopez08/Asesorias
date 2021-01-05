/*
    SeisOcho
    Práctica 3
    p3pro3520a
    TiempoTraduccion=02:324
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

//Declaración y definición de constantes simbolicas
#define IVA 16
#define RIVA 10
#define RISR 10
#define CAPTURA_MES 1
#define CAPTURA_INGRESO 2
#define CAPTURA_GASTO 3
#define MOSTRAR_INGRESO 4
#define MOSTRAR_GASTOS 5
#define CALCULO_IMPUESTOS 6
#define SALIR 8
#define TOTAL_MESES 12
//Variables de uso interno del programa
int mesCaptura;
char* meses[12];
//Declaración de variables para cómputo
float ingresoTotal,gastoTotal,gastoIva,subtotal,total,gananciaNeta,manejoIsr,isrPagar;
float ivaPagar,retencionIsr,retencionIva,gananciaBruta,manejoIva;
int ISR[3];
float vectorMontos[3][2];
//Variables de programa modificables por el usuario
float ingresos[TOTAL_MESES]={},gastos[TOTAL_MESES]={};

void pausar();
int menuPrincipal();
void mesDeCaptura();
void capturaIngreso();
void capturaGasto();
void mostrarIngresos();
void mostrarGastos();
void calcularImpuestos();
int calculoIsr();
void mostrarImpuestos();
int inicializacionVariables();
int main()
{
    //Variables de uso interno del programa
    int repetir;
    repetir=inicializacionVariables();
    do
    {
        system(CLEAR);
        switch (menuPrincipal())
        {
        case CAPTURA_MES:
            mesDeCaptura();
            break;
        case CAPTURA_INGRESO:
            capturaIngreso();
            break;
        case CAPTURA_GASTO:
            capturaGasto();
            break;
        case MOSTRAR_INGRESO:
            mostrarIngresos();
            break;
        case MOSTRAR_GASTOS:
            mostrarGastos();
            break;
        case CALCULO_IMPUESTOS:
            mostrarImpuestos();
            break;
        case SALIR:
            repetir=0;
            break;
        default:
            printf("Opci%cn no v%clida\n",162,160);
            break;
        }
        if (repetir)
        {
            pausar();
        }
    } while (repetir);
    return 0;
}
void pausar()
{
    printf("Presione entrar para continuar...\n");
    getchar();
    getchar();
}
int menuPrincipal()
{
    //Variables de uso interno del programa
    int menu;
    printf("C%cLCULO DE IMPUESTOS ANUAL\n\n",181);
    printf("Men%c principal: \n",163);
    printf("1. Establecer mes para captura (mes actual es %s)\n2. Captura de ingresos\n",meses[mesCaptura]);
    printf("3. Captura de gastos\n4. Mostrar lista de ingresos anual\n");
    printf("5. Mostrar lista de gastos anual\n6. C%clculo de impuestos anual\n",160);
    printf("7.Guardar en archivo\n8. Salir\n");
    printf("Opci%cn: ",162);
    scanf("%d",&menu);
    return menu;
}
void mesDeCaptura()
{
    //Variables de uso interno del programa
    int opValida;
    opValida=1;
    system(CLEAR);
    //Entrada de datos
    printf("Establecer mes para captura\n");
    printf("1) Enero\n2) Febrero\n3) Marzo\n4) Abril\n5) Mayo\n6) Junio\n7) Julio\n");
    printf("8) Agosto\n9) Septiembre\n10) Octubre\n11) Noviembre\n12) Diciembre\n");
    printf("Elige el mes (1-12): ");
    scanf("%d",&mesCaptura);
    mesCaptura--;
    do
    {
        if (mesCaptura>=0&&mesCaptura<=11)
        {
            printf("Se ha estableido el mes de captura en %s\n",meses[mesCaptura]);
            opValida=0;
        }
        else
        {
            printf("Mes no v%clido, vuelva a ingresar el mes: ",160);
            scanf("%d",&mesCaptura);
        }
    } while (opValida);
}
void capturaIngreso()
{
    //Entrada de datos
    printf("\nCaptura de ingresos\n");
    ingresoTotal-=ingresos[mesCaptura];
    printf("Dame el ingreso del mes de %s: ",meses[mesCaptura]);
    scanf("%f",&ingresos[mesCaptura]);
    ingresoTotal+=ingresos[mesCaptura];
}
void capturaGasto()
{
    //Entrada de datos
    printf("\nCaptura de gastos\n");
    gastoTotal-=gastos[mesCaptura];
    printf("Dame el gasto del mes de %s: ",meses[mesCaptura]);
    scanf("%f",&gastos[mesCaptura]);
    gastoTotal+=gastos[mesCaptura];
}
void mostrarIngresos()
{
    system(CLEAR);
    //Salida de resultados
    printf("Mostrar lista de ingresos anual\n");
    printf("Enero = %.2f\nFebrero = %.2f\n",ingresos[0],ingresos[1]);
    printf("Marzo = %.2f\nAbril = %.2f\n",ingresos[2],ingresos[3]);
    printf("Mayo = %.2f\nJunio = %.2f\n",ingresos[4],ingresos[5]);
    printf("Julio = %.2f\nAgosto = %.2f\n",ingresos[6],ingresos[7]);
    printf("Septiembre = %.2f\nOctubre = %.2f\n",ingresos[8],ingresos[9]);
    printf("Noviembre = %.2f\nDiciembre = %.2f\n",ingresos[10],ingresos[11]);
}
void mostrarGastos()
{
    system(CLEAR);
    //Salida de resultados
    printf("Mostrar lista de gastos anual\n");
    printf("Enero = %.2f\nFebrero = %.2f\n",gastos[0],gastos[1]);
    printf("Marzo = %.2f\nAbril = %.2f\n",gastos[2],gastos[3]);
    printf("Mayo = %.2f\nJunio = %.2f\n",gastos[4],gastos[5]);
    printf("Julio = %.2f\nAgosto = %.2f\n",gastos[6],gastos[7]);
    printf("Septiembre = %.2f\nOctubre = %.2f\n",gastos[8],ingresos[9]);
    printf("Noviembre = %.2f\nDiciembre = %.2f\n",gastos[10],gastos[11]);
}
void calcularImpuestos()
{
    //Cálculo de impuestos
    manejoIva = (ingresoTotal*IVA)/100;
    subtotal = manejoIva + ingresoTotal;
    retencionIsr = (ingresoTotal*RISR)/100;
    retencionIva = (ingresoTotal*RIVA)/100;
    total = subtotal - retencionIva - retencionIsr;
    gananciaBruta=ingresoTotal-gastoTotal;
    manejoIsr=(gananciaBruta*calculoIsr(gananciaBruta))/100;
    gananciaNeta=gananciaBruta-manejoIsr;
    gastoIva=(gastoTotal*IVA)/100;
    isrPagar=manejoIsr-retencionIsr;
    ivaPagar=manejoIva-gastoIva-retencionIva;  
}
int calculoIsr()
{
    if (gananciaBruta<=vectorMontos[0][1]){
        return ISR[0];
    }
    else if (gananciaBruta<=vectorMontos[1][1]){
        return ISR[1];
    }
    else if (gananciaBruta>=vectorMontos[2][0])
    {
        return ISR[2];
    }
    else
    {
        return 0;
    }
}
void mostrarImpuestos()
{
    system(CLEAR);
    int porcentajeIsr;
    calcularImpuestos();
    porcentajeIsr=calculoIsr();
    //Salida de datos
    printf("CALCULO DE IMPUESTOS\n\n");
    printf("***Tabla Recibo de Honorarios***\n");
    printf("Ingresos \t\t %10.2f\n", ingresoTotal);
    printf("(+) IVA \t\t %10.2f\n",manejoIva);
    printf("(=) Subtotal \t\t %10.2f\n", subtotal);
    printf("(-) Retenci%cn ISR \t %10.2f\n",162, retencionIsr);
    printf("(-) Retenci%cn IVA \t %10.2f\n",162, retencionIva);
    printf("(=) Total\t\t %10.2f\n", total);
    printf("***Tabla ganancias***\n");
    printf("Ingresos \t\t %10.2f\n", ingresoTotal);
    printf("(-) Gastos \t\t %10.2f\n", gastoTotal);
    printf("(=) Ganancia bruta \t %10.2f\n", gananciaBruta);
    printf("(-) ISR(%d%%) \t\t %10.2f\n",porcentajeIsr,manejoIsr);
    printf("(=) Ganancia neta \t %10.2f\n", gananciaNeta);
    printf("***Tabla ISR***\n");
    printf("ISR(%d%%) \t\t %10.2f\n",porcentajeIsr,manejoIsr);
    printf("(-) ISR retenido \t %10.2f\n",retencionIsr);
    printf("(=) ISR a Pagar \t %10.2f\n",isrPagar);
    printf("***Tabla IVA***\n");
    printf("IVA \t\t\t %10.2f\n", manejoIva);
    printf("(-) Gastos IVA \t\t %10.2f\n", gastoIva);
    printf("(-) Retenci%cn IVA \t %10.2f\n",162,retencionIva);
    printf("(=) IVA  a Pagar \t %10.2f\n",ivaPagar);
}
int inicializacionVariables()
{
    //Variables de uso interno del programa
    int repetir;
    //Inicializacion de variables
    repetir=1;
    mesCaptura=0;
    ingresoTotal=0;
    gastoTotal=0;
    meses[0]="Enero";
    meses[1]="Febrero";
    meses[2]="Marzo";
    meses[3]="Abril";
    meses[4]="Mayo";
    meses[5]="Junio";
    meses[6]="Julio";
    meses[7]="Agosto";
    meses[8]="Septiembre";
    meses[9]="Octubre";
    meses[10]="Noviembre";
    meses[11]="Diciembre";
    ISR[0]=11;
    ISR[1]=15;
    ISR[2]=20;
    vectorMontos[0][0]=0;
    vectorMontos[0][1]=10000;
    vectorMontos[1][0]=10000.01;
    vectorMontos[1][1]=20000.00;
    vectorMontos[2][0]=20000.01;
    vectorMontos[2][1]=20000.01;
    return repetir;
}