#include <bits/stdc++.h>
using namespace std;

int cost[1000][5];
int dp[1000][5];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < 3; j ++)
      cin >> cost[i][j];
  }
  dp[0][0] = cost[0][0];
  dp[0][1] = cost[0][1];
  dp[0][2] = cost[0][2];
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < 3; j ++) { 
      dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + cost[i][j];
    } 
  }
  cout << *min_element(dp[n-1], dp[n-1]+3);

}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}