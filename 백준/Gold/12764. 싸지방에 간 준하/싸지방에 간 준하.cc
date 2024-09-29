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
const int MAX_P = 1000005, MAX_N = 100005;
int en[MAX_P], st[MAX_P], cnt[MAX_N], p[MAX_N];
void solve() {
  int N;
  cin >> N;
  set<int> seat;
  for(int i = 1; i <= N; i ++) {
    seat.insert(i);
    int x, y;
    cin >> x >> y;
    st[x] = i, en[y] = i;
  }
  int ans = 0;
  for(int i = 0; i <= 1000000; i ++) {
    if(st[i]) {
      int cur = *seat.begin();
      p[st[i]] = cur;
      ans = max(cur, ans);
      seat.erase(cur);
      cnt[cur] ++;
    }
    if(en[i]) {
      seat.insert(p[en[i]]);
    }
  }
  cout << ans << nl;
  for(int i = 1; i <= ans; i ++) cout << cnt[i] << ' ';
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