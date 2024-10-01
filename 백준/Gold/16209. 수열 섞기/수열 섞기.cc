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
  vector<int> A(N);
  for(auto &e : A) cin >> e;
  sort(all(A));
  // int ans = 0;
  vector<int> B;
  B.pb(A[0]);
  for(int i = 2; i < N; i += 2) B.pb(A[i]);
  if(N&1) {
    for(int i = N-2; i >= 2; i -= 2) B.pb(A[i]);
  }
  else {
    for(int i = N-1; i >= 2; i -= 2) B.pb(A[i]);
  }
  B.pb(A[1]);
  // ans = B[0] * B[N-1];
  // for(int i = 1; i < N; i ++) ans += B[i] * B[i-1];
  // cout << ans << nl;
  for(auto &e : B) cout << e << ' ';
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