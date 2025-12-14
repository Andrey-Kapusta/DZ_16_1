#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <limits.h>
#include "array.h"



long long Task_11(int size);
int Task_14(int size);
int Task_16(int size);
int Task_16_dz();


int main() {
    system("chcp 1251");
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    int choice;
    int size;

    // Ввод количества элементов массива
    printf("Введите количество элементов массива (n > 0): ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Ошибка: количество элементов должно быть положительным!\n");
        return 1;
    }


    printf("Выберите задание для выполнения:\n");
    printf("1 - Основное задание 16 (удаление/вставка элементов)\n");
    printf("2 - Дополнительное задание (16 дз) (генерация и объединение 3 массивов)\n");
    printf("3 - Задание 11\n");
    printf("4 - задание 14\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода выбора!\n");
        return 1;
    }

    switch (choice) {
    case 1:
        printf("Задание 16:");
        Task_16(size);
        break;
    case 2:
        printf("Задание 16:");
        Task_16_dz();
        break;
    case 3:
        printf("Задание 11\nНахождение произведения всех элементов, расположенных между первым 0 и вторым 0:\n");
        printf("Произведение всех элементов, расположенных между первым 0 и вторым 0: %ll",Task_11(size));
        break;

    case 4:
        printf("Задание 14\nНахождение индексов первого отрицательного,нулевого,положительного элемента:\n");
        printf("Количество найденых элементов: %d",Task_14(size));
        break;
    default:
        printf("Неверный выбор!\n");
        break;
    }


    printf("\nПрограмма успешно завершена.\n");


    return 0;
}







long long Task_11(int size)
{

    // Выделение памяти под массив
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Ввод элементов массива
    printf("Введите %d целых чисел (положительных и отрицательных):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Поиск индексов первого и второго нулевых элементов
    int first_zero_index = -1;
    int second_zero_index = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            if (first_zero_index == -1) {
                first_zero_index = i;
            }
            else if (second_zero_index == -1) {
                second_zero_index = i;
                break; // Нашли оба нуля, выходим из цикла
            }
        }
    }
    long long product = 1; // Используем long long для больших произведений
    // Проверка, найдены ли два нуля
    if (first_zero_index == -1) {
        printf("В массиве нет нулевых элементов.\n");
    }
    else if (second_zero_index == -1) {
        printf("В массиве только один нулевой элемент.\n");
    }
    else {
        // Вычисление произведения элементов между нулями
        int elements_count = 0; // Счетчик элементов между нулями

        // Элементы находятся между first_zero_index+1 и second_zero_index-1
        for (int i = first_zero_index + 1; i < second_zero_index; i++) {
            product *= arr[i];
            elements_count++;
        }

        if (elements_count == 0) {
            printf("Между нулевыми элементами нет других элементов.\n");
        }
    }
    free(arr);
    return product;


}







int Task_14(int size) {


    // Выделение памяти под массив
    double* arr = (double*)malloc(size * sizeof(double));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }


    full_elements(arr, size);
    put_elements(arr, size);
    int count_elem = 0;


    if (find_first_element(arr, size, -1) >= 0) {
        printf("\nИндекс первого отрицательного элемента массива: %d\n", find_first_element(arr, size, -1));
        count_elem++;
    }
    else
    {
        printf("В массиве не найден отрицательный элемент\n");
    }

    if (find_first_element(arr, size, 0) >= 0) {
        printf("Индекс первого нулевого элемента массива: %d\n", find_first_element(arr, size, 0));
        count_elem++;
    }
    else
    {
        printf("В массиве не найден нулевой элемент\n");
    }

    if (find_first_element(arr, size, 1) >= 0) {
        printf("Индекс первого положительного элемента массива: %d\n\n", find_first_element(arr, size, 1));
        count_elem++;
    }
    else
    {
        printf("В массиве не найден положительный элемент\n");
    }
    return count_elem;

}





int Task_16(int size) {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    double* ptr_array = NULL;



    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL)
    {
        puts("Ошибка выделения памяти!");
        return -1;
    }


    printf("Исходный массив:\n");
    full_elements(ptr_array, size);
    put_elements(ptr_array, size);


    printf("Обработанный массив:\n");
    double* new_array = calc_elements(ptr_array, size);
    if (new_array != NULL) {
        put_elements(new_array, size);
    }


    printf("\n=== Демонстрация удаления элемента ===\n");

    int del_index = 2;

    printf("Удаляем %d максимальных элемента\n", del_index);


    size = delete_k(ptr_array, size, del_index);
    printf("Массив после удаления (%d элементов):\n", size);
    put_elements(ptr_array, size);




    printf("\n=== Демонстрация вставки элемента ===\n");



    int insert_index;

    if (size > 0) {

        insert_index = max_elem(ptr_array, size);

        printf("Вставляем -999 перед элемента с индексом %d\n", insert_index);

        double* temp_array = insert(ptr_array, &size, insert_index, -999.0);

        if (temp_array != NULL) {

            ptr_array = temp_array;

            printf("Массив после вставки (%d элементов):\n", size);

            put_elements(ptr_array, size);

        }
    }



    if (ptr_array != NULL)
    {
        free(ptr_array);
        ptr_array = NULL;
    }


    printf("Программа завершена успешно.\n");
    return 0;
}




int Task_16_dz() {
    srand(time(NULL));

    double* ptr_array1 = NULL;
    double* ptr_array2 = NULL;
    double* ptr_array3 = NULL;
    double* ptr_array4 = NULL;
    int size4 = 5;
    int size;

    size = (rand() % 41) + 10;


    ptr_array1 = (double*)malloc(size * sizeof(double));
    ptr_array2 = (double*)malloc(size * sizeof(double));
    ptr_array3 = (double*)malloc(size * sizeof(double));
    ptr_array4 = (double*)malloc(size4 * sizeof(double));

    if (ptr_array1 == NULL || ptr_array2 == NULL || ptr_array3 == NULL || ptr_array4 == NULL)
    {
        puts("Ошибка выделения памяти!");
        return -1;
    }


    printf("\nИсходный массив 1:\n");
    full_elements_r(ptr_array1, size);
    put_elements(ptr_array1, size);

    printf("\nИсходный массив 2:\n");
    full_elements_r(ptr_array2, size);
    put_elements(ptr_array2, size);

    printf("\nИсходный массив 3:\n");
    full_elements_r(ptr_array3, size);
    put_elements(ptr_array3, size);

    printf("\nИсходный массив 4:\n");
    full_elements4(ptr_array4, ptr_array1, size4);
    for (int i = (last_negative(ptr_array2, size) + 1); i < size; i++) {
        double* temp_array = insert(ptr_array4, &size4, 0, ptr_array2[i]);
        if (temp_array != NULL) {
            ptr_array4 = temp_array;
        }
    }
    put_elements(ptr_array4, size4);


    if (ptr_array1 != NULL)
    {
        free(ptr_array1);
        ptr_array1 = NULL;
    }
    if (ptr_array2 != NULL)
    {
        free(ptr_array2);
        ptr_array2 = NULL;
    }
    if (ptr_array3 != NULL)
    {
        free(ptr_array3);
        ptr_array3 = NULL;
    }
    if (ptr_array4 != NULL)
    {
        free(ptr_array4);
        ptr_array4 = NULL;
    }
    return 0;
}



