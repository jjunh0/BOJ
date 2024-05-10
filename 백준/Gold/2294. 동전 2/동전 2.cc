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
vector<int> A(105);
vector<int> dp(10005, mx);
int n, k;


void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i ++) {
    cin >> A[i];
  }
  dp[0] = 0;
  for(int i = 0; i <= k; i ++) {
    for(int j = 0; j < n; j ++) {
      if(i-A[j] >= 0) {
        dp[i] = min(dp[i], dp[i-A[j]]+1);
      }
    }
  }
  cout << (dp[k] == mx ? -1 : dp[k]);
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
