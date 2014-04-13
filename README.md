SliderSearch
============

Cameron Cross 7193432 AI Assignment 1

Features:
- GEN option to generate a board
- CUS1 is a version of depth first search that starts with a depth limit of 1 and increments it until it is found.
- CUS2 is a version of A* that uses the same heuristic to get the cost and the depth. I dont think its any good, but its something 
- LEN is a custom mode where it generates a new board and solves it and gets the depth. This was used to try 

Bugs:
- DFS has a depth limit, so if the number of moves to get to the end is < (width*height)^2. 
  Lowering this value manually will result in a faster fix. Increasing this value will 
  increase find time and also results in a worse result.
- 

Missing:


Resources:

http://www.cs.mcgill.ca/~newborn/nxp_puzzleOct9.htm - Intresting paper on NxP puzzles and how to solve them. 
https://oeis.org/search?q=30%2C81&sort=&language=english&go=Search - Database of integer series. Used to try find a theoretical MAX depth.


