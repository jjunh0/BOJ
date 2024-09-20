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
int N, W;
vector<pi> A;
int dp[1005][1005];
ti nxt[1005][1005];
int dis(pi a, pi b) {
    return abs(a.X-b.X) + abs(a.Y-b.Y);
}

int f(int cur1, int cur2) {
    int idx = max(cur1, cur2) + 1;
    if(idx >= W) return 0;
    if(dp[cur1][cur2] != -1) return dp[cur1][cur2];
    int ret;
    int f1 = dis(A[cur1], A[idx]) + f(idx, cur2), f2 = dis(A[cur2], A[idx]) + f(cur1, idx);
    if(f1 > f2) {
        ret = f2;
        nxt[cur1][cur2] = {cur1, idx, 2};
    }
    else {
        ret = f1;
        nxt[cur1][cur2] = {idx, cur2, 1};
    }
    dp[cur1][cur2] = ret;
    return ret;
}
void solve() {
    cin >> N >> W;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < 1005; i ++) for(int j = 0; j < 1005; j ++) nxt[i][j] = {-1, -1, -1};
    A.pb({1, 1}), A.pb({N, N});
    for(int i = 0; i < W; i ++) {
        int a, b;
        cin >> a >> b;
        A.pb({a, b});
    }
    W += 2;
    cout << f(0, 1) << nl;
    int sx = 0, sy = 1;
    while(1) {
        auto [x, y, cur] = nxt[sx][sy];
        if(x == -1 && y == -1) break;
        cout << cur << nl;
        sx = x, sy = y;
    }
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