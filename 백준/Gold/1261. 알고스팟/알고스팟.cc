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

typedef tuple<int, int, int> ti;
int arr[105][105];
int d[105][105];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
void solve() {
	int n, m;
	cin >> m >> n;
	for(int i = 1; i <= n; i ++) {
    fill(d[i], d[i]+m+1, mx);
		string s;
		cin >> s;
		for(int j = 1; j <= m; j ++) {
			arr[i][j] = s[j-1] - '0';
		}
	}

  priority_queue<ti, vector<ti>, greater<ti>> pq;
  pq.push({0, 1, 1});
  d[1][1] = 0;
  while(!pq.empty()) {
    int x, y, v;
    tie(v, x, y) = pq.top();
    pq.pop();
    if(d[x][y] != v) continue;
    for(int dir = 0; dir < 4; dir ++) {
      int nx = dx[dir] + x;
      int ny = dy[dir] + y;
      if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if(d[nx][ny] <= v + arr[nx][ny]) continue;
      d[nx][ny] = v + arr[nx][ny];
      pq.push({d[nx][ny], nx, ny});
    }
  }
  cout << d[n][m];
  

}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}
