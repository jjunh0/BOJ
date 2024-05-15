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
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int board[55][55];
int cnt = 0, ans = mx;
vector<pi> v;
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      if(board[i][j] == 2) {
        v.pb({i, j});
      }
      if(board[i][j] != 1) {
        cnt ++;
      }
    }
  }
  cnt -= m;
  if(cnt == 0) {
    cout << 0 << nl;
    return;
  }
  vector<int> cand;
  for(int i = 0; i < sz(v); i ++) {
    if(i < m) cand.pb(0);
    else cand.pb(1);
  }
  do {
    vector<vector<int>> vis(55, vector<int>(55, 0));
    queue<pi> q;
    for(int i = 0; i < sz(cand); i ++) {
      if(cand[i] == 0) {
        vis[v[i].X][v[i].Y] = 1;
        q.push({v[i].X, v[i].Y});
      }
    }
    int cur_cnt = 0;
    bool flag = false;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir ++) {
        int nx = dx[dir] + cur.X;
        int ny = dy[dir] + cur.Y;
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny] == 1 || vis[nx][ny] != 0) continue;
        cur_cnt ++;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push({nx, ny});
        if(cur_cnt == cnt) {
          ans = min(ans, vis[nx][ny]);
          flag = true;
          break;
        }
      }
      if(flag) break;
    }
  } while(next_permutation(all(cand)));
  cout << (ans == mx ? -1 : ans-1);
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