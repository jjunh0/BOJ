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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), lis, idx, pre(n), ans;

  for(auto &e : A) cin >> e;
  for(int i = 0; i < n; i ++) {
    if(lis.empty() || lis.back() < A[i]) {
      if(!lis.empty()) pre[i] = idx.back();
      else pre[i] = -1;
      lis.pb(A[i]);
      idx.pb(i);
    }
    else {
      auto it = lower_bound(all(lis), A[i]) - lis.begin();
      lis[it] = A[i];
      idx[it] = i;
      if(it == 0) pre[i] = -1;
      else pre[i] = idx[it-1];
    }

  }
  int cur = idx[sz(lis)-1];
  while(cur != -1) {
    ans.pb(A[cur]);
    cur = pre[cur];
  }
  reverse(all(ans));
  cout << sz(ans) << nl;
  for(auto e : ans) cout << e << ' ';
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