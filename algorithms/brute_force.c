void selection_sort_brute(int* arr, int length) {
  for(int i = 0; i < length; i++){
    for (int j = i+1; j < length; j++){
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }

    }
  }
}
