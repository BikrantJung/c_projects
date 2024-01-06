#include "lib/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int COLUMNS = 3;
void display_board(char (*board_data)[3]);
/*
 ==============================================
 Function to generate random coordinates for AI
 ==============================================
 reserved_locations = {
    {2, 3},
    {5, 7},
    {2, 1},
    {0, 0},
 }
 1. Generate random x and y location between 0
 and 3.
 2. Check in reserved_locations if generated
 x and y already exists or not.
 3. If yes, generate random location again, else
 return the generated location to calling function.
`int (*reserved_locations)[2]` means array containing
 whatever` rows. Each row contains 2 integers inside it.
*/
int ai_location(int *reserved_locations, int size) {
  int location = rand() % 9;
  if (!isNumberInArray(reserved_locations, size, location)) {
    return location;
  } else {
    ai_location(reserved_locations, size);
  }
}

void update_board(char (*board_data)[3], int *coords, char player) {
  board_data[coords[0]][coords[1]] = player;
}

char check_winner(char (*board_data)[3], char *winner) {
  // Check if all columns have same characters.
  printf("Checking winner\n");
  for (int i = 0; i < 3; i++) {
    printf("Checking column %c\n", board_data[0][i]);
    if (board_data[0][i] == board_data[1][i] &&
        board_data[1][i] == board_data[2][i]) {
      *winner = board_data[0][i];
    }
  }
  // Check if all rows have same characters.
  for (int i = 0; i < 3; i++) {
    if (board_data[i][0] == board_data[i][1] &&
        board_data[i][1] == board_data[i][2]) {
      *winner = board_data[i][0];
    }
  }

  // Check if diagonals are equal
  if (board_data[0][0] == board_data[1][1] &&
      board_data[1][1] == board_data[2][2]) {
    *winner = board_data[1][1];
  }
  if (board_data[0][2] == board_data[1][1] &&
      board_data[1][1] == board_data[2][0]) {
    *winner = board_data[1][1];
  }
  if (*winner == 'O') {
    printf("You lose!");
  }
  if (*winner == 'X') {
    printf("You won!");
  }
}
int check_position_taken(char (*board_data)[3], int *coords) {
  if (board_data[coords[0]][coords[1]] == 'X' ||
      board_data[coords[0]][coords[1]] == 'O') {
    return 1;
  } else {
    return 0;
  }
}
void player_move(char (*board_data)[3], char *winner, int *reserved_locations,
                 int size) {
  int player_location;
  int exit = 0;
  while (exit != 1) {
    display_board(board_data);
    printf("Choose your location: ");
    scanf("%d", &player_location);
    int *coords = get_position(player_location, COLUMNS);
    int is_position_taken = check_position_taken(board_data, coords);
    if (player_location < 1 || player_location > 9 || is_position_taken) {
      printf("\033[1;31mInvalid Move. Move again!\033[0m");
    } else {
      update_board(board_data, coords, 'X');
      check_winner(board_data, winner);
      exit = 1;
    }
    /* code */
  }
}
void computer_move(char (*board_data)[3], char *winner, int *reserved_locations,
                   int size) {
  int exit = 0;
  display_board(board_data);
  // * TODO: Fix computer choosing already existing location
  int computer_location = ai_location(reserved_locations, size);

  int *coords = get_position(computer_location, COLUMNS);
  update_board(board_data, coords, 'O');
  check_winner(board_data, winner);
  /* code */
}

/*Main Function*/
int main() {
  int player_location;
  int loop_number = 0;
  int game_over = 0; // false;
  char winner;       // 'C' for computer or 'P' for player

  char board_data[3][3] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'},
  };
  srand(time(NULL));
  //   Keep track of the locations which are already filled.
  int reserved_locations[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

  while (winner != 'X' || winner != 'O') {
    printf("Winner in main func %c\n", winner);
    player_move(board_data, &winner, reserved_locations,
                sizeof(reserved_locations) / sizeof(reserved_locations[0]));
    // * TODO : Implement Computer Move Functionality
    computer_move(board_data, &winner, reserved_locations,
                  sizeof(reserved_locations) / sizeof(reserved_locations[0]));
  }

  return 0;
}

/*
 Function to display board on screen with updated data,
 `char (*board_data)[3]` means array of `whatever` rows(not_specified), each
 row contains 3 elements inside it.
 NOTE: When passing array to function, no of rows is not mandatory, because
 at the end, array decays into pointer containing address of first element in
 array.
*/
void display_board(char (*board_data)[3]) {
  printf("\n===============\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      printf("| %c |", board_data[i][j]);
    }
    printf("\n");
    printf("|---||---||---|");
    printf("\n");
  }
  printf("===============\n");
}
