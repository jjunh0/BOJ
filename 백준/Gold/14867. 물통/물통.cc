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
int a, b, c, d;
map<pi, int> mp;
queue<pi> q;

void func(int x, int y, int val) {
  if(mp.find({x, y}) == mp.end()) {
    q.push({x, y});
    mp[{x, y}] = val + 1;
  }
}

void solve() {
  cin >> a >> b >> c >> d;
  q.push({0, 0});
  mp[{0, 0}] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    if(cur.X == c && cur.Y == d) {
      break;
    }
    int cur_val = mp[{cur.X, cur.Y}];
    func(a, cur.Y, cur_val);
    func(cur.X, b, cur_val);
    func(0, cur.Y, cur_val);
    func(cur.X, 0, cur_val);
    func(cur.X - min(b-cur.Y, cur.X), cur.Y + min(b-cur.Y, cur.X), cur_val);
    func(cur.X + min(a - cur.X, cur.Y), cur.Y - min(a - cur.X, cur.Y), cur_val);
    
  }  
  if(mp.find({c, d}) != mp.end()) cout << mp[{c, d}]-1;
  else cout << -1;
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