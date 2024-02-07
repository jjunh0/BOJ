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

int board[105][105];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cur = -1;
int n, m;

void dfs(int x, int y) {
  
  for(int dir = 0; dir < 4; dir ++) {
    int nx = dx[dir] + x;
    int ny = dy[dir] + y;
    if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
    if(board[nx][ny] == cur || board[nx][ny] == 1) continue;
    board[nx][ny] = cur;
    dfs(nx, ny);
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) { 
      cin >> board[i][j];
    } 
  }
  while(1) {
    board[0][0] = cur;
    dfs(0, 0);    
    bool flag = false;
    for(int i = 1; i <= n; i ++) {
      for(int j = 1; j <= m; j ++) {
        if(board[i][j] <= 0) continue;
        flag = true;
        int cnt = 0;
        for(int dir = 0; dir < 4; dir ++) {
          int nx = dx[dir] + i;
          int ny = dy[dir] + j;
          if(nx < 1 || nx > n+1 || ny < 1 || ny > m+1) continue;
          if(board[nx][ny] != cur) continue;
          cnt ++;
        }
        if(cnt >= 2) board[i][j] = 0;
      }
    }

      // for(int i = 0; i <= n+1; i ++) {
      //   for(int j = 0; j <= m+1; j ++) { 
      //     cout << board[i][j] << ' ';
      //   }
      //   cout << nl; 
      // }
      // cout << nl;
    if(!flag) {
      cout << -cur-1;
      return;
    }
    cur --;
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