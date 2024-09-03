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
  int n;
  cin >> n;
  vector<int> A(n);
  for(auto &e : A) cin >> e;
  int en = 0, ans = 0, cnt = 0;
  vector<int> used(10);
  for(int st = 0; st < n; st ++) {
    while(en < n) {
      used[A[en]] ++;
      if(used[A[en]] == 1) cnt ++;
      en ++; 
      if(cnt <= 2) ans = max(ans, en - st);
      if(cnt > 2) break;
    }
    used[A[st]] --;
    if(!used[A[st]]) cnt --;
  }
  cout << ans;
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