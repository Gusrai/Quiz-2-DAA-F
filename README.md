# Quiz-2-DAA-F
Quiz 2 Design &amp; Analysis of Algorithms (F) by Muhammad Farhan Haykal(05111740000169), Ida Bagus Rai Widnyana(05111740000087), and Muhammad Rayhan Hakim(05111740000160)


In this Repositories, we tried to make a game about N-puzzle with A* algorithm. In this case, we make 8-puzzle.
8-Puzzle Explanation
Formula: sqrt(N+1) rows and sqrt(N+1)columns. in this case, the puzzle consists of 8 tiles with 1 random empty space so the tiles can be moved.
![State png](https://user-images.githubusercontent.com/42793734/55274402-72a97f80-530a-11e9-9957-f4ec6f5cc430.png)
## A* Algorithm
We use this Algorithm because the key feature of the A* algorithm is that it keeps a track of each visited node which helps in ignoring the already visited nodes. and it chooses the most optimal node which help us to achieving this 8-puzzle in a short time.
A* Algorithm :
F(n) = H9n) + G(n)
with : F(n) as estimation of total cost from n path to goal;
       H(n) as Estimation cost to n goal;
       G(n) as Total cost to get to n.
