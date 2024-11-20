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
int N;
int val[] = {
  0, 1, 10, 100, 1000
};
bool check(int nx, int ny) {
  return nx < 0 || nx >= N || ny < 0 || ny >= N;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[25][25];
void solve() {
  cin >> N;
  vector<set<int>> A(N*N+1);
  vector<int> cand;
  for(int i = 0; i < N*N; i ++) {
    int x;
    cin >> x;
    cand.pb(x);
    for(int j = 0; j < 4; j ++) {
      int y;
      cin >> y;
      A[x].insert(y);
    }
  }
  
  for(int cand_idx = 0; cand_idx < N*N; cand_idx ++) {
    int cur = cand[cand_idx];
    int f = -1, e = -1, x=0, y=0;
    for(int i = 0; i < N; i ++) {
      for(int j = 0; j < N; j ++) {
        if(board[i][j]) continue;
        int f_cur = 0, e_cur = 0;
        for(int dir = 0; dir < 4; dir ++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if(check(nx, ny)) continue;
          if(board[nx][ny] == 0) {
            e_cur ++;
          }
          else if(A[cur].count(board[nx][ny])) {
            f_cur ++;
          }
        }
        if(f < f_cur || (f == f_cur && e < e_cur)) {
          x = i, y = j;
          f = f_cur, e = e_cur;
        }
      }
    }
    board[x][y] = cur;
  }
  int ans = 0;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      int cnt = 0;
      for(int dir = 0; dir < 4; dir ++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(check(nx, ny)) continue;
        if(A[board[i][j]].count(board[nx][ny])) cnt ++;
      }
      ans += val[cnt];
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