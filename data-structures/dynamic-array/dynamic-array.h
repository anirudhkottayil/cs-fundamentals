#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stddef.h>

typedef struct {
  size_t size;
  size_t capacity;
  int* items;
} DynamicArray;

DynamicArray* create_array(size_t capacity);
int insert(DynamicArray* arr, int val, size_t index);
int remove_at(DynamicArray* arr, size_t index);
int resize(DynamicArray* arr);
int get(DynamicArray* arr, size_t index, int* return_val);
int set(DynamicArray* arr, size_t index, int val);
void destroy_array(DynamicArray* arr);
void print_array(DynamicArray* arr);
#endif
