#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
using ll = long long;
bool isPn(ll x) {
	ll r = sqrt(1 + 24 * x);
	return r*r == 1 + 24 * x && r % 6 == 5;
}
int main() {
	freopen("input.txt", "r", stdin);
	vector<ll> pn;
	ll i, c = 1, cur = 1;
	while (1) {
		pn.push_back(cur);
		for (i = 0; i < pn.size() - 1; i++) {
			if (isPn(cur - pn[i]) && isPn(cur + pn[i])) {
				printf("%lld", cur - pn[i]);
				return 0;
			}
		}
		cur += 3 * c + 1;
		c++;
	}
	return 0;
}
