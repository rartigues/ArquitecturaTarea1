#include <stdio.h>
#include <stdlib.h>

typedef unsigned datetime;


datetime save_datetime(unsigned minute, unsigned hour, unsigned day, unsigned month,unsigned year);
void print_datetime(unsigned datetime);

int main(int argc, char *argv[]) {
    unsigned minute, hour, day, month, year;
    printf("Ingrese la hora (hh mm): ");
    scanf("%u %u", &hour, &minute);
    printf("Ingrese la fecha (dd mm yyyy): ");
    scanf("%u %u %u", &day, &month, &year);

    datetime savedDateTime = save_datetime(minute, hour, day, month, year);
    print_datetime(savedDateTime);

    return 0;
}


// Se decidio cambiar el tipo de retorno de void a datetime (otra opcion era usar una variable global)
datetime save_datetime(unsigned minute, unsigned hour, unsigned day, unsigned month,unsigned year){
    datetime datetime;
    datetime = minute;
    datetime |= hour << 6;
    datetime |= day << 11;
    datetime |= month << 16;
    datetime |= year << 20;

    return datetime;
}

void print_datetime(unsigned datetime){
    unsigned minute, hour, day, month, year;
    minute = datetime & 0x3F;
    hour = (datetime >> 6) & 0x1F;
    day = (datetime >> 11) & 0x1F;
    month = (datetime >> 16) & 0x0F;
    year = (datetime >> 20) & 0xFFF;
    
    printf("%d-%d-%d;%d:%d \n", year, month, day, hour, minute);
}