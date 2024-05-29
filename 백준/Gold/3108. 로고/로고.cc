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

int board[2005][2005];
bool vis[2005][2005];
void solve() {
  int n, sx = 1000, sy = 1000;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 *= 2; x2 *= 2; y1 *= 2; y2 *= 2;
    x1 += 1000; x2 += 1000; y1 += 1000; y2 += 1000;
    for(int x = x1; x <= x2; x ++) {
      board[x][y1] = 1;
    }
    for(int x = x1; x <= x2; x ++) {
      board[x][y2] = 1;
    }
    for(int y = y1; y <= y2; y ++) {
      board[x1][y] = 1;
    }
    for(int y = y1; y <= y2; y ++) {
      board[x2][y] = 1;
    }
  }  
  int ans = 0;
  for(int i = 0; i <= 2000; i ++) {
    for(int j = 0; j <= 2000; j ++) {
      if(!board[i][j] || vis[i][j]) continue;
      ans ++;
      queue<pi> q;
      q.push({i, j});
      vis[i][j] = 1;
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir ++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx > 2000 || ny < 0 || ny > 2000) continue;
          if(!board[nx][ny] || vis[nx][ny]) continue;
          q.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }
    }
  }
  if(vis[1000][1000]) ans --;
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