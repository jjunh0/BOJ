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
int adj[505][505];
void solve() {
  int n, Q;
  cin >> n;
  vector<int> A(n), deg(n+1);
  for(auto &e : A) cin >> e;
  for(int i = 0; i < n; i ++) {
    fill(adj[i], adj[i]+505, 0);
  }
  for(int i = 0; i < n; i ++) {
    for(int j = i+1; j < n; j ++) {
      adj[A[i]][A[j]] = 1;
      deg[A[j]] ++;
    }
  }
  cin >> Q;
  while(Q--) {
    int x, y;
    cin >> x >> y;
    if(adj[x][y]) {
      adj[x][y] = 0;
      deg[y] --;
      adj[y][x] = 1;
      deg[x] ++;
    }
    else {
      adj[y][x] = 0;
      deg[x] --;
      adj[x][y] = 1;
      deg[y] ++;
    }
  }
  queue<int> q;
  for(int i = 1; i <= n; i ++) {
    if(!deg[i]) q.push(i);
  }
  if(sz(q) == 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vector<int> ans;
  while(sz(q) == 1) {
    auto cur = q.front();
    q.pop();
    ans.pb(cur);
    for(int i = 1; i <= n; i ++) {
      if(!adj[cur][i]) continue;
      deg[i] --;
      if(deg[i] == 0) q.push(i);
    }
  }
  if(sz(ans) != n || sz(q) > 1) cout << "IMPOSSIBLE";
  else for(auto e : ans) cout << e << ' ';
  cout << nl;

}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}