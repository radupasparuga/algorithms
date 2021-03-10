#include <bits/stdc++.h>

using namespace std;

int solve(int N, int B, int arr[100000]) {
  int sum = 0, count = 0;
  sort(arr+1, arr+N+1);
  for(int i = 1; i <= N; ++i) {
    sum += arr[i];
    if(sum > B) break;
    count++;
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1, N, B, arr[100000];
  cin >> tc;

  for(int t = 1; t <= tc; ++t) {
    cin >> N >> B;
    for(int i = 1; i <= N; ++i) {
      cin >> arr[i];
    }
    cout << "Case #" << t  << ": " << solve(N, B, arr) << endl;
  }
}