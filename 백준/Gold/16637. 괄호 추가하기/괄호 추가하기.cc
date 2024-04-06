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
#define int ll
int N, ans = -1e15;
string s;

int calc(int a, char op, int b) {
  if(op == '+') return a+b;
  else if(op == '-') return a-b;
  else return a*b;
}

void func(int cur, int val) {
  if(cur >= N) {
    ans = max(ans, val);
    return;
  }
  func(cur+2, calc(val, s[cur-1], s[cur] - '0'));
  if(cur == N-1) {
    return;
  }
  func(cur+4, calc(val, s[cur-1], calc(s[cur]-'0', s[cur+1], s[cur+2]-'0')));
}

void solve() {
  cin >> N;
  cin >> s;
  func(2, s[0]-'0');
  cout << ans;
}

// ************************************

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while(tt--) {
    solve();
  }
}