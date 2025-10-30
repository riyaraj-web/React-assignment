#include <bits/stdc++.h>
using namespace std;
int n, k, a[200001], b[200001];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= k; i++)
    cin >> b[i];
  long long ans = 0;
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  for (int i = 1; i <= n; i++)
    ans += a[i];
  long long id = n + 1;
  for (int i = 1; i <= k; i++) {
    id -= b[i];
    if (id >= 1)
      ans -= a[id];
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
