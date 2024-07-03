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
int board[15][15];

bool canFill(int x, int y, int c) {
  if(x+c > 10 || y+c > 10) return false;
  for(int i = x; i < x+c; i ++) {
    for(int j = y; j < y+c; j ++) {
      if(!board[i][j]) return false;
    }
  }
  return true;
}
void _fill(int x, int y, int c, int val) {
  for(int i = x; i < x+c; i ++) {
    for(int j = y; j < y+c; j ++) {
      board[i][j] = val;
    }
  }
}
int ans = MX;
vector<int> cnt = {0, 5, 5, 5, 5, 5};
void func(int n, int used) {
  if(n == 100) ans = min(ans, used);
  if(used >= ans) return;
  int x = n/10, y = n%10;
  if(board[x][y] == 0) return func(n+1, used);
  bool flag = false;
  int ret = MX;
  flag = true;
  for(int c = 5; c >= 1; c --) {
    if(cnt[c] == 0) continue;
    if(used > ans) return;
    if(canFill(x, y, c)) {
      _fill(x, y, c, 0);
      cnt[c] --;
      func(n+1, used+1);
      _fill(x, y, c, 1);
      cnt[c] ++;
    }
  }

}

void solve() {
  for(int i = 0; i < 10; i ++) {
    for(int j = 0; j < 10; j ++) {
      cin >> board[i][j];
    }
  }
  func(0, 0); 
  cout << (ans == MX ? -1 : ans);
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