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

struct tup {
  int x, y, z;
};
bool cmp(tup a, tup b) {
  return a.x < b.x;
}
struct SegTree{
	int size, N;
	vector<ll> arr;
	SegTree(int n){
		size = n;
		N = 1;
		while(N < size) N *= 2;
    arr.resize(2*N+1);
    fill(all(arr), mx);
	}
	void update(int i, ll val){
		i += N;
		arr[i] = val;
		while(i > 1){
			i /= 2;
			arr[i] = min(arr[i*2], arr[i*2+1]);
		}
	}
  ll get(int L, int R, int nodeNum, int nodeL, int nodeR){
      if(R < nodeL || nodeR < L) return mx;
      if(L <= nodeL && nodeR <= R) return arr[nodeNum];
      int mid = (nodeL + nodeR) / 2;
      return min(get(L, R, nodeNum*2, nodeL, mid), get(L, R, nodeNum*2+1, mid+1, nodeR));
  }
  ll get(int L, int R) {
    return get(L, R, 1, 0, N-1);
  }
};

void solve() {
  int n;
  cin >> n;

  vector<tup> v(n+1);
  for(int j = 0; j < n; j ++) {
    int num; cin >> num;
    v[num].x = j+1;
  }
  for(int j = 0; j < n; j ++) {
    int num; cin >> num;
    v[num].y = j+1;
  }
  for(int j = 0; j < n; j ++) {
    int num; cin >> num;
    v[num].z = j+1;
  }
  sort(all(v), cmp);
  vector<bool> isB(n+1);
  SegTree st(n);
  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    auto [a, x, y] = v[i];
    if(st.get(1, x-1) < y) {
      ans ++; 
    }
    st.update(x, y);
  }
  cout << n-ans;
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