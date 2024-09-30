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

int L[1005], R[1005], p[1005][35];
void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i ++) {
    cin >> L[i] >> R[i];
  }  
  vector<int> D;
  for(int i = 0; i < M; i ++) {
    char c;
    cin >> c;
    if(c == 'L') D.pb(0);
    else D.pb(1);
  }
  for(int i = 1; i <= N; i ++) {
    int cur = i;
    for(int j = 0; j < M; j ++) {
      if(D[j]) cur = R[cur];
      else cur = L[cur];
    }
    p[i][0] = cur;
  }
  for(int bit = 1; bit <= 30; bit ++) {
    for(int i = 1; i <= N; i ++) {
      p[i][bit] = p[p[i][bit-1]][bit-1];
    }
  }
  int cur = 1, diff = K;

  for(int i = 0; diff; i ++) {
    if(diff%2) {
      cur = p[cur][i];
    }
    diff /= 2;
  }
  cout << cur;
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