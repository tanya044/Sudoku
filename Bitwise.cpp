// C++ program to solve sudoku 
#include <iostream> 
#include <string.h> 
  
// N is used for the size of Sudoku grid.   
// Size will be NxN   
#define N 9 
  
using namespace std; 
  
/* A utility function to print grid */
void printGrid(int grid[N][N])   
{   
    for (int row = 0; row < N; row++)   
    {   
    for (int col = 0; col < N; col++)   
            cout << grid[row][col] << " ";   
        cout << endl;  
    }   
} 
/* Takes a partially filled-in grid and attempts   
to assign values to all unassigned locations in   
such a way to meet the requirements for  
Sudoku solution (non-duplication across rows,  
columns, and boxes) */
bool solve(int r, int c, int board[9][9],  
           int submatrixDigits[3][3],  
           int rowDigits[9],  
           int columnDigits[9]) 
{ 
    if (r == 9) 
    { 
          
        return true; 
    } 
    if (c == 9) 
    { 
        return solve(r + 1, 0, board, submatrixDigits,  
                     rowDigits, columnDigits); 
    } 
      
    if (board[r] == 0) { 
        for (int i = 1; i <= 9; i++) 
        { 
            int digit = 1 << (i - 1); 
              
            if (!((submatrixDigits[r / 3] & digit)  
                  || (rowDigits[r] & digit)  
                  || (columnDigits & digit))) 
            { 
                // set digit 
                submatrixDigits[r / 3] |= digit; 
                rowDigits[r] |= digit; 
                columnDigits |= digit; 
                board[r] = i; 
                  
                if (solve(r, c + 1, board, submatrixDigits, 
                          rowDigits, columnDigits)) 
                { 
                    return true; 
                } 
                else
                { 
                    submatrixDigits[r / 3] &= ~digit; 
                    rowDigits[r] &= ~digit; 
                    columnDigits &= ~digit; 
                    board[r] = 0; 
                } 
            } 
        } 
        return false; 
    } 
    return solve(r, c + 1, board, submatrixDigits,  
                 rowDigits, columnDigits); 
} 
  
// Function checks if Sudoku can be 
// solved or not 
bool SolveSudoku(int board[9][9]) 
{ 
    int submatrixDigits[3][3]; 
    int columnDigits[9]; 
    int rowDigits[9]; 
      
    for (int i = 0; i < 3; i++) 
        memset(submatrixDigits[i], 0, 3 * sizeof(int)); 
      
      
    memset(rowDigits, 0, 9 * sizeof(int)); 
    memset(columnDigits, 0, 9 * sizeof(int)); 
      
    // get 3x3 submatrix, row and column digits 
    for (int i = 0; i < 9; i++) 
        for (int j = 0; j < 9; j++) 
            if (board[i][j] > 0) 
            { 
                int value = 1 << (board[i][j] - '1'); 
                submatrixDigits[i / 3][j / 3] |= value; 
                rowDigits[i] |= value; 
                columnDigits[j] |= value; 
            } 
    // Backtrack 
    if (solve(0, 0, board, submatrixDigits, 
              rowDigits, columnDigits)) 
        return true; 
    else
        return false; 
} 
  
  
// Driver Code  
int main()   
{   
    // 0 means unassigned cells   
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},   
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},   
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},   
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},   
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},   
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},   
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},   
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},   
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};   
    if (SolveSudoku(grid) == true)   
        printGrid(grid);   
    else
        cout << "No solution exists";   
    
    return 0;   
}   
