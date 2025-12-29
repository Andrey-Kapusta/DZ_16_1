#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"




double func(double x) {
    double i = (x - 2) * 0.5;
    return i * i - i * i * i;
}



int find_first_element(double* array, int size, int type) {

    for (int i = 0; i < size; i++) {
        if ((type == -1 && array[i] < 0.0) || (type == 0 && array[i] == 0.0) || (type == 1 && array[i] > 0)) {
            return i;
            break;
        }
    }
}




double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = func(i);
    }

    return ptr_array;
}


double* full_elements_r(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (-1.0*func(i));
    }

    return ptr_array;
}




double* full_elements4(double* ptr_array4, double* ptr_array1, int size4) {
    for (int i = 0; i < size4; i++)
    {
        ptr_array4[i] = ptr_array1[i];
    }
    return ptr_array4;
}




int put_elements(double* ptr_array, int size) { 
    int count = 0;
    if (ptr_array == NULL) {
        puts("Массив пуст!");
        return -1;
    }

    if (size <= 0) {
        puts("Неверный размер массива!");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d] = %.4f\n", i, ptr_array[i]);
        count++;
    }

    return count;
}







double* calc_elements(double* ptr_array, int size) {    
    for (int i = 0; i < size; i++) {
        if (ptr_array[i] == 0.0) {
            ptr_array[i] = 0.0;
        }
        else {
            ptr_array[i] = ceil(ptr_array[i]);
        }
    }
    return ptr_array;
}




int delete_k(double* ptr_arr, int size, int k) {      
    if (ptr_arr == NULL)
    {
        return 0;
    }


    if (k < 0 || k >= size) {
        printf("Некорректное количество для удаления: %d\n", k);
        return size;
    }

    int n = size - k;

    for (int j = 1; j <= k; j++)
    {
        int u = size - j;
        for (int t = max_elem(ptr_arr, size); t < u; t++) {
            ptr_arr[t] = ptr_arr[t + 1];
        }


    }

    return n;
}





int max_elem(double* ptr_array, int size) {
    if (ptr_array == NULL || size <= 0) {
        return -1;
    }
    double max_value = ptr_array[0];
    int max_index = 0;


    for (int i = 1; i < size; i++) {
        if (ptr_array[i] > max_value) {
            max_value = ptr_array[i];
            max_index = i;
        }
    }

    return max_index;
}





int last_negative(double* ptr_array, int size) {
    if (ptr_array == NULL || size <= 0) {
        return -1;
    }

    int index = 0;

    for (int i = 1; i < size; i++) {
        if (ptr_array[i] < 0) {
            index = i;
        }
    }

    return index;
}












double* insert(double* ptr_arr, int* size, int index, double num) {
    // Проверка входных параметров
    if (size == NULL) {
        printf("Ошибка: указатель на размер массива равен NULL!\n");
        return NULL;
    }

    if (index < 0 || index > *size) {
        fprintf(stderr, "Ошибка: некорректный индекс %d (размер массива: %d)\n", index, *size);
        return NULL;
    }

    // Увеличиваем размер массива
    int new_size = *size + 1;
    double* new_arr = (double*)realloc(ptr_arr, new_size * sizeof(double));

    if (new_arr == NULL) {
        printf("Ошибка перераспределения памяти!\n");
        free(ptr_arr); // Освобождаем старую память в случае ошибки
        return NULL;
    }

    // Сдвигаем элементы вправо, начиная с index
    for (int i = new_size - 1; i > index; i--) {
        new_arr[i] = new_arr[i - 1];
    }

    // Вставляем новый элемент
    new_arr[index] = num;

    // Обновляем размер
    *size = new_size;

    return new_arr;
}


