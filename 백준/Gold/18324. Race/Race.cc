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

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int N, K;
  cin >> K >> N;
  while(N--) {
    int t;
    cin >> t;
    int d = 0, v = 1, ans = 0;
    for(v = 1; v <= t; v ++) {
      d += v;
      ans ++;
      if(d >=K) 
        break;
    }
    v --;
    while(d < K) {
      d += v;
      ans ++;
      if(d >= K) break;
      v ++;
      d += v;
      ans ++;
    }
    cout << ans << nl;
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}