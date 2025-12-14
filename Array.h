#pragma once
#ifndef ARRAYS_H
#define ARRAYS_H



/**
 * ѕолучение уникального значени€
 * @param x измен€емый параметр
 * @return уникальное значение
 */
double func(double x);



/**
 * ѕоиск первого элемента в массиве
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @param type тип элемента
 * @return индекс найденного элемента или -1 если не найден
 */
int find_first_element(double* array, int size, int type);







/**
 * «аполнение массива значени€ми
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n);


/**
 * «аполнение массива значени€ми
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements_r(double* ptr_array, int n);



/**
 * «аполнение массива значени€ми
 * @param ptr_array4 указатель на заполн€емый массив 
 * @param ptr_array1 указатель на с исходными данными массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements4(double* ptr_array4, double* ptr_array1, int size4);




/**
 * ѕечать элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int size);







/**
 * ќбработка элементов массива согласно индивидуальному варианту
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return значени€ после обработки массива
 */
double* calc_elements(double* ptr_array, int size);






/**
 * ”даление элемента из массива
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @param k индекс удал€емого элемента
 * @return размер нового массива
 */
int delete_k(double* ptr_arr, int size, int k);





/**
 * ѕоиск максимального элемента в массиве
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return индекс найденного элемента
 */
int max_elem(double* ptr_array, int size);




/**
 * ѕоиск последнего отрицательного элемента в массиве
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return индекс найденного элемента
 */
int last_negative(double* ptr_array, int size);






/**
 * ¬ставл€ет число num по указанному индексу в динамический массив.
 *
 * @param ptr_arr ”казатель на массив типа double
 * @param size ”казатель на переменную, хран€щую размер массива
 * @param index »ндекс дл€ вставки (0 ? index ? *size)
 * @param num „исло дл€ вставки
 * @return ”казатель на обработанный массив. ¬ случае ошибки возвращает NULL и освобождает пам€ть.
 */
double* insert(double* ptr_arr, int* size, int index, double num);


#endif