# 🏴‍☠️ Treasure Hunt - Graph Search Algorithms

## 📋 About the Project

This project implements a treasure hunting system on two-dimensional maps using **Depth-First Search (DFS)** and **Breadth-First Search (BFS)** algorithms. The program analyzes maps composed of islands and oceans, identifies all existing islands, and finds the best path between an initial location and a hidden treasure.

### 🎯 Project Objectives

- **Implement data structures**: Graphs using adjacency lists
- **Apply search algorithms**: DFS and BFS for graph exploration
- **Connected components analysis**: Island identification and measurement
- **Path reconstruction**: Visualization of the found route
- **Memory management**: Proper allocation and deallocation of resources

## 🗺️ How It Works

The program represents the map as an undirected graph where:

- **Vertices**: Each map cell (except water)
- **Edges**: Connections between adjacent cells (horizontal and vertical)
- **Connected components**: Represent separate islands

### Map Symbols

| Symbol | Meaning |
|---------|-------------|
| `#` | Land (part of an island) |
| `.` | Water (ocean) |
| `L` | Initial location (starting point) |
| `X` | Treasure (destination) |
| `>` `<` `^` `v` | Path directions found |

## 🚀 How to Use

### Compilation

```bash
gcc -o treasure main.c grafo.c busca.c mapa.c PilhaEstatica.c FilaEstatica.c
```

### Execution

```bash
./treasure
```

### Input Format

1. **First line**: `N M` (map dimensions - rows and columns)
2. **Next N lines**: Map characters (one per cell)

### Output Format

1. Information about the islands found
2. Path using depth-first search (if exists)
3. Path using breadth-first search (if exists)
4. Number of steps for each algorithm

## 📁 Project Structure

```
📦 treasure-hunt/
├── 📄 main.c              # Main program
├── 📄 grafo.c/.h          # Graph implementation
├── 📄 busca.c/.h          # Search algorithms (DFS/BFS)
├── 📄 mapa.c/.h           # Map manipulation
├── 📄 PilhaEstatica.c/.h  # Stack structure for DFS
├── 📄 FilaEstatica.c/.h   # Queue structure for BFS
└── 📄 README.md           # This file
```

## 📊 Usage Examples

### 🏖️ Example 1: Simple Island
```
Input:
4 5
#####
#L..#
#.X.#
#####

Output:
Ha 1 ilhas(s)
A maior tem tamanho 12
A menor tem tamanho 12

Busca em profundidade:
#####
#L>.#
#.X.#
#####
2 passo(s)

Busca em largura:
#####
#L>.#
#.X.#
#####
2 passo(s)
```

### 🏝️ Example 2: Multiple Islands
```
Input:
5 6
##....
#L....
......
....##
....#X

Output:
Ha 2 ilhas(s)
A maior tem tamanho 3
A menor tem tamanho 3

Nao ha caminho para o tesouro
```

### 🌊 Example 3: Complex Maze
```
Input:
6 8
########
#L.....#
#.####.#
#....#.#
#.##.#X#
########

Output:
Ha 1 ilhas(s)
A maior tem tamanho 28
A menor tem tamanho 28

Busca em profundidade:
########
#L>>>>>v
#^####v#
#^...#v#
#^##.#X#
########
12 passo(s)

Busca em largura:
########
#L>>>>>v
#^####v#
#^...#v#
#^##.#X#
########
12 passo(s)
```

## ⚙️ Implemented Algorithms

### 🔍 Depth-First Search (DFS)
- **Structure**: Stack (LIFO)
- **Strategy**: Explores as far as possible before backtracking
- **Advantage**: Uses less memory
- **Application**: Island counting and path finding

### 🌐 Breadth-First Search (BFS)
- **Structure**: Queue (FIFO)
- **Strategy**: Explores all neighbors before moving to the next level
- **Advantage**: Finds the shortest path
- **Application**: Optimal path to treasure

## 🧩 Key Features

- ✅ **Island Analysis**: Identifies and measures all map islands
- ✅ **Path Finding**: Implements DFS and BFS to find routes
- ✅ **Visualization**: Shows the found path with directional arrows
- ✅ **Comparison**: Presents results from both algorithms
- ✅ **Validation**: Reports when no path is possible

## 💡 Covered Concepts

- **Undirected graphs** and adjacency lists
- **Connected components** and connectivity analysis
- **Search algorithms** and their practical differences
- **Path reconstruction** using predecessor arrays
- **Memory management** in C
- **Modularization** and separation of concerns

## 🔧 Possible Improvements

- [ ] Implement A* algorithm for heuristic search
- [ ] Add support for diagonal movements
- [ ] Create graphical interface for visualization
- [ ] Implement different terrain types with costs
- [ ] Add interactive map creation mode

## 👨‍💻 Developed by

This project was developed as an academic assignment to study:
- Data Structures
- Search Algorithms
- C Programming
- Graph Analysis

---

⭐ **Tip**: Try creating your own maps and observe the differences between DFS and BFS algorithms!
