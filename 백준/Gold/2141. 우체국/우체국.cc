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
  ll n;
  cin >> n;
  vector<pl> v(n);
  for(auto &e : v) cin >> e.X >> e.Y;
  sort(all(v));
  ll sum = 0;
  for(int i = 0; i < n; i ++) {
    sum += v[i].Y;
  }
  ll cur = 0;
  for(int i = 0; i < n; i ++) {
    cur += v[i].Y;
    if(cur >= (sum+1)/2) {
      cout << v[i].X << nl;
      return;
    }
  }
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