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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int val, n, m;
  cin >> val;
  cin >> n >> m;
  vector<int> A(n), B(m), pre_A(n+1), pre_B(m+1), all_A, all_B;
  for(auto &e : A) cin >> e;
  for(auto &e : B) cin >> e;
  pre_A[1] = A[0]; pre_B[1] = B[0];
  for(int i = 1; i < n; i ++) {
    pre_A[i+1] = pre_A[i] + A[i];
  }
  for(int i = 1; i < m; i ++) {
    pre_B[i+1] = pre_B[i] + B[i];
  }
  for(int i = 1; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      int tmp = pre_A[min(n,j+i)] - pre_A[j];
      if(n < j+i) {
        tmp += pre_A[j+i-n];
      }
      all_A.pb(tmp);
    }
  }
  all_A.pb(pre_A[n]);
  for(int i = 1; i < m; i ++) {
    for(int j = 0; j < m; j ++) {
      int tmp = pre_B[min(m,j+i)] - pre_B[j];
      if(m < j+i) {
        tmp += pre_B[j+i-m];
      }
      all_B.pb(tmp);
    }
  }
  all_B.pb(pre_B[m]);

  sort(all(all_A));
  sort(all(all_B));
  int ans = 0;
  for(int i = 0; i <= val; i ++) {
    int a = upper_bound(all(all_A), i) - lower_bound(all(all_A), i);
    int b = upper_bound(all(all_B), val-i) - lower_bound(all(all_B), val-i);
    if((a || b) &&
      (i == 0 || i == val)) {
      a = max(1, a);
      b = max(1, b);
    }
    ans += a*b;
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