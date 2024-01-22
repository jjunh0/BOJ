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

vector<pair<int, int>> board;
int n;
int dp[1005][1005];
int func(int d, int idx) { // d일에 idx를 선택했을때의 최대 점수
  if(dp[d][idx] != 0) return dp[d][idx];
  for(int i = idx; i < n; i ++) {
    if(board[i].X <= d) continue;
    dp[d][idx] = max(dp[d][idx], board[i].Y + func(d+1, i+1));
  }
  return dp[d][idx];
}
void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int a, b;
    cin >> a >> b;
    board.pb({a, b});
  }
  sort(all(board));
  int ans = 0;
  cout << func(0, 0);
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