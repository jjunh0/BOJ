#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
long long arr[1005];
pair<int, int> p[1005];
bool vis[1005];
bool cmp(pair<int, long> a, pair<int, long> b) {
  if(a.X == b.X) return a.Y < b.Y;
  return a.X > b.X;
}

void solve() {
  int n, c;
  cin >> n >> c;
  for(int i = 0; i < n; i ++) {
    cin >> arr[i];
  }

  for(int i = 0; i < n; i ++) {
    if(vis[i]) continue;
    int cnt = 0;
    for(int j = 0; j < n; j ++) {
      if(arr[j] == arr[i]) {
        cnt ++;
        vis[j] = 1;
      }
    }
    for(int j = 0; j < n; j ++) {
      if(arr[j] != arr[i]) continue;
      p[j].X = cnt; // 등장 횟수
      p[j].Y = i; // 같다면
    }
  }

  sort(p, p+n, cmp);

  for(int i = 0; i < n; i ++) {
    cout << arr[p[i].Y] << ' ';
  }
  
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}