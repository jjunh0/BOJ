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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> a[1005];
int st[1005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      int t;
      cin >> t;
      a[i].pb(t);
    }
    sort(all(a[i]));
  }
  int ans = 0x3f3f3f3f;
  while(1) {
    int mn = 0x3f3f3f3f, mx = 0, mn_i;
    for(int j = 0; j < n; j ++) {
      if(mn > a[j][st[j]]) {
        mn = a[j][st[j]];
        mn_i = j;
      }
      mx = max(mx, a[j][st[j]]);
    }
    ans = min(ans, mx - mn);
    st[mn_i] ++;
    if(st[mn_i] >= m) break;
  }
  cout << ans;
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