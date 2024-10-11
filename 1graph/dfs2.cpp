#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>


class Graph {
public:
  Graph() {}
  int n() const {
    return adjLists_.size();
  }
  int m() const {
    int count = 0;
    for(auto list : adjLists_) {
        count += list.size();
    }
    return count / 2;
  }
  void addVertex() {
    adjLists_.push_back(std::set<int>{});
  }
  void addEdge(int i, int j) {
    adjLists_[i].insert(j);
    adjLists_[j].insert(i);
  }

  // what does this print?
  void DFSHelper(int cur, std::vector<bool> &visited) {
    // HERE
    std::cout << "cur: " << cur << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << (visited[i] ? "T" : "F") << " ";
    }
    std::cout << std::endl;

    for (auto neighbor : adjLists_[cur]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        DFSHelper(neighbor, visited);
      }
    }
  }

  void DFS(int source) {
    std::vector<bool> visited (n(), 0);
    visited[source] = true;
    DFSHelper(source, visited);
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists_;
};


int main () {
  if (0) {
    // in class demo
    Graph G;
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(4,3);
    G.addEdge(0,4);

    G.DFS(0);
  } else {
    // in class exercise
    Graph G;
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(3,5);
    G.addEdge(4,3);
    G.addEdge(0,4);

    G.DFS(4);
  }
}
