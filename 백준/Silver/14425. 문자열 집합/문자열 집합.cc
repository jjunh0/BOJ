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
  const int MAX_N = 5000005;
  int ROOT = 1, top = 2, nxt[MAX_N][30], chk[MAX_N];

  int cc(char c) {
    return c - 'a';
  }

  void insert(string &s) {
    int cur = ROOT;
    for(auto c : s) {
      if(nxt[cur][cc(c)] == -1) {
        nxt[cur][cc(c)] = top ++;
      }
      cur = nxt[cur][cc(c)];
    }
    chk[cur] = 1;
  }

  bool find(string &s) {
    int cur = ROOT;
    for(auto c : s) {
      if(nxt[cur][cc(c)] == -1) return false;
      cur = nxt[cur][cc(c)];
    }
    return chk[cur];
  }

  void solve() {
    int N, M;
    cin >> N >> M;
    memset(nxt, -1, sizeof(nxt));
    for(int i = 0; i < N; i ++) {
      string s;
      cin >> s;
      insert(s);
    }
    int ans = 0;
    for(int i = 0; i < M; i ++) {
      string s;
      cin >> s;
      if(find(s)) ans ++;
    }
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