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

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int board[25][25], pri[405][5][5], rtime[25][25], smell[25][25], die[405];
iii shark[405];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> board[i][j];
      if(board[i][j] != 0) {
        shark[board[i][j]] = {i, j, 0};
      }
    }
  }
  for(int i = 1; i <= m; i ++) {
    int t;
    cin >> t;
    auto &[a, b, c] = shark[i];
    c = t;
  }
  for(int i = 1; i <= m; i ++) {
    for(int j = 1; j <= 4; j ++) {
      for(int k = 0; k < 4; k ++) {
        cin >> pri[i][j][k];
      }
    }
  }
  int cur_t = 0;
  bool end = false;
  while(!end && cur_t < 1000) {
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < n; j ++) {
        if(board[i][j] == 0) continue;
        smell[i][j] = board[i][j];
        rtime[i][j] = cur_t + k;
      }
    }
    for(int i = m; i >= 1; i --) {
      if(die[i]) continue;
      auto [x, y, dd] = shark[i];
      bool flag = false;
      for(int dir = 0; dir < 4; dir ++) {
        int ddir = pri[i][dd][dir];
        int nx = x + dx[ddir];
        int ny = y + dy[ddir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(smell[nx][ny] != 0 && (rtime[nx][ny] > cur_t)) continue;
        board[x][y] = 0;
        die[board[nx][ny]] = 1;
        board[nx][ny] = i;
        flag = true;
        shark[i] = {nx, ny, ddir};
        break;
      }
      if(flag) continue;
      for(int dir = 0; dir < 4; dir ++) {
        int ddir = pri[i][dd][dir];
        int nx = x + dx[ddir];
        int ny = y + dy[ddir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(smell[nx][ny] != i) continue;
        board[x][y] = 0;
        die[board[nx][ny]] = 1;
        board[nx][ny] = i;
        shark[i] = {nx, ny, ddir};
        break;
      }
    }
    cur_t ++;
    end = true;
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < n; j ++) {
        if(board[i][j] != 0 && board[i][j] != 1) {
          end = false;
          break;
        }
      }
    }
  }
  cout << (!end ? -1 : cur_t);
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