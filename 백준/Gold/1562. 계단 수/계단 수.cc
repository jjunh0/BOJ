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
const int mx = 1'000'000'000;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll dp[105][15][(1<<10)];
void solve() {
  int n; cin >> n;
  for(int i = 1; i < 10; i ++) {
    dp[1][i][(1<<i)] = 1;
  }
  for(int i = 2; i <= n; i ++) {
    for(int j = 0; j <= 9; j ++) {
      for(int k = 0; k < (1<<10); k ++) {
        if(j-1 >= 0)
          dp[i][j][k | (1<<j)] += dp[i-1][j-1][k];
        if(j+1 <= 9)
          dp[i][j][k | (1<<j)] += dp[i-1][j+1][k];
        dp[i][j][k|(1<<j)] %= mx;
      }
    }
  }
  ll ans = 0;
  for(int j = 0; j <= 9; j ++) {
    ans += dp[n][j][(1<<10)-1];
  }
  cout << ans % mx;
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