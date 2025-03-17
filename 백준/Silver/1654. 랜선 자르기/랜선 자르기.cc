#include <bits/stdc++.h>
using namespace std;

int arr[10005];
void solve() {
  int n, k;
  cin >> k >> n;
  for(int i = 0; i < k; i ++) cin >> arr[i];
  long long st = 1, en = 0x7fffffff;
  long long mid, cnt;
  while(st < en) {
    mid = (1 + st + en) / 2;
    cnt = 0;
    for(int i = 0; i < k; i ++) cnt += arr[i]/mid;
    if(cnt >= n) st = mid;
    else en = mid - 1;
  }
  cout << st;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}