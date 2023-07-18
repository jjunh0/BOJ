#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

vector<int> adj[100005];
int ans[100005];
void dfs(int cur, int par) {
  for(int nxt : adj[cur]) {
    if(nxt == par) continue;
    ans[nxt] = cur;
    dfs(nxt, cur);
  }
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i ++) {
    int t1, t2;
    cin >> t1 >> t2;
    adj[t1].pb(t2);
    adj[t2].pb(t1);
  }
  dfs(1, 0);
  for(int i = 2; i <= n; i ++) cout << ans[i] << '\n';
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}