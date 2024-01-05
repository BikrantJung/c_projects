#include <stdio.h>

void matrix_multiplication();
void displayMatrix(int rows, int columns, const int (*matrix)[columns]);
int main() {
  int operation;

  printf("Which operation would you like to perform?\n");
  printf("Press 1 for Matrix Multiplication\n");
  printf("Press 2 for Matrix Addition: ");

  scanf("%d", &operation);

  switch (operation) {
  case 1:
    printf("You choose matrix multiplication");
    matrix_multiplication();
    break;
  case 2:
    printf("You choose matrix addition");
    break;
  default:
    printf("Please choose valid input");
    break;
  }
  return 0;
}

struct Matrix {
  int rows;
  int columns;
  // Matrix size mustn't be greater than 3 * 3 but can be anything like 2 * 3 or
  // 3 * 2, or 2 * 2 or 3 * 3
  int data[3][3];
};

void matrix_multiplication() {
  int matrixA_rows;
  int matrixA_columns;
  int matrixB_rows;
  int matrixB_columns;

  printf("Enter no of rows and columns in matrix A \n E.g. 3 2: ");
  scanf("%d %d", &matrixA_rows, &matrixA_columns);

  printf("Enter no of rows and columns in matrix A \n E.g. 2 3: ");
  scanf("%d %d", &matrixB_rows, &matrixB_columns);

  // Create a 2D array matrixA of rows and columns

  // Column of matrix a must be equal to row of matrix b
  if (matrixA_columns != matrixB_rows) {
    printf("Column of matrix a must be equal to row of matrix b\n");
  }

  int matrix_a[matrixA_rows][matrixA_columns];
  int matrix_b[matrixB_rows][matrixB_columns];

  printf("Enter elements of the %dx%d matrix for matrix A :\n", matrixA_rows,
         matrixA_columns);

  for (int i = 0; i < matrixA_rows; i++) {
    for (int j = 0; j < matrixA_columns; j++) {
      printf("Enter element at position (%d, %d): ", i + 1, j + 1);
      scanf("%d", &matrix_a[i][j]);
    }
  }
  printf("\nEnter elements of the %dx%d matrix for matrix B :\n", matrixB_rows,
         matrixB_columns);

  for (int i = 0; i < matrixB_rows; i++) {
    for (int j = 0; j < matrixB_columns; j++) {
      printf("Enter element at position (%d, %d): ", i + 1, j + 1);
      scanf("%d", &matrix_b[i][j]);
    }
  }
  displayMatrix(matrixA_rows, matrixA_columns, matrix_a);
}
void displayMatrix(int rows, int columns, const int matrix[rows][columns]) {
  printf("Matrix:\n");

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}