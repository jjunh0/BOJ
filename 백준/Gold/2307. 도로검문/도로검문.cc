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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pi> adj[1005];
vector<pi> A;
void solve() {
  int n, m;
  cin >> n >> m;
  A.pb({-1, -1});
  for(int i = 0; i < m; i ++) {
    int a, b, v;
    cin >> a >> b >> v;
    adj[a].pb({v, b});
    adj[b].pb({v, a});
    A.pb({a, b});
  }
  int org, ans = 0;
  for(int i = 0; i < m; i ++) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> d(1005, MX);
    pq.push({0, 1});
    d[1] = 0;
    while(sz(pq)) {
      auto [dist, cur] = pq.top();
      pq.pop();
      if(d[cur] != dist) continue;
      for(auto nxt : adj[cur]) {
        if(d[nxt.Y] <= dist + nxt.X) continue;
        if(min(nxt.Y, cur) == min(A[i].X, A[i].Y) && max(nxt.Y, cur) == max(A[i].X, A[i].Y)) continue;
        d[nxt.Y] = dist + nxt.X;
        pq.push({d[nxt.Y], nxt.Y});
      }
    }
    if(i == 0) org = d[n];
    else {
      ans = max(ans, d[n]);
    }
  }
  cout << (ans != MX ? ans - org : -1);
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