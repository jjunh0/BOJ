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
char board[105][105];
bool vis[105][105];
vector<bool> key(30);
queue<pi> adj[30];
queue<pi> q;
int n, m;

int ans = 0;
void bfs(int i, int j) {
  q.push({i, j});
  vis[i][j] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    if(board[cur.X][cur.Y] == '$') ans ++;
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
      if(board[nx][ny] == '*' || vis[nx][ny]) continue;
      if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
        if(!key[board[nx][ny]-'A']) {
          adj[board[nx][ny]-'A'].push({nx, ny});
          vis[nx][ny] = 1;
          continue;
        }
      }
      if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
        if(!key[board[nx][ny]-'a']) {
          while(!adj[board[nx][ny]-'a'].empty()) {
            auto nxt = adj[board[nx][ny]-'a'].front();
            q.push({nxt.X, nxt.Y});
            vis[nxt.X][nxt.Y] = 1;
            adj[board[nx][ny]-'a'].pop();
          }
          key[board[nx][ny]-'a'] = 1;
        }
      }
      q.push({nx, ny});
      vis[nx][ny] = 1;
    }
  }
}

void init() {
  for(int i = 0; i < 105; i ++) fill(board[i], board[i]+105, '.');
  for(int i = 0; i < 105; i ++) fill(vis[i], vis[i]+105, 0);
  q = queue<pi>();
  for(int i = 0; i < 30; i ++) adj[i] = queue<pi>();
  fill(all(key), 0);
}

void solve() {
  cin >> n >> m;
  init();
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      cin >> board[i][j];
    }
  }
  string s;
  cin >> s;
  if(s != "0")
    for(int keyi = 0; keyi < sz(s); keyi ++) key[s[keyi]-'a'] = 1;
  ans = 0;
  bfs(0, 0);
  cout << ans << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}