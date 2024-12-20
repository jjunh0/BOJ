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

ll dp[35][35];

ll func(int W, int H) {
    if(W == 0 && H == 0) {
        return 1;
    }
    if(dp[W][H] != -1) {
        return dp[W][H];
    }
    dp[W][H] = 0;
    if(W-1 >= 0)
        dp[W][H] += func(W-1, H+1);
    if(H-1 >= 0)
        dp[W][H] += func(W, H-1);
    return dp[W][H];
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int N;
    while(cin >> N, N) {
        cout << func(N, 0) << nl;
    }
}