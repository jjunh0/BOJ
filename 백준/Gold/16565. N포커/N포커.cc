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
const int MX = 0x3f3f3f3f;
const int MOD = 10007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int nCr[55][55];
void solve() {
  int n;
  cin >> n;
	for (int i = 0; i < 53; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		}
	}
  int ans = 0;
  for(int i = 1; i*4 <= n; i ++) {
    if(i%2) ans += nCr[13][i] * nCr[52-4*i][n-4*i];
    else ans -= nCr[13][i] * nCr[52-4*i][n-4*i];
    ans %= MOD;
    ans = (ans+MOD)%MOD;
  }
  cout << ans;
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