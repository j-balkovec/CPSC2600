//[FILE]: Graph.h
//[AUTHOR]: Jakob Balkovec (CPSC 2600)
//[INSTRUCTOR]: S. Oh (CPSC 2600)
//
//[DATE]: Sun 12th Nov
//
//[REVISION HISTORY]
//- 1.0 [11/08/2023]: Initial class design
//- 2.0 [11/12/2023]: Debugging and Documentation
//
//[DESC]: -This file contains the definition of the Graph class.
//[COMPILATION FLAGS]: -std=c++11 
//                     -Wall
//                     -Wextra
//                     -pedantic
//                     -Werror 
//                     -Wshadow
//                     -Wconversion
//                     -Wuninitialized 
//                     -Wunused 
//                     -Wreorder 
//                     -Weffc++
//[VALGRIND]: valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file="p4_valgrind.log" ./main

#include <new>
#include <algorithm>

#pragma once

namespace GraphLibrary {
  class Graph
  {
  private:
    size_t m_NumOfVertices = 0;
    unsigned int** m_AdjacencyList = nullptr;

    void DFS (int vertex, bool* visited) const;
    void BFS (int vertex, bool* visited) const;

    //[NOTE]: To omit effc++ compiler flag
    Graph (const Graph& other) = delete;
    Graph& operator=(const Graph& other) = delete;

  public:
    Graph ();
    ~Graph ();

    void Load (const char* filename);
    void Display () const;
    void DisplayDFS (unsigned int vertex) const;
    void DisplayBFS (unsigned int vertex) const;
  };
}