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

  void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    deque<pi> dq;
    int ans = 0;
    
    for(int i = 0; i < m; i ++) {
      if(s[i] == 'I' && (dq.empty() || dq.back().X == 0)) dq.push_back({1, i});
      else if(s[i] == 'O' && (!dq.empty() && dq.back().X == 1)) dq.push_back({0, i});
      else {
        dq.clear();
        if(s[i] == 'I') dq.push_back({1, i});
        else dq.push_back({0, i});
      }
      while(!dq.empty() && (dq.front().Y < i - 2*n || dq.front().X != 1)) dq.pop_front();
      if(sz(dq) == 2*n+1) {
        ans ++;
        dq.pop_front();
        dq.pop_front();

      }
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