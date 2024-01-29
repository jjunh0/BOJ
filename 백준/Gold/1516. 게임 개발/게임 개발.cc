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

vector<int> val(505);
vector<vi> adj(505);
int dp[505];
int deg[505];
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++) {
    cin >> val[i];
    int t;
    cin >> t;
    while(t != -1) {
      adj[t].pb(i);
      deg[i] ++;
      cin >> t;
    }
  }
  queue<int> q;
  for(int i = 1; i <= n; i ++) {
    if(deg[i] == 0) {
      q.push(i);
      dp[i] = val[i];
    }
  }
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      deg[nxt] --;
      dp[nxt] = max(dp[nxt], dp[cur] + val[nxt]);
      if(deg[nxt] == 0) q.push(nxt);
    }
  }
  for(int i = 1; i <= n; i ++) {
    cout << dp[i] << nl;
  }
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