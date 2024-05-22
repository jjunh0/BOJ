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
  int t;
  cin >> t;
  int bit = 0;
  while(t--) {
    string s;
    int n;
    cin >> s;
    if(s == "add") {
      cin >> n;
      bit |= (1<<(n-1));
    }
    else if(s == "remove") {
      cin >> n;
      bit &= (~(1<<(n-1)));
    }
    else if(s == "check") {
      cin >> n;
      cout << ((bit>>(n-1)) & 1) << nl;
    }
    else if(s == "toggle") {
      cin >> n;
      bit ^= (1<<(n-1));
    }
    else if(s == "all") {
      bit = 0xfffff;
    }
    else {
      bit = 0;
    }
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
}