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
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  int n;
  cin >> n;
  vector<ti> v(n+1);
  vector<int> ans(n+1), pre_col(n+1);
  int pre_sum = 0, pre = -1;
  stack<pi> st;
  for(int i = 1; i <= n; i ++) {
    int a, b;
    cin >> a >> b;
    v[i] = {b, a, i};
  }
  sort(v.begin()+1, v.end());
  for(int i = 1; i <= n; i ++) {
    auto [len, col, idx] = v[i];
    if(pre != -1 && pre != len) {
      while(sz(st)) {
        auto cur = st.top();
        st.pop();
        pre_col[cur.Y] += cur.X;
        pre_sum += cur.X;
      }
    }
    ans[idx] = pre_sum - pre_col[col];
    st.push({len, col});
    pre = len;
  }
  for(int i = 1; i <= n; i ++) cout << ans[i] << nl;
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