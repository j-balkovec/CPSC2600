//[FILE]: Graph.cpp
//[AUTHOR]: Jakob Balkovec (CPSC 2600)
//[INSTRUCTOR]: S. Oh (CPSC 2600)
//
//[DATE]: Sun 12th Nov
//
//[REVISION HISTORY]
//- 1.0 [11/08/2023]: Initial class design
//- 2.0 [11/12/2023]: Debugging and Documentation
//
//[DESC]: -This file contains the implementation of the Graph class.
//[VALGRIND]: valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file="p4_valgrind.log" ./main

#include <iostream>
#include <new>
#include <queue>
#include <fstream>

#include "Graph.h"

//[NAMESPACE]: Deemed unnecessary because Graph is the only class in the library, 
//             but is good practice to avoid namespace polution
namespace GraphLibrary
{
  //[DESC]: Private utility method to perform Depth-First Search (DFS) on the graph.
  //        This method is called by the public method DisplayDFS.
  //[NOTES]: Uses recursion to traverse the graph. Note: Calls can be expensive, therefore 
  //         avoid using on large-scale graphs.
  //
  //[PARAM]: 'vertex' The starting vertex for DFS.
  //[PARAM]: 'visited' An array to keep track of visited vertices.
  //[RETURNS]: 'void'
  //
  //[PRE]: 'visited' must not be null, and vertex must be a valid vertex within the graph
  //[PRE]: Enough stack space is available
  //[POST]: Graph is traversed in depth-first order
  //
  //[ATTENTION]: Method tagged as const because it does not modify the graph
  void Graph::DFS (int vertex, bool* visited) const
  {
    visited[vertex] = true;
    std::cout << vertex << " "; //needs formating
    for (unsigned int neighbor = 0; neighbor < m_NumOfVertices; ++neighbor)
    {
      if (m_AdjacencyList[vertex][neighbor] && !visited[neighbor])
      {
        DFS (neighbor, visited);
      }
    }
  }

  //[DESC]: Private utility method to perform Breadth-First Search (BFS) on the graph.
  //        This method is called by the public method DisplayBFS.
  //[NOTES]: Uses 'std::queue' to traverse the graph.
  //[DEPENDENCY]: 'std::queue' ==> {SEE} <queue>
  //
  //[PARAM]: 'vertex' The starting vertex for DFS.
  //[PARAM]: 'visited' An array to keep track of visited vertices.
  //[RETURNS]: 'void'
  //
  //[PRE]: 'visited' must not be null, and vertex must be a valid vertex within the graph
  //[POST]: Graph is traversed in breadth-first order
  //
  //[ATTENTION]: Method tagged as const because it does not modify the graph
  void Graph::BFS (int vertex, bool* visited) const
  {
    std::queue<unsigned int> BFSQueue;
    visited[vertex] = true;
    BFSQueue.push (vertex);

    while (!BFSQueue.empty ())
    {
      unsigned int CurrentVertex = BFSQueue.front ();
      BFSQueue.pop ();

      std::cout << CurrentVertex << " ";
      for (unsigned int neighbor = 0; neighbor < m_NumOfVertices; ++neighbor)
      {
        if (m_AdjacencyList[CurrentVertex][neighbor] && !visited[neighbor])
        {
          visited[neighbor] = true;
          BFSQueue.push (neighbor);
        }
      }
    }
  }

  //[DESC]: Constructor for the Graph class
  //[NOTE]: Instantiates an empty graph
  Graph::Graph ()
  {
    m_NumOfVertices = 0;
    m_AdjacencyList = nullptr;
  }

  //[DESC]: Destructor for the Graph class
  //[NOTE]: Handles memory deallocation and zeros out the memory handle
  Graph::~Graph ()
  {
    if (m_AdjacencyList != nullptr) {
      for (size_t i = 0; i < m_NumOfVertices; ++i) {
        delete[] m_AdjacencyList[i];
      }
      delete[] m_AdjacencyList;
    }
    m_AdjacencyList = nullptr;
  }

