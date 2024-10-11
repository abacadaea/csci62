#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

void print_stack(stack<int> s)
{
  stack<int> s2;
  while (!s.empty()) {
    s2.push(s.top());
    s.pop();
  }
  while (!s2.empty())
  {
    cout << s2.top() << " ";
    s2.pop();
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
    adjLists_.push_back(set<int>{});
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


  // what does this print out?

  void DFS(int source) {
    stack<int> stck;
    vector<bool> visited (n(), 0);

    visited[source] = true;
    stck.push(source);

    while (stck.size() > 0) {
      int cur = stck.top();
      stck.pop();
      for (auto neighbor : adjLists_[cur]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          stck.push(neighbor);
        }
      }
      // HERE
      // print statements added
      cout << "cur: " << cur << endl;
      cout << "stck: ";
      print_stack(stck);
      cout << "visited: ";
      for (int i = 0; i < n(); i ++) {
        cout << i << (visited[i] ? "T" : "F") << " ";
      }
      cout << endl << endl;
    }
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
