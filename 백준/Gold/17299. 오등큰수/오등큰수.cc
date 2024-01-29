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
  int n;
  cin >> n;
  vector<int> v(n), cnt(n);
  for(auto &e : v) cin >> e;
  vector<int> mp(1000006);
  for(auto e : v) {
    mp[e] ++;
  }  
  for(int i = 0; i < n; i ++) {
    cnt[i] = mp[v[i]];
  }
  stack<pi> st; // cnt i
  vector<int> ans(n);
  for(int i = 0; i < n; i ++) {
    while(!st.empty() && st.top().X < cnt[i]) {
      ans[st.top().Y] = v[i];
      st.pop();
    }
    st.push({cnt[i], i});
  }
  while(!st.empty()) {
    ans[st.top().Y] = -1;
    st.pop();
  }
  for(auto e : ans) cout << e << ' ';
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
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