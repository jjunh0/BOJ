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
  string s;
  int k;
  cin >> s >> k;
  queue<pair<string, int>> q;
  q.push({s, 0});
  set<string> st[k+1];
  st[0].insert(s);
  while(sz(q)) {
    auto cur = q.front();
    q.pop();
    if(cur.Y == k) continue;
    for(int i = 0; i < sz(cur.X); i ++) {
      for(int j = i+1; j < sz(cur.X); j ++) {
        string nxt = cur.X;
        swap(nxt[i], nxt[j]);
        if(nxt[0] == '0') continue;
        if(st[cur.Y+1].find(nxt) != st[cur.Y+1].end()) continue;
        q.push({nxt, cur.Y+1});
        st[cur.Y+1].insert(nxt);
      }
    }
  }
  int ans = 0;
  for(auto e : st[k]) {
    ans = max(ans, stoi(e));
  }
  cout << (ans==0 ? -1 : ans);


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