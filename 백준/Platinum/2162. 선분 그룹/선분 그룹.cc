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
typedef tuple<int, int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int ccw(pi a, pi b, pi c) {
  int res = (b.X - a.X) * (c.Y - b.Y) - (b.Y - a.Y) * (c.X - b.X);
  if(res > 0) return 1;
  if(res < 0) return -1;
  return 0;
}
int p[3005];
int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  p[a] += p[b];
  p[b] = a;
}

void solve() {
  int n;
  cin >> n;
  vector<ti> A;
  fill(p, p+n, -1);
  for(int i = 0; i < n; i ++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    pi a = {x1, y1}, b = {x2, y2};
    if(a > b) swap(a, b);
    for(int j = 0; j < sz(A); j ++) {
      auto [bx1, by1, bx2, by2] = A[j];
      pi c = {bx1, by1}, d = {bx2, by2};
      int val1 = ccw(a, b, c) * ccw(a, b, d);
      int val2 = ccw(c, d, a) *  ccw(c, d, b);
      if(val1 == 0 && val2 == 0) {
        if(a <= d && c <= b) {
          merge(i, j);
        }
      }
      else if(val1 <= 0 && val2 <= 0) {
        merge(i, j);
      }
    }
    A.pb({a.X, a.Y, b.X, b.Y});
  }
  int ans = 0, mx = 0;
  for(int i = 0; i < n; i ++) {
    if(p[i] < 0) {
      ans ++;
      mx = max(mx, -p[i]);
    }
  }
  cout << ans << nl << mx;
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