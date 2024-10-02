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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int B[505][505];

void solve() {
  int N, M, sx, sy, ex, ey;
  cin >> N >> M;
  memset(B, -1, sizeof(B));
  vector<string> A(N);
  for(auto &e : A) cin >> e;
  vector<pi> wall;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      if(A[i][j] == '+') wall.pb({i, j});
    }
  }
  queue<pi> q;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      if(A[i][j] == '+') {
        q.push({i, j});
        B[i][j] = 0;
      }
      if(A[i][j] == 'V') {
        sx = i, sy = j;
      }
      else if(A[i][j] == 'J') {
        ex = i, ey = j;
      }
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(B[nx][ny] != -1) continue;
      B[nx][ny] = B[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  // for(int i = 0; i < N; i ++) {
  //   for(int j = 0; j < M; j ++) {
  //     cout << B[i][j] << ' ';
  //   }
  //   cout << nl;
  // }
  int st = 0, en = 1005;
  while(st + 1 < en) {
    int mid = (st+en)/2;
    if(B[sx][sy] < mid) {
      en = mid;
      continue;
    }
    vector<vector<int>> vis(N, vector<int>(M, 0));
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(vis[nx][ny] || B[nx][ny] < mid) continue;
        q.push({nx, ny});
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      }
    }
    if(vis[ex][ey] != 0) st = mid;
    else en = mid; 
  }
  cout << st;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}