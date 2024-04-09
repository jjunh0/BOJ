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

int X[1005];
tuple<int, int, int> edge[10005];
vector<int> p(1005, -1);
int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff(int a, int b) {
  if(X[a] == X[b]) return 0;
  a = find(a);
  b = find(b);
  if(a == b) return 0;
  p[b] = a;
  return 1;
}

void solve() {
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= N; i ++) {
    char c;
    cin >> c;
    X[i] = (c == 'M' ? 1 : 0);
  }
  for(int i = 0; i < M; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[i] = {c, a, b};
  }
  sort(edge, edge+M);
  int cnt = 0;
  int sum = 0;
  for(int i = 0; i < M; i ++) {
    int a, b, c;
    tie(c, a, b) = edge[i];
    if(is_diff(a, b)) {
      cnt ++;
      sum += c;
    }
    if(cnt == N-1) break;
  }
  cout << (cnt == N-1 ? sum : -1);
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