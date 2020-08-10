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


# Things to be noticed:
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


Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. Method 1: Simple.Approach The naive approach is to generate all possible configurations of numbers from 1 to 9 to fill the empty cells. Try every configuration one by one until the correct configuration is found, i.e. for every unassigned position fill the position with a number from 1 to 9. After filling all the unassigned position check if the matrix is safe or not. If safe print else recurs for other cases.

# Algorithm:

Create a function that checks if the given matrix is valid sudoku or not. Keep Hashmap for the row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true; Create a recursive function that takes a grid and the current row and column index. Check some base cases. If the index is at the end of the matrix, i.e. i=N-1 and j=N then check if the grid is safe or not, if safe print the grid and return true else return false. The other base case is when the value of column is N, i.e j = N, then move to next row, i.e. i++ and j = 0. if the current index is not assigned then fill the element from 1 to 9 and recur for all 9 cases with the index of next element, i.e. i, j+1. if the recursive call returns true then break the loop and return true. if the current index is assigned then call the recursive function with index of next element, i.e. i, j+1

# Complexity Analysis:

Time complexity: O(9^(nn)). For every unassigned index there are 9 possible options so the time complexity is O(9^(nn)). Space Complexity: O(n*n). To store the output array a matrix is needed.

Method 2: Backtracking. Approach: Like all other Backtracking problems, Sudoku can be solved by one by one assigning numbers to empty cells. Before assigning a number, check whether it is safe to assign. Check that the same number is not present in the current row, current column and current 3X3 subgrid. After checking for safety, assign the number, and recursively check whether this assignment leads to a solution or not. If the assignment doesn’t lead to a solution, then try the next number for the current empty cell. And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.

# Algorithm:

Create a function that checks after assigning the current index the grid becomes unsafe or not. Keep Hashmap for a row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops. Create a recursive function which takes a grid. Check for any unassigned location. If present then assign a number from 1 to 9, check if assigning the number to current index makes the grid unsafe or not, if safe then recursively call the function for all safe cases from 0 to 9. if any recursive call returns true, end the loop and return true. If no recursive call returns true then return false. If there is no unassigned location then return true.
