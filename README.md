# Sudoku
Program for Sudoku Generator
The rules of Suduku for a player are:-
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
