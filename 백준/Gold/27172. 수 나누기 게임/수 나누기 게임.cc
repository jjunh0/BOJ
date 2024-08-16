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

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n), ans(n), val(1000001, -1);
  for(int i = 0; i < n; i ++) {
    cin >> A[i];
    val[A[i]] = i;
  }
  for(int i = 0; i < n; i ++) {
    int cur = A[i];
    for(int j = cur*2; j <= 1000000; j += cur) {
      if(val[j] < 0) continue;
      ans[i] ++;
      ans[val[j]] --;
    }
  } 
  for(int i = 0; i < n; i ++) cout << ans[i] << ' ';
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