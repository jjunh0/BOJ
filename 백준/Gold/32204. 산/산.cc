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
  int n;
  cin >> n;
  vector<int> A(n), dp1(n), dp2(n);
  for(auto &e : A) cin >> e;
  dp1[0] = 0, dp2[0] = 0;
  for(int i = 1; i < n; i ++) {
    dp1[i] = i, dp2[i] = i;
    if(A[i-1] >= A[i]) dp1[i] = dp1[i-1];
    if(A[i-1] <= A[i]) dp2[i] = dp2[i-1];
  }
  ll ans = 1;
  for(int i = 1; i < n; i ++) {
    if(dp1[i] != i) {
      ans += i-dp2[dp1[i]]+1;
    }
    else if(dp2[i] != i) {
      ans += i - dp2[i]+1;
    }
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