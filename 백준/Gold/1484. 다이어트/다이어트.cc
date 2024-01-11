#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pw(x) x*x
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
  int g;
  cin >> g;
  vector<ll> ans;
  ll st=1, en=1;
  while(1) {
    if(pw(en) - pw(st) > g && en-st <= 1) break;
    if(pw(en) - pw(st) < g) en ++;
    else if(pw(en) - pw(st) > g) st ++;
    else ans.pb(en++);
  }
  sort(all(ans));
  if(sz(ans) == 0) {
    cout << -1;
    return;
  }
  for(auto e : ans) cout << e << nl;
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