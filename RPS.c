#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void game() {

  // Create a big arena of memory and then take smaller pools out of it to
  // assign to variables ("Rock" = 5,"Paper" = 6, "Scissors" = 9, user_input =
  // 10, computer_input = 10 Total 40bytes)
  void *arena = malloc(64);
  if (!arena) {
    return;
  };
  //Cast void *arena to a char (1byte) which helps to move exactly 1 spot on the memory space
  char *BytePtr = (char *)arena;

  // Create offset by which the memory is allocated
  int offset = 0;

  char **options = (char **)(BytePtr + offset); // List of pointers
  offset += (3 * sizeof(char *));

  // Now assigning buffer to each 8bytes of options
  options[0] = BytePtr + offset;
  offset += 5;

  options[1] = BytePtr + offset;
  offset += 6;

  options[2] = BytePtr + offset;
  offset += 9;

  // Link all the pointers inside options to their respective values (Rock,
  // Paper, Scissors)
  strcpy(options[0], "Rock");
  strcpy(options[1], "Paper");
  strcpy(options[2], "Scissors");

  // Create pointers to point to memory addresses in the arena
  char *user_input = BytePtr + offset; // user pointer
  offset += 10;

  char *computer_input; // computer pointer

  // Game Initiallisatin
  printf("Welcome to the game of Rock, Paper and Scissors!!! \n");

  // Before user input lets choose an option for computer
  // Computer Choice needs to be random so we need a random int generator
  srand(time(NULL));
  int randomInt = rand() % 3;

  // Make the computer choose from the options available
  computer_input = options[randomInt];

  // User Input
  printf("What do You choose? \n");
  scanf("%9s", user_input);

  // Display everyones choice
  printf("You Chose: %s\n", user_input);
  printf("Computer chose: %s\n", computer_input);

  // Game Logic
  if (strcmp(user_input, computer_input) == 0) {
    printf("It is a DRAW!!!");
  } else if (strcmp(user_input, "Rock") == 0) {
    if (strcmp(computer_input, "Paper") == 0) {
      printf("You LOSE!!");
    } else {
      printf("You WIN!!");
    };
  } else if (strcmp(user_input, "Paper") == 0) {
    if (strcmp(computer_input, "Scissors") == 0) {
      printf("You LOSE!!");
    } else {
      printf("You WIN!!");
    }
  } else if (strcmp(user_input, "Scissors") == 0) {
    if (strcmp(computer_input, "Rock") == 0) {
      printf("You LOSE!!");
    } else {
      printf("You WIN!!");
    }
  } else {
    printf("Invalid Input. Please check capitalization errors");
  };

  free(arena);
}

int main() {
  game();
  return EXIT_SUCCESS;
}
