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

void solve() {
  int N, M;
  cin >> N >> M;
  vector<pi> v;
  for(int i = 0; i < N; i ++) {
    int a, b;
    cin >> a >> b;
    if(a > b) {
      v.pb({b, a});
    }
  }
  ll sum = 0;
  ll en = -1;
  sort(all(v));
  for(int i = 0; i < sz(v); i ++) {
    if(en <= v[i].X) {
      sum += v[i].Y - v[i].X;
      en = v[i].Y;
    }
    else if(en < v[i].Y ) {
      sum += v[i].Y - en;
      en = v[i].Y;
    }
  }
  cout << sum*2 + M << nl;
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