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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int n, cur = 0, t, s, e;
  cin >> n;
  vector<int> A(n), val(n), res(n), ans(n);
  t = 0; s = 1; e = n-1;
  for(auto &e : A) cin >> e;
  for(int i = 0; i < n; i ++) val[i] = i;
  for(int i = 0; i < n; i ++) {
    if(A[i] == 1) {
      res[cur++] = val[t];
      t = s;
      s++;
    }
    else if(A[i] == 2) {
      res[cur++] = val[s];
      s ++;
    }
    else {
      res[cur++] = val[e];
      e --;
    }
  }
  for(int i = 0; i < n; i ++) {
    ans[res[i]] = n-i;
  }
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