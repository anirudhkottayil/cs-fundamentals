#include <stdio.h>
#include "qsort.h"
#include "insort.h"

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
