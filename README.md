# Sudoku
Program for Sudoku Generator
The rules of Sudoku for a player are:-
In all 9 sub matrices 3×3 the elements should be 1-9, without repetition.
In all rows there should be elements between 1-9 , without repetition.
In all columns there should be elements between 1-9 , without repetition.
The task is to generate a 9 x 9 Suduku grid that is valid, i.e., a player can fill the grid following above set of rules.


Simple solution for this can be:
1.Randomly take any number 1-9.
2.Check if it is safe to put in the cell.(row , column and box)
3.If safe, place it and increment to next location and go to step 1.
4.If not safe, then without incrementing go to step 1.
5.Once matrix is fully filled, remove k no. of elements randomly to complete game.


Things to be noticed:
 We can improve the solution, if we understand a pattern in this game. We can observe that all 3 x 3 matrices, which are diagonally present are independent of other 3 x 3 adjacent matrices initially, as others are empty.
 So if we fill them first, then we will only have to do box check and thus column/row check not required.
 
 Secondly, while we fill rest of the non-diagonal elements, we will not have to use random generator, but we can fill recursively by checking 1 to 9.
 
 
 Hence, improved logic will be:
1. Fill all the diagonal 3x3 matrices.
2. Fill recursively rest of the non-diagonal matrices.
   For every cell to be filled, we try all numbers until
   we find a safe number to be placed.  
3. Once matrix is fully filled, remove K elements
   randomly to complete game.
