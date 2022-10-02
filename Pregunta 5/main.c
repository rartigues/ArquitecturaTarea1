/**
 * Se define el tipo de datodatetimeque maneja la fecha y la hora almacenados en 32 bits.
 * Su declaración es la siguiente:typedef unsigned datetime;
 * Para ello, utiliza cada bit con la siguiente distribución (numerados desde el bit menos significativo almás significativo):
 * 0-5: 6 bits : minutos
 * 6-10: 5 bits: hora
 * 11-15: 5 bits: día del mes
 * 16-19: 4 bits: mes
 * 20-31: 12 bits: año
 * 
 * Implemente una función que permita almacenar los datos de la estructura, 
 * y una función que le permita mostrar por pantalla el contenido de la estructura. 
 * Utilice los siguientes prototipos:
 * // Asuma que todos los valores son válidos
 * void save_datetime(unsigned minute, unsigned hour, unsigned day, unsigned month,unsigned year);
 * 
 * // Utilice el formato yyyy-MM-DD;HH:mm
 * void print_datetime(unsigned datetime);
 * 
 *
 * **/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned datetime;

// Asuma que todos los valores son válidos
void save_datetime(unsigned minute, unsigned hour, unsigned day, unsigned month,unsigned year);
// Utilice el formato yyyy-MM-DD;HH:mm
void print_datetime(unsigned datetime);

int main(int argc, char *argv[]) {
    unsigned minute, hour, day, month, year;
    printf("Ingrese la fecha y hora: ");
    scanf("%d %d %d %d %d", &minute, &hour, &day, &month, &year);
    save_datetime(minute, hour, day, month, year);
    print_datetime();
    return 0;
}

void save_datetime(unsigned minute, unsigned hour, unsigned day, unsigned month,unsigned year){
    datetime datetime;
    datetime = minute;
    datetime = datetime | (hour << 6);
    datetime = datetime | (day << 11);
    datetime = datetime | (month << 16);
    datetime = datetime | (year << 20);
}

void print_datetime(unsigned datetime){
    unsigned minute, hour, day, month, year;
    minute = datetime & 0x3F;
    hour = (datetime >> 6) & 0x1F;
    day = (datetime >> 11) & 0x1F;
    month = (datetime >> 16) & 0x0F;
    year = (datetime >> 20) & 0xFFF;
    printf("%d-%d-%d;%d:%d", year, month, day, hour, minute);
}