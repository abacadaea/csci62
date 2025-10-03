#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void print_queue(queue<int> q)
{
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}


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

  vector<int> shortestPath(int from, int to) {
    queue<int> q;
    vector<bool> visited (n(), 0);
    // prev[v] is the vertex that visited/queued v
    vector<int> prev (n(), -1); // new

    visited[from] = true;
    q.push(from);

    cout << "=======Before loop======\n";
    cout << "q: " ;
    print_queue(q);
    cout << "prev: ";
    for (int i = 0; i < n(); i ++) {
      cout << prev[i] << " ";
    }
    cout << endl;

    while (q.size() > 0) {
      int cur = q.front();
      q.pop();
      for (auto neighbor : adjLists_[cur]) {
        if (!visited[neighbor]) {
          prev[neighbor] = cur; // new
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
      cout << "=============\n";
      cout << "cur: " << cur << endl;
      cout << "q: " ;
      print_queue(q);
      cout << "prev: ";
      for (int i = 0; i < n(); i ++) {
        cout << prev[i] << " ";
      }
      cout << endl;
    }
    vector<int> output;
    int cur = to;
    // version 1
    while (cur != -1 ) {
      output.push_back(cur);
      cur = prev[cur];
    }
    // version 2
    //while (cur != from ) {
    //  output.push_back(cur);
    //  cur = prev[cur];
    //}
    //output.push_back(from);
    reverse(output.begin(), output.end());
    return output;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  vector<set<int> > adjLists_;
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
    G.addEdge(0,4);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(3,4);

    vector<int> path = G.shortestPath(0,3);
    cout << "Number of Vertices on Path: " << path.size() << endl << "Path: ";
    for (auto v : path) {
      cout << v << " ";
    }
    cout << endl;
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

    std::vector<int> path = G.shortestPath(4,2);
    std::cout << "Number of Vertices on Path: " << path.size() << std::endl << "Path: ";
    for (auto v : path) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
}

