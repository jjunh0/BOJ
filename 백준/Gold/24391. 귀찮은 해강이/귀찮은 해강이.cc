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
vector<int> P(100005, -1);

int find(int x) {
  if(P[x] < 0) return x;
  return P[x] = find(P[x]); 
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  P[a] = b;
}

void solve() {
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }
  int ans = 0;
  int x;
  cin >> x;
  int pre = x;
  for(int i = 0; i < N-1; i ++) {
    cin >> x;
    if(find(x) != find(pre)) ans ++;
    pre = x;
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