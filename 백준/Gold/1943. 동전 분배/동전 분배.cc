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
int dp[105][100005];
int N;

bool f(int idx, int sum, vector<pi> &coin) {
  if(sum == 0) return 1;
  if(idx == N) return 0;
  if(dp[idx][sum] != -1) return dp[idx][sum];
  bool ret = 0;
  for(int j = 0; j <= coin[idx].Y; j ++) {
    if(sum - coin[idx].X * j >= 0)
      ret |= f(idx+1, sum - coin[idx].X * j, coin);
  }
  dp[idx][sum] = ret;
  return ret;
}

void solve() {
  for(int tt = 0; tt <3; tt ++) {
    cin >> N;
    vector<pi> coin;
    int sum = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i ++) {
      int v, c;
      cin >> v >> c;
      coin.pb({v, c});
      sum += v*c;
    }
    if(sum%2) {
      cout << 0 << nl;
    }
    else 
      cout << f(0, sum/2, coin) << nl;
  }
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