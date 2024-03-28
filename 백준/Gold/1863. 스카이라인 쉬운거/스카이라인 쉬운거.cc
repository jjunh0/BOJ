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

void solve() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for(int i = 0; i < N; i ++) {
    cin >> X[i] >> Y[i];
  }
  stack<int> st;
  int ans = 0;
  for(int i = 0; i < N; i ++) {
    if(Y[i] == 0) {
      while(!st.empty()) st.pop();
      continue;
    }
    while(!st.empty() && st.top() > Y[i]) {
        st.pop();
    }
    if(st.empty() || st.top() != Y[i]) {
      st.push(Y[i]);
      ans ++;
    }
  }
  cout << ans;
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