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
const int MAX_N = 1000 * 15 + 5;
int ROOT = 1, unused = 2; 
vector<pi> nxt[MAX_N];
map<string, int> mp;
map<int, string> inv;

bool cmp(pi a, pi b) {
  return inv[a.X] < inv[b.X];
}

void insert(vector<int> &A) {
  int cur = ROOT;
  for(auto c : A) {
    int b = -1;
    for(int i = 0; i < sz(nxt[cur]); i ++) {
      if(c == nxt[cur][i].X) {
        b = i;
        break;
      }
    }
    if(b < 0) {
      nxt[cur].pb({c, unused ++});
      b = sz(nxt[cur])-1;
    }
    cur = nxt[cur][b].Y;
  }
}

void f(int cur, int depth) {
  for(auto c : nxt[cur]) {
    for(int i = 0; i < depth; i ++) cout << "--";
    cout << inv[c.X] << nl;
    f(c.Y, depth+1);
  }
}

void solve() {
  int N;
  cin >> N;
  int n;
  string t;
  int top = 1;

  for(int i = 0; i < N; i ++) {
    cin >> n;
    vector<int> A;
    for(int j = 0; j < n; j ++) {
      cin >> t;
      if(mp.find(t) == mp.end()) {
        inv[top] = t;
        mp[t] = top ++; 
      }
      A.pb(mp[t]);
    }
    insert(A);
  }
  for(int i = 1; i < unused; i ++) sort(all(nxt[i]), cmp);
  f(ROOT, 0);

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