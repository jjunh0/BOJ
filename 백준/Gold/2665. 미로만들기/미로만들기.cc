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

int board[55][55];
int vis[55][55][55];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j ++) {
      board[i][j] = s[j]-'0';
    }
  }
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  vis[0][0][0] = 1;
  while(!q.empty()) {
    int x, y, z;
    tie(x, y, z) = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z;
      if(nx < 0 || nx >= n || ny < 0 || ny >= n || nz >= 50) continue;
      if(board[nx][ny] == 1) {
        if(vis[nx][ny][nz] != 0) continue;
      }
      else {
        nz ++;
        if(vis[nx][ny][nz] != 0) continue;
      }   
      q.push({nx, ny, nz});
      vis[nx][ny][nz] = 1;
    }
  }

  for(int i = 0; i < 55; i ++) {
    if(vis[n-1][n-1][i] != 0) {
      cout << i;
      return;
    }
  }
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