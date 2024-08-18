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
typedef tuple<int, int, int, int, int> ti;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int board[105][105], nxt_board[105][105];
void solve() {
  int r, c, m, ans = 0;
  cin >> r >> c >> m;
  vector<ti> shark(m+1);
  vector<bool> die(m+1);
  for(int i = 0; i < m; i ++) {
      int x, y, s, d, z;
      cin >> x >> y >> s >> d >> z;      
      d --, x --, y --;
      shark[i+1] = {z, s, d, x, y};
  }
  sort(all(shark));
  for(int i = 1; i <= m; i ++) {
    board[get<3>(shark[i])][get<4>(shark[i])] = i;
  }
  for(int i = 0; i < r; i ++) {
    for(int j = 0; j < c; j ++) {
      nxt_board[i][j] = board[i][j];
    }
  }
  for(int f = 0; f < c; f ++) {
    for(int i = 0; i < r; i ++) {
      for(int j = 0; j < c; j ++) {
        board[i][j] = nxt_board[i][j];
        nxt_board[i][j] = 0;
      }
    }
    for(int i = 0; i < r; i ++) {
      if(board[i][f] != 0 && !die[board[i][f]]) {
        ans += get<0>(shark[board[i][f]]);
        die[board[i][f]] = 1;
        board[i][f] = 0;
        break;
      }
    }
    for(int i = 1; i <= m; i ++) {
      if(die[i]) continue;
      auto [z, s, d, x, y] = shark[i];
      int nx = x, ny = y;
      int S = s, D = d;
      if(D <= 1) S%= (r-1)*2;
      else S%=(c-1)*2;
      while(S > 0) {
        if(D <= 1) {
          if(nx + dx[D] < 0) D = 1;
          if(nx + dx[D] >= r) D = 0;
          nx += dx[D];
        }
        else {
          if(ny + dy[D] < 0) D = 2;
          if(ny + dy[D] >= c) D= 3;
          ny += dy[D];
        }
        S --;
      }
      die[nxt_board[nx][ny]] = 1;
      nxt_board[nx][ny] = i;
      shark[i] = {z, s, D, nx, ny};
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