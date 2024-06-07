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
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  while(cin >> n) {
    vector<int> lis;
    int t; cin >> t;
    lis.pb(t);
    for(int i = 1; i < n; i ++) {
      cin >> t;
      if(lis.back() < t) lis.pb(t);
      else {
        auto it = lower_bound(all(lis), t);
        *it = t;
      } 
    }
    cout << sz(lis) << nl;
  }
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