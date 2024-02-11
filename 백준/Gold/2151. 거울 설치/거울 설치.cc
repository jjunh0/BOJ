#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// 위 아래 왼 오른
char board[55][55];
int vis[55][55][5];
void solve() {
  for(int i = 0; i < 55; i ++) {
    for(int j = 0; j < 55; j ++) {
      for(int k = 0; k < 5; k ++) {
        vis[i][j][k] = 5555;
      }
    }
  }
  int n;
  cin >> n;
  int xx, yy;
  bool flag = false;
  int tx, ty;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j ++) {
      board[i][j] = s[j];
      if(!flag && board[i][j] == '#') {
        tie(xx, yy) = {i, j};
        flag = true;
      }
      if(flag && board[i][j] == '#') tie(tx, ty) = {i, j};
    }
  }
  queue<tuple<int, int, int, int>> q;
  for(int i = 0; i < 4; i ++) {
    q.push({xx, yy, 1, i});
    vis[xx][yy][i] = 1;
  }
  while(!q.empty()) {
    int x, y ,z, dir;
    tie(x, y, z, dir) = q.front();
    q.pop();
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n || z > 2501) continue;
    if(board[nx][ny] == '!') {
      if(dir <= 1) {
        if(vis[nx][ny][2] > z+1) {
          vis[nx][ny][2] = z+1;
          q.push({nx, ny, z+1, 2});
        }
        if(vis[nx][ny][3] > z+1) {
          vis[nx][ny][3] = z+1;
          q.push({nx, ny, z+1, 3});
        }
      }
      else {
        if(vis[nx][ny][0] > z+1) {
          q.push({nx, ny, z+1, 0});
          vis[nx][ny][0] = z+1;
        }
        if(vis[nx][ny][1] > z+1) {
          q.push({nx, ny, z+1, 1});
          vis[nx][ny][1] = z+1; 
        }
      }
    }
    if(board[nx][ny] != '*') {
      if(vis[nx][ny][dir] > z) {
        q.push({nx, ny, z, dir});
        vis[nx][ny][dir] = z;
      }
    }
  }
  cout << *min_element(vis[tx][ty], vis[tx][ty] + 4) - 1;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}