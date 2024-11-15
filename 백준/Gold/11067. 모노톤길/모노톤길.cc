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
void solve() {
  int N;
  cin >> N;
  vector<vector<int>> A(100000+5, vector<int>());
  vector<pi> ans;
  for(int i = 0; i < N; i ++) {
    int x, y;
    cin >> x >> y;
    A[x].pb(y);
  }
  for(int i = 0; i <= 100000; i ++) {
    sort(all(A[i]));
  }

  int pre = 0;
  for(int i = 0; i <= 100000; i ++) {
    if(!sz(A[i])) continue;
    if(A[i][0] != pre) reverse(all(A[i]));
    for(int j = 0; j < sz(A[i]); j ++) {
      ans.pb({i, A[i][j]});
      pre = A[i][j];
    }
  }
  int Q;
  cin >> Q;
  while(Q--) {
    int cur;
    cin >> cur;
    cout << ans[cur-1].X << ' ' << ans[cur-1].Y << nl;
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    while(tests--) {
        solve();
    }
}