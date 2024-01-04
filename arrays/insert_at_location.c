/*
Write a C program to insert an element in an array.
*/
#include <stdio.h>
#define MAX_SIZE 100 // Maximum size of array
int main() {
  // Array of 10 integers
  int arr[MAX_SIZE];
  int element_to_insert, position, array_size, i;

  // Get maximum size of array from user
  printf("Enter size of array MAX_SIZE = 100: ");
  scanf("%d", &array_size);

  // Validation
  if (array_size > MAX_SIZE) {
    printf("\nThe maximum size should be below 100\n");
    return 0;
  }

  // Get all elements to be inserted
  printf("Enter elements in array (space separated): ");
  for (i = 0; i < array_size; i++) {
    scanf("%d", &arr[i]);
  }

  // Get new element from user to be inserted
  printf("\nEnter element to insert: ");
  scanf("%d", &element_to_insert);

  // Get new position in which element will be inserted
  printf("\nWhich position to insert 1 to %d : ", array_size);
  scanf("%d", &position);

  // Position should not be less than 0 or more than array size
  if (position > array_size + 1 | position <= 0) {
    printf("Invalid position! Please enter position between 1 to %d",
           array_size);
    return 0;
  }

  //   Shift all elements from [position - 1] index towards right, and make room
  //   for new element Add new element to [position - 1] index
  for (i = array_size; i >= position; i--) {
    arr[i] = arr[i - 1];
  }

  // Insert new element to given position and increment size by 1
  arr[position - 1] = element_to_insert;
  array_size++;

  // Display new array
  printf("Array elements after insertion : ");
  for (i = 0; i < array_size; i++) {
    printf("%d\t", arr[i]);
  }
  return 0;
}