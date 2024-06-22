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
int cube[25];
int ans = 0;
bool func(int l, int w, int h) {
  if(l == 0 || w == 0 || h == 0) return 1;
  for(int i = 20; i >= 0; i --) {
    int pw = (1 << i);
    if(pw > l || pw > w || pw > h || !cube[i]) continue;
    cube[i] --;
    ans ++;
    return func(l-pw, pw, pw) & func(pw, w-pw, pw) & func(l-pw, w-pw, pw) & func(l, w, h - pw);
  }
  return 0;
}

void solve() {
  int l, w, h, n;
  cin >> l >> w >> h;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int a, b;
    cin >> a >> b;
    cube[a] = b;
  }

  cout << (func(l, w, h)? ans : -1);

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