#include "Graph.h"
#include "util.h"

int main(int argc, char *argv[]) {
  auto parser = initCmdLineParser(argc, argv); // init the command line parser
  auto pathToFile = parser.get<std::string>("file"); // get the path parameter
  auto s = parser.get<std::string>("source");
  auto t = parser.get<std::string>("target");

  Graph graph(pathToFile);

  // Output the length of the shortest path
  std::cout << "The length of the shortest path is " << graph.shortestPath(s, t)
            << std::endl;

  std::cout << "The last performed shortestPath is: " << graph.getShortestPath()
            << std::endl;
  return 0;
}