#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>

using namespace std;


class Digraph {
public:
  Digraph(){}
  int n() {
    return outAdjList.size();
  }
  int m() {
    int ans = 0;
    for (auto list : outAdjList) {
      ans += list.size();
    }
    return ans;
  }
  void addVertex() {
    outAdjList.push_back(set<int> ());
  }
  void addEdge(int id1, int id2) {
    outAdjList[id1].insert(id2);
  }
  bool canReach(int from, int to) {
    vector<bool> visited(n(), 0);
    stack<int> stck;
    visited[from] = true;
    stck.push(from);
    while(!stck.empty()) {
      int cur = stck.top();
      stck.pop();
      for (auto neighbor : outAdjList[cur]) {
        if (!visited[neighbor]) { 
          visited[neighbor] = true; 
          stck.push(neighbor);
        }
      }
    }
    return visited[to];
  }
private:
  vector<set<int> > outAdjList;
};

  
int main() {
    Digraph G;
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(2,1);
    G.addEdge(1,3);
    G.addEdge(3,2);
    G.addEdge(4,0);
    G.addEdge(4,1);
    G.addEdge(4,3);
    
    for (int i = 0; i <= 4; i ++) {
      for (int j = 0; j <= 4; j ++) {
        bool isReach = G.canReach(i,j);
        cout << i << " can"  << (isReach ? " " : "not ")  <<  "reach " << j << endl;
      }
    }
    return 0;
}

