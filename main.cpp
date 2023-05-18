#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr auto inf = int{ 987'654'321 };

int n;
int ans;
vi dp;

void solve() {
	for (auto i = 0; i <= n; ++i) {
		dp[i] = i;
	}

	for (const auto& i : ranges::iota_view{ 2, n + 1 }) {
		if (0 == i % 3) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}

		if (0 == i % 2) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	ans = dp[n] - 1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	dp = vi(n + 1);

	solve();
	cout << ans << '\n';

	while (0 < n) {
		cout << n << ' ';

		if (1 == dp[n] - dp[n - 1]) {
			n -= 1;
		}
		else if (0 == n % 3 &&
			1 == dp[n] - dp[n / 3]) {
			n /= 3;
		}
		else if (0 == n % 2 &&
			1 == dp[n] - dp[n / 2]) {
			n /= 2;
		}
	}

	return 0;
}