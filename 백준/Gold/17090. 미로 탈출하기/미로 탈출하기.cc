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

char board[505][505];
int dp[505][505];
int n, m;
bool func(int x, int y) {
  if(x < 0 || x >= n || y < 0 || y >= m) {
    return true;
  }
  if(dp[x][y] != -1) {
    return dp[x][y];
  }

  dp[x][y] = 0;
  if(board[x][y] == 'D') {
    dp[x][y] = dp[x][y] | func(x+1, y);
  }  
  if(board[x][y] == 'L') {
    dp[x][y] = dp[x][y] | func(x, y-1);
  }
  if(board[x][y] == 'U') {
    dp[x][y] = dp[x][y] | func(x-1, y);
  }
  if(board[x][y] == 'R') {
    dp[x][y] = dp[x][y] | func(x, y+1);
  }
  return dp[x][y];
  
}

void solve() {
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j ++) {
      board[i][j] = s[j];
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      if(func(i, j)) ans ++;
    }
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}