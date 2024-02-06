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
const ll mod = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> dp(n+1);
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 2;
  for(int i = 4; i <= n; i ++) {
    dp[i] = 1LL * (dp[i-1]+dp[i-2]) * (i-1)%mod;
  }
  cout << dp[n];
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