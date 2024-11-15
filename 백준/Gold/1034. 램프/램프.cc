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
  int N, M, K;
  cin >> N >> M;
  vector<string> A(N);
  map<string, int> mp;
  for(auto &e : A) {
    cin >> e;
    mp[e] ++;
  }
  cin >> K;
  int ans = 0;
  for(auto e : mp) {
    string s = e.X;
    int cnt = 0;
    for(int i = 0; i < M; i ++) {
      if(s[i] == '0') {
        cnt ++;
      }
    }
    if(K >= cnt && K%2 == cnt%2) {
      ans = max(ans, e.Y);
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