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
  vector<int> A(n);
  for(auto &e : A) cin >> e;
  stack<pi> st;
  ll ans = 0;
  for(int i = 0; i < n; i ++) {
    while(!st.empty() && st.top().X < A[i]) {
      ans += st.top().Y;
      st.pop();
    }
    if(!st.empty()) {
      auto cur = st.top();
      if(cur.X == A[i]) {
        ans += cur.Y;
        st.pop();
        if(!st.empty()) ans ++;
        st.push({A[i], cur.Y+1});
      }
      else {
        ans ++;
        st.push({A[i], 1});
      }
    }
    else st.push({A[i], 1});
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