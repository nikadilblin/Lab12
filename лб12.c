#include <stdio.h>
#include <stddef.h>
#include <locale.h>

// Вспомогательная функция для Задания 5 (побайтовый вывод любого типа)
void print_bytes(void* ptr, size_t size) {
    unsigned char* p = (unsigned char*)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    printf("=== ЗАДАНИЕ 1 ===\n");
    // Определение объема памяти под указатели
    printf("Размер указателя на char: %zu байт\n", sizeof(char*));
    printf("Размер указателя на int: %zu байт\n", sizeof(int*));
    printf("Размер указателя на double: %zu байт\n", sizeof(double*));
    printf("Вывод: размер указателя не зависит от типа данных, на который он указывает, а зависит от архитектуры (обычно 4 или 8 байт).\n\n");

    printf("=== ЗАДАНИЕ 2 ===\n");
    // Анализ кода
    float PI = 3.14159, * p1, * p2;
    p1 = p2 = &PI;
    printf("По адресу p1=%p хранится *p1=%g\n", (void*)p1, *p1);
    printf("По адресу p2=%p хранится *p2=%g\n", (void*)p2, *p2);
    printf("Вывод: p1 и p2 указывают на один и тот же адрес (&PI), поэтому выводятся одинаковые адреса и значения.\n\n");

    printf("=== ЗАДАНИЕ 3 ===\n");
    // Исследование арифметики указателей
    int x = 5;
    int* pa = &x;
    printf("--- Тип int ---\n");
    printf("Адрес: %p, Значение: %d\n", (void*)pa, *pa);
    pa++;
    printf("После pa++: Адрес: %p (сдвиг на %zu байт)\n", (void*)pa, sizeof(int));
    pa--;
    printf("После pa--: Адрес: %p\n", (void*)pa);

    // Модификация для double
    printf("--- Тип double ---\n");
    double d = 3.14;
    double* pd = &d;
    printf("Адрес: %p, Значение: %f\n", (void*)pd, *pd);
    pd++;
    printf("После pd++: Адрес: %p (сдвиг на %zu байт)\n", (void*)pd, sizeof(double));

    // Модификация для char
    printf("--- Тип char ---\n");
    char c = 'A';
    char* pc = &c;
    printf("Адрес: %p, Значение: %c\n", (void*)pc, *pc);
    pc++;
    printf("После pc++: Адрес: %p (сдвиг на %zu байт)\n\n", (void*)pc, sizeof(char));

    printf("=== ЗАДАНИЕ 4 ===\n");
    // Перемещение по массиву с помощью указателя
    float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    float* ptr_a = array;

    // 4.1
    printf("4.1: array=%p, &array[0]=%p, &array=%p\n", (void*)array, (void*)&array[0], (void*)&array);

    // 4.2
    printf("4.2: Исходный ptr_a=%p, *ptr_a=%f\n", (void*)ptr_a, *ptr_a);
    ptr_a++;
    printf("После ptr_a++: ptr_a=%p, *ptr_a=%f\n", (void*)ptr_a, *ptr_a);
    // (ptr_a+4 и ptr_a-2 просто вычисляют адрес, не меняя сам ptr_a)

    // 4.3 Цикл с шагом 2
    printf("4.3: Проход с шагом 2: ");
    for (float* p = array; p < array + 10; p += 2) {
        printf("%.1f ", *p);
    }
    printf("\n");

    // 4.4 Обратный проход
    printf("4.4: Обратный проход: ");
    for (float* p = array + 9; p >= array; p--) {
        printf("%.1f ", *p);
    }
    printf("\n\n");

    printf("=== ЗАДАНИЕ 5 ===\n");
    // Побайтовый вывод
    int num = 0x12345678;
    unsigned char* a = (unsigned char*)&num;
    printf("Байты числа 0x12345678: %x %x %x %x\n", a[0], a[1], a[2], a[3]);
    printf("Вывод: Если выводится 78 56 34 12, то система Little-endian (младший байт в начале).\n");

    // Усовершенствованная программа для любого типа
    printf("Байты для int 12345: ");
    int i_val = 12345;
    print_bytes(&i_val, sizeof(i_val));

    printf("Байты для float 12345.0: ");
    float f_val = 12345.0f;
    print_bytes(&f_val, sizeof(f_val));

    printf("Байты для double 12345.0: ");
    double d_val = 12345.0;
    print_bytes(&d_val, sizeof(d_val));

    return 0;
}