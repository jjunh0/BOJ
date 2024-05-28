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

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int board[5][5];
tuple<int, int, int, int> mp[25];


int func(int sx, int sy, int sd) {
    // cout << sx << ' ' << sy << nl;
    // for(int i = 0; i < 4; i ++) {
    //   for(int j = 0; j < 4; j ++) { 
    //     cout << board[i][j] << ' ';
    //     // cout << get<2>(mp[board[i][j]]) << ' ';
    //   } 
    //   cout << nl;
    // }
    // cout << nl;
  int board_pre[5][5];
  tuple<int, int, int, int> mp_pre[25];
  for(int i = 1; i <= 16; i ++) {
    int x, y, dir, flag;
    tie(x, y, dir, flag) = mp[i];
    if(flag == 1) continue;
    for(int j = 0; j < 8; j ++) {
      int nx = x + dx[(dir+j)%8];
      int ny = y + dy[(dir+j)%8];
      if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
      if(nx == sx && ny == sy) continue;
      int ndir = get<2>(mp[board[nx][ny]]), nflag = get<3>(mp[board[nx][ny]]);
      swap(board[nx][ny], board[x][y]);
      mp[board[nx][ny]] = {nx, ny, (dir+j)%8, flag};
      mp[board[x][y]] = {x, y, ndir, nflag};
      break;
    }
  }
  for(int i = 0; i < 4; i ++) {
    for(int j = 0; j < 4; j ++) { 
      board_pre[i][j] = board[i][j];
    } 
  }
  for(int i = 0; i < 25; i ++) mp_pre[i] = mp[i];
  int ret = 0;
  for(int mul = 1; mul <= 3; mul ++) {
    int nx = sx + dx[sd]*mul;
    int ny = sy + dy[sd]*mul;
    if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
    int x, y, dir, flag;
    tie(x, y, dir, flag) = mp[board[nx][ny]];
    if(flag) continue;
    mp[board[nx][ny]] = {x, y, dir, 1};

    ret = max(board[nx][ny]+func(nx, ny, dir), ret);
    for(int i = 0; i < 4; i ++) {
      for(int j = 0; j < 4; j ++) { 
        board[i][j] = board_pre[i][j];
      } 
    }
    for(int i = 0; i < 25; i ++) mp[i] = mp_pre[i];
  }
  return ret;
} 

void solve() {
  for(int i = 0; i < 4; i ++) {
    for(int j = 0; j < 4; j ++) {
      int a, b;
      cin >> a >> b;
      
      mp[a] = {i, j, --b, 0};
      board[i][j] = a;
    }
  }
  int a, b, c, d;
  tie(a, b, c, d) = mp[board[0][0]];
  mp[board[0][0]] = {a, b, c, 1};
  cout << board[0][0] + func(0, 0, c);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}