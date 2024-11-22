#include <stdio.h>
# include <stdlib.h>
   
  int Xf = 88;  // Variable holding the ASCII value of "X".
  int Of = 79;  // Variable holding the ASCII value of "O".
  int Ef = 35;  // Variable holding the ASCII value of "#".
  int row, col;
  int f[4][5] = {
    {0, 35, 35, 35, 35},
    {0, 35, 35, 35, 35},
    {0, 35, 35, 35, 35},
    {0, 35, 35, 35, 35}
  };
 
/* int f[4][4] = {
    {Ef, Ef, Ef, Ef},
    {Ef, Ef, Ef, Ef},
    {Ef, Ef, Ef, Ef},
    {Ef, Ef, Ef, Ef}
  }; */


// Function for displaying the Grid and any changes on the Grid
int printGrid(void) {
  for(row = 0; row < 4; row++) {
    printf("\n");
    for(col = 0; col < 5; col++) {
      printf("%c ", f[row][col]);
    }
  };
  printf("\n");
}

int main(void) 
{
  printGrid();
  f[1][3] = Xf;
  system("clear");
  printGrid();
  scanf(userInput1) // Add user input and test it working or not working. this is where it was last left off.
  return 0;

}
