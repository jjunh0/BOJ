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

int A[105][105];
int vis[105][105][5];
void solve() {
  int N, M;
  cin >> N >> M;
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  sx --, sy --, ex --, ey --;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      cin >> A[i][j];
    }
  }
  queue<ti> q;
  q.push({sx, sy, 1});
  vector<vector<int>> dx = {
    {-1, 1, 0, 0}, {-1, 1}, {0, 0}
  }, dy = {
    {0, 0, -1, 1}, {0, 0}, {-1, 1}
  };
  memset(vis, MX, sizeof(vis));
  vis[sx][sy][1] = 0;
  while(!q.empty()) {
    auto [cx, cy, k] = q.front();
    q.pop();
    int nk = (k+1)%3;
    for(int dir = 0; dir < sz(dx[k]); dir ++) {
      int nx = cx + dx[k][dir], ny = cy + dy[k][dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(A[nx][ny] == -1 || (vis[nx][ny] != 0 && vis[cx][cy][k] + A[nx][ny] >= vis[nx][ny][nk])) continue;
      vis[nx][ny][nk] = vis[cx][cy][k] + A[nx][ny];
      q.push({nx, ny, nk}); 
    }
  }
  int ans = *min_element(vis[ex][ey], vis[ex][ey]+3);
  cout << (ans == MX ? -1 : ans);
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