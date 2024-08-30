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

ll ans = 0;
const int N = 100005;
vector<int> p(N, -1);
vector<pl> cnt(N, {0, 0});
int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return 0;
  ans -= cnt[a].X*cnt[a].Y + cnt[b].X*cnt[b].Y;
  cnt[b].X += cnt[a].X;
  cnt[b].Y += cnt[a].Y;
  ans += cnt[b].X * cnt[b].Y;
  cnt[a] = {0, 0};
  p[a] = b;
  return 1;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    if(t%2 == 0) cnt[i].X ++;
    else cnt[i].Y ++;
  }
  for(int i = 0; i < m; i ++) {
    int a, b;
    cin >> a >> b;
    a --, b--;
    merge(a, b);
    cout << ans << nl;
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