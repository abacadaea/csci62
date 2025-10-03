#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void print_queue(queue<int> q)
{
  cout << "q: ";
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
    adjLists_.push_back(set<int> ());
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

  // PRACTICE: What is wrong with this BFS?
  void BFS(int source) {
    queue<int> q;

    q.push(source);
    while (q.size() > 0) {
      int cur = q.front();
      q.pop();

      cout << "=====\ncur: " << cur << endl;
      print_queue(q);

      for (auto neighbor : adjLists_[cur]) {
          q.push(neighbor);
      }
      print_queue(q);
    }
  }
 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  vector<set<int> > adjLists_;
};


int main () {
  Graph G;
  G.addVertex();
  G.addVertex();
  G.addEdge(0,1);
  G.BFS(0);
}
