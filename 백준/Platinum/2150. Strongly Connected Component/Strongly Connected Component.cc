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

int num = 1, idx = 0;
vector<pi> vn;
vector<int> adj[10005], iadj[10005];
vector<vector<int>> ans;
bool vis[10005];
void dfs1(int ver) {
  for(auto nxt : adj[ver]) {
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    dfs1(nxt);
  }
  vn.pb({num, ver});
  num ++;
}

void dfs2(int ver) {
  for(auto nxt : iadj[ver]) {
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    ans[idx].pb(nxt);
    dfs2(nxt);
  }
}

void solve() {
  int v, e;
  cin >> v >> e;
  for(int i = 0; i < e; i ++) {
    int a, b;
    cin >> a >> b;
    a --, b --;
    adj[a].pb(b);
    iadj[b].pb(a);
  }
  for(int i = 0; i < v; i ++) {
    if(vis[i]) continue;
    vis[i] = 1;
    dfs1(i);
  }
  sort(rall(vn));
  fill(vis, vis+v+1, 0);
  for(int i = 0; i < sz(vn); i ++) {
    if(vis[vn[i].Y]) continue;
    ans.pb(vector<int>());
    ans[idx].pb(vn[i].Y);
    vis[vn[i].Y] = 1;
    dfs2(vn[i].Y);
    idx ++;
  }
  for(int i = 0; i < sz(ans); i ++) sort(all(ans[i]));
  sort(all(ans), [](vector<int> a, vector<int> b) {
    return a[0] < b[0];
  });
  cout << sz(ans) << nl;
  for(int i = 0; i < sz(ans); i ++) {
    for(auto e : ans[i]) cout << e+1 << ' ';
    cout << -1 << nl;
  }
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