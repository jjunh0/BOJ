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

vector<int> A, B, aa, bb;

ll sum = 0;
void dfs1(int cur) {
  if(sum > 1e9) return;
  if(cur == sz(A)) {
    aa.pb(sum);
    return;
  }
  dfs1(cur+1);
  sum += A[cur];
  dfs1(cur+1);
  sum -= A[cur];
}
void dfs2(int cur) {
  if(sum > 1e9) return;
  if(cur == sz(B)) {
    bb.pb(sum);
    return;
  }
  dfs2(cur+1);
  sum += B[cur];
  dfs2(cur+1);
  sum -= B[cur];
}

void solve() {
  int N, C;
  cin >> N >> C;
  for(auto &e : A) cin >> e;
  for(int i = 0; i < N/2; i ++) {
    int t; cin >> t;
    A.pb(t);
  }
  for(int i = N/2; i < N; i ++) {
    int t; cin >> t;
    B.pb(t);
  }
  dfs1(0);
  dfs2(0);
  sort(all(bb));
  ll ans = 0;
  for(int i = 0; i < sz(aa); i ++) {
    ans += upper_bound(all(bb), C - aa[i]) - bb.begin();
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