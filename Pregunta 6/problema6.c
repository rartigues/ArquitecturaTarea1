#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_windows;

int andAB();
int xorAB();
int notA();
int64_t numeroRango(int64_t A, unsigned char s, unsigned char e);
int numeroDe1s();
void clean_screen();
void checkOS();

int main(){
    int A, B,opcion;
    int64_t A64;
    unsigned char s, e;
    checkOS();
    clean_screen();
    while(0==0){ 
        printf("\n1. andAB\n2. xorAB\n3. notA\n4. numeroRango\n5. numeroDe1s\n6. Salir\n");
        printf("Ingrese la opcion que desea ejecutar: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Ingrese el valor de A: ");
                scanf("%d", &A);
                printf("Ingrese el valor de B: ");
                scanf("%d", &B);
                clean_screen();
                printf("El resultado es: %d\nSeleccione funcion a ejecutar", andAB(A, B));
                break;
            case 2:
                printf("Ingrese el valor de A: ");
                scanf("%d", &A);
                printf("Ingrese el valor de B: ");
                scanf("%d", &B);
                clean_screen();
                printf("El resultado es: %d\nSeleccione funcion a ejecutar", xorAB(A, B));
                break;
            case 3:
                printf("Ingrese el valor de A: ");
                scanf("%d", &A);
                clean_screen();
                printf("El resultado es: %d\nSeleccione funcion a ejecutar", notA(A));
                break;
            case 4:
                printf("Ingrese el valor de A: ");
                scanf("%ld", &A64);
                printf("Ingrese el valor de s: ");
                scanf("%hhu", &s);
                printf("Ingrese el valor de e: ");
                scanf("%hhu", &e);
                clean_screen();
                printf("El resultado es: %ld\nSeleccione funcion a ejecutar", numeroRango(A64, s, e));
                break;
            case 5:
                printf("Ingrese el valor de A: ");
                scanf("%d", &A);
                clean_screen();
                printf("El resultado es: %d\nSeleccione funcion a ejecutar", numeroDe1s(A));
                break;
            case 6:
                printf("Saliendo...");
                return 0;
            default:
                printf("Opcion no valida");
                clean_screen();
                break;
        }
    };
    return 0;
}

int andAB(int a, int b){
    int ayb;
    ayb= ~(~a | ~b);
    return ayb;
}
int xorAB(int a, int b){
    int xorab;
    xorab=(~(~a&~b)&~(a&b));
    return xorab;
}
int notA(int a){
    int notA;
    notA= (a^(-1));
    notA= notA+1;
    return notA;
}

int64_t numeroRango(int64_t A, unsigned char s, unsigned char e){
    int64_t numero;
    int64_t mask;

    mask= 1;
    mask= mask << (e-s+1);
    mask= mask -1;
    mask= mask << s;
    numero= A & mask;
    numero= numero >> s;
    return numero;
}
int numeroDe1s(int A){
    int count=0;
    while (A > 0){ 
        count = count + 1;
        A = A & (A-1);
    };
    return count;
}

void clean_screen(){
    if(is_windows){
        system("cls");
    }else{
        system("clear");
    }
}
void checkOS(){
    #ifdef _WIN32
        is_windows = true;
    #else
        is_windows = false;
    #endif
}