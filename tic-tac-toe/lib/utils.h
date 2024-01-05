#include <stdio.h>
#include <stdlib.h>
/*
 * ALGORITHM TO CHANGE NUMBER INTO COORDINATE
 E.g. number = 5, cols = 2

 This means we have a table of 2 columns (no. of rows doesn't matters)
 and we need rows and column index of number 5 in the table. This algorithm
 assumes that we have table of 2 columns and (whatever no of rows). Each cell
 of table starts from 1 and keeps filling towards right.

 If the argument is passed `5` and `2`. This means we have table of 2 columns
 and we want to find the index of number `5`.

 table = {
     { 1, 2 },
     { 3, 5 },
     { `5`, 6 },
     { 7, 8 },
 }
 This will return { 2,0 }

 Since we are not passing our dynamic table something like :
 table = {
     { 3, 6 },
     { 1, 5 },
     { 7, 2 },
 }, this algorithm currently cannot find the location of 5
 This algorithm is useful in games like tic tac toe, where you want to take
 user input as `1 2 3 4 5 6 7 8 9` (for 9 cells). If user selects `7`, the
 coordinates of `7` will be `{2, 0}`

 */
int *get_position(int number, int cols) {

  int *coords = (int *)malloc(2 * sizeof(int));
  //  If
  if (number % cols == 0) {
    // The inputted number is on last column.
    coords[1] = cols - 1;
    coords[0] = number / cols - 1;
  } else {
    coords[0] = number / cols;
    coords[1] = number % cols - 1;
  }

  return coords;
}

/*
 ===============================================
 Function to check if an element exists in array
 ===============================================
 ```
 array = {2,4,6,2,6}
 elem = 2;
 return 1;
 ```
 ```
 array = {2,4,6,2,6}
 elem = 10;
 return 0;
 ```
*/
int isNumberInArray(int arr[], int size, int number) {

  for (int i = 0; i < size; i++) {
    if (arr[i] == number) {
      return 1;
    }
  }
  return 0;
}
