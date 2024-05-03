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
int dist[105][105];
void solve() {
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= N; i ++) fill(dist[i], dist[i]+N+1, mx);
  for(int i = 1; i <= N; i ++) dist[i][i] = 1;
  for(int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    dist[b][a] = 1;
  }
  for(int k = 1; k <= N; k ++) {
    for(int i = 1; i <= N; i ++) {
      for(int j = 1; j <= N; j ++) { 
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      } 
    }
  }
  int ans = 0;
  for(int i = 1; i <= N; i ++) {
    int cnt_s = 0, cnt_b = 0;
    for(int j = 1; j <= N; j ++) {
      if(i == j) continue;
      if(dist[i][j] != mx) cnt_s ++;
      if(dist[j][i] != mx) cnt_b ++;
    }
    if(cnt_s >= (N+1)/2 || cnt_b >= (N+1)/2) ans ++;
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