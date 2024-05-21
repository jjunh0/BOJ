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
int board[105][105];

int fac(int n) {
  if(n == 1) return n;
  return n * fac(n-1);
}

void solve() {
  int n, k, r;
  cin >> n >> k >> r;
  set<pair<pi, pi>> st;
  for(int i = 0; i < r; i ++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    st.insert({{x1, y1}, {x2, y2}});
    st.insert({{x2, y2}, {x1, y1}});
  }
  vector<pi> c;
  for(int i = 0; i < k; i ++) {
    int x, y;
    cin >> x >> y;
    c.pb({x, y});
    board[x][y] = 1;
  }
  vector<vector<int>> vis(n+5, vector<int>(n+5, 0));
  int cnt = 1;
  
  for(int i = 0; i < k; i ++) {
    if(vis[c[i].X][c[i].Y] != 0) continue;
    queue<pi> q;
    q.push({c[i].X, c[i].Y});
    vis[c[i].X][c[i].Y] = cnt;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if(vis[nx][ny] != 0) continue;
        if(st.find({{cur.X, cur.Y}, {nx, ny}}) != st.end()) {
          continue;
        }
        vis[nx][ny] = cnt;
        q.push({nx, ny});
      } 
    }
    cnt ++;
  }
  vector<int> cow(cnt+1, 0);
  for(int i = 0; i < k; i ++) {
    cow[vis[c[i].X][c[i].Y]] ++;
  }
  int ans = 0, num = 0;
  for(int i = 1; i < cnt; i ++) {
    num += cow[i];
    ans += cow[i] * (k-num);
  }
  cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
}