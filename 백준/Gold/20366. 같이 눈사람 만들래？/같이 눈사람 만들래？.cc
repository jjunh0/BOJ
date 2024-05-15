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
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[605];
void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> a[i];
  sort(a, a+n);
  int en = 0;
  int ans = 0x7fffffff;
  for(int i = 0; i < n; i ++) {
    for(int j = i+3; j < n; j ++) {
      int st = i+1, en = j-1;
      int m = a[i] + a[j];
      while(st < en) {
        int s = a[st]+a[en];
        if(s < m) st ++;
        else if(s > m) en --;
        else {
          cout << 0;
          return;
        }
        ans = min(ans, abs(m-s));
      }
    }
  }
  cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}