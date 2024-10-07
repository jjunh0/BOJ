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

ll p[100005];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

ll val(ll x) {
  return (
    x * (x+1) * (2*x+1) / 6 + x * (x+1) / 2
   ) / 2;
}
ll val2(ll x) {
  return x * (x-1) / 2;
}

void solve() {
  int N;
  cin >> N;
  fill(p, p+100005, -1);
  ll sum = 0, sum2 = 0;
  for(int i = 0; i < N-1; i ++) {
    int t;
    cin >> t;
    int f = find(t);
    sum -= (val(-p[f]-1) + val(-p[t+1]-1));
    sum2 -= val2(-p[f]) + val2(-p[t+1]);
    p[f] += p[t+1];
    p[t+1] = f;
    ll s = -p[f];
    sum += val(s-1);
    sum2 += val2(-p[f]);
    cout << sum2 << ' ' << sum << nl;
    
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