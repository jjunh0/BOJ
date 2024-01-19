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

vector<tuple<int, int, int>> v;
vector<int> dp(105, -1);
vector<int> pre(105, -1);
int n;
// x위에 쌓을 수 있는 높이의 최대
int func(int x) {
  if(dp[x] != -1) return dp[x];
  int l, h, m;
  tie(l, h, m) = v[x];
  dp[x] = h;
  for(int i = 0; i < n; i ++) {
    if(i == x) continue;
    int a, b, c;
    tie(a,b,c) = v[i];
    if(l < a || c > m) continue;
    int f = func(i);
    if(dp[x] < h + f) {
      pre[x] = i;
      dp[x] = h+f;
    }
  }
  return dp[x];
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.pb({a, b, c});
  }  
  for(int i = 0; i < n; i ++) {
    func(i);
  }
  int idx = max_element(all(dp)) - dp.begin();
  int cur = idx;
  vector<int> ans;
  while(cur != -1) {
    ans.pb(cur);
    cur = pre[cur];
  }
  reverse(all(ans));
  cout << sz(ans) << nl;
  for(auto e : ans) cout << e+1 << nl;

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