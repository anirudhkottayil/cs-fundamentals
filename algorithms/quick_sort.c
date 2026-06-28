#include <stdio.h>
#include <stdlib.h>

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

int main(){
  int arr[] = {10,9,6,3,5,8};
  int length = 6;
  q_sort(arr, length);

  for (int i = 0;i < length; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
  // printf("low: %d\n", low);
  // printf("high: %d\n", high);
  // printf("boundary: %d\n", boundary);
