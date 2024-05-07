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
  int n, m;
  cin >> n >> m;
  vl cnt(m);
  ll sum = 0;
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    sum += t;
    cnt[sum%m] ++;
  }
  ll ans = cnt[0];
  for(int i = 0; i < m; i ++) {
    if(cnt[i] > 0)
      ans += cnt[i]*(cnt[i]-1)/2;
  }
  cout << ans << nl;

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