#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;

void solve() { 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, a[i] - a[i - 1]);
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
} 