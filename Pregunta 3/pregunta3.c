#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x = 0xFA430021;
    int y = 0x3F;
    int k = 10;
    int a = x + y;
    int b = x | (y << 16);
    int c = x & (y << 24);
    int d = (x >> 6) & ~y;
    int e = (x & y) | (y << 12);
    int f = x = (y << k) | (x >> (32 - k));
    int g = x &= (x << 8);

    printf("a) %x \n", a);
    printf("b) %x \n", b);
    printf("c) %x \n", c);
    printf("d) %x \n", d);
    printf("e) %x \n", e);
    printf("f) %x \n", f);
    printf("g) %x \n", g);

    return 0;
}