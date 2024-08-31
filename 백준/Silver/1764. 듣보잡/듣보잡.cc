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
  int n, m;
  cin >> n >> m;
  set<string> st;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    st.insert(s);
  }
  vector<string> ans;
  for(int i = 0; i < m; i ++) {
    string s;
    cin >> s;
    if(st.count(s)) {
      ans.pb(s);
    }
  }
  sort(all(ans));
  cout << sz(ans) << nl;
  for(auto e : ans) cout << e << nl;
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