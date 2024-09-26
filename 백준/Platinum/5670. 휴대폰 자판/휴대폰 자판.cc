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
const int MN = 1e6 + 5;
vector<pi> nxt[MN];
vector<bool> chk(MN);
const int ROOT = 1;
int unused = 2, ans = 0;

int c2i(char c) {
  return c - 'a';
}

void insert(string &s) {
  int cur = ROOT;
  for(auto c : s) {
    int idx = -1;
    for(auto e : nxt[cur]) {
      if(e.X == c2i(c)) {
        idx = e.Y;
        break;
      }
    }
    if(idx < 0) {
      nxt[cur].pb({c2i(c), unused});
      idx = unused ++;
    }
    cur = idx;
  }
  chk[cur] = 1;
}

void f(int cur, int cnt) {
  if(chk[cur]) {
    ans += cnt;
  }
  for(auto e : nxt[cur]) {
    f(e.Y, cnt + (sz(nxt[cur]) != 1 || chk[cur]));
  }
}

void solve() {
  int N;
  while(cin >> N) {
    for(int i = 0; i < MN; i ++) nxt[i].clear();
    fill(all(chk), 0);
    unused = 2, ans = 0;
    for(int i = 0; i < N; i ++) {
      string s;
      cin >> s;
      insert(s);
    }
    for(auto e : nxt[ROOT]) {
      f(e.Y, 1);
    }
    cout << 1. * ans/N << nl;
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);
    int tests = 1;
    while(tests--) {
        solve();
    }
}