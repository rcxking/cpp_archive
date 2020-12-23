/*
 * BreadthFirstSearch.cpp
 *
 * Example of performing breadth-first search on a graph of people.
 *
 * Bryant Pong
 * 12/27/20
 */
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Use a hash table to represent the graph.  Key is the person's name and the
 * value is a vector of that person's friends.
 */
std::unordered_map<std::string, std::vector<std::string> >
  FRIEND_GRAPH = {
  {"you", {"alice", "bob", "claire"}},
  {"bob", {"anuj", "peggy"}},
  {"claire", {"thom", "jonny"}},
  {"alice", {"peggy"}},
  {"anuj", {}},
  {"thom", {}},
  {"jonny", {}},
  {"peggy", {}}
};

bool BreadthFirstSearch(const std::string &searchName) {
  // Start searching from yourself
  std::unordered_set<std::string> visited;
  std::queue<std::string> toVisit;
  toVisit.push("you");

  while (!toVisit.empty()) {
    const std::string nextName = toVisit.front();
    toVisit.pop();

    std::cout << "nextName: " << nextName << std::endl;
    // Check if we've found the searchName
    if (nextName == searchName)
      return true;

    // Check if we've already visited this person
    if (visited.find(searchName) != visited.end()) {
      // Visited
      continue;
    }
    visited.insert(searchName);

    // Add nextName's friends
    std::vector<std::string> friends = FRIEND_GRAPH[nextName];
    for (size_t i = 0; i < friends.size(); ++i)
      toVisit.push(friends[i]);
  }

  return false;
}

int main(int argc, char *argv[]) {
  // Ensure user specifies name they are looking for
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <name>" << std::endl;
    return -1;
  }

  const std::string searchName(argv[1]);
  const bool found = BreadthFirstSearch(searchName);
  if (!found)
    std::cout << "Could not find name: " << searchName << std::endl;
  else
    std::cout << "Found name: " << searchName << " in graph" << std::endl;

  return 0;
}
