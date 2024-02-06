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

vector<pi> v(105);
vector<int> dp(105, -1);
int n;

int func(int cur) {
  if(dp[cur] != -1) return dp[cur];
  dp[cur] = 0;
  int curX = v[cur].X;
  int curY = v[cur].Y;

  for(int i = cur; i < n; i ++) {
    if(curX >= v[i].X && curY >= v[i].Y) {
      dp[cur] = max(dp[cur], 1 + func(i));
    }
  }
  return dp[cur];
}
void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    cin >> v[i].X >> v[i].Y;
    if(v[i].X > v[i].Y) swap(v[i].X, v[i].Y);
  }
  sort(rall(v));

  for(int i = 0; i < n; i ++) {
    func(i);
  }

  cout << *max_element(all(dp));
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