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

int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
int board[20][20], dp[20][20][5];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> board[i][j];
    }
  }
  for(int i = 1; i < n; i ++) {
    if(board[0][i]) break;
    dp[0][i][0] = 1;
  }
  for(int i = 1; i < n; i ++) {
    for(int j = 1; j < n; j ++) {
      if(board[i][j]) continue;
      dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
      dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
      if(board[i-1][j] == 0 && board[i][j-1] == 0)
        dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
    }
  }
  cout << accumulate(dp[n-1][n-1], dp[n-1][n-1]+4, 0);
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