#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		vector<long long> pref(n);
		pref[0] = a[0];
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + a[i];
		}
		for (int i = 0; i < q; i++) {
			int x;
			cin >> x;
			if (pref[n - 1] < x) {
				cout << -1 << '\n';
				continue;
			}
			int low = 0;
			int high = n - 1;
			int mn = n;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (pref[mid] >= x) {
					mn = min(mn, mid);
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			cout << mn + 1 << '\n';
		}
	}
	return 0;
}
