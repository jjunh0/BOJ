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
int p[100005];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return 0;
  p[a] = b;
  return 1;
}

void solve() {
  int n;
  cin >> n;
  vector<pi> x(n), y(n), z(n);
  for(int i = 0; i < n; i ++) {
    cin >> x[i].X >> y[i].X >> z[i].X;
    x[i].Y = y[i].Y = z[i].Y = i;
  }
  sort(all(x)), sort(all(y)), sort(all(z));
  vector<ti> adj;
  for(int i = 1; i < n; i ++) {
    adj.pb({x[i].X-x[i-1].X, x[i].Y, x[i-1].Y});
    adj.pb({y[i].X-y[i-1].X, y[i].Y, y[i-1].Y});
    adj.pb({z[i].X-z[i-1].X, z[i].Y, z[i-1].Y});
  }
  sort(all(adj));
  fill(p, p+n, -1);
  ll ans = 0, cnt = 0;;
  for(int i = 0; i < sz(adj); i ++) {
    auto [cost, a, b] = adj[i];
    if(!merge(a, b)) continue;
    ans += 1LL * cost;
    cnt ++;
    if(cnt == n-1) break;
  }
  cout << ans;
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