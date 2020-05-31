Given a partially filled 9×9 matrix, digits (from 1 to 9) must be assigned to the empty cells so that every row, column, and submatrix of size 3×3 contains exactly one instance of the digits from 1 to 9.

In the pure backtracking solution, we iterate through the matrix and whenever an empty cell (cell without any digit) is found, we assign a digit to the cell, where such digit is not present in the current column, row, and 3×3 submatrix. After assigning the digit to the current cell, we recursively check whether this assignment leads to a valid solution or not. If the assignment doesn’t lead to a valid solution, then we try the next valid digit for the current empty cell. And if none of the digits leads to a valid solution, then the instance is infeasible.


Algo:
1. If there is no empty cell in the matrix M:
    return true
2. Let (i, j) be an empty cell in the matrix M
3. For i from 1 to 9:
    3.1. If i is not present in the row r, in column c, and the 3x3
    submatrix of (r, c):
        a) M(r, c) = i 
        b) recursively try fill in remaining empty cells
        c) If recursion was successful:
            return true
        d) M(r, c) = 0
4. return false

The step (3.1) can be performed by traversing the respective row, column, and 3×3 submatrix. However, we can make this step faster by preprocessing those digits before the backtracking, and this is the main point of this article.
