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

vector<int> adj[100005];
vector<int> ans, tar;
vector<int> vis(100005);
vector<int> ord(100005);

bool cmp(int a, int b) {
  return ord[a] < ord[b];
}

// void dfs(int cur) {
//   for(auto e : adj[cur]) {
//     if(vis[e]) continue;
//     vis[e] = 1;
//     ans.pb(e);
//     dfs(e);
//   }
// }
void dfs(int x) {
    if (vis[x] == true) {
        return;
    }
    vis[x] = true;
    ans.pb(x);
    // x를 방문
    for (int y : adj[x]) {
        if (vis[y] == false) {
            dfs(y);
        }
    }
}
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i ++) { 
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    tar.pb(t);
    ord[t] = i;
  }
  if(tar[0] != 1) {
    cout << 0;
    return;
  }
  for(int i = 1; i <= n; i ++) {
    sort(all(adj[i]), cmp);
  }

  dfs(1);

  for(int i = 0; i < n; i ++) {
    if(ans[i] != tar[i]) {
      cout << 0;
      return;
    }   
  }
  cout << 1;


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