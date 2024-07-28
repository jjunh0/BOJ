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
#define int ll
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int n, k;
  cin >> k >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<int> A(k);
  for(auto &e : A) {
    cin >> e;
    pq.push(e);
  }
  sort(rall(A));
  while(n-- > 1) {
    int cur = pq.top();
    pq.pop();
    for(auto e : A) {
        pq.push(cur*e);
        if(cur%e == 0) break;
    }
  }
  cout << pq.top();
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}