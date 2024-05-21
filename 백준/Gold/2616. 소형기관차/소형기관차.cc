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
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int a[50005];
int dp[5][50005];
int pre[50005];
int func(int cnt, int idx) {
  if(idx == n) return 0;
  if(dp[cnt][idx] != -1) return dp[cnt][idx];
  int result = func(cnt, idx+1);
  if(cnt > 0 && idx+m <= n) {
    result = max(result, pre[idx+m] - pre[idx] + func(cnt-1, idx+m));
  }
  dp[cnt][idx] = result;
  return result;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> a[i];
  for(int i = 0; i < n; i ++) pre[i+1] = pre[i] + a[i];
  for(int i = 0; i < 5; i ++) fill(dp[i], dp[i]+n+1, -1);
  cin >> m;
  cout << func(3, 0);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}