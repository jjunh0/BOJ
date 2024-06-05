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
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, l, p;
vector<pi> v;
void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int x, val;
    cin >> x >> val;
    v.pb({x, val});
  }
  cin >> l >> p;
  v.pb({l, 0});
  sort(all(v));
  int ans = 0;
  priority_queue<int, vector<int>, less<int>> pq;
  for(int i = 0; i <= n; i ++) {
    while(!pq.empty() && p < v[i].X) {
      p += pq.top();
      pq.pop();
      ans ++;
    }
    if(p < v[i].X) {
      cout << -1;
      return;
    }
    pq.push(v[i].Y);
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