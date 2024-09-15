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
  int N, M, K;
  cin >> N >> K >> M;
  M--;
  vector<int> A(N);
  vector<vector<int>> B(K+1, vector<int>(32));
  for(int i = 0; i < N; i ++) cin >> A[i];
  for(int i = 1; i <= K; i ++) {
    cin >> B[i][0];
  }
  for(int i = 1; i < 32; i ++) {
    for(int j = 1; j <= K; j ++) {
      B[j][i] = B[B[j][i-1]][i-1];
    }
  }
  for(int i = 0; i < N; i ++) {
    int cur = A[i];
    for(int i = 31; i >= 0; i --) {
      if((M >> i) & 1) {
        cur = B[cur][i];
      }
    }
    cout << cur << ' ';
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