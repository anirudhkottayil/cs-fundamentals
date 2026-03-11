#include "dynamic-array.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(DynamicArray* arr){
  for (size_t i = 0; i < arr->size; i++){
    printf("%d ", arr->items[i]);
  }
  printf("\n");
}

void destroy_array(DynamicArray* arr){
  free(arr->items);
  free(arr);
}

int get(DynamicArray* arr, size_t index, int* return_val){
  if (index >= arr->size){
    return -1; // nothing to fetch out of bounds
  }
  *return_val = arr->items[index];
  return 0;
}

int set(DynamicArray* arr, size_t index, int val){
  if (index >= arr->size){
    return -1; // out of bounds to set
  }
  arr->items[index] = val;
  return 0;
}

DynamicArray* create_array(size_t capacity){
  DynamicArray* arr = malloc(sizeof(DynamicArray));
  if (arr == NULL){
    perror("memory alloc failed for arr");
    return NULL;
  }
  arr->size = 0;
  arr->capacity = (capacity == 0) ? 4 : capacity;
  arr->items = malloc(arr->capacity * sizeof(int));
  if (arr->items == NULL){
    free(arr);
    perror("memory allocation failed for items arr");
    return NULL;
  }
  return arr;
}

int resize(DynamicArray* arr){
  int* new_items = malloc((arr->capacity*2) * sizeof(int));
  if (new_items == NULL){
    perror("memory alloc failed for new_arr");
    return 1;
  }
  for (size_t i = 0; i < arr->size; i++){
    new_items[i] = arr->items[i];
  }
  int* temp = arr->items;
  arr->items = new_items;
  arr->capacity = arr->capacity*2;
  free(temp);

  return 0;
  
}

int insert(DynamicArray* arr, int val, size_t index){
  if (arr->size == arr->capacity){
    int resize_check = resize(arr);
    if (resize_check == 1) {return 1;} // 1 means resize failed so in turn no space to insert.
  }
  if (index == arr->size){
    arr->items[arr->size] = val;
  } else if (index < arr->size){
    for (size_t i = arr->size; i > index; i--){
      arr->items[i] = arr->items[i-1];
    }
    arr->items[index] = val;
  } else {
    return -1; // -1 means the index provided made a gap in the array
  }
  arr->size++;
  return 0; // 0 means insertion happened without any errors
}

int remove_at(DynamicArray* arr, size_t index){
  if (arr->size == 0){
    return -1; // Nothing to remove
  }
  if (arr->size - 1 == index){
    ;// im just reducing the array size outside the control flow since that indicates the index is free
  } else if (index < arr->size){
    for (size_t i = index; i < arr->size-1; i++){
      arr->items[i] = arr->items[i+1];
    }
  } else {
    return 1; // 1 means the index provided is more than the number of elements in the array atm.
  }
  arr->size--; 
  return 0; // 0 means the deletion happened without any errors
}
