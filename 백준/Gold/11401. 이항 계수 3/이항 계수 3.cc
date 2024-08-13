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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX_N = 4000005;
vector<long long> fact(MAX_N), inv_fact(MAX_N);
 
long long power(long long x, int y) {
    long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
 
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv_fact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}
 
long long nCr(int n, int r) {
    if (r > n) return 0;
    return (((fact[n] * inv_fact[r]) % MOD) * inv_fact[n-r]) % MOD;
}

void solve() {
  precompute();
  int n, k;
  cin >> n >> k;
  cout << nCr(n,k);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}