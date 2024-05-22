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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> a[10005];
void solve() {
  int n;
  cin >> n;
  int mx = 0;
  priority_queue<int, vector<int>, less<int>> pq;
  for(int i = 0; i < n; i ++) {
    int d, p;
    cin >> p >> d;
    a[d].pb(p);
    mx = max(d, mx);
  }
  int ans = 0;
  for(int i = mx; i > 0; i --) {
    for(int j = 0; j < sz(a[i]); j ++) {
      pq.push(a[i][j]);
    }
    if(pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
}