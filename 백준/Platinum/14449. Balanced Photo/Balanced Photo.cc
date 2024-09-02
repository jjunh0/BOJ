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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), L(n), R(n);
  for(auto &e : A) cin >> e;

  ordered_set l, r;
  for(int i =0; i < n; i ++) {
    L[i] = i-l.order_of_key(A[i]);
    l.insert(A[i]);
  }
  for(int i = n-1; i >= 0; i --) {
    R[i] = n-1 - i - r.order_of_key(A[i]);
    r.insert(A[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i ++) {
    int mn = min(L[i], R[i]);
    int mx = max(L[i], R[i]);
    if(mn * 2 < mx) ans ++;
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