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
string A[105];
int N;

void func1(int y, int sub) {
  for(int i = 0; i < N-1; i ++) {
    int cur = A[y][i] - '0';
    if(i-1 >= 0 && A[y+sub][i-1] == 'b') cur --;
    if(A[y+sub][i] == 'b') cur --;
    if(cur > 0) A[y+sub][i+1] = 'b';
  }
}

void func2(int x, int sub) {
  for(int i = 0; i < N-1; i ++) {
    int cur = A[i][x] - '0';
    if(i-1 >= 0 && A[i-1][x+sub] == 'b') cur --;
    if(A[i][x+sub] == 'b') cur --;
    if(cur > 0) A[i+1][x+sub] = 'b';
  }
}

void solve() {
  cin >> N;
  for(int i = 0; i < N; i ++) {
    cin >> A[i];
  }
  func1(0, 1);
  func1(N-1, -1);
  func2(0, 1);
  func2(N-1, -1);
  int cnt = 0;
  for(int i = 1; i < N-1; i ++) {
    for(int j = 1; j < N-1; j ++) {
      if((i > 1 && i < N-2 && j > 1 && j < N-2 )|| A[i][j] == 'b') cnt ++;
    }
  }
  cout << cnt << nl;
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