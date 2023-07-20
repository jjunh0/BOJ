#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

int lc[10005];
int rc[10005];
int val[10005];
int depth[10005];
int cnt = 1;
int p[10005];
void in(int cur) {
	if(lc[cur] != 0) {
		depth[lc[cur]] = depth[cur]+1;
		in(lc[cur]);
	}
	val[cur] = cnt ++;
	if(rc[cur] != 0) {
		depth[rc[cur]] = depth[cur] + 1;
		in(rc[cur]);
	}
	
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if(t2 != -1) lc[t1] = t2;
		if(t3 != -1) rc[t1] = t3;
		p[t2] = t1;
		p[t3] = t1;
	}
	
	int rt;
	for(int i = 1; i <= n; i ++) {
		if(p[i] == 0) {
			rt = i;
			break;
		}
	}
	depth[rt] = 1;
	in(rt);
	
	vector<int> v[10005];
	for(int i = 1; i <= n; i ++) {
		v[depth[i]].pb(val[i]);
	}
	int mx = 0, ans;
	for(int i = 1; i <= n; i ++) {
		//cout << i << ' ' << val[i] << '\n';
		if(v[i].size() == 0) continue;
		sort(v[i].begin(), v[i].end());
		int t = v[i][v[i].size()-1] - v[i][0] + 1;
		//cout << i << ' ' << v[i][0] << ' ' << v[i][v[i].size()-1] << '\n';
		if(mx < t) {
			mx = t;
			ans = i;
		}
	}
	cout << ans << ' ' << mx << '\n';

}

// ************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}