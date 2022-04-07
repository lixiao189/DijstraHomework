#include "Graph.h"
#include "util.h"
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

Graph::Graph(const std::string &pathToFile) { readGraphFromFile(pathToFile); }

Graph::~Graph() {}

// Add an edge from vertex u to vertex v
void Graph::addEdge(const std::string &u, const std::string &v, int weight) {
  const int uID = vertexIDMap[u];
  const int vID = vertexIDMap[v];

  edges.push_back({uID, vID, weight});
  if (firstEdge[uID] == -1) {
    // The first edge of vertex u
    nextEdge.push_back(-1);
  } else {
    // Set this edge as the header edge
    nextEdge.push_back(firstEdge[uID]);
  }

  firstEdge[uID] = edges.size() - 1;
}

void Graph::readGraphFromFile(const std::string &pathToFile) {
  // Clear all data in the graph
  edges.clear();
  firstEdge.clear();
  nextEdge.clear();
  vertexIDMap.clear();

  std::fstream fileStream(pathToFile);
  std::string inputLine;
  std::vector<std::string> command;

  int id = 0;
  while (!std::getline(fileStream, inputLine).eof()) {
    command.clear();
    split(inputLine, command);

    if (command.size()) {
      if (command[0] == "vertex") {
        vertexIDMap.insert(std::pair<std::string, int>(command[1], id));
        vertexName.insert(std::pair<int, std::string>(id, command[1]));
        id++;
        firstEdge.push_back(-1);
      } else if (command[0] == "edge") {
        addEdge(command[1], command[2], std::stoi(command[3].c_str()));
        addEdge(command[2], command[1], std::stoi(command[3].c_str()));
      }
    }
  }
}

int Graph::shortestPath(const std::string &u, const std::string &v) {
  // initialize the preVertex
  preVertex.clear();
  for (int i = 0; i < vertexIDMap.size(); i++)
    preVertex.push_back(-1);
  // define the infinity
  const int INF = 0x3f3f3f3f;
  // declare the heapnode
  struct HeapElement {
    int targetVertexID;
    int weight;

    bool operator>(const HeapElement &otherNode) const {
      return this->weight > otherNode.weight;
    }
  };
  std::priority_queue<HeapElement, std::vector<HeapElement>,
                      std::greater<HeapElement>>
      tmpHeap;
  std::vector<int> dis(vertexIDMap.size(), INF);
  // hadResult[i] represents the vertex_i has the find the shortest path to it
  std::vector<bool> hasResult(vertexIDMap.size(), false);

  // Get the id of source vertex and the target vertex
  int uID = (vertexIDMap.find(u))->second;
  int vID = (vertexIDMap.find(v))->second;
  // Store the target ID
  lastTargetID = vID;

  // Initialize the tmpHeap, dis and visited
  dis[uID] = 0;
  tmpHeap.push({uID, dis[uID]});

  HeapElement nearestVertex;
  int edgeID;
  while (!hasResult[vID]) {
    nearestVertex = tmpHeap.top();
    tmpHeap.pop();

    if (hasResult[nearestVertex.targetVertexID])
      continue;
    hasResult[nearestVertex.targetVertexID] = true;

    // Find all edges which nearestVertex connects with.
    edgeID = firstEdge[nearestVertex.targetVertexID];
    while (edgeID != -1) {
      if (!hasResult[edges[edgeID].v] &&
          edges[edgeID].weight + nearestVertex.weight < dis[edges[edgeID].v]) {
        dis[edges[edgeID].v] = edges[edgeID].weight + nearestVertex.weight;
        tmpHeap.push({edges[edgeID].v, dis[edges[edgeID].v]});

        // Store the previous vertex
        preVertex[edges[edgeID].v] = nearestVertex.targetVertexID;
      }
      edgeID = nextEdge[edgeID];
    }
  }

  return dis[vID];
}

std::string Graph::getShortestPath() {
  std::string path = "";
  std::vector<std::string> result; // Store the vertex in the shortest path
  for (int id = lastTargetID; id != -1; id = preVertex[id]) {
    result.push_back(vertexName[id]);
  }

  while (!result.empty()) {
    path += result.back();
    result.pop_back();

    if (!result.empty())
      path += "->";
  }

  return path;
}