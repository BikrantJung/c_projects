/*
Write a C program to print all negative elements in an array.
*/
#include <stdio.h>

int main() {
  // Array of 10 integers
  int arr[10] = {1, -3, -7, 2, 7, 45, -65, -1, 7, -9};

  //   Get the length of array. Total size / size of 1 element
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] < 0) {
      printf("Negative element: %d\n", arr[i]);
    }
  }

  return 0;
}