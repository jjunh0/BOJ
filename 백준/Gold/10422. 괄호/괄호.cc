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
const int mx = 0x3f3f3f3f;
const int mod = 1000000007;
#define int ll
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dp[5005];

// ************************************

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  dp[2] = 1; dp[4] = 2; 
  dp[0] = 1;
  for(int i = 6; i <= 5000; i += 2) {
    dp[i] += dp[i-2];
    for(int j = 2; j < i; j += 2) {
      dp[i] += (dp[j-2] * dp[i-j]) % mod;
    }
    dp[i] %= mod;
  }
  
  while(tt--) {
    int n;
    cin >> n;
    cout << dp[n] << nl;
  }
}