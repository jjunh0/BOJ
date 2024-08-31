#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int n, k;
  cin >> n >> k;
  ordered_set os;
  ll ans = 0;
  vector<int> A(n);
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    A[i] = t;
    os.insert(t);
    if(sz(os) > k) {
      auto it = os.order_of_key(A[i-k]);
      os.erase(os.find_by_order(it));
    }
    if(i >= k-1) {
      ans += *os.find_by_order((k+1)/2 - 1);
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