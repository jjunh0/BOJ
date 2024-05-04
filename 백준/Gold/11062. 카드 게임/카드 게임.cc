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
int A[1005];
int dp[1005][1005];
int N;
int func(int st, int en, int t) { // st ~ en에서 t가 얻을수있는 최대 카드합
  if(st > en) return 0;
  if(dp[st][en] != -1) return dp[st][en];
  if(t == 0) {
    dp[st][en] = max(A[st] + func(st+1, en, !t), A[en] + func(st, en-1, !t));
    return dp[st][en];
  }
  else {
    return dp[st][en] = min(func(st+1, en, !t), func(st, en-1, !t));
  }
    
  
}

void solve() {
  cin >> N;
  for(int i = 0; i < N; i ++) cin >> A[i];
  for(int i = 0; i < N; i ++) fill(dp[i], dp[i]+N, -1);
  cout << func(0, N-1, 0) << nl;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while(tt--) {
    solve();
  }
}