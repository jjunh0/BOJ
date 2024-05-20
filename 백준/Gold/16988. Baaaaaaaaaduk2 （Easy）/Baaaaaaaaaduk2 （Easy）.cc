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
int board[25][25];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      cin >> board[i][j];
    } 
  }
  int ans = 0;
  for(int x1 = 0; x1 < n; x1 ++) {
    for(int y1 = 0; y1 < m; y1 ++) {
      for(int x2 = 0; x2 < n; x2 ++) {
        for(int y2 = 0; y2 < m; y2 ++) {
          if(x1 == x2 && y1 == y2) continue;
          if(board[x1][y1] != 0 || board[x2][y2] != 0) continue;
          board[x1][y1] = 1; board[x2][y2] = 1;
          vector<vector<bool>> vis(25, vector<bool>(25, 0));
          int cnt = 0;
          for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
              if(vis[i][j] || board[i][j] != 2) continue;
              queue<pi> q;
              q.push({i, j});
              vis[i][j] = 1;
              int t = 1;
              bool flag = false;
              while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir ++) {
                  int nx = cur.X + dx[dir];
                  int ny = cur.Y + dy[dir];
                  if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                  if(board[nx][ny] == 0) {
                    flag = true;
                  }
                  if(board[nx][ny] == 1 || vis[nx][ny]) continue;
                  t ++;
                  q.push({nx, ny});
                  vis[nx][ny] = 1;
                }
              }
              if(!flag) {
                cnt += t;
              }
            }
          }
          ans = max(cnt, ans);
          board[x1][y1] = 0; board[x2][y2] = 0;
        }
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