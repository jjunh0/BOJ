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

int board[55][55];
ll sum[55][55];

ll get(int startx, int starty, int endx, int endy) {
	int sum = 0;
	for (int i = startx; i <= endx; i++) {
		for (int j = starty; j <= endy; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++) {
    string s;
    cin >> s;
    for(int j = 1; j <= m; j ++) {
      board[i][j] = s[j-1] - '0';
    }
  }
  // sum[i][j] = 1,1 ~ i,j까지의 합
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) { 
      sum[i][j] = board[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    } 
  }
  ll ans = 0;

  for(int i = 1; i < m-1; i ++) {
    for(int k = i+1; k < m; k ++) {
			ans = max(ans, get(1, 1, n, i)* get(1, i + 1, n, k)* get(0, k + 1, n, m));
    }
  }



	for (int i = m; i > 1; i--) {
		for (int j = 1; j < n; j++) {
			ans = max(ans, get(1, i, n, m)* get(1, 1, j, i - 1) * get(j + 1, 1, n, i - 1));
		}
	}

	//4번 모양
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			ans = max(ans, get(1, 1, n, i)* get(1, i + 1, j, m)* get(j + 1, i + 1, n, m));
		}
	}

  for(int i = 1; i < n-1 ; i ++) {
    for(int k = i+1; k < n; k ++) {
      ans = max(ans, get(1,1, i,m) * get(i+1,1, k, m) * get(k+1, 1, n, m));
    }
  } 
  
  for(int i = 1; i < n; i ++) {
    for(int k = 1; k < m; k ++) {
      ans = max(ans, get(1,1, i, m) * get(i+1, 1, n, k) * get(i+1, k+1, n, m)
          ); // ㅜ
      ans = max(ans, get(1, 1, i, k) * get(1, k+1, i, m) * get(i+1, 1, n, m));
      // ㅗ
    }
  }
  
  for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			ans = max(ans, get(0, 0, n, i) * get(0, i+1, j, m) * get(j+1, i+1, n, m));
		}
	}

  cout << ans;
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