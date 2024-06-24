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
int adj[20][20];
int n;
int dp[20][(1<<16)];
int func(int cur, int vis) {
  if(vis == (1<<n)-1) {
    if(adj[cur][0]) return adj[cur][0];
    return mx;
  }
  if(dp[cur][vis] != -1) return dp[cur][vis];
  dp[cur][vis] = mx;
  for(int i = 0; i < n; i ++) {
    if(vis & (1<<i) || !adj[cur][i]) continue;
    dp[cur][vis] = min(adj[cur][i] + func(i, vis|(1<<i)), dp[cur][vis]);
  }
  return dp[cur][vis];
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> adj[i][j];
    }
  }
  for(int i = 0; i < n; i ++) fill(dp[i], dp[i]+ (1<<n), -1);
  cout << func(0, 1);
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