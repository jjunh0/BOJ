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
string board[55];
int p[2505];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return 1;
  p[a] = b;
  return 0;
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> key;
  fill(p, p+2505, -1);
  for(int i = 0; i < N; i ++) {
    cin >> board[i];
    for(int j = 0; j < N; j ++) {
      if(board[i][j] == 'S' || board[i][j] == 'K') key.pb(i*N+j);
    }
  }
  vector<ti> adj;
  for(int i = 0; i < sz(key); i ++) {
    int x = key[i]/N, y = key[i]%N;
    queue<pi> q;
    q.push({x, y});
    vector<vector<int>> vis(N, vector<int>(N, 0));
    vis[x][y] = 1;
    while(sz(q)) {
      auto cur = q.front();
      q.pop();
      if(board[cur.X][cur.Y] == 'S' || board[cur.X][cur.Y] == 'K') {
        adj.pb({vis[cur.X][cur.Y]-1, key[i], cur.X*N+cur.Y});
      }
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(board[nx][ny] =='1' || vis[nx][ny]) continue;
        q.push({nx, ny});
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      }
    }
  }
  sort(all(adj));
  int ans = 0, cnt = 0;
  for(int i = 0; i < sz(adj); i ++) {
    auto [cost, a, b] = adj[i];
    if(merge(a, b)) continue;
    ans += cost;
    cnt ++;
  }
  cout << (cnt == K ? ans : -1);
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