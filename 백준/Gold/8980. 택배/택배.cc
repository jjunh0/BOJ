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
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pi> adj[25];
void solve() {
  int n, c, m;
  cin >> n >> c >> m;
  vector<ti> A(m);
  for(auto &[y, x, v] : A) {
    cin >> x >> y >> v;
  }
  sort(all(A));
  vector<int> cap(n+1, c);
  int ans = 0;
  for(int i = 0; i < m; i ++) {
    auto [y, x, v] = A[i];
    int mx = min(v, *min_element(cap.begin()+x, cap.begin()+y));
    for(int j = x; j < y; j ++) cap[j] -= mx;
    ans += mx;
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