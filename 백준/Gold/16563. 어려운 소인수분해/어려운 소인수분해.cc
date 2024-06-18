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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[5'000'005];
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i ++) {
    cin >> A[i];
  }
  int mx = *max_element(all(A));
  for(int i = 2; i*i <= mx; i ++) {
    if(vis[i] == 1) continue;
    for(int j = i*i; j*j <= mx; j += i) {
      vis[j] = 1;
    }
  }
  vector<int> cand;
  for(int i = 2; i*i <= mx; i ++) {
    if(vis[i] == 0) cand.pb(i);
  }
  for(int i = 0; i < n; i ++) {
    vector<int> tv;
    for(int j = 0; j < sz(cand); j ++) {
      while(A[i]%cand[j] == 0) {
        tv.pb(cand[j]);
        A[i] /= cand[j];
      }
    }
    if(A[i] != 1) tv.pb(A[i]);
    sort(all(tv));
    for(int i = 0; i < sz(tv); i ++) cout << tv[i] << ' ';
    cout << nl;
  }
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