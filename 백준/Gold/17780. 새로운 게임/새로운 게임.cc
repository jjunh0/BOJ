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

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int board[15][15];
deque<int> cord[15][15];
tuple<int, int, int> h[15];

int change_dir(int dir) {
  if(dir == 0) return 1;
  if(dir == 1) return 0;
  if(dir == 2) return 3;
  return 2;
}

void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> board[i][j];
    }
  }
  for(int i = 1; i <= k; i ++) {
    int x, y, c;
    cin >> x >> y >> c;
    x --; y --; c --;
    h[i] = {x, y, c};
    cord[x][y].pb(i);
  }
  int ans = 0;
  bool flag = false;
  while(!flag && ans <= 1000) {
    ans ++;
    for(int i = 1; i <= k; i ++) {
      int x, y, dir;
      tie(x, y, dir) = h[i];
      if(cord[x][y][0] != i) continue;
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx  < 0 || nx >= n || ny < 0 || ny >= n
        || board[nx][ny] == 2) {
        dir = change_dir(dir);
        nx = x + dx[dir];
        ny = y + dy[dir];
        h[i] = {x, y, dir};
      }
      if(nx < 0 || nx >= n || ny < 0 || ny >=n) continue;
      if(board[nx][ny] == 0) {
        while(!cord[x][y].empty()) {
          cord[nx][ny].push_back(cord[x][y].front());
          h[cord[x][y].front()] = {nx, ny, get<2>(h[cord[x][y].front()])};
          cord[x][y].pop_front();
        }
      }
      else if(board[nx][ny] == 1) {
        reverse(all(cord[x][y]));
        while(!cord[x][y].empty()) {
          cord[nx][ny].push_back(cord[x][y].front());
          h[cord[x][y].front()] = {nx, ny, get<2>(h[cord[x][y].front()])};
          cord[x][y].pop_front();
        }
      }
    }
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < n; j ++) { 
        if(sz(cord[i][j]) >= 4) flag = true;
      } 
      // if(flag) break;
    }
  }
  if(ans > 1000) cout << -1;
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