SliderSearch
============

Cameron Cross 7193432 AI Assignment 1

Features:
- GEN option to generate a board
- CUS1 is a version of depth first search that starts with a depth limit of 1 and increments it until a result is found.
- CUS2 is an ungreedy depth first search, ie. it only expands the nodes with the lowest heuristic cost
- LEN is a custom mode where it generates a new board and solves it and gets the depth. This was used to try 

Bugs:
- DFS and GBFS are not depth limited which means that for larger puzzles, it will take an extremely long time. They also produce fairly poor results.
- BFS will tend to consume memory very rapidly if it doesnt find a result within the first 10-20 layers.
- The C++ STL vectors/lists/etc will cause it to run extremely slowly unless it is built as a "Release" binary. Even with the "Release" binary, the C++ STL stuff still causes it to run extremely slowly.
- Memory is not cleaned up perfectly, as I assumed that the program would end and the OS would reclaim the memory. In some areas I have attempted to clean up correctly, but not across the board.



Resources:

http://www.cs.mcgill.ca/~newborn/nxp_puzzleOct9.htm
- Accessed 11/4/14
- Intresting paper on NxP puzzles and how to solve them. 

https://oeis.org/search?q=30%2C81&sort=&language=english&go=Search 
- Accessed 11/4/14
- Database of integer series. Used to try find a theoretical MAX depth.

www.cplusplus.com/reference/
- Accessed Constantly
- This was a useful site for getting information regarding STL lits/vectors etc.




Notes:

I was investigating how to logically depth limit the DFS and GBFS search. I found some pages that had mathematically worked out the maximum depth for the 3x3 and 4x4, but nothing that was simple enough to apply to other puzzles.
I created the LEN option to experimentally determine the length for a given puzzle size. 
This was done by generating random puzzles and solving them with BFS. Unfortunately we were then told that we couldnt depth limit DFS, which meant this was all a waste.

I also had a version of DFS which was recursive. This had the benefit of very little ram usage, but it tended to use up stack space. This wasnt too bad when it was depth limited, as the stack can be increased, but unlimited depth meant that it would crash with a stack overflow error. It was by far the fastest DFS implementation that I have developed, but for large cases it required special compilation options.

I also implemented a map to lookup past states, but you mentioned in a lecture that checking for the past state was not suitable so I have changed it back for most of the implementations and I dont have time to correctly reimplement it again.

