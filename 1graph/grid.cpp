#include <iostream>
#include <queue>

using namespace std;

// pre: grid is a rectangular n x m grid of 0s and 1s. 
//      0 means lava, 1 means soild ground
//      grid[0][0] and grid[n-1][m-1] are guaranteed to be 1
// post: return true if can reach (n-1,m-1) from (0,0) by moving to adjacent squares
bool canReach(vector<vector<bool> > grid) {
  int n = grid.size();
  int m = grid[0].size();

  queue<pair<int,int> > q; // queue<int> q;
  // vector<bool> visited (n(), 0); // n() = num vertices
  vector<vector<bool> > visited (n, vector<bool> (m, false)); 

  visited[0][0] = true; // visited[source] = true;
  q.push(pair<int,int> (0,0)); // q.push(source);

  while (q.size() > 0) {
    pair<int,int> cur = q.front(); // int cur = q.front();
    q.pop();

    // (x,y) is current grid square
    int x = cur.first;
    int y = cur.second;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    //for (int neighbor : adjLists_[cur]) {
    for (int i = 0; i < 4; i ++) {
      int newx = x + dx[i];
      int newy = y + dy[i];

      // (newx,newy) is one of (x+1,y), (x-1,y), (x,y+1), (x,y-1)

      // issue: if (x,y)=(0,0), i=1, (newx,newy) = (-1,0)

      //if (!visited[neighbor]) {
      if (newx >= 0 && newx < n && newy >= 0 && newy < m) { // check valid grid square
        if (grid[newx][newy] == 1) { // check (newx,newy) is solid ground
          if (!visited[newx][newy]) {
            visited[newx][newy] = true; // visited[neighbor] = true;
            q.push(pair<int,int> (newx,newy)); // q.push(neighbor);
          }
        }
      }
    }
  }

  return visited[n-1][m-1];
}

int main () {
  vector<vector<bool> > grid;
  grid = vector<vector<bool> > {
             vector<bool> {1,1,0},
             vector<bool> {0,1,1},
             vector<bool> {0,0,1}};
  assert(canReach(grid) == true);

  grid = vector<vector<bool> >{
             vector<bool> {1,0,0},
             vector<bool> {0,1,1},
             vector<bool> {0,0,1}};
  assert(canReach(grid) == false);
}
