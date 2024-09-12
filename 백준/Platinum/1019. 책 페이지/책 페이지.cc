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

void f2(int cur, vector<ll> &cnt) {
  while(cur > 1) {
    cnt[cur%10] ++;
    cur /= 10;
  }
}
void f(int cur, vector<ll> &cnt) {
  while(cur) {
    cnt[cur%10] ++;
    cur /= 10;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<ll> ans(10, 0), pre(10, 0);
  for(int i = 0; i <= 999; i ++) {
    f2(1000 + i, pre);
  }
  vector<ll> cnt(10);
  for(int i = 1; i <= min(999, n); i ++) {
    f(i, ans);
  }
  for(int i = 1000; i <= n; i += 1000) {
    if(i+1000 > n) {
      for(int j = i; j <= n; j ++) {
        f(j, ans);
      }
    }
    else {
      fill(all(cnt), 0);
      f(i/1000, cnt);
      for(int j = 0; j < 10; j ++) {
        ans[j] += pre[j] + cnt[j]*1000;
      }
    }
  }
  for(int i = 0; i < 10; i ++) cout << ans[i] << ' ';
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