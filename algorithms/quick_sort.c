#include <stdio.h>
#include <stdlib.h>

void move(int* arr, int length){
  int temp = arr[0];
  for (int i = 0; i < length-1; i++){
    arr[i] = arr[i+1];
  }
  arr[length-1] = temp;
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
      move(&arr[i], length-i);
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
  int arr[] = {3,3,3,3,3,3,3,3,3,3,3};
  int length = 11;
  q_sort(arr, length);

  printf("####################\n");
  for (int i = 0;i < length; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
  // printf("pivot: %d\n", pivot);
  // printf("low: %d\n", low);
  // printf("high: %d\n", high);
  // printf("boundary: %d\n", boundary);
