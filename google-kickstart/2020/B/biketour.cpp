#include <bits/stdc++.h>

using namespace std;

int n, arr[100], sum;

void solve() {
  cin >> n;
  sum = 0;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for(int i = 1; i < n-1; ++i) {
    if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) sum++;
  }
  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  cin >> tc;

  for(int t = 1; t <= tc; ++t) {
    cout << "Case #" << t  << ": ";
    solve();
  }
}