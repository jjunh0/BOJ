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
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sdx[] = {-1, 0, 1, 0};
int sdy[] = {0, -1, 0, 1};
vector<int> fish[5][5];
vector<int> fish_nxt[5][5];
int smell[5][5];
int sx, sy;
bool vis[5][5];
int sdir[5];

void f(int brute) {
  for(int i = 0; i < 3; i ++) {
    int dir = brute%4;
    brute /= 4;
    sdir[2-i] = dir;
  }
}

void solve() {
  int M, S;
  cin >> M >> S;
  for(int i = 0; i < M; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    fish[a-1][b-1].pb(c-1);
  }
  for(int i = 0; i < 5; i ++) fill(smell[i], smell[i]+5, -10);
  cin >> sx >> sy;
  sx --, sy --;
  for(int t = 0; t < S; t ++) {
    for(int i = 0; i < 4; i ++) 
      for(int j = 0; j < 4; j ++) fish_nxt[i][j] = {};
    // 물고기 이동
    for(int i = 0; i < 4; i ++) {
      for(int j = 0; j < 4; j ++) {
        for(int f = 0; f < sz(fish[i][j]); f ++) {
          int dir = fish[i][j][f];
          bool flag = false;
          for(int nd = 0; nd < 8; nd ++) {
            int curd = (dir - nd + 8) % 8;
            int nx = i + dx[curd];
            int ny = j + dy[curd];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || tie(sx, sy) == tie(nx, ny) || t - smell[nx][ny] <= 2) continue;
            fish_nxt[nx][ny].pb(curd);
            flag = true;
            break;
          }
          if(!flag) fish_nxt[i][j].pb(dir);
        }
      }
    }
    // 상어 이동방향 확인
    int mx = -1, membit=0;
    for(int bit = 0; bit < (1<<6); bit ++) {
      int nx = sx, ny = sy, cur_val = 0;
      for(int i = 0; i < 4; i ++) fill(vis[i], vis[i]+4, 0);
      f(bit);
      for(int i = 0; i < 3; i ++) {
        int dir = sdir[i];
        nx += sdx[dir], ny += sdy[dir];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
          cur_val = -10;
          break;
        }
        if(!vis[nx][ny])
          cur_val += sz(fish_nxt[nx][ny]);
        vis[nx][ny] = 1;
      }
      if(cur_val > mx) {
        mx = cur_val, membit = bit;
      }
    }
    f(membit);
    for(int i = 0; i < 3; i ++) {
      int dir = sdir[i];
      sx += sdx[dir], sy += sdy[dir];
      if(sz(fish_nxt[sx][sy])) {
        fish_nxt[sx][sy] = {};
        smell[sx][sy] = t;
      }
    }
    for(int i = 0; i < 4; i ++) {
      for(int j = 0; j < 4; j ++) {
        for(int k = 0; k < sz(fish_nxt[i][j]); k ++) fish[i][j].pb(fish_nxt[i][j][k]);
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < 4; i ++) {
    for(int j = 0; j < 4; j ++) {
      ans += sz(fish[i][j]);
    }
  }
  cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}