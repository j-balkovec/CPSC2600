# Graph Library

This C++ file, `Graph.cpp`, contains the implementation of the Graph class. The class is designed to handle graph operations, including Depth-First Search (DFS), Breadth-First Search (BFS), loading graphs from files, and displaying graph information.

## File Information

**File**: Graph.cpp
**Author**: Jakob Balkovec (CPSC 2600)
**Instructor**: S. Oh (CPSC 2600)
**Date**: Sun 12th Nov

## Revision History

**1.0 [11/08/2023]:** Initial class design
**2.0 [11/12/2023]:** Debugging and Documentation

## Usage

**Valgrind Command**
- To check for memory leaks using Valgrind, you can use the following command:

```bash
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file="p4_valgrind.log" ./main
```

- Ensure you have a C++ compiler installed on your machine.
- Compile the program using the appropriate compiler command.
```bash
g++ Graph.h Graph.cpp main.cpp -pedantic -O3 -Werror -Wall -o prog

./prog graphs/graph0
```

## Graph Class

The Graph class provides functionality for handling graph operations. The class includes methods for DFS, BFS, loading graphs from files, and displaying graph information.

## Methods

### `DFS(int vertex, bool* visited) const`
- Private utility method for Depth-First Search (DFS) on the graph.
- Called by the public method DisplayDFS.
- Uses recursion to traverse the graph.
  
**Parameters:**
- `vertex`: The starting vertex for DFS.
- `visited`: An array to keep track of visited vertices.

### `BFS(int vertex, bool* visited) const`
- Private utility method for Breadth-First Search (BFS) on the graph.
- Called by the public method DisplayBFS.
- Uses `std::queue` to traverse the graph.
  
**Parameters:**
- `vertex`: The starting vertex for BFS.
- `visited`: An array to keep track of visited vertices.

### `Graph()`
- Constructor for the Graph class.
- Instantiates an empty graph.
  
### `~Graph()`
- Destructor for the Graph class.
- Handles memory deallocation.
  
### `Load(const char* filename)`
- Reads the graph data from a file and populates the graph's adjacency list based on the file contents.
- Throws exceptions if the file cannot be opened or parsed.
  
**Parameters:**
- `filename`: The name of the file to load the graph from.

### `Display() const`
- Displays the adjacency matrix of the graph to the standard output.
- Each element in the matrix represents the connection status between vertices.
  
### `DisplayDFS(unsigned int vertex) const`
- Displays the Depth-First Search (DFS) traversal on the graph starting from the given vertex.
- Calls the private DFS method.
  
### `DisplayBFS(unsigned int vertex) const`
- Displays the Breadth-First Search (BFS) traversal on the graph starting from the given vertex.
- Calls the private BFS method.
  
## Contributing

Feel free to contribute to the development of this Graph Library. If you encounter issues or have suggestions, please open an issue on GitHub.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
