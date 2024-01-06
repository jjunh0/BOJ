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
const ll mx = 20000000005;
vector<pair<int, int>> adj[100005];


void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(k);
  int a, b, c;
  while(m--) {
    cin >> a >> b >> c;
    adj[b].pb({c, a});
  }
  vector<ll> d(n+1, mx);
  priority_queue<pl, vector<pl>, greater<pl>> pq;
  for(int i = 0; i < k; i ++) {
    cin >> p[i];
    pq.push({0, p[i]});
    d[p[i]] = 0;
  }
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(cur.X != d[cur.Y]) continue;
    for(auto nxt : adj[cur.Y]) {
      ll tmp = cur.X + nxt.X;
      if(tmp >= d[nxt.Y]) continue;
      d[nxt.Y] = tmp;
      pq.push({tmp, nxt.Y});
    }
  }
  ll ans = 0, ans_idx;
  for(int i = 1; i <= n; i ++)  {
    if(ans < d[i]) {
      ans = d[i];
      ans_idx = i;
    }
  }
  cout << ans_idx << nl << ans;
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