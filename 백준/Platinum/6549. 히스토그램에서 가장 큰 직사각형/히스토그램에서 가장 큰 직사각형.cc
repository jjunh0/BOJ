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
  while(cin >> N, N) {
    vector<ll> A(N);
    for(auto &e : A) cin >> e;
    stack<pl> st;
    ll ans = 0;
    A.pb(-1);
    for(int i = 0; i < N+1; i ++) {
      if(st.empty() || st.top().X <= A[i]) st.push({A[i], i});
      else {
        int t = i;
        while(!st.empty() && st.top().X > A[i]) {
          auto cur = st.top();
          st.pop();
          t = cur.Y;
          ans = max(ans, cur.X*(i-cur.Y));
        }
        st.push({A[i], t});
      }
    }
    cout << ans << nl;
  }
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