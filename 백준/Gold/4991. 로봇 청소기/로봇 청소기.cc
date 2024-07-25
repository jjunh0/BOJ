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

void solve() {
  int n, m;
  while(cin >> m, cin >> n, n != 0 && m != 0) {
    vector<pi> d;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    int sx, sy;
    for(int i = 0; i < n; i ++) {
      string s;
      cin >> s;
      for(int j = 0; j < m; j ++) {
        if(s[j] == '*') d.pb({i, j});
        if(s[j] == 'x') board[i][j] = 1;
        if(s[j] == 'o') tie(sx, sy) = {i, j};
      }
    }
    d.pb({sx, sy});
    vector<vector<int>> dis(sz(d)+1, vector<int>(sz(d)+1, 0));
    for(int i = 0; i < sz(d); i ++) {
      queue<pi> q;
      vector<vector<int>> vis(n+1, vector<int>(m+1));
      q.push(d[i]);
      vis[d[i].X][d[i].Y] = 1;
      while(sz(q)) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir ++ ){ 
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(vis[nx][ny] || board[nx][ny]) continue;
          vis[nx][ny] = vis[cur.X][cur.Y] + 1;
          q.push({nx, ny});
        }
      }
      for(int j = 0; j < sz(d); j ++) {
        if(i == j) continue;
        dis[i][j] = vis[d[j].X][d[j].Y] - 1;
      }
    }
    vector<int> cand;
    for(int i = 0; i < sz(d)-1; i ++) {
      cand.pb(i);
    }
    int ans = MX;
    do {
      int cur = sz(d)-1;
      int sum = 0;
      for(int i = 0; i < sz(cand); i ++) {
        sum += dis[cur][cand[i]];
        if(dis[cur][cand[i]] == -1) {
          sum = MX;
          break;
        }
        cur = cand[i];
      }
      ans = min(ans, sum);
    } while(next_permutation(all(cand)));
    cout << (ans==MX ? -1 : ans) << nl;
  }
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