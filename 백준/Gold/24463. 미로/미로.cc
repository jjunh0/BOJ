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
int vis[2005][2005];
pi pre[2005][2005];
string A[2005];
int N, M;
void f(int &x, int &y) {
  for(int i = 0; i < N; i += N-1) {
    for(int j = 0; j < M; j ++) {
      if(A[i][j] == '.') {
        x = i, y = j;
        return;
      }
    }
  }
  for(int j = 0; j < M; j += M-1) {
    for(int i = 0; i < N; i ++) {
      if(A[i][j] == '.') {
        x = i, y = j;
        return;
      }
    }
  }
}

void print() {
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      if(A[i][j] == 'x') cout << '.';
      else if(A[i][j] == '.') cout << '@';
      else cout << '+';
    }
    cout << nl;
  }
}

void solve() {
  cin >> N >> M;
  for(int i = 0; i < N; i ++) {
    cin >> A[i];
  }
  queue<pi> q;
  int sx, sy;
  f(sx, sy);
  q.push({sx, sy});
  vis[sx][sy] = 1;
  pre[sx][sy] = {-1, -1};
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
        if(cur.X == sx && cur.Y == sy) continue;
        int x = cur.X, y = cur.Y;
        while(x != -1 && y != -1) {
          A[x][y] = 'x';
          tie(x, y) = pre[x][y];
        }
        print();
        return;
      }
      if(A[nx][ny] == '+' || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      pre[nx][ny] = {cur.X, cur.Y};
      q.push({nx, ny});
    }
  }
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