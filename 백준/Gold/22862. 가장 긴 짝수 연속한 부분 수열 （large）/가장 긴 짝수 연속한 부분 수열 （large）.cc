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
  int n, k;
  cin >> n >> k;
  vector<int> v(1000005);
  for(int i = 0; i < n; i ++) cin >> v[i];
  int st = 0, en = 0;
  int kt = k;
  int ans = 0, cnt = 0;
  while(1) {
    if(v[en] % 2 == 0) {
      en ++;
      cnt ++;
    }
    else if(kt > 0) {
      en ++;
      kt --;
    }
    else {
      if(v[st]%2 == 0) cnt --;
      else kt ++;
      st ++;
    }
    ans = max(ans, cnt);
    if(en >= n) break;
  }
  cout << ans;
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