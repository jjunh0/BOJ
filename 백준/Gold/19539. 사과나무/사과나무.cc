#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

void solve() {
	int n;
	cin >> n;
	vector<int> v(n+1);
	int sum=0;
	int cnt=0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		cnt += v[i]/2;
	}

	
	if(sum % 3 == 0 && cnt >= (sum/3)) cout << "YES";
	else cout << "NO";
	
	
	
}

// ************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}