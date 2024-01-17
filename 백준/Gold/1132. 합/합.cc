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
  int n;
  cin >> n;
  vector<string> s(n);
  vector<pair<ll, bool>> v(15);
  set<char> st;
  for(int i = 0 ; i < n; i ++) {
    cin >> s[i];
    v[s[i][0] - 'A'].Y = 1;
    for(int j = 0; j < sz(s[i]); j ++) {
      v[s[i][j] - 'A'].X += pow(10, sz(s[i]) - j - 1);
      st.insert(s[i][j]);
    }
  }
  int idx;
  sort(rall(v));
  int used_idx = -1;
  for(int i = 15; i >= 0; i --) {
    if(v[i].X && !v[i].Y) {
      used_idx = i;
      break;
    }
  }
  int cur = 9;
  ll ans = 0;
  for(int i = 0; i < 15; i ++) {
    if(v[i].X == 0) break;
  if((st.size() == 10 && i == used_idx)) continue;
    ans += v[i].X *(cur--);
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