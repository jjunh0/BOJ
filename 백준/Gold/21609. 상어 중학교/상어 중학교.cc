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
int board[25][25], tmp[25][25];
vector<vector<bool>> vis(25, vector<bool>(25));
int n, m;
int sz = 2, rcnt = 0, gx = -1, gy = -1;
void bfs(int i, int j, bool flag) {
    for(int i = 0; i < n; i ++) fill(all(vis[i]), 0);
    queue<pi> q;
    int cur_val = board[i][j];
    q.push({i, j});
    vis[i][j] = 1;
    if(flag) board[i][j] = -2;
    int cur_cnt = 1, cur_rcnt = 0, cur_sum = board[i][j];
    int xx=i, yy=j;
    while(sz(q)) {
      auto cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(vis[nx][ny] || board[nx][ny] < 0) continue;
        if(board[nx][ny] > 0 && board[nx][ny] != cur_val) continue;
        if(board[nx][ny] == 0) cur_rcnt ++;
        if(board[nx][ny] == cur_val) {
          if(i*n+j > nx*n+ny) {
            i = nx;
            j= ny;
          }
        }
        cur_cnt ++;
        cur_sum += board[nx][ny];
        vis[nx][ny] = 1;
        q.push({nx, ny});
        if(flag) board[nx][ny] = -2;
      }
    }
    if(flag) return;
    if(cur_cnt > sz ||
      (cur_cnt == sz && cur_rcnt > rcnt) ||
      (cur_cnt == sz && cur_rcnt == rcnt && i > gx) ||
      (cur_cnt == sz && cur_rcnt == rcnt && i == gx && j > gy)) {
      gx = i;
      gy = j;
      sz = cur_cnt;
      rcnt = cur_rcnt;
    }
}

void grav() {
  for(int j = 0; j < n; j ++) {
    int cur = n-1;
    for(int i = n-1; i >= 0; i --) {
      if(board[i][j] == -1) {
        cur = i-1;
      } 
      if(board[i][j] >= 0) {
        int b = board[i][j];
        board[i][j] = -2;
        board[cur--][j] = b;
      }
    }
  }
}

void rot() {
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      tmp[i][j] = board[j][n-1-i];
    }
  }
  swap(tmp, board);
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) { 
      cin >> board[i][j];
    } 
  }
  int ans = 0;
  while(1) {
    sz = 0; rcnt = 0; gx = -1; gy = -1;
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < n; j ++) {
        if(board[i][j] <= 0) continue;
        bfs(i, j, 0);
      }
    }
    if(sz < 2) break;
    ans += sz * sz;
    bfs(gx, gy, 1); 

    grav();
    rot();
    grav();

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