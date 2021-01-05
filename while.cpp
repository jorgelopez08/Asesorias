#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int opc, a, b, res, j=0;
    bool repetir = true;
    /* while(repetir){
        printf("1. suma\n2. resta\n3. salir\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            a=5;
            b=15;
            res= a+b;
            printf("resultado: %d\n", res);
            break;
        case 2:
            a=51;
            b=15;
            res= a-b;
            printf("resultado: %d\n", res);
        case 3:
            repetir = false;
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } */
    
    while (j<5)
    {
        cout<<"ejecucion "<<1 + j++<<endl;
    }
    
    
    return 0;
}
