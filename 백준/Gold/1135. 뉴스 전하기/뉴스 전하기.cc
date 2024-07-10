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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;
vector<int> adj[55];
int dp[55];

int func(int cur, int p) { // cur부터 맨 밑까지의 부하 길이중 최대 길이
  int ret = 0;
  vector<int> v;
  for(auto nxt : adj[cur]) {
    if(nxt == p) continue;
    v.pb(func(nxt, cur));
  }
  sort(rall(v));
  for(int i = 0; i < sz(v); i ++) {
    ret = max(ret, v[i] + i + 1);
  }
  return ret;
}



void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    if(t == -1) continue;
    adj[i].pb(t);
    adj[t].pb(i);
  }
  cout << func(0, -1);
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