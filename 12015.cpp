#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  int ans = 0;
  vector<int> v(n+1, 0);
  int vi = 1;
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    if(i == 0) v[i] = t;
    else {
      auto l = lower_bound(v.begin(), v.begin() + vi, t);
      *l = t;
      if(l == v.begin() + vi) vi ++;
    }
  }
  // for(int i = 0; i < vi; i ++) {
  //   cout << v[i] << ' ';
  // }
  cout << vi;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}