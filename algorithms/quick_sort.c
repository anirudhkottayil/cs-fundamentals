#include <stdio.h>
#include <stdlib.h>


int* q_sort(int* arr, int length){

  if (arr == NULL) {
    return NULL;
  }
  for (int i =0;i < length; i++){
    arr[i] = i;
  }

  return NULL;

}

int main(){
  int arr[] = {5,2,1,-10,8};
  int length = 5;
  q_sort(arr, length);

  for (int i = 0;i < length; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
