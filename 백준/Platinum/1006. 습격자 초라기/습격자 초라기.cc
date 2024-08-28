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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int board[10005][2];
int dp[10005][5];
int dp2[10005][5];
int dp3[10005][5];
int n, m;

int func(int cur, int sel, int lim) {
  if(cur < lim) return 0;
  if(dp[cur][sel] != MX) return dp[cur][sel];
  if(sel == 0) {
    if(cur-1 >= lim && board[cur][0] + board[cur-1][0] <= m && board[cur][1] + board[cur-1][1] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 2 + func(cur-1, 3, lim));
    }
    if(cur-1 >= lim &&board[cur][0] + board[cur-1][0] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 2 + func(cur-1, 1, lim));
    }
    if(cur-1 >= lim && board[cur][1] + board[cur-1][1] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 2 + func(cur-1, 2, lim));
    }
    if(board[cur][1] + board[cur][0] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 1 + func(cur-1, 0, lim));
    }
    dp[cur][sel] = min(dp[cur][sel], 2 + func(cur-1, 0, lim));
  }
  if(sel == 1 || sel == 2) {
    dp[cur][sel] = min(dp[cur][sel], 1 + func(cur-1, 0, lim));
    int r = !(sel-1);
    if(cur-1 >= lim && board[cur][r] + board[cur-1][r] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 1 + func(cur-1, r+1, lim));
    }
  }
  if(sel == 3) dp[cur][sel] = func(cur-1, 0, lim);
  return dp[cur][sel];
}
int func2(int cur, int sel, int lim) {
  if(cur < 0) return 0;
  if(cur == 0 && (sel == lim || sel == 3)) return MX;
  if(cur == 0 && sel == 0) return 1;
  if(cur == 0) return 0;
  if(dp[cur][sel] != MX) return dp[cur][sel];
  if(sel == 0) {
    if(cur-1 >= 0 && board[cur][0] + board[cur-1][0] <= m && board[cur][1] + board[cur-1][1] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 2 + func2(cur-1, 3, lim));
    }
    if(cur-1 >= 0 &&board[cur][0] + board[cur-1][0] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 2 + func2(cur-1, 1, lim));
    }
    if(cur-1 >= 0 && board[cur][1] + board[cur-1][1] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 2 + func2(cur-1, 2, lim));
    }
    if(board[cur][1] + board[cur][0] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 1 + func2(cur-1, 0, lim));
    }
    dp[cur][sel] = min(dp[cur][sel], 2 + func2(cur-1, 0, lim));
  }
  if(sel == 1 || sel == 2) {
    dp[cur][sel] = min(dp[cur][sel], 1 + func2(cur-1, 0, lim));
    int r = !(sel-1);
    if(cur-1 >= 0 && board[cur][r] + board[cur-1][r] <= m) {
      dp[cur][sel] = min(dp[cur][sel], 1 + func2(cur-1, r+1, lim));
    }
  }
  if(sel == 3) dp[cur][sel] = (cur == 0 ? 0 : func2(cur-1, 0, lim));
  return dp[cur][sel];
}


void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> board[i][0]; 
  for(int i = 0; i < n; i++) cin >> board[i][1]; 
  for(int i = 0; i < n; i ++) fill(dp[i], dp[i]+4, MX);
  int ans = func(n-1, 0, 0);
  if(board[0][0] + board[n-1][0] <= m) {
    for(int i = 0; i < n; i ++) fill(dp[i], dp[i]+4, MX);
    ans = min(ans, func2(n-1, 1, 1) + 1);
  }
  if(board[0][1] + board[n-1][1] <= m) {
    for(int i = 0; i < n; i ++) fill(dp[i], dp[i]+4, MX);
    ans = min(ans, func2(n-1, 2, 2) + 1);
  }
  if(board[0][0] + board[n-1][0] <= m && board[0][1] + board[n-1][1] <= m) {
    for(int i = 0; i < n; i ++) fill(dp[i], dp[i]+4, MX);
    ans = min(ans, func(n-2, 0, 1) + 2);
  }
  cout << ans << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    while(tests--) {
        solve();
    }
}