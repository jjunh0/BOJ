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

int cnt[5];
void solve() {
  int N, ans = MX;
  cin >> N;
  vector<int> A(N);
  for(auto &e : A) {
    cin >> e;
    cnt[e] ++;
  }
  vector<int> cand = {1, 2, 3};
  do {
    vector<int> B(5, 0);
    int cur = 0;
    for(int i = 0; i < 3; i ++) {
      for(int j = 0; j < cnt[cand[i]]; j ++) {
        if(cand[i] == 1 && A[cur] != 1) B[1] ++;
        else if(cand[i] == 2 && A[cur] == 3) B[2] ++;
        else if(cand[i] == 3 && A[cur] == 2) B[3] ++;
        cur ++;
      }
    }
    ans = min(ans, B[1] + max(B[2], B[3]));
  } while(next_permutation(all(cand)));
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