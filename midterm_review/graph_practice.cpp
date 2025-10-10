#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
public:
  // create an empty graph
  Graph() {}

  // add a new vertex
  void addVertex() { adjLists.push_back(set<int> {}); }

  // add an edge between ith and jth vertex
  void addEdge(int i, int j) {
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }

  vector<pair<int,int> > getEdgeList() {
    // solution 1 
    vector<pair<int,int> > answer;
    int n = adjLists.size();
    for (int i = 0; i < n; i ++) {
      for (int j : adjLists[i]) {
        if (i < j) 
          answer.push_back(pair<int,int> (i,j));
      }
    }
    return answer;
    // solution 2
    /*
    set<pair<int,int> > answerSet;
    int n = adjLists.size();
    for (int i = 0; i < n; i ++) {
      for (int j : adjLists[i]) {
        //if (!answerSet.contains(pair<int,int>(i,j))
        //&&  !answerSet.contains(pair<int,int>(j,i))) {
        if (!answerSet.contains(pair<int,int>(j,i))) {
          answerSet.insert(pair<int,int> (i,j));
        }
      }
    }
    vector<pair<int,int> > answer;
    for (pair<int,int> p : answerSet) {
      answer.push_back(p);
    }
    return answer;
    */
  }

  int shortestPath(int from, int to) {
    int n = adjLists.size();
    queue<int> q;
    vector<bool> vis(n,false);
    vector<int> dist(n,-1);

    q.push(from);
    vis[from] = true;
    dist[from] = 0;

    while (q.size() > 0) {
      int cur = q.front();
      q.pop();
      for (int neighbor: adjLists[cur]) {
        if (!vis[neighbor]) {
          vis[neighbor] = true;
          dist[neighbor] = dist[cur] + 1;
          q.push(neighbor);
        }
      }
    }
    return dist[to];
  }

  int diameter () {
    int n = adjLists.size();
    int diam = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        // return -1 if graph is disconnected
        int curDist = shortestPath(i,j);
        if (curDist == -1) return -1;

        // update max distance seen
        diam = max(diam, curDist);
        if(curDist > diam) diam = curDist;
      } 
    } 
    return diam;
  }

  int diameterFast() {
    int n = adjLists.size();
    int diam = 0;
    for (int from = 0; from < n; from ++) {
      // run BFS from 'from'
      queue<int> q;
      vector<bool> vis(n,false);
      vector<int> dist(n,-1);

      q.push(from);
      vis[from] = true;
      dist[from] = 0;

      while (q.size() > 0) {
        int cur = q.front();
        q.pop();
        for (int neighbor: adjLists[cur]) {
          if (!vis[neighbor]) {
            vis[neighbor] = true;
            dist[neighbor] = dist[cur] + 1;
            q.push(neighbor);
          }
        }
      }
      // update diam with max distance seen so far
      for (int d : dist) {
        if (d == -1) return -1;
        diam = max(diam, d);
      }
    }
    return diam;
  }

  vector<int> dist5(int from) {
    // Run BFS
    int n = adjLists.size();
    queue<int> q;
    vector<bool> vis(n,false);
    vector<int> dist(n,-1);

    q.push(from);
    vis[from] = true;
    dist[from] = 0;

    while (q.size() > 0) {
      int cur = q.front();
      q.pop();
      for (int neighbor: adjLists[cur]) {
        if (!vis[neighbor]) {
          vis[neighbor] = true;
          dist[neighbor] = dist[cur] + 1;
          q.push(neighbor);
        }
      }
    }
    
    // Get answer from BFS
    vector<int> ans;
    for (int x = 0; x < n; x ++) {
      if (dist[x] == 5) {
        ans.push_back(x);
      }
    }
    return ans;
  }

 private:
   vector<set<int> > adjLists;
};

int main () {
  if (0) {
    Graph G = Graph();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(0,3);
    G.addEdge(0,2);

    vector<pair<int,int> > edgeList = G.getEdgeList();
    for (pair<int,int> p : edgeList) {
      cout << p.first << " " << p.second << endl;
    }
  } else { 
    Graph G2 = Graph();
    G2.addVertex();
    G2.addVertex();
    G2.addVertex();
    G2.addVertex();
    G2.addVertex();
    G2.addVertex();
    G2.addVertex();
    G2.addEdge(0,1);
    G2.addEdge(1,2);
    G2.addEdge(2,3);
    G2.addEdge(3,4);
    G2.addEdge(4,5);
    G2.addEdge(4,6);
    cout << "G2.diameter(): " << G2.diameter() << endl;
    cout << "G2.diameterFast(): " << G2.diameterFast() << endl;
    //cout << "G2.dist5(0): ";
    //vector<int> g2d5 = G2.dist5(0);
    //for (int x : g2d5) {
    //  cout << x << " ";
    //}
    //cout << endl;
  }
}
