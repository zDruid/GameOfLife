# Conway's Game of Life: C++ Implementation

In this project, we'll develop an implementation of Conway's Game of Life. 

## History of the Game

[Conway's Game of Life - Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) is a cellular automaton devised by the British mathematician John Horton Conway in 1970. Its roots can be traced back to the 1940s when John von Neumann and Stanislaw Ulam were developing simulation theories at Los Alamos National Laboratory. They did this work not long after working with Robert Oppenheimer to develop the first nuclear bomb. The game, which started as a mathematical concept, has applications in various fields including biology, economics, and computer science.

The Game of Life simulation operates on a grid of squares (cells) where each cell can be alive or dead, and evolves in steps from generation to generation, following a set of simple rules based on the number of living neighbors a cell has.

![](assets/gameofliferules2.png)

With the right inputs, applying these simple rules can have remarkable consequences. Here, for example, is a "glider", a stable object that migrates across the grid.

![](assets/Glider.gif)

Your job will be to implement the Life class. Life makes use of a few concepts, such as maintaining a dynamic array, using a flat array to represent a 2D array, as well as implementing the "rule of three" methods: copy constructor, assignment operator and destructor.

## This Project Requires a Lot of Console Space

Be sure to stretch your console window side-to-side if necessary, and use (cmd or cntrl) + the minus key to zoom out your browser window.

## Resources

- [Conway's Game of Life - Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- [Learn CPP](https://www.learncpp.com/)


[^1]: Fun coincidence that this question seems equally salient to real life, too.
[^2]: Like life in our simulation, is *your* behavior determined at the outset while still being computationally irreducable? Stanford professor Robert Sapolsky [seems to think so](https://mitpressbookstore.mit.edu/book/9780525560975).
