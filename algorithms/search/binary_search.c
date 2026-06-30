#include <stdio.h>

int binary_search(int* arr, int length, int elem){

  int left = 0;
  int right = length-1;
  int mid;

  while (left <= right){
    mid = (left + right)/2;

    if (arr[mid] == elem){
      return mid;
    } else if (arr[mid] < elem){
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}



int main(){
  int arr[] = {1,2,3,4,5};
  int length = 5;
  int elem = 5;

  int ind = binary_search(arr, length, elem);
  printf("Index of elem %d is: %d\n", elem, ind);

  return 0;
}
