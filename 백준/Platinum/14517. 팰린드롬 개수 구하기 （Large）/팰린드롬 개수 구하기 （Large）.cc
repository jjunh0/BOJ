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
const int MX = 10007;
const int MOD = 10007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dp[1005][1005], N;
string s;
int f(int x, int y) {
  if(x > y) return 0;
  if(dp[x][y] != -1) return dp[x][y];
  int ret = 0;
  if(s[x] == s[y]) {
    ret += (1 + f(x+1, y-1))%MOD;
  }
  ret += (f(x+1, y) + f(x, y-1) - f(x+1, y-1) + MOD)%MOD;
  ret %= MOD;
  dp[x][y] = ret;
  return ret;
}

void solve() {
  cin >> s;
  N = sz(s);
  for(int i = 0; i < N; i ++) fill(dp[i], dp[i]+N, -1);
  cout << f(0, N-1)%MOD;
  
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