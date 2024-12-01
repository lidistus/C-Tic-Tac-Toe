#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
  
  int runningState = 1; // Variable controlling the main loop of the program.
  char currentPlayer[20]; // Variable containing the active "name" of the current player.
  int i = 0;    // Variable for user input.
  int state = 1;    // Variable for gamestate. If == 0 then exits game.
  int currentTurn;    // Variable for currenTurn. Used in conjuction with turnCounter for displaying current player's turn.
  int turnPiece;    // Variable used to determine what value to place in the Grid if the users input is successful.
  int turnCounter;    // // Variable for currentTurn. Used in userTurn function for determing the current player's turn through increments.
  int xF = 88;  // Variable holding the ASCII value of "X".
  int oF = 79;  // Variable holding the ASCII value of "O".
  int eF = 35;  // Variable holding the ASCII value of "#".
  int row, col;   // Variable's for displaying the Grid. Used in the printGrid function via iteration to loop through the g[] array.


  // Array for printGrid. Each object is set as an ASCII reference.
  int g[3][4] = {
    {0, 35, 35, 35},
    {0, 35, 35, 35},
    {0, 35, 35, 35}
  };

  // Array for win condition checking. Each object is a true or false so that it may be referenced for its state.
  int c[3][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
  };

// Function for resetting the arrays above to default values for a new game.
int logicReset() {

  i = 0;
  turnCounter = 0;
  currentTurn = 0;
  // Loops through row -> col and repeats until all elements have been set to 35.
  for(row = 0; row < 3; row++) {
    for(col = 1; col < 4; col++) {
      g[row][col] = 35;
    }
  }
  // Loops through row -> col and repeats until all elements have been set to 0.
  for(row = 0; row < 3; row++) {
    for(col = 1; col < 4; col++) {
      c[row][col] = 0;
    }
  }

  state = 2;
}

// Function for displaying the Grid. Loops through row -> col and repeats until all col have been printed.
int printGrid(void) {
  for(row = 0; row < 3; row++) {
    printf("\n");
    for(col = 0; col < 4; col++) {
      printf("%c ", g[row][col]);
    }
  };
  printf("\n");
}

// Function for checking if the Grid space has been used. If not, it will apply the current player's (calculated through the turnPiece var) piece to the space.
int gridPlacement() {
   switch (i) {
    case 1 :
      if (g[0][1] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
        g[0][1] = turnPiece;
        c[0][0] = 1;
      turnCounter++;
        }
    break;
    case 2 :
      if (g[0][2] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[0][2] = turnPiece;
      c[0][1] = 1;
      turnCounter++;
        }
    break;
    case 3 :
      if (g[0][3] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[0][3] = turnPiece;
      c[0][2] = 1;
      turnCounter++;
        }
    break;
    case 4 :
      if (g[1][1] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[1][1] = turnPiece;
      c[1][0] = 1;
      turnCounter++;
        }
    break;
    case 5 :
      if (g[1][2] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[1][2] = turnPiece;
      c[1][1] = 1;
      turnCounter++;
        }
    break;
    case 6 :
      if (g[1][3] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[1][3] = turnPiece;
      c[1][2] = 1;
      turnCounter++;
        }
    break;
    case 7 :
      if (g[2][1] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[2][1] = turnPiece;
      c[2][0] = 1;
      turnCounter++;
        }
    break;
    case 8 :
      if (g[2][2] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[2][2] = turnPiece;
      c[2][1] = 1;
      turnCounter++;
        }
    break;
    case 9 :
      if (g[2][3] != eF) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      printf("This spot has already been used. Please try again: ");
        }
      else {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      g[2][3] = turnPiece;
      c[2][2] = 1;
      turnCounter++;
        }
    break;
      }
}

// Function for taking user input. Checks if input is greater than 17. If true, then it restarts the function.
int userInput() {
  printf("Please select your box by using a number 1 - 9:\n");
  scanf("%d", &i);
  if (i > 9 || i == 0) {
//  printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
    printf("You have entered an incorrect number. Please try again:\n");
    userInput();
  }
// Attempting to add this function into the next.
  gridPlacement();
}

// Function for checking user's turn. Utilizes turnCounter() and divides the variables value by two to check the turn.
int userTurn() {
if (turnCounter % 2) {
  printf("It is Player 2's turn.\n");
  currentTurn = 1;
  turnPiece = xF;
  strcpy(currentPlayer, "Player 2");
  }
  else {
    printf("It is Player 1's turn.\n");
    currentTurn = 0;
    turnPiece = oF;
    strcpy(currentPlayer, "Player 1");
  }
}

