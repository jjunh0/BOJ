#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

bool dp[2505][2505];
void solve() {
   string s;
   cin >> s;
	 int n = (int)s.size();
   for(int i = 0; i < n; i ++) {
      dp[i][i] = 1;
   }
   for(int i = n-2; i >= 0; i --) {
		if(s[i] == s[i+1]) dp[i][i+1] = 1;
      for(int j = i+2; j < n; j++) {
        if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = 1;
      }
   }

		vector<int> cnt(n);
		cnt[0] = 1;
		for(int i = 0; i < n; i ++) {
			cnt[i] = cnt[i-1] + 1;
			for(int j = 0; j < i; j ++) {
				if(dp[j][i] == 1) {
					if(j == 0) cnt[i] = 1;
					else cnt[i] = min(cnt[j-1] + 1, cnt[i]);
				}
			}
		}
	 
	 cout << cnt[n-1];
}

// ************************************

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t = 1;
   //cin >> t;
   while(t--)
      solve();
}