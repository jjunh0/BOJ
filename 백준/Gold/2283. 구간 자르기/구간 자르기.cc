#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
#define int long long
using namespace std;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int mx = 0;
pi a[1005];
int pre[1'000'005];
int pre_sum[1'000'005];
void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i ++) {
    cin >> a[i].X >> a[i].Y;
    pre[a[i].X] ++;
    pre[a[i].Y] --;
    mx = max(a[i].Y, mx);
  }
  for(int i = 1; i <= mx; i ++) {
    pre[i] += pre[i-1];
  }
  for(int i = 1; i <= mx; i ++) {
    pre_sum[i] = pre_sum[i-1] + pre[i-1];
  }
  int st = 0, en = 0;
  while(en < mx+1) {
    int sum = pre_sum[en] - pre_sum[st];
    // 시작점 = xx[st], 끝점 = yy[en]
    if(sum < k) en ++;
    else if(sum > k) st ++;
    else {
      cout << st << ' ' << en;
      return;
    }
  }
  cout << 0 << ' ' << 0 << nl;
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
}