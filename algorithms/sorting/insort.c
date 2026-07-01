#include <stdio.h>
#include <string.h>
#include "insort.h"

int insertion_point(int* arr, int length, int elem){
  int left = 0;
  int right = length;
  int mid = 0;

  while (left <= right){
    mid = (left + right)/2;
    if (arr[mid] > elem){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

void in_sort(int* arr, int length){
  for (int i = 1; i < length; i++){
    int temp = arr[i];int indx;
    
    if (temp < arr[i-1]){
      indx = insertion_point(arr, i, temp);
      memmove(arr+indx+1, arr+indx, sizeof(int) * (i - indx));
      arr[indx] = temp;
    }
  }
}

