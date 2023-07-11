#include <bits/stdc++.h>
using namespace std;
#define Y second
#define X first
int arr[505];
int dp[505];
void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for(int i = 1; i <= n; i ++) {
    int t1, t2;
    cin >> t1 >> t2;
    v.push_back({t1, t2});
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i ++) {
    arr[i] = v[i].Y;
  } 
  int ans = 0;
  for(int i = 0; i < n; i ++) {
    dp[i] = 1;
    for(int j = 0; j < i; j ++) {
      if(arr[i] > arr[j]) {
        dp[i] = max(dp[j]+1, dp[i]);
        ans = max(ans, dp[i]);
      }
    }
    //cout << i << ' ' << arr[i] << '\n';
  }
  cout << n - ans;
}

// ************************************

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}