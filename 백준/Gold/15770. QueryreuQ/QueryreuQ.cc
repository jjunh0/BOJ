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
const int MAX_N = 10005;
bool D[MAX_N][MAX_N];
ll dp[MAX_N];
void solve() {
  ll N, sum = 0, idx = 0;
  string s;
  vector<char> str;
  cin >> N >> s;
  for(int i = 0; i < N; i ++) {
    if(s[i] == '-') {
      str.pop_back();
      idx --;
      sum -= dp[idx];
      for(int j = 0; j < MAX_N; j ++) {
        D[j][idx] = 0;
      }
    }
    else {
      D[idx][idx] = 1;
      dp[idx] = 1;
      str.pb(s[i]);
      for(int j = 0; j < idx; j ++) {
        if(str[j] == str[idx] && (D[j+1][idx-1] || idx-1<j+1)) {
          dp[idx] ++;
          D[j][idx] = 1;
        }
      }
      sum += dp[idx];
      idx ++;
    }
    cout << sum << ' ';
  }
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