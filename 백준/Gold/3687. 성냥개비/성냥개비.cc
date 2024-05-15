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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string mx[105], mn[105];
int p[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool cmp(string a, string b) {
  if(sz(a) != sz(b)) return sz(a) < sz(b);
  return a < b;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;

    for(int i = 1; i <= 100; i ++) {
      for(int j = 0; j < 10; j ++) {
        if(i - p[j] < 0) continue;
        if(sz(mx[i-p[j]]) == 0 && i-p[j] != 0) continue;
        char cur = '0' + j;
        if(cmp(mx[i], cur + mx[i-p[j]]))
          mx[i] = cur + mx[i-p[j]];
      }
    }
    mn[2] = "1";
    for(int i = 1; i <= 100; i ++) {
      bool flag = false;
      for(int j = 0; j < 10; j ++) {
        if(i - p[j] < 0) continue;
        if(sz(mx[i-p[j]]) == 0 && i-p[j] != 0) continue;
        char cur = '0' + j;
        if(!flag || cmp(cur + mn[i-p[j]], mn[i]))
          mn[i] = cur + mn[i-p[j]];
          flag = true;
      }
    }
    while(tt--) {
      int n;
      cin >> n;
      string ans;
      bool flag = false;
      for(int j = 1; j < 10; j ++) {
        if(n - p[j] < 0) continue;
        if(sz(mx[n-p[j]]) == 0 && n-p[j] != 0) continue;
        char cur = '0' + j;
        if(!flag || cmp(cur + mn[n-p[j]], ans)) {
          flag = true;
          ans = cur + mn[n-p[j]];
        }
      }
      cout << ans << ' ' << mx[n] << nl;
    }
}