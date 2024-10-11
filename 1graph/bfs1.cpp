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
    adjLists_.push_back(set<int>());
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
  void BFS(int source) {
    queue<int> q;
    vector<bool> visited (n(), 0);

    visited[source] = true;
    q.push(source);

    cout << "===Before while loop===\n"; 
    cout << "q: "; print_queue(q); 
    cout << "visited: "; 
    for (int i = 0; i < n(); i ++) {
      cout << i << (visited[i] ? "x" : ".") << " "; 
    }
    cout << endl << endl
         << "===Inside while loop===\n"; 

    while (q.size() > 0) {
      int cur = q.front();
      q.pop();
      for (int neighbor : adjLists_[cur]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
      cout << "cur: " << cur << endl;
      cout << "q: "; print_queue(q);
      cout << "visited: "; 
      for (int i = 0; i < n(); i ++) {
        cout << i << (visited[i] ? "x" : ".") << " "; 
      }
      cout << endl << endl;
    }
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  vector<set<int> > adjLists_;
};


int main () {
  if (1) {
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

    G.BFS(2);
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

    G.BFS(4);
  }
}
