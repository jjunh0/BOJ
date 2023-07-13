#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
ll b[500005]; // 내림차순
ll s[500005];
ll e[500005];
ll cnt[500005*2 + 1];
void solve() {
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i ++) {
    cin >> a[i];
    b[i] = -a[i];
  }
  sort(a+1, a+1+n);
  sort(b+1, b+1+n);
  for(int i = 1; i <= n; i ++) {
    a[i] += a[i-1];
    b[i] += b[i-1];
  }
  vector<ll> v;
  v.push_back(0);
  for(int i = 1; i <= m; i ++) {
    cin >> s[i] >> e[i];
    v.push_back(s[i]);
    v.push_back(e[i] + 1);
    // imos[s[i]] ++;
    // imos[e[i]+1] --;
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i <= m; i ++) {
    int p = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
    cnt[p] ++;
    p = lower_bound(v.begin(), v.end(), e[i]+1) - v.begin();
    cnt[p] --;
  }
  for(int i = 1; i < v.size(); i ++) {
    //cout << i << ' ' << cnt[i] << '\n';
    cnt[i] += cnt[i-1];
  }
  long long mn = 0, mx = 0;
  for(int i = 1; i < v.size()-1; i ++) {
    //if(cnt[i] > n) cnt[i] = n;
    mn += 1ll * a[cnt[i]] * (v[i+1] - v[i]);
    mx += -1ll * b[cnt[i]] * (v[i+1] - v[i]);
    //cout << i << ' ' << v[i+1] << ' ' << v[i] << '\n';
  }
  cout << mn << ' ' << mx;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}