/*
 * SetCovering.cpp
 *
 * Example program of implementing a greedy algorithm to find the minimum set of
 * sets to minimize the costs of advertising on radio stations.
 *
 * Bryant Pong
 * 1/5/21
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

// Typedefs
typedef std::set<std::string> StringSet;
typedef std::map<std::string, StringSet> StationMap;

// Set of states that need a radio station to cover them.
const StringSet STATES {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};

// Radio station coverage
const StationMap STATIONS {
  {"kone",   {"id", "nv", "ut"}},
  {"ktwo",   {"wa", "id", "mt"}},
  {"kthree", {"or", "nv", "ca"}},
  {"kfour",  {"nv", "ut"}},
  {"kfive",  {"ca", "az"}}
};

int main(void) {
  /*
   * Greedy algorithm is to perform the following:
   * 1) Add the station that covers the most uncovered states.
   * 2) Repeat until there are no uncovered states.
   */

  // Set holding the selected stations
  StringSet selectedStations;

  // Set holding states that still need coverage
  StringSet statesNeeded = STATES;

  while (statesNeeded.size() > 0) {
    // The next best station (most coverage) to select
    std::string nextStation;

    // The number of uncovered stations covered by nextStation
    size_t numCovered = 0;

    for (StationMap::const_iterator itr = STATIONS.begin(); itr !=
          STATIONS.end(); ++itr) {
      std::cout << "Evaluating station: " << itr->first << std::endl;

      // Count how many uncovered sets are covered by this station
      size_t i = 0;
      for (StringSet::const_iterator stateItr = itr->second.begin(); stateItr !=
            itr->second.end(); ++stateItr) {
        if (statesNeeded.find(*stateItr) != statesNeeded.end()) {
          // This is an uncovered station found
          ++i;
        }
      }

      // Does this station cover more uncovered stations than before?
      if (i > numCovered) {
        nextStation = itr->first;
        numCovered = i;
      }
    }

    // Add in the next station
    selectedStations.insert(nextStation);

    // Remove states covered by nextStation (if applicable)
    StationMap::const_iterator itr = STATIONS.find(nextStation);
    for (StringSet::iterator stationItr = itr->second.begin();
          stationItr != itr->second.end(); ++stationItr) {
      StringSet::iterator findItr = statesNeeded.find(*stationItr);
      if (findItr != statesNeeded.end()) {
        // Remove this state
        statesNeeded.erase(findItr);
      }
    }
  }

  // Output final result
  std::cout << "Minimum stations needed for complete coverage" << std::endl;
  for (StringSet::iterator itr = selectedStations.begin(); itr !=
        selectedStations.end(); ++itr) {
    std::cout << *itr << std::endl;
  }

  return 0;
}
