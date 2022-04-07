#include "Graph.h"
#include "util.h"

int main(int argc, char *argv[]) {
  auto parser = initCmdLineParser(argc, argv); // init the command line parser
  auto pathOfFile = parser.get<std::string>("path"); // get the path parameter

  Graph graph;

  graph.readGraphFromFile(pathOfFile); // read data from files

  // Output the length of the shortest path
  std::cout << "The length of the shortest path is" << std::endl
            << graph.shortestPath("s", "t") << std::endl;

  return 0;
}