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
typedef tuple<int, int, int> iii;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[55][55];
int vis[5][55][55];
void solve() {
  int n;
  cin >> n;
  bool flagA = false, flagB = false;
  queue<iii> q;
  int dest_x, dest_y, dest_dir = -1, bx, dbx;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j ++) {
      if(sz(q) == 0 && s[j] == 'B') {
        if(flagA) {
          if(bx == i) {
            q.push({i, j, 0});
            vis[0][i][j] = 1;
          }
          else {
            q.push({i, j, 1});
            vis[1][i][j] = 1;
          }
        }
        else {
          flagA = 1;
          bx = i;
        }
      }
      else if(dest_dir == -1 && s[j] == 'E') {
        if(flagB) {
          if(dbx == i) 
            dest_dir = 0;
          else
            dest_dir = 1;
          dest_x = i;
          dest_y = j;
        }
        else {
          flagB = 1;
          dbx = i;
        }
      }
      if(s[j] == '1') board[i][j] = s[j]-'0';
    }
  }
  while(sz(q)) {
    auto [xx, yy, ddir] = q.front();
    q.pop();
    if(ddir == 0) {
      for(int dir = 0; dir < 4; dir ++) {
        int nx = xx + dx[dir];
        int ny = yy + dy[dir];
        if(nx < 0 || nx >= n || ny < 1 || ny >= n-1) continue;
        if(vis[ddir][nx][ny]) continue;
        if(board[nx][ny-1] != 0 || board[nx][ny] != 0 || board[nx][ny+1] != 0) continue;
        vis[ddir][nx][ny] = vis[ddir][xx][yy] + 1;
        q.push({nx, ny, ddir});
      }

    }
    else {
      for(int dir = 0; dir < 4; dir ++) {
        int nx = xx + dx[dir];
        int ny = yy + dy[dir];
        if(nx < 1 || nx >= n-1 || ny < 0 || ny >= n) continue;
        if(vis[ddir][nx][ny]) continue;
        if(board[nx-1][ny] != 0 || board[nx][ny] != 0 || board[nx+1][ny] != 0) continue;
        vis[ddir][nx][ny] = vis[ddir][xx][yy] + 1;
        q.push({nx, ny, ddir});
      }
    }
    if(xx < 1 || xx >= n-1 || yy < 1 || yy >= n-1 ||
      vis[!ddir][xx][yy]) continue;
    bool flag = false;
    for(int dx = -1; dx <= 1; dx ++) {
      for(int dy = -1; dy <= 1; dy ++) {
        if(board[xx+dx][yy+dy] != 0) {
          flag = true;
        }
      }
    }
    if(!flag) {
      vis[!ddir][xx][yy] = vis[ddir][xx][yy] + 1;
      q.push({xx, yy, !ddir});
    }

  }
  int ans = vis[dest_dir][dest_x][dest_y];
  if(ans == 0) cout << 0;
  else cout << ans-1;
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