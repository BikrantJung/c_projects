/*
Write a C program to find second largest element in an array.
Solution 1: Sort the array in ascending order print the
second last element of array

Solution 2: Find the largest element and assign the previous value of largest
element to second_largest variable in each loop.

In this code, we will apply solution 2.
*/
#include <stdio.h>

/*
 * `int arr[5] = {3, 12, 7, 45, 100};`
 * Explanation:
 * Initially we set the `largest` and `second_largest` variable
 * to the first element of the array. i.e. `3`
 *
 * Then we loop over the elements and check if the next element
 * is greater than the current element. In first loop, we check
 * `is 3 greater than 3`, no it's not, and we do nothing, in
 * second loop we check `is 12 greater than 3`, yes it is, we
 * set `largest` to `12` and `second_largest` to old value of
 * `largest` which was `3` initially.
 * Once we finish the loop, we will get largest and second
 * largest element of array.
 */
int main() {
  // Array of 10 integers
  int arr[10] = {3, 1, 12, 2, 7, 45, 65, 23, 56, 100};
  int second_largest = arr[0];
  int largest = arr[0];
  //   Get the length of array. Total size / size of 1 element
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < arr_size; i++) {
    if (largest < arr[i]) {
      second_largest = largest;
      largest = arr[i];
    }
  }
  printf("Largest = %d\t Second largest = %d\n", largest, second_largest);
  // Output: Largest: 100, Second Largest = 65
  return 0;
}