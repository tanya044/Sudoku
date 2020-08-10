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

# Graph coloring
A graph is a mathematical representation of a set of objects where some pairs of objects are connected (linked) to each other. The objects are represented by vertices (nodes) and the links are called edges. Graph coloring is the assignment of "colors" to vertices of the graph such that no two adjacent vertices share the same color. For example, in the graph mentioned above vertices 1 and 2 cannot have the same color because they have an edge connecting them. However, vertices 2 and 3 can have the same color because they are not connected. Below is one possible coloring of this graph.

It should be clear by now that one graph can have more than one possible coloring. The goal is to use the minimum number of colors possible. Below are another two possible colorings for the example graph. Coloring (1) uses the 3 colors while Coloring (2) uses 5 colors, hence, coloring (1) is better than coloring (2). Our color is to find a coloring of a given graph that uses the minimum number of colors. A coloring that uses at most k colors is called k-coloring (e.g. coloring (1) in the above example is a 3-coloring while coloring (2) is a 5-coloring).

If you tried to color the above graph using only two colors you will find out that it cannot be colored at all, Go try it out I will wait :). Therefore, the smallest number of colors needed to color a graph is called its chromatic number

Easy algo:

Find the degree of each vertex. (Degree: is the number of edges connected to it)

Order the vertices in descending order according to their degree.

Go through the list, color each vertex not connected to colored vertices with the same color.

Remove colored vertices from the list and repeat the process until all vertices are colored.

Contraction algo:

Select the vertex of maximum degree V.

Find the set of non-adjacent vertices to V.

From this set select the vertex Y of maximum common vertices with V.

Contract Y into V to be colored with the same color.

Remove Y from the set and repeat steps 3-5 until the list is empty.

6 .Remove vertex V from the graph

Repeat steps 1-6 until the resulting graph has all contracted nodes adjacent to each other.
In my implementation, I choose a greedy coloring algorithm with some modifications as proposed in the paper by Dr. Hussein Al-Omari and Khair Eddin Sabri published in the American Journal of Mathematics and Statistics.

As I discussed earlier, the trick is choosing the next vertex to color. The proposed algorithm uses a combination of saturated degree ordering (SDO) and degree ordering that we explained earlier.

The saturation degree of a vertex is the number of its adjacent differently colored vertices. The vertices are ordered according to their saturation degree and if two vertices have the same degree the tie is broken by comparing their degree.

Sudoku Solver A Sudoku puzzle (9x9) can be thought of a graph with 81 vertices, one for each cell, and two vertices are connected by an edge if they cannot be assigned the same value. For example, all cells in the same row, column or block will have edges between their corresponding vertices.

Given a Sudoku puzzle we can build the associated graph. The given number in the puzzle cane be used to add additional edges to the graph we can then use graph coloring to find a 9-coloring of this graph (colors 1-9)

The optimal solution in the case of the Sudoku puzzle is to find a coloring using only 9 colors. Some algorithms behave better than others and it is usually a tradeoff between runtime complexity and the number of colors used. Currently not all puzzles can be solved; for some puzzles the algorithm cannot find a coloring that uses only nine colors
