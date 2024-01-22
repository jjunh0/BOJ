#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

int arr[205][205];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dx_[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy_[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dis[205][205][35];
void solve() {
  int k, n, m;
  cin >> k >> m >> n;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> arr[i][j];
    }
  }

  queue<pair<pair<int,int>, int>> q;
  q.push({{0, 0}, k});
  dis[0][0][k] = 1;
  while(!q.empty()) {
    auto cur = q.front().X;
    auto cur_k = q.front().Y;
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = dx[dir] + cur.X;
      int ny = dy[dir] + cur.Y;
      if(nx == n-1 && ny == m-1) {
        cout << dis[cur.X][cur.Y][cur_k];
        return;
      }
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dis[nx][ny][cur_k] > 0 || arr[nx][ny] == 1) continue;
      q.push({{nx, ny}, cur_k});
      dis[nx][ny][cur_k] = dis[cur.X][cur.Y][cur_k] + 1;
    }
    if(cur_k <= 0) continue;
    for(int dir = 0; dir < 8; dir ++) {
      int nx = dx_[dir] + cur.X;
      int ny = dy_[dir] + cur.Y;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dis[nx][ny][cur_k - 1] > 0 || arr[nx][ny] == 1) continue;
      if(nx == n-1 && ny == m-1) {
        cout << dis[cur.X][cur.Y][cur_k];
        return;
      }
      q.push({{nx, ny}, cur_k - 1});
      dis[nx][ny][cur_k - 1] = dis[cur.X][cur.Y][cur_k] + 1;
    }
  }
  if(n == 1 && m == 1) cout << 0;
  else cout << -1;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}