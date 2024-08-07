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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string board[105];
bool G[10005];
int cnt[10005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    cin >> board[i];
  }
  int q, cur = 0;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    t = n-t;
    if(cur%2 == 0) {
      for(int j = 0; j < m; j ++) {
        if(board[t][j] == 'x') {
          board[t][j] = '.';
          break;
        }
      }
    }
    else {
      for(int j = m-1; j >= 0; j --) {
        if(board[t][j] == 'x') {
          board[t][j] = '.';
          break;
        }
      }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cluster = 1;
    queue<pi> q;
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++) {
        if(vis[i][j] || board[i][j] == '.') continue;
        q.push({i, j});
        vis[i][j] = cluster;
        while(sz(q)) {
          auto cur = q.front();
          q.pop();
          for(int dir = 0; dir < 4; dir ++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '.' || vis[nx][ny]) continue;
            vis[nx][ny] = cluster;
            q.push({nx, ny});
          }
        }
        cluster ++;
      }
    }
    fill(G, G+10005, 0);
    fill(cnt, cnt+10005, MX);
    for(int j = 0; j < m; j ++) {
      if(board[n-1][j] == 'x') {
        G[vis[n-1][j]] = 1;
      }
    }
    for(int j = 0; j < m; j ++) {
      int bottom = n;
      for(int i = n-1; i >= 0; i --) {
        if(board[i][j] == '.') continue;
        if(G[vis[i][j]]) {
          bottom = i;
          continue;
        }
        cnt[vis[i][j]] = min(cnt[vis[i][j]], bottom-i-1);
      }
    }
    for(int j = 0; j < m; j ++) {
      for(int i = n-1; i >= 0; i --) {
        if(board[i][j] == '.' || G[vis[i][j]]) continue;
        swap(board[i][j], board[i+cnt[vis[i][j]]][j]);
      }
    }
    cur ++;

  }
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < m; j ++) { 
        cout << board[i][j];
      } 
      cout << nl;
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