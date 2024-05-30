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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int val[10005];
vector<int> adj[10005];
int dp[10'005][2];
int func(int idx, int p, bool flag) {
  if(dp[idx][flag] != -1) return dp[idx][flag];
  int ret = 0;
  for(auto e : adj[idx]) {
    if(e == p) continue;
    ret += func(e, idx, 0);
  }
  dp[idx][flag] = ret;
  if(flag) return ret;
  int ret2 = val[idx];
  for(auto e : adj[idx]) {
    if(e == p) continue;
    ret2 += func(e, idx, 1);
  }
  dp[idx][flag] = max(ret, ret2);
  return max(ret, ret2);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < 10005; i ++) fill(dp[i], dp[i]+2, -1);
  for(int i = 1; i <= n; i ++) cin >> val[i];
  for(int i = 0; i < n-1; i ++) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  cout << func(1, -1, 0);
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