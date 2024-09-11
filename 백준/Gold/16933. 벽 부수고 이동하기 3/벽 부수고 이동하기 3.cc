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
typedef tuple<int, int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};
int vis[1005][1005][3][15];
string board[1005];
void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  for(int i = 0; i < N; i ++) {
      cin >> board[i];
  }
  queue<ti> q;
  vis[0][0][0][K] = 1;
  q.push({0, 0, 0, K});
  while(!q.empty()) {
    auto [x, y, d, k] = q.front();
    q.pop();
    for(int dir = 0; dir < 5; dir ++) {
      int nx = x + dx[dir], ny = y + dy[dir], nd = !d, nk = k;
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(dir < 4 && board[nx][ny] == '1') {
        if(nk > 0 && nd == 1) {
          nk --;
        }
        else {
          continue;
        }
      }
      if(vis[nx][ny][nd][nk]) continue;
      q.push({nx, ny, nd, nk});
      vis[nx][ny][nd][nk] = vis[x][y][d][k] + 1;
    }
  }
  int ans = MX;
  for(int i = 0; i <= 1; i ++) {
    for(int j = 0; j <= K; j ++) {
      if(vis[N-1][M-1][i][j])
        ans = min(ans, vis[N-1][M-1][i][j]);
    }
  }
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