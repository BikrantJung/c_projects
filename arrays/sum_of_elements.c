/*
Write a C program to find sum of all array elements.
*/

#include <stdio.h>

int main() {
  // Array of 10 integers
  int arr[10] = {1, 3, 7, 2, 7, 45, 65, 1, 7, 9};
  int total = 0;

  //   Get the length of array. Total size / size of 1 element
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < arr_size; i++) {
    total += arr[i]; // Or, total = total + arr[i]
  }

  printf("The sum of all elements is: %d\n", total);

  return 0;
}