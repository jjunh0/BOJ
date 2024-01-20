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

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  stack<char> st;
  for(int i = 0; i < n; i ++) {
    if(st.empty()) st.push(s[i]);
    else if(st.top() >= s[i]) st.push(s[i]);
    else {
      while(!st.empty() && st.top() < s[i] && k > 0) {
        st.pop();
        k --;
      }
      st.push(s[i]);
    }
  }
  while(k > 0) {
    st.pop();
    k--;
  }
  vector<char> v;
  while(!st.empty()) {
    v.pb(st.top());
    st.pop();
  }
  reverse(all(v));
  for(auto e : v) cout << e;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}