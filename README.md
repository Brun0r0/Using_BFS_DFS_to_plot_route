# 🗺️ Treasure Hunt: A Pathfinding Adventure (C Language) 🚀

Welcome to the **Treasure Hunt** project! This C-language application is designed to explore graph traversal algorithms (Depth-First Search - DFS and Breadth-First Search - BFS) to navigate a 2D map, discover islands, and find hidden treasure! 🏝️💰

## ✨ Idea Behind the Project

Imagine you're an adventurer on a mysterious map, trying to find a hidden treasure ('X') starting from your current location ('L'). But there's a twist! Some parts of the map are water ('.') and can't be crossed. The rest are land, forming various islands.

This project aims to:

1.  **Map the World**: Represent our adventurer's world as a graph, where each land cell is a node and adjacent land cells are connected. 🌐
2.  **Island Discovery**: Identify and quantify the number of distinct islands, and determine the largest and smallest islands on the map. 🕵️‍♀️
3.  **Treasure Quest!**: Find the shortest and any valid path from your starting point to the treasure using two classic graph search algorithms:
    * **Depth-First Search (DFS)**: Think of it as exploring one path as far as possible before backtracking. Like a determined explorer! 🏞️
    * **Breadth-First Search (BFS)**: This method explores all immediate neighbors before moving to the next level of neighbors. Like a systematic search party! 🔍

## ⚙️ How It Works (Under the Hood)

This project leverages fundamental data structures and algorithms:

### Data Structures:

* **Adjacency List (Graph Representation)**: The map is represented as an array of linked lists (`nodo** lista`), where each index corresponds to a cell on the map, and its linked list contains its traversable neighbors. This is a highly efficient way to store sparse graphs (graphs with relatively few connections). 🔗
* **Static Stack (`PilhaEstatica.h`/`.c`)**: Used for the Depth-First Search (DFS) algorithm. It allows us to keep track of the path we're currently exploring. Think of it as a pile of plates – you always take the last one you put on! 🍽️
* **Static Queue (`FilaEstatica.h`/`.c`)**: Used for the Breadth-First Search (BFS) algorithm. It helps us explore the graph level by level, ensuring we find the shortest path. Imagine a line at the bank – first in, first out! 🚶‍♀️🚶‍♂️

### Algorithms:

* **Depth-First Search (DFS) (`buscaProfunda` and `tesouroProfundidade` in `busca.c`)**:
    * `buscaProfunda`: Explores an island completely to determine its size. It's crucial for identifying the "islands" on our map and their respective sizes. 🏝️📏
    * `tesouroProfundidade`: Determines if there's a path from the starting point to the treasure using DFS and reconstructs one such path. 🧭
* **Breadth-First Search (BFS) (`tesouroLargura` in `busca.c`)**:
    * `tesouroLargura`: Finds a path from the starting point to the treasure using BFS. Because BFS explores layer by layer, it inherently finds the *shortest* path in an unweighted graph!  shortest path. 🏁

## 🚀 Getting Started

To compile and run this project:

1.  **Clone the repository (or download the files):**
    ```bash
    git clone <repository_url>
    cd <repository_name>
    ```

2.  **Compile the C code:**
    You'll need a C compiler (like GCC). Navigate to the project directory in your terminal and run:
    ```bash
    gcc main.c FilaEstatica.c PilhaEstatica.c grafo.c busca.c -o treasure_hunt
    ```
    This command compiles all the `.c` files and links them, creating an executable named `treasure_hunt`.

3.  **Run the executable:**
    ```bash
    ./treasure_hunt
    ```

### Input Format:

The program expects input from `stdin`. The first two lines should be:

* `N`: The number of rows in the map.
* `M`: The number of columns in the map.

Followed by `N * M` characters representing the map, where:

* `'L'`: Your starting location.
* `'X'`: The treasure's location.
* `'#'`: Land (traversable).
* `'.'`: Water (non-traversable).

**Example Input:**

´´´
10 40

.....##.................................
.....##L############################....
.################################.......
.###########################............
.####X#########.........................
.#########...............########.......
.######...............############......
.###..................###########.......
.######..................#####..........
.....##..................######.........
´´´

### Output:

The program will output:

* The number of islands found.
* The size of the largest and smallest islands.
* If a path to the treasure exists:
    * The path found by Depth-First Search, marked with arrows (`<`, `>`, `^`, `v`).
    * The number of steps taken by DFS.
    * The path found by Breadth-First Search, also marked with arrows.
    * The number of steps taken by BFS.
* If no path to the treasure exists, a "Nao ha caminho para o tesouro" message.

## 🤝 Contributing

Feel free to fork this project, open issues, or submit pull requests! Any contributions to improve the code, add features, or enhance documentation are highly welcome. Let's make this treasure hunt even better! 🌟

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

Happy Adventuring! 🚀
