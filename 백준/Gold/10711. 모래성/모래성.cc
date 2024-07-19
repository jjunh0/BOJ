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
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
int board[1005][1005];
void solve() {
  int n, m;
  cin >> n >> m;
  queue<ti> q;
  for(int i = 0 ; i < n; i ++) {
    string s;
    cin >> s;
    for(int j =0; j < m; j ++) {
      if(s[j] == '.') {
        board[i][j] = 0;
        q.push({0, i, j});
      }
      else board[i][j] = s[j]-'0';
    }
  }
  int ans = 0;
  while(sz(q)) {
    auto [stage, xx, yy] = q.front();
    q.pop();
    ans = max(stage, ans);
    for(int dir = 0; dir < 8; dir ++) {
      int nx = xx + dx[dir];
      int ny = yy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 0) continue;
      board[nx][ny] --;
      if(board[nx][ny] == 0) {
        q.push({stage+1, nx, ny});
      }
    }
  }

  cout << ans;
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