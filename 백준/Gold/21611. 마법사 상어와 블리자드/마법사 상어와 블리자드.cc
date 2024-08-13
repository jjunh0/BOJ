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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int ddx[] = {0, 1, 0, -1};
int ddy[] = {-1, 0, 1, 0};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int board[55][55];
int b_val[2505];
int n, m;
int ans[4];
void make_board() {
  int x = n/2, y = n/2;
  int cur = 0, dir = 0, cnt = 0, total_cnt = 0, dir_cnt = 1;
  while(cur < n*n) {
    board[x][y] = cur++;
    x += ddx[dir];
    y += ddy[dir];
    cnt ++;
    if(cnt == dir_cnt) {
      dir = (dir+1)%4;
      cnt = 0;
      total_cnt ++;
      if(total_cnt == 2) {
        dir_cnt ++;
        total_cnt = 0;
      }
    }
  }
}

void move() {
  int tp = 1;
  for(int i = 1; i < n*n; i ++) {
    if(b_val[i] == 0) continue;
    swap(b_val[i], b_val[tp]);
    tp ++;
  }
}

bool bomb() {
  int st = 1;
  bool flag = false;
  for(int en = 2; en <= n*n; en ++) {
    if(b_val[st] != b_val[en]) {
      if(en-st >= 4) {
        ans[b_val[st]] += en-st;
        for(int i = st; i < en; i ++) b_val[i] = 0;
        flag = true;
      }
      st = en;
    }
  }
  return flag;
}

void change() {
  int st = 1;
  vector<pi> v;
  for(int en = 1; en <= n*n; en ++) {
    if(b_val[st] == b_val[en]) continue;
    v.pb({en-st, b_val[st]});
    st = en;
  }
  int idx = 1;
  for(int i = 0; i < sz(v) && idx < n*n; i ++) {
    b_val[idx++] = v[i].X;
    if(idx >= n*n) break;
    b_val[idx++] = v[i].Y;
  }
  for(int i = idx; i < n*n; i ++) b_val[i] = 0;
}

void solve() {
  cin >> n >> m;
  make_board();
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) { 
      int t;
      cin >> t;
      b_val[board[i][j]] = t;
    } 
  }
  while(m--) {
    int d, s;
    cin >> d >> s;
    d--;
    int sx = n/2 + dx[d], sy = n/2 + dy[d];
    for(int i = 0; i < s; i ++) {
      b_val[board[sx][sy]] = 0;
      sx += dx[d];
      sy += dy[d];
    }
    while(1) {
      move();
      if(!bomb()) break;
    }
    change();
  
  }
  cout << 1*ans[1] + 2*ans[2] + 3*ans[3];
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