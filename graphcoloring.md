A graph is a mathematical representation of a set of objects where some pairs of objects are connected (linked) to each other. The objects are represented by vertices (nodes) and the links are called edges.
Graph coloring is the assignment of "colors" to vertices of the graph such that no two adjacent vertices share the same color. For example, in the graph mentioned above vertices 1 and 2 cannot have the same color because they have an edge connecting them. However, vertices 2 and 3 can have the same color because they are not connected. Below is one possible coloring of this graph.

It should be clear by now that one graph can have more than one possible coloring. The goal is to use the minimum number of colors possible. Below are another two possible colorings for the example graph. Coloring (1) uses the 3 colors while Coloring (2) uses 5 colors, hence, coloring (1) is better than coloring (2).
Our color is to find a coloring of a given graph that uses the minimum number of colors. A coloring that uses at most k colors is called k-coloring (e.g. coloring (1) in the above example is a 3-coloring while coloring (2) is a 5-coloring).

If you tried to color the above graph using only two colors you will find out that it cannot be colored at all, Go try it out I will wait :). Therefore, the smallest number of colors needed to color a graph is called its chromatic number

Easy algo:
1. Find the degree of each vertex. (Degree: is the number of edges connected to it)

2. Order the vertices in descending order according to their degree.

3. Go through the list, color each vertex not connected to colored vertices with the same color.

4. Remove colored vertices from the list and repeat the process until all vertices are colored.



In my implementation, I choose a greedy coloring algorithm with some modifications as proposed in the paper by Dr. Hussein Al-Omari and Khair Eddin Sabri published in the American Journal of Mathematics and Statistics.

As I discussed earlier, the trick is choosing the next vertex to color. The proposed algorithm uses a combination of saturated degree ordering (SDO) and degree ordering that we explained earlier.

The saturation degree of a vertex is the number of its adjacent differently colored vertices.  The vertices are ordered according to their saturation degree and if two vertices have the same degree the tie is broken by comparing their degree.

Sudoku Solver
A Sudoku puzzle (9x9) can be thought of a graph with 81 vertices, one for each cell, and two vertices are connected by an edge if they cannot be assigned the same value. For example, all cells in the same row, column or block will have edges between their corresponding vertices.

Given a Sudoku puzzle we can build the associated graph. The given number in the puzzle cane be used to add additional edges to the graph we can then use graph coloring to find a 9-coloring of this graph (colors 1-9)


The optimal solution in the case of the Sudoku puzzle is to find a coloring using only 9 colors. Some algorithms behave better than others and it is usually a tradeoff between runtime complexity and the number of colors used. Currently not all puzzles can be solved; for some puzzles the algorithm cannot find a coloring that uses only nine colors
