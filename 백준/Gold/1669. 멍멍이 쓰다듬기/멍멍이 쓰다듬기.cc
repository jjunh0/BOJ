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

ll f(ll x) {
  return x * (x+1) / 2 + (x-1) * x / 2;
}

void solve() {
  ll A, B;
  cin >> A >> B;
  ll sub = B -  A;
  if(sub == 0) {
    cout << 0;
    return;
  }
  if(sub == 3) {
    cout << 3;
    return;
  }
  ll st = 0, en = 1e6;
  while(st + 1 < en) {
    ll mid = (st+en)/2;
    if(f(mid) > sub) en = mid;
    else st = mid;
  }
  if(f(st) == sub) cout << 2*st-1;
  else if(sub <= f(st) + st) cout << 2*st;
  else cout << st*2+1;
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