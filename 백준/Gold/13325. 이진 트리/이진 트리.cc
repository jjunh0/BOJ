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
int k;
int mx;

vector<int> val_l((1<<21), 0);
vector<int> val_r((1<<21), 0);
vector<int> dp((1<<21), -1);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int getMax(int cur) {
  if(cur >= mx) return 0;
  if(dp[cur] != -1) return dp[cur];
  return dp[cur] = max(val_l[cur] + getMax(cur*2), val_r[cur] + getMax(cur*2 + 1));
}

void func(int cur, int sum) {
  if(cur > (1<<k)-1) return;
  val_l[cur] += sum - val_l[cur] - dp[cur*2];
  func(cur*2, sum - val_l[cur]);
  val_r[cur] += sum - val_r[cur] - dp[cur*2+1];
  func(cur*2+1, sum - val_r[cur]);
}

void solve() {
  cin >> k;
  mx = (1<<(k+1));
  int sum = 0;
  for(int i = 1; i <= mx - 1; i ++) {
    cin >> val_l[i] >> val_r[i];
  }
  getMax(1);
  func(1, dp[1]);
  sum = accumulate(all(val_l), 0) + accumulate(all(val_r), 0);
  cout << sum;
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