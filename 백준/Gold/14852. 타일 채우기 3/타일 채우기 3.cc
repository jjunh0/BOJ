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
const int mod = 1000000007;
vector<ll> dp(1000005);
vector<ll> sum(1000005);
void solve() {
  int n;
  cin >> n;
  dp[1] = 2;
  sum[1] = dp[1];
  dp[2] = 7;
  sum[2] = dp[2] + sum[1];
  for(int i = 3; i <= n; i ++) {
    dp[i] = (dp[i-1]*2 + dp[i-2] * 3 + 2)%mod;
    dp[i] += sum[i-3]*2%mod;
    sum[i] = (sum[i-1] + dp[i])%mod;
  } 
  cout << dp[n]%mod;
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