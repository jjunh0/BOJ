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



// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    vector<ll> dp(1000005);
    for(int i = 1; i <= 1000000; i ++) {
      for(int j = 1; i * j <= 1000000; j ++) {
        dp[i*j] += i;
      }
    }
    partial_sum(all(dp), dp.begin());
    while(tests--) {
      int n;
      cin >> n;
      cout << dp[n] << nl;
    }
}