#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insort.h"

void move(int* arr,int i, int length, int pivot, int pivot_index){
  if (i == pivot_index-1){
    int temp = arr[pivot_index];
    arr[pivot_index] = arr[i];
    arr[i] = pivot;
    return;
  } 
  int temp_piv = arr[(pivot_index - 1)];
  arr[pivot_index] = arr[i];
  arr[pivot_index-1] = pivot;
  arr[i] = temp_piv;
}

int* q_sort(int* arr, int length){

  if (arr == NULL) {
    return NULL;
  }
  if (length == 0) {
    return NULL;
  }

  if (length == 1) {
    return &arr[0];
  }

  if (length < 17) {
    in_sort(arr, length);
    return NULL;
  }

  srand(time(NULL));
  int rand_num = rand() % length;
  int temp = arr[length-1];
  arr[length-1] = arr[rand_num];
  arr[rand_num] = temp;

  int low = 0;
  int high = length -1;
  int boundary = high;
  int pivot = arr[high];
  int pivot_index = high;
  int move_count = 0;

  for (int i = 0; i < boundary; i++){
    if (arr[i] >= pivot){
      move(arr, i, length, pivot, boundary);
      move_count++;
      boundary = pivot_index - move_count;
      i--;
    }
  }
  q_sort(&arr[0], boundary);
  q_sort(&arr[boundary+1], length - boundary-1);
  return NULL;
}

