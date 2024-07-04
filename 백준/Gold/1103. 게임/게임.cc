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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[55][55];
int n, m;
int dp[55][55];
bool vis[55][55];
int func(int x, int y) { // x,y 부터 끝가지 가능한 턴 수의 최대값
  if(dp[x][y] != -1) return dp[x][y];
  int ret = 1;
  for(int dir = 0; dir < 4; dir ++) {
    int nx = x + board[x][y] * dx[dir];
    int ny = y + board[x][y] * dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(board[nx][ny] == 0) continue;
    if(vis[nx][ny])
      return MX;
    vis[nx][ny] = 1;
    ret = max(ret, 1 + func(nx, ny));
    vis[nx][ny] = 0;
  }
  dp[x][y] = ret;
  return ret;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < 55; i ++) fill(dp[i], dp[i]+55, -1);
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j ++) {
      if(s[j] == 'H') board[i][j] = 0;
      else board[i][j] = s[j]-'0';
    }
  }
  vis[0][0] = 1;
  int ans = func(0, 0);
  if(ans >= MX) cout << -1;
  else cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}