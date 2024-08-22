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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cross(pi p1, pi p2) {
  return p1.X * p2.Y - p2.X * p1.Y;
}
void solve() {
  pi c[3];
  cin >> c[0].X >> c[0].Y >> c[1].X >> c[1].Y >> c[2].X >> c[2].Y;
  pi u, v;
  u.X = c[1].X - c[0].X;
  u.Y = c[1].Y - c[0].Y;
  v.X = c[2].X - c[1].X;
  v.Y = c[2].Y - c[1].Y;
  int ret = cross(u, v);
  cout << (ret == 0 ? 0 : (ret<0 ? -1 : 1));


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