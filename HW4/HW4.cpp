//[FILE]: HW4.cpp
//[AUTHOR]: Jakob Balkovec (CPSC 2600)
//[INSTRUCTOR]: S. Oh (CPSC 2600)
//
//[DATE]: Sun 12th Nov
//
//[DESC]: -This file contains the definition of the Graph class.
//[NOTES]: - Takes command line arguments as input.
//         - Uses the GraphLibray namespace

#include <stdexcept>
#include <iostream>

#include "Graph.h"

using namespace GraphLibrary;

//If running Makefile from the terminal: make clean release run_input input_file=GraphFiles/<filename.txt>
//[NOTE]: Graph txt files are located in a subdir "GraphFiles"

//[PARAM]: argc The number of command-line arguments.
//[PARAM]: argv An array of strings representing the command-line arguments.
int main (int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cout << "Usage: " << argv[0] << " <input_file_path>" << std::endl;
            return EXIT_FAILURE;
        }

        Graph graph;
        graph.Load (argv[1]);
        constexpr int DefualtIndex = 0;

        graph.Display ();
        graph.DisplayDFS (DefualtIndex);
        graph.DisplayBFS (DefualtIndex);

    }
    catch (const std::exception& e) {
        std::cout << '\n' << e.what () << '\n';
        std::exit (EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
