#include <vector>
#include <set>

class Graph {
public:
  // create an empty graph
  Graph() {}

  // add a new vertex
  void addVertex() { adjLists_.push_back(std::set<int> {}); }

  // add an edge between ith and jth vertex
  void addEdge(int i, int j) {
    adjLists_[i].insert(j);
    adjLists_[j].insert(i);
  }

 private:
  std::vector<std::set<int> > adjLists_;
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
}
