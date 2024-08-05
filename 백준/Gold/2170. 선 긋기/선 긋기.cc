#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> v;
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());

  int i = 0;
  int ans = 0;
  int start = -0x7f7f7f7f;
  int end = -0x7f7f7f7f;
  while(i < n) {
    if(start > v[i].Y) {
      i ++;
      continue;
    }
    if(v[i].X < start) {
      ans += v[i].Y - start;
    }
    else {
      ans += v[i].Y - v[i].X;
    }
    start = v[i].Y;
    i ++;
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}