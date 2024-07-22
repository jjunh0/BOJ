#include <bits/stdc++.h>
using namespace std;

int a[4005], b[4005], c[4005], d[4005];  
void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; i ++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<int> a2b;
  vector<int> c2d;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++)
      a2b.push_back(a[i] + b[j]);
  }
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++)
      c2d.push_back(c[i] + d[j]);
  } 
  sort(c2d.begin(), c2d.end());
  long long ans = 0;
  for(int i = 0; i < a2b.size(); i ++) {
    ans += upper_bound(c2d.begin(), c2d.end(), -a2b[i]) - lower_bound(c2d.begin(), c2d.end(), -a2b[i]);
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}