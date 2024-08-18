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

void solve() {
  ll a, b;
  cin >> a >> b;
  queue<pair<ll, int>> q;
  q.push({a, 1});
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    if(cur.X > b) continue;
    if(cur.X == b) {
      cout << cur.Y;
      return;
    }
    q.push({cur.X*2, cur.Y+1});
    q.push({cur.X*10 + 1, cur.Y+1});
  }
  cout << -1;
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