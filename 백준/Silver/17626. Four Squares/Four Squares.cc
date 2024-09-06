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

int n;
int dp[50005];
int func(int cur) {
  if(cur == 0) return 0;
  if(dp[cur] != -1) return dp[cur];
  int ret = MX;
  for(int i = 1; i*i <= cur; i ++) {
    ret = min(1 + func(cur - i*i), ret);
  }
  dp[cur]= ret;
  return ret;
}
void solve() {
  cin >> n;
  fill(dp, dp+n+1, -1);
  cout << func(n);
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