#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>


// Макрос для вычисления размера типа без использования sizeof
// Создает массив из 2 элементов, находит разницу адресов между 2-м и 1-м элементом в байтах
#define GET_TYPE_SIZE(type) \
    ((size_t)((char*)&((type*)0)[1] - (char*)&((type*)0)[0]))

int main() {
    setlocale(LC_CTYPE, "RUS");

    printf("Размеры основных типов данных (без использования sizeof):\n\n");

    printf("1) char:               %zu байт\n", GET_TYPE_SIZE(char));
    printf("2) short int:          %zu байт\n", GET_TYPE_SIZE(short int));
    printf("3) unsigned short int: %zu байт\n", GET_TYPE_SIZE(unsigned short int));
    printf("4) int:                %zu байт\n", GET_TYPE_SIZE(int));
    printf("5) unsigned char:      %zu байт\n", GET_TYPE_SIZE(unsigned char));
    printf("6) wchar_t:            %zu байт\n", GET_TYPE_SIZE(wchar_t));
    printf("7) long long int:      %zu байт\n", GET_TYPE_SIZE(long long int));
    printf("8) size_t:             %zu байт\n", GET_TYPE_SIZE(size_t));
    printf("9) float:              %zu байт\n", GET_TYPE_SIZE(float));
    printf("10) double:            %zu байт\n", GET_TYPE_SIZE(double));
    printf("11) signed int:        %zu байт\n", GET_TYPE_SIZE(signed int));

    return 0;
}