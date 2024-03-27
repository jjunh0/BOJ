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

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int board[25][25];
void solve() {
  int N, x, y;
  cin >> N;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      cin >> board[i][j];
      if(board[i][j] == 9) {
        x = i; y = j;
      }
    }
  }
  int cur_size = 2, cur_ate = 0;
  int ans = 0;
  while(1) {
    queue<pi> q;
    vector<vi> vis(25, vector<int>(25, 0));
    q.push({x, y});
    vis[x][y] = 1;
    bool flag = false;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      if(board[cur.X][cur.Y] != 0 && board[cur.X][cur.Y] < cur_size) {

      }
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(vis[nx][ny] != 0) continue;
        if(board[nx][ny] > cur_size) continue;
        vis[nx][ny] =  vis[cur.X][cur.Y] + 1;
        q.push({nx, ny});
      }
    }
    int min_dis = mx, mn_x, mn_y;
    for(int i = 0; i < N; i ++) {
      for(int j = 0; j < N; j ++) { 
        if(board[i][j] != 0 && board[i][j] != 9 && vis[i][j] != 0 && board[i][j] < cur_size && vis[i][j] < min_dis) {
          mn_x = i;
          mn_y = j;
          min_dis = vis[i][j];
        }
      } 
    }
    if(min_dis == mx) break;
    ans += vis[mn_x][mn_y]-1;
    cur_ate ++;
    if(cur_ate == cur_size) {
      cur_size ++;
      cur_ate = 0;
    } 
    board[mn_x][mn_y] = 9;
    board[x][y] = 0;
    flag = true;
    x = mn_x;
    y = mn_y;

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