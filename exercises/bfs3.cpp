#include <iostream>
#include <vector>
#include <set>
#include <queue>

class Graph {
public:
  // pre: none
  // post: an empty Graph has been created
  Graph() {}

  // pre: none
  // post: returns the number of vertices in this Graph
  int n() const {
    return adjLists_.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int count = 0;
    for(auto list : adjLists_) {
        count += list.size();
    }
    return count / 2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjLists_.push_back(std::set<int>{});
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    adjLists_[i].insert(j);
    adjLists_[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    adjLists_[i].erase(j); 
    adjLists_[j].erase(i); 
  }

  std::vector<int> shortestPath(int from, int to) {
    std::queue<int> q;
    std::vector<bool> visited (n(), 0);
    std::vector<int> prev (n(), -1);

    visited[from] = true;
    q.push(from);

    while (q.size() > 0) {
      int cur = q.front();
      q.pop();
      for (auto neighbor : adjLists_[cur]) {
        if (!visited[neighbor]) {
          prev[neighbor] = cur;
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    // print statements added
    for (int i = 0; i < n(); i ++) {
      std::cout << "prev[" << i << "]=" << prev[i] << std::endl;
    }
    // end print statements

    std::vector<int> output;
    int cur = to;
    while (cur != from) {
      output.push_back(cur);
      cur = prev[cur];
    }
    return output;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists_;
};


int main () {
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

  std::vector<int> path = G.shortestPath(4,2);
  std::cout << "Number of Vertices on Path: " << path.size() << std::endl << "Path: ";
  for (auto v : path) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}
