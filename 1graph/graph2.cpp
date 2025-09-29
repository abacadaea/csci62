#include <iostream>
#include <vector>
#include <set>

using namespace std;

// REVIEW: How to implement these methods?
class Graph {
public:
  // # vertices
  int n() {
    return adjLists.size();
  }
  // # edges
  int m() {
    int sum = 0;
    for (set<int> list : adjLists) {
      sum += list.size();
    }
    return sum / 2;
  }
  // create new vertex
  void addVertex() { 
    adjLists.push_back(set<int>());
  }
  // add edge between vertex i and j
  void addEdge(int i, int j) {
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }
  // true iff i and j are adj
  bool areAdjacent(int i, int j) {
    return adjLists[i].contains(j);
  }
private:
  vector<set<int> > adjLists;
};

int main () {
  Graph G = Graph();
  G.addVertex();
  G.addVertex();
  G.addVertex();
  G.addVertex();
  G.addEdge(0,1);
  G.addEdge(1,2);
  G.addEdge(0,3);
  G.addEdge(0,2);
  cout << G.m() << endl;
}
