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
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N;
int A[1005], dp[1005];

void solve() {
  cin >> N;
  for(int i = 1; i <= N; i ++) {
    cin >> A[i];
  }
  for(int i = 1; i <= N; i ++) {
    dp[i] = A[i];
    for(int j = 1; j < i; j ++) {
      dp[i] = max(dp[i], dp[i-j] + A[j]);
    }
  }
  cout << dp[N];
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}