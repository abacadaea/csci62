#include <vector>
#include <set>

class Graph {
public:
  int n() { // returns the number of vertices in this Graph
    return adjLists.size(); 
 
  }
  int m() { // returns the number of edges in this Graph
    int count = 0;
    for (auto list : adjLists) {
      count += list.size();
    }
    return count / 2;

    /*
    for (int i = 0; i < adjLists.size(); i ++) {
      count += adjLists[i].size();
    }
    return count / 2;
    */
  }
  void addVertex() { // Add new vertex
    adjLists.push_back(std::set<int> ());

  }
  void addEdge(int i, int j) { // add edge (i,j) to the Graph
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }
  bool areAdjacent(int i, int j) { // return true if (i,j) is an edge
                                     // check if j is in adjLists[i]
    return (adjLists[i].find(j) != adjLists[i].end());
    /*
    if (adjLists[i].find(j) != adjLists[i].end()) {
      return true; 
    } else {
      return false;
    }*/
  }
 private:
  std::vector<std::set<int> > adjLists;
};

int main () {

}
