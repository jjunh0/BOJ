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
#define int ll
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int pw[300005];
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(auto &e : A) cin >> e;
  pw[0] = 1;
  for(int i = 1; i <= n; i ++) {
    pw[i] = pw[i-1] * 2;
    pw[i] %= MOD;
  }
  sort(all(A));
  int ans1 = 0, ans2 = 0;
  for(int i = 0; i < n; i ++) {
    ans1 += (A[i] * ((pw[i]) - 1));
    ans2 += (A[i]* ((pw[n-i-1]) - 1));
    ans1 %= MOD; ans2 %= MOD;
  }
  cout << (ans1 - ans2 + MOD) % MOD;
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}