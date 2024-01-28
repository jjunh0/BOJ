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
  ll n, k, q;
  cin >> n >> k >> q;
  while(q--) {
    ll x, y;
    cin >> x >> y;
    x--; y --;
    int cnt = 0;
    if(k == 1) {
      cout << max(x,y)-min(x,y) << nl;
      continue;
    }
    while(1) {
      if(x == y) {
        cout << cnt << nl;
        break;
      }
      if(x > y) {
        x = (x-1)/k;
      }
      else {
        y = (y-1)/k;
      }
      cnt ++;
    }    

  }
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