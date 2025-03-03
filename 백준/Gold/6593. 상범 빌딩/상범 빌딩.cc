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
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

string A[35][35];
int vis[35][35][35];
int L, R, C, sz, sx, sy, zz, xx, yy;
void solve() {
  memset(&vis, 0, sizeof(vis));
  for(int i = 0; i < L; i ++) {
    for(int j = 0; j < R; j ++) {
      cin >> A[i][j];
      for(int k = 0; k < C; k ++) {
        if(A[i][j][k] == 'S') {
          tie(sz, sx, sy) = {i, j, k};
        }
        if(A[i][j][k] == 'E') {
          tie(zz, xx, yy) = {i, j, k};
        }
      }
    }
  }
  vis[sz][sx][sy] = 1;
  queue<ti> q;
  q.push({sz, sx, sy});

  while(!q.empty()) {
    auto [z, x, y] = q.front();
    q.pop();
    for(int dir = 0; dir < 6; dir ++) {
      int nz = dz[dir] + z;
      int nx = dx[dir] + x;
      int ny = dy[dir] + y;
      if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if(A[nz][nx][ny] == '#' || vis[nz][nx][ny] > 0) continue;
      vis[nz][nx][ny] = vis[z][x][y] + 1;
      q.push({nz, nx, ny});
    }
  }
  if(vis[zz][xx][yy] > 0) {
    cout << "Escaped in " << vis[zz][xx][yy]-1 <<  " minute(s).\n";
  }
  else {
    cout << "Trapped!\n";
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        solve();
    }
}