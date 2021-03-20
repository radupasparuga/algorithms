#include <bits/stdc++.h>

using namespace std;
int n;
long long d, arr[1000];

int solve() {
  cin >> n >> d;
  for(int i = 0; i < n; ++i) cin >> arr[i];
  arr[n-1] = d - d % arr[n-1];
  for(int i = n-1-1; i >= 0; --i) {
    arr[i] = arr[i+1] - arr[i+1] % arr[i];
  }
  return arr[0];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  cin >> tc;

  for(int t = 1; t <= tc; ++t) {
    cout << "Case #" << t  << ": ";
    cout << solve() << endl;
  }
}