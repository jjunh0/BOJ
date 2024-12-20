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

void solve() {  
    int N, D, K, C;
    cin >> N >> D >> K >> C;
    vector<int> A(2*N);
    for(auto &e : A) cin >> e;
    for(int i = 0; i < K; i ++) A[N+i] = A[i];
    vector<int> mp(D+1);
    int ans = 0, len = 1;
    mp[C] ++;
    for(int i = 0; i < N+K; i ++) {
        if(i < K) {
            if(mp[A[i]] == 0) len ++;
            mp[A[i]] ++;
        }
        else {
            ans = max(len, ans);
            mp[A[i-K]] --;
            if(mp[A[i-K]] == 0) len --;
            if(mp[A[i]] == 0) len ++;
            mp[A[i]] ++;
        }
    }
    ans = max(len, ans);
    cout << ans;
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