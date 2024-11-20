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

void solve() {
  int N;
  cin >> N;
  vector<int> dp(N+1);
  dp[0] = 1, dp[1] = 1;
  for(int i = 2; i <= N; i ++) {
    dp[i] = dp[i-1] + dp[i-2] * 2;
  }
  if(N&1) cout << (dp[N] + dp[N/2])/2;
  else cout << (dp[N] + dp[N/2] + dp[N/2 - 1] * 2)/2;
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