  //[DESC]: This method reads the graph data from a file and populates the graph's
  //        adjacency list based on the file contents. The file should contain vertex
  //        information and edge connections between vertices.
  //[PARAM]: filename The name of the file to load the graph from.
  //
  //[THROW]: std::invalid_argument if the 'filename' parameter is null.
  //[THROW]: Throws std::invalid_argument if the file cannot be opened
  //[THROW]: Throws std::invalid_argument if the file cannot be parsed
  //
  //[PRE]: 'filename' must not be null.
  //[POST]: The graph is loaded from the specified file.
  //
  //[NOTES/INVARIANT]: The file format is assumed to be: 
  //        - The first line indicates the number of vertices in the graph.
  //        - Subsequent lines represent edges, where each line consists of two
  //          vertex indices indicating an edge between them.
  void Graph::Load (const char* filename) {
    if (filename == nullptr)
    {
      throw std::invalid_argument ("[G]Load(...) [Cannot call with null filename]");
    }

    std::ifstream inputFile (filename);
    if (!inputFile.is_open ())
    {
      throw std::invalid_argument ("[G]Load(...) [Cannot open file]");
    }

    constexpr int InitialValue = 0;
    constexpr int HasAnEdge = 1;

    inputFile >> m_NumOfVertices;
    m_AdjacencyList = new (std::nothrow) unsigned int* [m_NumOfVertices];
    for (size_t i = 0; i < m_NumOfVertices; ++i) {
      m_AdjacencyList[i] = new (std::nothrow) unsigned int[m_NumOfVertices];
      for (size_t j = 0; j < m_NumOfVertices; ++j) {
        m_AdjacencyList[i][j] = InitialValue;
      }
    }

    unsigned int vertex1, vertex2 = 0;
    while (inputFile >> vertex1 >> vertex2) {
      if (vertex1 < m_NumOfVertices && vertex2 < m_NumOfVertices) {
        m_AdjacencyList[vertex1][vertex2] = HasAnEdge;
        m_AdjacencyList[vertex2][vertex1] = HasAnEdge;
      }
    }
    inputFile.close ();
  }

  //[DESC]: This method prints the adjacency matrix of the graph to the standard output.
  //        Each element in the matrix represents the connection status between vertices.
  //        The matrix is square, with the size determined by the number of vertices in the graph.
  //
  //[PRE]: The graph's adjacency list must be initialized.
  //[POST]: The graph is displayed using an adjacency matrix representation.
  void Graph::Display () const {
    std::cout << "\n<[Adjacency Matrix]> \n\n";

    for (size_t i = 0; i < m_NumOfVertices; ++i) {
      for (size_t j = 0; j < m_NumOfVertices; ++j) {
        std::cout << "[" << m_AdjacencyList[i][j] << "]";
      }
      std::cout << std::endl;
    }
  }


  //[DESC]: This method displays the Depth-First Search (DFS) traversal on the graph 
  //        starting from the given vertex. It calls the private DFS method. 
  //        See DFS for more details.
  //
  //[THROW]: std::invalid_argument if the starting vertex index is invalid.
  //
  //[PARAM]: vertex The index of the vertex to start the DFS traversal from.
  //
  //[PRE]: The graph must be initialized, and the provided vertex index should be within the graph bounds.
  //[POST]: The DFS traversal starting from the specified vertex is displayed on the standard output.
  void Graph::DisplayDFS (unsigned int vertex) const
  {
    if (vertex >= m_NumOfVertices)
    {
      throw std::invalid_argument ("[G]DisplayDFS(...) [Invalid starting Index]");
    }

    bool* visited = new (std::nothrow) bool[m_NumOfVertices];
    for (unsigned int i = 0; i < m_NumOfVertices; i++)
    {
      visited[i] = false;
    }

    std::cout << "\n<[DFS at vertex " << vertex << "]>  {";
    DFS (vertex, visited);
    std::cout << "\b}\n";
    delete[] visited;
  }

  //[DESC]: This method displays the Breadth-First Search (BFS) traversal on the graph 
  //        starting from the given vertex. It calls the private BFS method. 
  //        See BFS for more details.
  //
  //[THROW]: std::invalid_argument if the starting vertex index is invalid.
  //
  //[PARAM]: vertex The index of the vertex to start the BFS traversal from.
  //
  //[PRE]: The graph must be initialized, and the provided vertex index should be within the graph bounds.
  //[POST]: The BFS traversal starting from the specified vertex is displayed on the standard output.
  void Graph::DisplayBFS (unsigned int vertex) const
  {
    if (vertex >= m_NumOfVertices)
    {
      throw std::invalid_argument ("[G]DisplayBFS(...) [Invalid starting Index]");
    }

    bool* visited = new (std::nothrow) bool[m_NumOfVertices];
    for (unsigned int i = 0; i < m_NumOfVertices; i++)
    {
      visited[i] = false;
    }

    std::cout << "\n<[BFS at Vertex: " << vertex << "]> {";
    BFS (vertex, visited);
    std::cout << "\b}\n\n";
    delete[] visited;
  }
}