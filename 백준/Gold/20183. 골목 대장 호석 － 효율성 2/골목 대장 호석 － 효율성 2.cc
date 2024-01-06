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
const ll mx = 1e14+5;

vector<pl> adj[100'000+5];
vector<ll> d(100005);
priority_queue<pl, vector<pl>, greater<pl>> pq;

ll n, m, a, b, c;

bool check(ll mid) {
  fill(all(d), mx);
  pq.push({0, a});
  d[a] = 0;
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) continue; 
    for(auto nxt : adj[cur.Y]) {
      if(nxt.X > mid) continue;
      ll t = nxt.X + cur.X;
      if(t < d[nxt.Y]) {
        d[nxt.Y] = t;
        pq.push({t, nxt.Y});
      }
    }
  }
  if(d[b] == mx || d[b] > c) return 1;
  return 0;
}
void solve() {
  cin >> n >> m >> a >> b >> c;
  int x, y, v;
  for(int i = 0; i < m; i ++) {
    cin >> x >> y >> v;
    adj[x].pb({v, y});
    adj[y].pb({v, x});
  }
  ll st = 0, en = mx;
  // { 값, 좌표}
  while(st + 1 < en) {
    ll mid = (st+en)/2;
    if(check(mid)) st = mid;
    else en = mid;
  }
  cout << (en == mx ? -1 : en) << nl;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
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