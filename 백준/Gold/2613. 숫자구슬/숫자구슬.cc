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
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for(int i = 0; i < n; i ++) {
    cin >> A[i];
  }

  int lo = 0, hi = 30000;
  while(lo + 1 < hi) {
    int mid = (lo+hi)/2;
    int sum = 0, cnt = 1, mx = 0;
    for(int i = 0; i < n; i ++) {
      if(A[i] > mid) {
        cnt = m+1;
        break;
      }
      sum += A[i];
      if(sum > mid) {
        sum -= A[i];
        sum = A[i];
        cnt ++;
      }
    }
    if(cnt <= m) hi = mid;
    else lo = mid;
  }
  cout << hi << nl;
  int cnt = 0, sum = 0;
  vector<int> ans;
  for(int i = 0; i < n; i ++) {
    sum += A[i];
    if(sum > hi) {
      ans.pb(cnt);
      cnt = 0;
      sum = A[i];
    }
    cnt ++;
  }
  ans.pb(cnt);
  while(sz(ans) < m) {
    for(int i = 0; i < sz(ans); i ++) {
      if(ans[i] > 1) {
        ans.insert(ans.begin()+i+1, 1);
        ans[i] --;
      }
      if(sz(ans) == m) break;
    }
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