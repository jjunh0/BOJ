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
vector<int> A[1000005];
vector<pi> cand;
int N, M, T, K;

int f(int x, int y) {
  int ret = 0;
  if(x+K > N || y-K < 0) return -1;
  for(auto e : cand) {
    if(e.X >= x && e.X <= x+K && e.Y <= y && e.Y >= y - K) ret ++;
  }
  return ret;
}

void solve() {
  cin >> N >> M >> T >> K;
  for(int i = 0; i < T; i ++) {
    int x, y;
    cin >> x >> y;
    A[x].pb(y);
    cand.pb({x, y});
  }
  sort(all(cand));
  int ans = 0, ans_x, ans_y;
  for(int i = 0; i < T; i ++) {
    int x = cand[i].X;
    if(x+K > N) {
      x = N-K;
    }
    for(int j = 0; j < T; j ++) {
      int y = cand[j].Y;
      if(y-K < 0) {
        y = K;
      }
      int ret = f(x, y);
      if(ans < ret) {
        ans_x = x, ans_y = y;
        ans = ret;
      }
    }
  }
  cout << ans_x << ' ' << ans_y << nl;
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