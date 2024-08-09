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
typedef tuple<int ,int, int, int> ti;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0}; // 위 오 아래 왼
int dy[] = {0, 1, 0, -1};
string board[15];
int dis[15][15][15][15];
ti pre[15][15][15][15];
int cur[15][15][15][15];

char func(int dir) {
  if(dir == 0) return 'U';
  else if(dir == 1) return 'R';
  else if(dir == 2) return 'D';
  else return 'L';
}

void solve() {
  int n, m; cin >> n >> m;
  pi r, b;
  for(int i = 0; i < n; i ++) {
    cin >> board[i];
    for(int j = 0; j < m; j ++) {
      if(board[i][j] == 'R') {
        r = {i, j};
        board[i][j] = '.';
      }
      else if(board[i][j] == 'B') {
        b = {i, j};
        board[i][j] = '.';
      }
    }
  }
  queue<tuple<int, int, int, int>> q;
  dis[r.X][r.Y][b.X][b.Y] = 1;
  cur[r.X][r.Y][b.X][b.Y] = -1;
  
  q.push({r.X, r.Y, b.X, b.Y});
  while(sz(q)) {
    auto [rx, ry, bx, by] = q.front();
    q.pop();
    if(dis[rx][ry][bx][by] > 10) continue;
    for(int dir = 0; dir < 4; dir ++) {
      int drx, dry, dbx, dby;
      tie(drx, dry, dbx, dby) = tie(rx, ry, bx, by);
      while(board[dbx+dx[dir]][dby+dy[dir]] == '.') {
        dbx += dx[dir];
        dby += dy[dir];
      }
      if(board[dbx+dx[dir]][dby+dy[dir]] == 'O') continue;
      while(board[drx+dx[dir]][dry+dy[dir]] == '.') {
        drx += dx[dir];
        dry += dy[dir];
      }
      if(board[drx+dx[dir]][dry+dy[dir]] == 'O') {
        cout << dis[rx][ry][bx][by] << nl;
        auto [brx, bry, bbx, bby] = make_tuple(rx,ry,bx,by);
        vector<char> ans;
        while(dir != -1) {
          ans.pb(func(dir));
          dir = cur[brx][bry][bbx][bby];
          tie(brx, bry, bbx, bby) = pre[brx][bry][bbx][bby];
        }
        reverse(all(ans));
        for(auto e : ans) cout << e;
        return;
      } 
      if(drx == dbx && dry == dby) {
        if(dir == 0) {
          if(rx > bx) drx ++;
          else dbx ++;
        }
        else if(dir == 1) {
          if(ry > by) dby --;
          else dry --;
        }
        else if(dir == 2) {
          if(rx > bx) dbx --;
          else drx --;
        }
        else if(dir == 3) {
          if(ry > by) dry ++;
          else dby ++;
        }
      } 
      if(dis[drx][dry][dbx][dby]) continue;
      dis[drx][dry][dbx][dby] = dis[rx][ry][bx][by] + 1;
      cur[drx][dry][dbx][dby] = dir;
      pre[drx][dry][dbx][dby] = {rx, ry, bx, by};
      q.push({drx, dry, dbx, dby});
    }
  }
  cout << -1;
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