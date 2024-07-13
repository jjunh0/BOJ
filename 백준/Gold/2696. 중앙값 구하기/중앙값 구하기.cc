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
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    int m;
    cin >> m;
    priority_queue<int, vector<int>, less<int>> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    vector<int> ans;
    for(int i = 0; i < m; i ++) {
        int t;
        cin >> t;
        if(sz(mx) == sz(mn)) mx.push(t);
        else mn.push(t);
        while(sz(mn) && mx.top() > mn.top()) {
            int mx_t = mx.top();
            int mn_t = mn.top();
            mx.pop(); mn.pop();
            mn.push(mx_t); mx.push(mn_t);
        } 
        if(i%2 == 0) ans.pb(mx.top());
    }
    cout << sz(ans) << nl;
    for(auto e : ans) cout << e << ' ';
    cout << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}