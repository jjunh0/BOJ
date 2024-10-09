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
int L[100005], R[100005], P[100005], A[100005];
char val[100005];
int A_cur = 0, ans = 0;
deque<int> dq;
int f(int cur, bool p) { // 1이면 cur부터 끝까지 최대
  int ret = 0;
  if(val[cur] == '+') {
    if(p) {
      if(L[cur] == -1) {
        ret += dq.back();
        dq.pop_back();
      }
      else {
        ret += f(L[cur], p);
      }
      if(R[cur] == -1) {
        ret += dq.back();
        dq.pop_back();
      }
      else {
        ret += f(R[cur], p);
      }
    }
    else {
      if(L[cur] == -1) {
        ret += dq.front();
        dq.pop_front();
      }
      else {
        ret += f(L[cur], p);
      }
      if(R[cur] == -1) {
        ret += dq.front();
        dq.pop_front();
      }
      else {
        ret += f(R[cur], p);
      }
    }
  }
  else {
    if(p) {
      if(L[cur] == -1) {
        ret += dq.back();
        dq.pop_back();
      }
      else {
        ret += f(L[cur], 1);
      }
      if(R[cur] == -1) {
        ret -= dq.front();
        dq.pop_front();
      }
      else {
        ret -= f(R[cur], 0);
      }
    }
    else {
      if(L[cur] == -1) {
        ret += dq.front();
        dq.pop_front();
      }
      else {
        ret += f(L[cur], 0);
      }
      if(R[cur] == -1) {
        ret -= dq.back();
        dq.pop_back();
      }
      else {
        ret -= f(R[cur], 1);
      }
    }
  }
  return ret;
}

void solve() {
  int N;
  cin >> N;
  memset(P, -1, sizeof(P));
  for(int i = 0; i < N; i ++) {
    cin >> A[i];
  }  
  sort(A, A+N);
  for(int i = 0; i < N; i ++) dq.pb(A[i]);
  for(int i = 0; i < N-1; i ++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    a -= N+1, b -= N+1;
    if(a < 0) L[i] = -1;
    else {
      L[i] = a; 
      P[a] = i;
    }
    if(b < 0) R[i] = -1;
    else {
      R[i] = b;
      P[b] = i;
    }
    val[i] = c;
  }
  int root = 0;
  while(P[root] != -1) {
    root = P[root];
  }
  cout << f(root, 1);
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