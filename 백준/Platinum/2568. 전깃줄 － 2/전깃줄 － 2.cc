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
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
pair<int, int> A[100005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int a, b;
    cin >> a >> b;
    A[i] = {a, b};
  }
  sort(A, A+n);
  vector<int> arr;
  stack<pi> st;
  arr.pb(A[0].Y);
  st.push({0, A[0].X});
  for(int i = 1; i < n; i ++) {
    if(arr.back() < A[i].Y) {
      st.push({sz(arr), A[i].X});
      arr.pb(A[i].Y);
    }
    else {
      int idx = lower_bound(all(arr), A[i].Y) - arr.begin();
      arr[idx] = A[i].Y;
      st.push({idx, A[i].X});
    }
  }
  vector<int> ans;
  int len = sz(arr)-1;
  while(!st.empty()) {
    auto cur = st.top();
    st.pop();
    if(cur.X == len) {
      len --;
    } 
    else {
      ans.pb(cur.Y);
    }
  }
  reverse(all(ans));
  cout << sz(ans) << nl;
  for(int i = 0; i < sz(ans); i ++) cout << ans[i] << nl;
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