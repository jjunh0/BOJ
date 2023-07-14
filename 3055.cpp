#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

char b[55][55];
int waterCnt[55][55];
int sCnt[55][55];
void solve() {
  int r, c;
  cin >> r >> c;
  queue<pair<int, int>> s;
  queue<pair<int, int>> water;
  for(int i = 0; i < r; i ++) {
    for(int j = 0; j < c; j ++) { 
      cin >> b[i][j];
      if(b[i][j] == 'S') {
        s.push({i, j});
        sCnt[i][j] = 1;
      }
      if(b[i][j] == '*') {
        water.push({i, j});
        waterCnt[i][j] = 1;
      }
    } 
  }
  while(!water.empty()) {
    auto cur = water.front();
    water.pop();
    for(int i = 0; i < 4; i ++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(waterCnt[nx][ny] != 0 || b[nx][ny] == 'X' || 
      b[nx][ny] == 'D') continue;
      water.push({nx, ny});
      waterCnt[nx][ny] = waterCnt[cur.X][cur.Y] + 1;
    }
  }
  
  while(!s.empty()) {
    auto cur = s.front();
    s.pop();
    for(int i = 0; i < 4; i ++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(b[nx][ny] == 'D') {
        cout << sCnt[cur.X][cur.Y];
        return;
      }
      if(sCnt[nx][ny] != 0 || b[nx][ny] == 'X') continue;
      if(waterCnt[nx][ny] != 0 && waterCnt[nx][ny] <= sCnt[cur.X][cur.Y] + 1) continue;
      s.push({nx, ny});
      sCnt[nx][ny] = sCnt[cur.X][cur.Y] + 1;
    } 
  }
    // for(int i = 0; i < r; i ++) {
    // for(int j = 0; j < c; j ++) { 
    //   cout << sCnt[i][j] << ' ';
  // } cout << '\n';}
  cout << "KAKTUS";
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}