#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Graph {
public:
  // pre: none
  // post: an empty Graph has been created
  Graph() {}

  // pre: none
  // post: returns the number of vertices in this Graph
  int n() const {
    return adjLists.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int count = 0;
    for(auto list : adjLists) {
        count += list.size();
    }
    return count / 2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjLists.push_back(std::set<int>{});
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    adjLists[i].erase(j); 
    adjLists[j].erase(i); 
  }

  int shortestPathLength(int from, int to) {
    std::queue<int> q;
    std::vector<bool> visited (n(), 0);
    // goal: dist[i] = d(from, i)
    std::vector<int> dist (n(), -1);

    dist[from] = 0; 
    visited[from] = true;
    q.push(from);

    while (q.size() > 0) {
      int cur = q.front();
      q.pop();
      for (auto neighbor : adjLists[cur]) {
        if (!visited[neighbor]) {
          dist[neighbor] = dist[cur] + 1;
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  
    // return dist[to] = d(from, to)
    return dist[to]; 
  }

  set<pair<int, int> > getEdgeList() {
    set<pair<int, int> > output;
    for (int id1 = 0; id1 < n(); id1 ++) {
      for (int id2 : adjLists[id1]) {
        //if (output.contains(make_pair(id1,id2)) || output.contains(make_pair(id2,id1))) 
        //  continue; 
        if (id1 < id2) 
          output.insert(make_pair(id1,id2));
      }
    }
    return output;
  }

  vector<int> dist5 (int from) {
    vector<int> answer, answer2;

    // Part 1: BFS
    queue<int> q;
    vector<bool> vis(n(), false);
    vector<int> dist(n(), -1);

    q.push(from);
    vis[from] = true;
    dist[from] = 0;

    while (!q.empty()) {
      int cur = q.front();
      q.pop ();
      
      for (int neigh : adjLists[cur]) {
        if (!vis[neigh]) {
          q.push(neigh);
          vis[neigh] = true;
          dist[neigh] = dist[cur] + 1;
          if (dist[neigh] == 5) {
            answer2.push_back(neigh);
          } 
        }
      }
    }
    sort(answer2.begin(), answer2.end());

    // Part 2: Use the result of BFS
    for (int i = 0; i < n(); i ++) {
      if (dist[i] == 5) {
        answer.push_back(i);
      }
    }
    return answer;
  }

  int diameterSlow () {
    int diam = -1;
    for (int i = 0; i < n(); i ++) {
      for (int j = 0; j < n(); j ++) {
        if (shortestPathLength(i,j) == -1) 
          return -1;
        diam = max(diam, shortestPathLength(i,j));
      }
    }
    return diam;
  }

  int diameter() {
    int diam = 0;
    for (int from = 0; from < n(); from ++) {
      // copy-paste
      queue<int> q;
      vector<bool> visited (n(), 0);
      vector<int> dist (n(), -1);

      dist[from] = 0; 
      visited[from] = true;
      q.push(from);

      while (q.size() > 0) {
        int cur = q.front();
        q.pop();
        for (auto neighbor : adjLists[cur]) {
          if (!visited[neighbor]) {
            dist[neighbor] = dist[cur] + 1;
            visited[neighbor] = true;
            q.push(neighbor);
          }
        }
      }
      // end copy-paste
      

      for (int i = 0; i < n(); i ++) {
        if (dist[i] == -1) return -1; // graph is disconnected
        diam = max(diam, dist[i]);
      }
    }
    return diam;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists;
};


int main () {
  Graph G;
  G.addVertex();
  G.addVertex();
  G.addVertex();
  G.addVertex();
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
  G.addEdge(5,6);
  G.addEdge(6,7);
  G.addEdge(7,8);
  G.addEdge(8,9);

  std::cout << "Edge List: " << std::endl;
  set<pair<int,int> > edgeList = G.getEdgeList();
  for (pair<int,int> p : edgeList) {
    cout << p.first << " " << p.second << endl;
  }
  std::cout << "dist5(8): " << endl;
  vector<int> answer = G.dist5(9);
  for (int v: answer) {
    cout << v << " ";
  }
  cout << endl;
  std::cout << "Diameter: " << G.diameter() << std::endl;
  std::cout << "DiameterSlow: " << G.diameterSlow() << std::endl;
}
