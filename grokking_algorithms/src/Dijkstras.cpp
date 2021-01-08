/*
 * Dijkstras.cpp
 *
 * Implementation of Dijkstra's Algorithm.
 *
 * Bryant Pong
 * 12/27/20
 */
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

/*
 * Graph representation.  Represented by a hash table with a string key for a
 * node and a hash table value associating that node's neighbors with the cost
 * to get to the neighbor from this node.
 */
std::unordered_map<std::string, std::unordered_map<std::string, int> > GRAPH {
  {"start", {{"a", 6}, {"b", 2}}},
  {"a", {{"end", 1}}},
  {"b", {{"a", 3}, {"end", 5}}},
  {"end", {}}
};

/*
 * Cost table.  Hash table with a string identifier for a node and an integer
 * value denoting the cost it takes to reach that node from the START.
 */
std::unordered_map<std::string, int> COSTS {
  // In the beginning, we know costs from START for nodes A and B.
  {"a", 6},
  {"b", 2},
  {"end", std::numeric_limits<int>::max()}
};

/*
 * Parent table.  Hash table associating a string key for a node and a string
 * value for its parent.
 */
std::unordered_map<std::string, std::string> PARENTS {
  {"a", "start"},
  {"b", "start"},
  {"end", ""}
};

// Visited nodes
std::unordered_set<std::string> visited;

/*
 * Helper function to find the next non-visited lowest-cost node.
 */
std::string FindNextNode() {
  std::string nextNode;
  std::unordered_map<std::string, int>::iterator itr = COSTS.begin();

  int lowestCost = std::numeric_limits<int>::max();
  for (; itr != COSTS.end(); ++itr) {
    if (visited.find(itr->first) == visited.end()) {
      const int nextCost = itr->second;
      if (nextCost <= lowestCost) {
        lowestCost = nextCost;
        nextNode = itr->first;
      }
    }
  }

  return nextNode;
}

template <typename T> void DisplayHT(const T& ht) {

}

int main(void) {
  /*
   * !!!! Dijkstra's only works on directed acyclical graphs with no negative
   * weights!
   *
   * Dijkstra's Algorithm steps:
   * Repeat for each node in the graph:
   * 1) Find the next non-visited cheapest node from the start.
   * 2) Update costs for that node's neighbors.
   * 3) If any neighbors' cost was updated, also update that neighbor's parent.
   *
   * To find the lowest cost from start to end, start with the end node and use
   * the parent hash table to traverse backwards to the start.
   */
  std::string nextNode(FindNextNode());
  while (nextNode != "") {
    const std::unordered_map<std::string, int> neighbors = GRAPH[nextNode];
    const int nodeCost = COSTS[nextNode];

    // Update costs for this node's neighbors
    std::unordered_map<std::string, int>::const_iterator itr =
      neighbors.begin();
    for (; itr != neighbors.end(); ++itr) {
      // Compute new cost from nextNode to this neighboring node
      const int newCost = nodeCost + itr->second;

      // If the new cost is cheaper than the old, update the cost and parent
      if (newCost < COSTS[itr->first]) {
        COSTS[itr->first] = newCost;
        PARENTS[itr->first] = nextNode;
      }
    }

    visited.insert(nextNode);

    // Get the next lowest-code node
    nextNode = FindNextNode();
  }

  // Construct the cheapest path from start to end
  std::cout << "Reconstructing cheapest path" << std::endl;
  std::stack<std::string> finalPath;
  nextNode = "end";
  finalPath.push(nextNode);

  while(nextNode != "start") {
    nextNode = PARENTS[nextNode];
    finalPath.push(nextNode);
  }

  std::cout << "Final Path:" << std::endl;
  while (!finalPath.empty()) {
    std::cout << finalPath.top() << std::endl;
    finalPath.pop();
  }

  return 0;
}
