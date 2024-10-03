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

int A[3005][3005], vis[3005][3005];
void solve() {
  int N,M,Q;
  cin >> N >> M;
  cin >> Q;
  while(Q--) {
    int r, c, d;
    cin >> r >> c >> d;
    r --, c--;
    A[r][c] = 1;
    for(int j = max(0,c-d); j <= min(M, c+d); j ++) {
      int sub = d - abs(c-j);
      int x1 = r+sub, x2 = r-sub;
      if(x1 >= 0 && x1 < N) A[x1][j] = 1;
      if(x2 >= 0 && x2 < N) A[x2][j] = 1;
    }
  }

  
  queue<pi> q;
  q.push({0, 0});
  vis[0][0] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx>= N || ny < 0|| ny>=M) continue;
      if(A[nx][ny] || vis[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
    }
  }
  if(vis[N-1][M-1]) {
    cout << "YES\n" << vis[N-1][M-1]-1;
  }
  else cout << "NO\n";

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