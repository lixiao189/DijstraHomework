#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>
#include <vector>

class Graph {
  struct Edge {
    int u; // vertex1 id
    int v; // vertex2 id
    int weight;
  };

private:
  // Store all edge in the vector
  std::vector<Edge> edges;
  // firstEdge[i] represents the vertex_i's first edge in the adjacency list;
  // -1 represents vertex_i ha no edge
  std::vector<int> firstEdge;
  // nextEdge[i] represents the next edge of edge_i.
  // -1 represents edge_i doesn't has next edge
  std::vector<int> nextEdge;
  // Store the id of vertex
  std::map<std::string, int> vertexIDMap;

public:
  Graph();
  ~Graph();

  void addEdge(const std::string &u, const std::string &v, int weight);
  int shortestPath(const std::string &u, const std::string &v) const;
  std::string getShortestPath() const;
  void readGraphFromFile(const std::string &pathToFile);
};
#endif