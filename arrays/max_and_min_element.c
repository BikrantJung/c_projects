/*
Write a C program to find maximum and minimum element in an array.
*/

#include <stdio.h>

int main() {
  // Array of 10 integers
  int arr[10] = {1, 3, 7, 2, 7, 45, 65, 1, 7, 9};
  int max = arr[0];
  int min = arr[0];

  //   Get the length of array. Total size / size of 1 element
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < arr_size; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
    if (min > arr[i]) {
      min = arr[i];
    }
  }

  printf("Max = %d\nMin = %d", max, min);

  return 0;
}