#include <stdio.h>
#include <stdlib.h>

unsigned rotate_left();

int main(){
    //obtener el numero hexadecimal
    unsigned int number;
    printf("Inserte el numero hexadecimal: ");
    scanf("%x", &number);
    //obtener bits a rotar
    unsigned int bits;
    printf("Ingrese la cantidad de bits a rotar ('n'): ");
    scanf("%d", &bits);
    //llamamos a la funcion rotar izquierda
    unsigned int rotated = rotate_left(number, bits);
    //imprimimos el resultado
    printf("El resultado es: %#010x", rotated);
}

unsigned rotate_left(unsigned x, int n){
    //obtenemos el largo del numero
    int bits = sizeof(x) * 8;
    //guardamos los bits que se van a perder
    unsigned int bits_to_rotate = x >> (bits - n);
    //rotamos los bits
    unsigned int rotated = x << n;
    //agregamos los bits que se perdieron
    rotated = rotated | bits_to_rotate;
    return rotated;
}