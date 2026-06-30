#include <stdio.h>


void in_sort(int* arr, int length){
  for (int i = 1; i < length; i++){
    int j = i;
    int temp = arr[j];
    int flag = 0;
    while ((j > 0) && (temp < arr[j-1])){
      arr[j] = arr[j-1];
      flag = 1;
      j--;
    }
    if (flag == 1)arr[j] = temp;
  }
}


int main(){
  int arr[] = {10,9,6,3,5,8};
  int length = 6;

  in_sort(arr, length);

  for (int i = 0; i < length; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
