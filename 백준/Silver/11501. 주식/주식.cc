#include <bits/stdc++.h>
using namespace std;

int a[1000005];
void solve() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int max_i = n;
    for(int i = 0; i < n;  i ++) {
      cin >> a[i];
    }
    a[n] = 0;
    long long ans = 0;
    for(int i = n; i >= 0; i --) {
      if(a[i] > a[max_i]) {
        max_i = i;
      }
      else {
        ans += a[max_i] - a[i];
      }
    }
    cout << ans << '\n';
  }
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}