// Function referenced if a win occurs. Will print who has won and change state of game.
int winConditionResults() {

  printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
  printf("%s has won the game. Thank you for playing!\n", currentPlayer);
  printf("Final results: ");
  printGrid();
  printf("You will now be sent back to the main menu.\n");
  sleep(2);
  state = 1;
}
// Function referenced if a draw occurs. Will change state of game.
int drawCondition() {
  char j;
  printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
  printf("The game has ended in a draw. Press any button to return to the main menu. Thank you for playing!\n", currentPlayer);
  printf("Final results: ");
  printGrid();
  logicReset();
  sleep(5);
  printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
    state = 2;
  
}
// Function to check the grid for a win condition. References the g[][] array for checking if the current player has a wind condition (lease reference tic-tac-toe win conditions) based on the active turnPiece. For a draw, it references the c[][] array to see if each element == 1. If so, it will go back to the main menu.
int winConditionCheck() { 
  //  Top Row 
  if (g[0][1] == turnPiece && g[0][2] == turnPiece && g[0][3] == turnPiece) {winConditionResults();}

  //  Middle Row 
  else if (g[1][1] == turnPiece && g[1][2] == turnPiece && g[1][3] == turnPiece) {winConditionResults();}

  //  Bottom Row
  else if (g[2][1] == turnPiece && g[2][2] == turnPiece && g[2][3] == turnPiece) {winConditionResults();}

  //  Left Col: |
  else if (g[0][1] == turnPiece && g[1][1] == turnPiece && g[2][1] == turnPiece) {winConditionResults();}

  //  Middle Col: |
  else if (g[0][2] == turnPiece && g[1][2] == turnPiece && g[2][2] == turnPiece) {winConditionResults();}

  //  Bottom Col: |
  else if (g[0][3] == turnPiece && g[1][3] == turnPiece && g[2][3] == turnPiece) {winConditionResults();}
  
  //  Bottom-Left to Top-Right Diag
  else if (g[2][1] == turnPiece && g[1][2] == turnPiece && g[0][3] == turnPiece) {winConditionResults();}

  //  Up-Left to Down-Right Diag 
  else if (g[0][1] == turnPiece && g[1][2] == turnPiece && g[2][3] == turnPiece) {winConditionResults();}
  
  //  Checks for a tie.
  else if (c[0][0] && c[0][1] && c[0][2] && c[1][0] && c[1][1] && c[1][2] && c[2][0] && c[2][1] && c[2][2] == 1) {drawCondition();}
  
}

// Function for counting time. Used in the 
int timeCount() {
    time_t time1 = time(NULL); // Grabs current system time since epoch.
    sleep(1);
    time_t time2 = time(NULL); // I have no idea what im doing.

    printf("You will now exit the game in...\n");
    for(int i = 3; time2 > time1 && i > 0; i--) {
      printf("%d...\n", i);
      sleep(1);
    }
    state = 3;
}

// Function for the Main Menu system. Uses a switch statement to go into ares of the program.
int mainMenu() {

  
  // printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
  int menuInput;
  printf("Welcome to Tic-Tic-Toe! Please select an option from the menu below.\n\n");
  printf("1. Person V.S. Person\n");
  printf("2. Person V.S. CPU\n");
  printf("3. Exit Game\n");
  scanf("%d", &menuInput);
  
  // Switch used to check menuInput.
  switch (menuInput) {    
    //Option 1: Person VS Person
    case 1:
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      logicReset();
      break;
    // Option 2: Person VS CPU
    case 2:

    break;

    // Option 3: Exit Game
    case 3:
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      timeCount();
    
    break;

    default:
      printf("That is not a correct input. Please try again.\n");
      sleep(1);
  }
}

// Main function for application.
int main(void) 
{
  while (runningState == 1) {
    while (state == 1) {
      printf("\033[2J"); // Attempting to clear screen manually. I could of made this into a function but feel it's better to have it as a single line here for clarity.
      mainMenu();
    }

    while (state == 2) {
      printGrid(); // Prints the Grid layout.
      userTurn(); // Checks turnCounter and sets the turn for player 1 or 2.
      userInput(); // Checks inputs from the user.
      winConditionCheck(); 
    }

    while (state == 3) {
      return 0;
    }
  }
  return 0;

}
