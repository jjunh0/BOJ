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

int s[] = {2, 3, 5, 7, 11, 13, 17};
ll c[20][20];
double val(double x) {
  double sum = 0;
  for(int i = 0; i < 7; i ++) {
    sum += 1.0 * c[19][s[i]] * pow(x, s[i]) * pow(1.0-x, 18-s[i]);
  }
  return sum;
}
void solve() {
  double a, b;
  cin >> a >> b;
  double x, y;
  x = a/100; y = b/100;

  for(int i = 1; i <= 18; i ++) c[i][0] = 1;
  for(int i = 1; i <= 19; i ++) {
    c[i][i] = c[i-1][i-1];
    for(int j = 1; j < i; j ++) {
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  cout << val(x) + val(y) - val(x)*val(y) << nl;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}