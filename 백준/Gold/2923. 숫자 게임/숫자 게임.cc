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

void solve() {
  int N;
  cin >> N;
  vector<int> A(105), B(105);
  while(N--) {
    int a, b, mx = 0;
    cin >> a >> b;
    A[a] ++, B[b] ++;
    
    int st = 100, en = 1;
    int st_val = A[st], en_val = B[en];
    while(st >= 1 && en <= 100) {
      if(st_val == 0) st_val = A[--st];
      else if(en_val == 0) en_val = B[++en];
      else if(st_val > en_val) {
        st_val -= en_val;
        en_val = 0;
        mx = max(st+en, mx);
      }
      else {
        en_val -= st_val;
        st_val = 0;
        mx = max(st+en, mx);
      }
    }
    cout << mx << nl;
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